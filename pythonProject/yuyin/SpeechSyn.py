# import numpy as np
from speechlib import*
# from sympy import Matrix

from scipy.signal import medfilt


def linsmoothm(x, n=3):
    win = np.hanning(n)
    win /= np.sum(win)
    l = len(x)
    y = np.zeros(l)
    if np.mod(n, 2) == 0:
        ll = n // 2
        xx = np.hstack((x[0] * np.ones(1), x, x[-1] * np.ones(ll)))
    else:
        ll = (n - 1) // 2
        xx = np.hstack((x[0] * np.ones(1), x, x[-1] * np.ones(ll + 1)))
    for i in range(l):
        y[i] = np.matmul(win, xx[i:i + n])
    return y


def pitfilterm1(x, vseg, vsl):
    y = np.zeros(len(x))
    for i in vseg.keys():
        ixb = vseg[i]['start']
        ixe = vseg[i]['end']
        u = x[ixb:ixe+1]
        u = medfilt(u, 5)
        v0 = linsmoothm(u, 5)
        y[ixb:ixe+1] = v0
    return y

def frmnt2coeff3(f0, bw, fs):
    R = np.exp(-np.pi*bw/fs)
    theta = (2*np.pi*f0)/fs
    poles = R*np.exp(1j*theta)
    A = np.real(np.poly([poles, poles.conjugate()]))
    B = np.abs(A[0]+A[1]*np.exp(1j*theta)+A[2]*np.exp(2j*theta))
    return A, B

def formant2filter4(F0, Bw, fs):
    F0 = np.append(F0,3500)
    Bw = np.append(Bw,100)
    An = []
    Bn = []
    for i in range(4):
        f0=F0[i]
        bw=Bw[i]
        A,B = frmnt2coeff3(f0,bw,fs)
        An.append(A)
        Bn.append(B)
    return An,Bn

def lpctolsf(a):
    if a[0]!=1.0:
        a = a/a[0]
    p = len(a)-1
    a1 = list(a)
    a1.append(0)
    a2 = a1.copy()
    a2.reverse()
    a1 = np.array(a1)
    a2 = np.array(a2)
    P1 = a1+a2
    Q1 = a1-a2
    if p%2==1:
        Q, R =np.polydiv(np.poly1d(Q1),np.poly1d([1,0,-1]))
        Q = np.array(Q)
        P = P1
    elif p%2 == 0:
        Q, R1 = np.polydiv(np.poly1d(Q1),np.poly1d([1,-1]))
        P, R1 = np.polydiv(np.poly1d(P1), np.poly1d([1, 1]))
        Q = np.array(Q)
        P = np.array(P)
    rP = np.roots(P)
    rQ = np.roots(Q)
    aP = np.angle(rP[::2])
    aQ = np.angle(rQ[::2])
    lsf = np.sort(np.append(aP,aQ))
    return lsf

def lsftolpc(lsf):
    p = len(lsf)
    z = np.exp((0+1j) * lsf)
    rP = z[::2]
    rQ = z[1::2]
    rQ = np.concatenate((rQ, rQ.conjugate()), axis=0)
    rP = np.concatenate((rP, rP.conjugate()), axis=0)
    Q1 = np.poly(rQ)
    P1 = np.poly(rP)
    if p % 2 == 1:
        Q = np.polymul(np.poly1d(Q1), np.poly1d([1, 0, -1]))
        Q = np.array(Q)
        P = P1
    elif p % 2 == 0:
        Q = np.polymul(np.poly1d(Q1), np.poly1d([1, -1]))
        P = np.polymul(np.poly1d(P1), np.poly1d([1, 1]))
        Q = np.array(Q)
        P = np.array(P)
    a = 0.5 * (P + Q)
    lpc = a[0:-1]
    return lpc

def Filpframe_OverlapA(x, win, inc):
    """
    基于重叠相加法的信号还原函数
    :param x: 分帧数据
    :param win: 窗
    :param inc: 帧移
    :return:
    """
    nf, slen = x.shape
    nx = (nf - 1) * inc + slen
    frameout = np.zeros(nx)
    x = x / win
    for i in range(nf):
        start = i * inc
        frameout[start:start + slen] += x[i, :]
    return frameout


def Filpframe_OverlapS(x, win, inc):
    """
    基于重叠存储法的信号还原函数
    :param x: 分帧数据
    :param win: 窗
    :param inc: 帧移
    :return:
    """
    nf, slen = x.shape
    nx = (nf - 1) * inc + slen
    frameout = np.zeros(nx)
    x = x / win
    for i in range(nf):
        frameout[slen + (i - 1) * inc:slen + i * inc] += x[i, slen - inc:]
    return frameout


def Filpframe_LinearA(x, win, inc):
    """
    基于比例重叠相加法的信号还原函数
    :param x: 分帧数据
    :param win: 窗
    :param inc: 帧移
    :return:
    """
    nf, slen = x.shape
    nx = (nf - 1) * inc + slen
    frameout = np.zeros(nx)
    overlap = len(win) - inc
    x = x / win
    w1 = [i / overlap for i in range(overlap)]
    w2 = [i / overlap for i in range(overlap - 1, -1, -1)]
    for i in range(nf):
        if i == 0:
            frameout[:slen] = x[i, :]
        else:
            M = slen + (i - 1) * inc
            y = frameout[M - overlap:M] * w2 + x[i, :overlap] * w1
            xn = x[i, overlap:]
            yy = np.hstack((y, xn))
            frameout[M - overlap:M - overlap + slen] += yy
    return frameout

'''
def lpctolsf(a):
    if a[0]!=1.0:
        a=a/a[0]
    if np.max(np.abs(np.roots(a))) >= 1.0:
        return
    p=len(a)-1
    a1=np.row_stack(a,)
'''

