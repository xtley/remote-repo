import numpy as np
import cmath
from numpy.matlib import repmat
from scipy import linalg
from scipy.linalg import schur

def jeig(A,B):
    L = linalg.cholesky(B, lower=True)  # 默认计算 upper， 所以指定 lower = True
    G = np.linalg.inv(L)
    C = np.dot(np.dot(G,A),G.T)
    Q,D=schur(C)
    X = np.dot(G.T,Q)
    return X,D

def mydsb(nChannels, dMic, DOA, freqVec):
    '''
    延迟求和
    :param nChannels: 通道数
    :param dMic: 麦克风间距
    :param DOA: 目标角度
    :param freqVec: 频率
    :return:
    '''
    c = 340
    theta0 = DOA * np.pi / 180
    ddd = 2 * np.pi * freqVec * dMic / c * np.array(list(range(nChannels))).T * np.cos(theta0)
    H = np.zeros(nChannels, dtype=complex)
    for i in range(len(ddd)):
        d = cmath.exp(complex(0, -1 * ddd[i]))
        H[i] = 1 / nChannels * d
    return H

def maximumDF(nChannels, dMic, DOA, freqVec):
    '''
    maximumDF波束
    :param nChannels:
    :param dMic:
    :param DOA:
    :param freqVec:
    :return:
    '''
    c = 340
    theta0 = DOA * np.pi / 180
    ddd = 2 * np.pi * freqVec * dMic / c * np.array(list(range(nChannels))).T * np.cos(theta0)
    m_mat, n_mat = np.meshgrid([i for i in range(1, nChannels + 1, 1)], [i for i in range(1, nChannels + 1, 1)])
    Gamma0 = np.sinc(2 * freqVec * dMic / c * (m_mat - n_mat))
    d = np.zeros(nChannels, dtype=complex)
    for i in range(len(ddd)):
        d1 = cmath.exp(complex(0, -1 * ddd[i]))
        d[i] = d1
    H_mDF = (np.linalg.solve(Gamma0, d)) / (np.dot(np.dot(d.T, np.linalg.inv(Gamma0)), d))
    return H_mDF

def Robust_Superdirective_Beamforming(nChannels, dMic, DOA, freqVec):
    '''
    Robust_Superdirective_Beamforming波束形成
    :param nChannels:
    :param dMic:
    :param DOA:
    :param freqVec:
    :return:
    '''
    c = 340
    alpha = 0.001
    theta0 = DOA * np.pi / 180
    ddd = 2 * np.pi * freqVec * dMic / c * np.array(list(range(nChannels))).T * np.cos(theta0)
    m_mat, n_mat = np.meshgrid([i for i in range(1, nChannels + 1, 1)], [i for i in range(1, nChannels + 1, 1)])
    Gamma0 = np.sinc(2 * freqVec * dMic / c * (m_mat - n_mat))
    d = np.zeros(nChannels, dtype=complex)
    for i in range(len(ddd)):
        d1 = cmath.exp(complex(0, -1 * ddd[i]))
        d[i] = d1
    Gamma_alpha = (1 - alpha) * Gamma0 + alpha * np.eye(nChannels)
    H_R = (np.linalg.solve(Gamma_alpha, d)) / (np.dot(np.dot(d.T, np.linalg.inv(Gamma_alpha)), d))
    return H_R

def subspace_beamformer(nChannels, dMic, DOA, freqVec):
    c = 340
    N = 2
    theta0 = DOA * np.pi / 180
    ddd = 2 * np.pi * freqVec * dMic / c * np.array(list(range(nChannels))).T * np.cos(theta0)
    m_mat, n_mat = np.meshgrid([i for i in range(1, nChannels + 1, 1)], [i for i in range(1, nChannels + 1, 1)])
    Gamma0 = np.sinc(2 * freqVec * dMic / c * (m_mat - n_mat))
    d = np.zeros(nChannels, dtype=complex)
    for i in range(len(ddd)):
        d1 = cmath.exp(complex(0, -1 * ddd[i]))
        d[i] = d1
    T, Lambda = jeig(np.dot(d, d.T), Gamma0)
    diagL = sorted(np.diag(Lambda), reverse=True)
    idx = sorted(range(len(np.diag(Lambda))), key=lambda k: np.diag(Lambda)[k], reverse=True)
    Lambda = np.diag(diagL)
    T = T[:, idx]
    T1N = T[:, 0:N]
    P1N = np.dot(np.dot(T1N, np.linalg.inv(np.dot(T1N.T, T1N))), T1N.T)
    for i in range(P1N.shape[0]):  # 防止产生奇异矩阵
        P1N[i, i] = 1e-6
    H_s = (np.linalg.solve(P1N, d)) / (np.dot(np.dot(d.T, np.linalg.inv(P1N)), d))
    return H_s

def MN_NS_Beamforming(nChannels, dMic, DOA_s,DOA_i, freqVec):
    c = 340;
    theta_d = DOA_s * np.pi / 180
    theta_i = DOA_i * np.pi / 180
    alpha = 0.001
    m_mat, n_mat = np.meshgrid([i for i in range(1, nChannels + 1, 1)], [i for i in range(1, nChannels + 1, 1)])
    i_c = np.array([1, 0]).T

    ddd_d = 2 * np.pi * freqVec * dMic / c * np.array(list(range(nChannels))).T * np.cos(theta_d)
    ddd_i = 2 * np.pi * freqVec * dMic / c * np.array(list(range(nChannels))).T * np.cos(theta_i)
    Gamma0 = np.sinc(2 * freqVec * dMic / c * (m_mat - n_mat))
    d_d = np.zeros(nChannels, dtype=complex)
    d_i = np.zeros(nChannels, dtype=complex)
    for i in range(len(ddd_d)):
        d1 = cmath.exp(complex(0, -1 * ddd_d[i]))
        d_d[i] = d1
    for i in range(len(ddd_d)):
        d2 = cmath.exp(complex(0, -1 * ddd_i[i]))
        d_i[i] = d2
    C = np.array([d_d, d_i]).T
    Gamma_alpha = (1 - alpha) * Gamma0 + alpha * np.eye(nChannels)
    H_mDF = (np.linalg.solve(Gamma_alpha, C)) / np.dot(np.dot(np.dot(C.T, np.linalg.inv(Gamma_alpha)), C), i_c)
    return H_mDF


def applyBeamforming(arraySignal, dMic, fs, DOA, DOA_i,f,beamtype):
    nChannels = arraySignal.shape[0]
    x = arraySignal
    len = int(np.floor(20 * fs / 1000))
    if len % 2 == 1:
        len = len + 1
    overlap = 0.50
    len1 = int(np.floor(len * overlap))
    len2 = len - len1
    nFrames = int(np.floor(x.shape[1] / len2) - np.floor(len / len2))
    xfinal = np.zeros(nFrames * len2 + len1)
    win = np.hamming(len).T
    win2D = repmat(win, nChannels, 1)
    nFFT = len

    if beamtype == 'DSB' :
        hw = mydsb(nChannels, dMic, DOA, f)
    elif beamtype == 'maximumDF':
        hw = maximumDF(nChannels, dMic, DOA, f)
    elif beamtype == 'Robust_Superdirective_Beamforming':
        hw = Robust_Superdirective_Beamforming(nChannels, dMic, DOA, f)
    elif beamtype == 'subspace_beamformer':
        hw = subspace_beamformer(nChannels, dMic, DOA, f)
    elif beamtype == 'MN_NS_Beamforming':
        hw = MN_NS_Beamforming(nChannels, dMic, DOA,DOA_i, f)
    else:
        print('error!')
    hw1 = repmat(hw,len,1).T

    k = 0
    for n in range(nFrames):
        xk = win2D * x[:,k:k+len]
        spec = np.fft.fft(xk,nFFT)   #  这儿有问题
        spec_bf = (hw1 * spec).sum(axis=0)
        xi_w = np.fft.ifft(spec_bf,nFFT)
        xi_w = np.real(xi_w)

        xfinal[k: k + len] =  xfinal[k: k + len] + win * xi_w
        k = k + len2
    x_out = xfinal
    return x_out



