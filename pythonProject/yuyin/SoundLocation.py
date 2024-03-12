import numpy as np
import math
from speechlib import enframe
import scipy.fftpack as fftpack

def GCC_Method(m,s1,s2,wnd,inc):
    N = wnd
    wnd = np.hamming(N)
    x = enframe(s1, wnd, inc)
    y = enframe(s2, wnd, inc)
    n_frame = x.shape[0]

    Gvalue = np.zeros(n_frame)
    G = np.zeros(n_frame)

    if m == 'standard':
        for i in range(n_frame):
            x = s1[i:i + N]
            y = s2[i:i + N]
            X = np.fft.fft(x,n=2*N-1)
            Y = np.fft.fft(y,n=2*N-1)
            Sxy = X*Y.conjugate()
            gain = 1 / np.abs(Sxy)
            Cxy = fftpack.fftshift(np.fft.ifft(Sxy*gain))
            # Gvalue[i] = np.max(Cxy)
            G[i] = np.argmax(Cxy)
    elif m == 'roth':
        for i in range(n_frame):
            x = s1[i:i + N]
            y = s2[i:i + N]
            X = np.fft.fft(x, n=2 * N - 1)
            Y = np.fft.fft(y, n=2 * N - 1)
            Sxy = X * Y.conjugate()
            Sxx = X * X.conjugate()
            gain = 1 / np.abs(Sxx)
            Cxy = fftpack.fftshift(np.fft.ifft(Sxy*gain))
            # Gvalue[i] = np.max(Cxy)
            G[i] = np.argmax(Cxy)
    elif m == 'scot':
        for i in range(n_frame):
            x = s1[i:i + N]
            y = s2[i:i + N]
            X = np.fft.fft(x, n=2 * N - 1)
            Y = np.fft.fft(y, n=2 * N - 1)
            Sxy = X * Y.conjugate()
            Sxx = X * X.conjugate()
            Syy = Y * Y.conjugate()
            gain = 1 / np.sqrt(Sxx * Syy)
            Cxy = fftpack.fftshift(np.fft.ifft(Sxy * gain))
            # Gvalue[i] = np.max(Cxy)
            G[i] = np.argmax(Cxy)
    elif m == 'phat':
        for i in range(n_frame):
            x = s1[i:i + N]
            y = s2[i:i + N]
            X = np.fft.fft(x, n=2 * N - 1)
            Y = np.fft.fft(y, n=2 * N - 1)
            Sxy = X * Y.conjugate()
            gain = 1 / np.abs(Sxy)
            Cxy = fftpack.fftshift(np.fft.ifft(Sxy * gain))
            # Gvalue[i] = np.max(Cxy)
            G[i] = np.argmax(Cxy)
    elif m == 'ml':
        for i in range(n_frame):
            x = s1[i:i+N]
            y = s2[i:i+N]
            X = np.fft.fft(x, n=2 * N - 1)
            Y = np.fft.fft(y, n=2 * N - 1)
            Sxy = X * Y.conjugate()
            Sxx = X * X.conjugate()
            Syy = Y * Y.conjugate()
            Zxy = (Sxy * Sxy) / (Sxx * Syy)
            gain = (1 / np.abs(Sxy)) * (np.power(Zxy, 2) / (1 - np.power(Zxy, 2)))
            Cxy = fftpack.fftshift(np.fft.ifft(Sxy * gain))
            # Gvalue[i] = np.max(Cxy)
            G[i] = np.argmax(Cxy)
    else:
        print('Method not defined...')
    return G

def Spectrum_Method(m,s1,s2,wlen,inc,rang):
    fs = 8000
    M = 2
    p = 1
    d = 0.5
    a = np.array([0, 1])
    t = np.arange(-np.pi, np.pi, 1 / fs)

    wnd = np.hamming(wlen)
    x = enframe(s1, wnd, inc)
    y = enframe(s2, wnd, inc)
    n_frame = x.shape[0]
    Rangle = np.arange(-rang, rang + 0.1, 0.1)
    X = np.zeros([2, 256])
    S_theta = np.zeros(901)
    AngleM = np.zeros(n_frame)

    if m == 'capon':
        for z in range(n_frame):
            X[0, :] = x[z, :]
            X[1, :] = y[z, :]
            RX = np.dot(X, X.T) / len(t)
            Rinv = np.linalg.inv(np.dot(X, X.T) / len(t))
            i = 0
            for theta in np.arange(-rang, rang + 0.1, 0.1):
                a0 = 0
                a1 = -np.pi * np.sin(theta * np.pi / 180) * a[0]
                a2 = -np.pi * np.sin(theta * np.pi / 180) * a[1]
                aaa0 = np.exp(complex(a0, a1))
                aaa1 = np.exp(complex(a0, a2))
                aaa = np.array([aaa0, aaa1])
                ccc = np.dot(aaa, Rinv)
                ddd = (np.abs(ccc)) ** 2
                bbb = 1 / np.sum(ddd)
                S_theta[i] = bbb
                i = i + 1
            S = 10 * np.log10(S_theta / np.max(S_theta))
            ya = np.argmin(S)
            AngleM[z] = Rangle[ya]
    elif m =='music':
        for z in range(n_frame):
            X[0, :] = x[z, :]
            X[1, :] = y[z, :]
            E, D, V = np.linalg.svd(np.dot(X, X.T) / len(t))
            Nn = np.dot(E[:, p: M], E[:, p: M].T)
            i = 0
            for theta in np.arange(-rang, rang + 0.1, 0.1):
                a0 = 0
                a1 = -np.pi * np.sin(theta * np.pi / 180) * a[0]
                a2 = -np.pi * np.sin(theta * np.pi / 180) * a[1]
                aaa0 = np.exp(complex(a0, -a1))
                aaa1 = np.exp(complex(a0, a2))
                aaa = np.array([aaa0, aaa1])
                bbb = 1 / np.sum((np.abs(np.dot(aaa, Nn))) ** 2)
                S_theta[i] = bbb
                i = i + 1
            S = 10 * np.log10(S_theta / np.max(S_theta))
            ya = np.argmin(S)
            AngleM[z] = Rangle[ya]
    elif m ==  'esprit':
        for z in range(n_frame):
            X[0, :] = x[z, :]
            X[1, :] = y[z, :]
            U, D, V = np.linalg.svd(np.dot(X, X.T) / len(t))
            S = U[:, 0].reshape(2, 1)
            aaa = np.linalg.inv(S[0, :].reshape(1, 1))
            bbb = S[1, :].reshape(1, 1)
            phi = np.dot(aaa, bbb)
            ccc = np.linalg.eig(phi)
            w = np.angle(ccc[0])
            AngleM[z] = math.asin(w / d / np.pi / 2) * 180 / np.pi
    else:
        print('Method not defined...')
    return AngleM
