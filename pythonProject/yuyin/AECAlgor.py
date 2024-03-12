import numpy as np

def nlms(x,d,M,w_cut,alpha,beta):
    w = np.zeros(M)
    sound_length = len(x)
    N = sound_length
    xn = x[0:M]
    nor_xn = np.matmul(xn.T,xn)
    dn = d[0:M]
    nor_dn = np.matmul(dn.T,dn)
    en = dn
    nor_en = np.matmul(en.T,en)
    e = np.zeros(N)
    e[0:M] = dn
    y = np.zeros(N)
    mis=np.zeros(N)
    ERLE= np.zeros(N)
    for n in range(M,sound_length):
        xn = x[n:n-M:-1]
        y[n]=np.matmul(xn.T,w)
        e[n]=d[n]-y[n]
        miu = alpha / (beta + nor_xn)
        w = w + miu * xn * e[n]
        mis[n]=np.power(np.linalg.norm(w-w_cut),2)/np.power(np.linalg.norm(w_cut),2)
        if nor_en-np.spacing(1) >0:
            max0 = nor_en
        else:
            max0 = np.spacing(1)
        tea = nor_dn/(max0+beta)
        ERLE[n] = 10 * np.log10(tea+beta)
        nor_xn = nor_xn + x[n] * x[n] - x[n - M] * x[n - M]
        nor_dn = nor_dn + d[n] * d[n] - d[n - M] * d[n - M]
        nor_en = nor_en + e[n] * e[n] - e[n - M] * e[n - M]
    return e,w,mis,ERLE

def FLMS(x,d,w_cut,alpha,lambda1):
    estimated_power = 0.01
    filter_length = len(w_cut)
    FILTER_COEFF = np.zeros(filter_length*2)
    input_length = len(x)
    block_length = np.floor(input_length / filter_length) * filter_length
    x = x[0:int(block_length)]
    d = d[0:int(block_length)]
    x = x[:]
    d = d[:]
    e = d
    Blocks = int(block_length / filter_length)
    mis = np.zeros(Blocks)
    ERLE = np.zeros(Blocks)
    for k in range(int(Blocks - 1)):
        xt = x[k * filter_length:(k + 2) * filter_length]
        xn = np.fft.fft(xt, 2 * filter_length)
        output = np.fft.ifft(np.multiply(xn, FILTER_COEFF))
        output1 = output[filter_length:2 * filter_length].real
        desired_vec = d[(k + 1) * filter_length:(k + 2) * filter_length]  # 2048
        AAAA = desired_vec * desired_vec
        e[(k + 1) * filter_length:(k + 2) * filter_length] = desired_vec - output1
        e_VEC = np.fft.fft(
            np.concatenate((np.zeros(filter_length), e[(k + 1) * filter_length:(k + 2) * filter_length]), axis=0),
            2 * filter_length)
        estimated_power = lambda1 * estimated_power + (1 - lambda1) * np.power(np.abs(xn), 2)
        DESIRED_VEC = np.ones(estimated_power.shape[0]) / (1 + estimated_power)
        phivec = np.fft.ifft(np.multiply(np.multiply(DESIRED_VEC, xn.conjugate()), e_VEC), 2 * filter_length)
        phivec = phivec[0:filter_length]
        FILTER_COEFF = FILTER_COEFF + alpha * np.fft.fft(np.concatenate((phivec, np.zeros(filter_length)), axis=0),
                                                         2 * filter_length)
        e = np.real(e[:])
        w = np.fft.ifft(FILTER_COEFF)
        w = np.real(w[0:int(len(FILTER_COEFF) / 2)])
        mis[k] = np.power(np.linalg.norm(w - w_cut), 2) / np.power(np.linalg.norm(w_cut), 2)
        a1 = np.multiply(e[(k + 1) * filter_length:(k + 2) * filter_length],
                         e[(k + 1) * filter_length:(k + 2) * filter_length])
        MM = np.sum(np.multiply(e[(k + 1) * filter_length:(k + 2) * filter_length],
                                e[(k + 1) * filter_length:(k + 2) * filter_length]))
        if MM - np.spacing(1) > 0:
            max0 = MM
        else:
            max0 = np.spacing(1)
        tea = np.sum(AAAA) / (max0+0.00001)
        ERLE[k] = 10 * np.log10(tea+0.00001)
    return e,w,mis,ERLE

def AP(x,d,K,P,w_cut,mu,epsilon):
    L = len(x)
    w = np.zeros((L, P))
    e = np.zeros(L)
    y = np.zeros(L)
    xvec = np.zeros(P)
    X = np.zeros((K, P))
    dvec = np.zeros(K)
    y = np.zeros(L)
    mis = np.zeros(L)
    ERLE = np.zeros(L)
    for i in range(L-2):
        xvec = np.append(x[i],xvec[0:P-1])
        c = []
        c.append([xvec])
        c.append([X[0,:]])
        X = np.concatenate(c)
        y[i] = np.matmul(w[i,:] , xvec)
        e[i] = d[i] - y[i]
        dvec = np.append(d[i],dvec[0:K-1])
        evec = dvec - np.matmul(X , w[i,:])
        upd1 = np.matmul(mu * X.T,np.linalg.inv(epsilon * np.eye(K)+np.matmul(X,X.T)))
        upd = np.matmul(upd1,evec)
        w[i + 1,:] = w[i,:] + upd.T
        mis[i] = np.power(np.linalg.norm(w[i,:] - w_cut), 2) / np.power(np.linalg.norm(w_cut), 2)
        MM = np.sum(np.multiply(evec, evec))
        if MM - np.spacing(1) > 0:
            max0 = MM
        else:
            max0 = np.spacing(1)
        ERLE[i] = 10 * np.log10(np.sum(np.multiply(dvec, dvec))/ (max0+0.00001)+0.00001)
    return e,w,mis,ERLE

def RLS(x,d,w_cut,M,Lambda,Delta):
    L = len(x)
    y = np.zeros(L)
    w = np.zeros(M)
    e = np.zeros(L)
    E = np.zeros(L)
    P = Delta * np.eye(M, M)
    loop = 1
    mis = np.zeros(480000)
    for i in range(L - M + 1):
        pi_ = np.matmul(x[i:i + M].T, P)
        k = Lambda + np.matmul(pi_, x[i:i + M])
        K = pi_.T / k
        y[i + M] = np.matmul(w, x[i:i + M])
        e[i + M] = d[i + M] - y[i + M]
        w = w + K.T * e[i + M]
        PPrime = K * pi_
        P = (P - PPrime) / Lambda
        mis[i] = np.power(np.linalg.norm(w.T - w_cut), 2) / np.power(np.linalg.norm(w_cut), 2)
        # E = E + e. ^ 2

    return e,w,mis

# def PBFDAFC(x,d,TN,w_cut,mu,fs,NLPon):
#     mu = 0.1
#     bet = 0.9
#     M = 16
#     y = np.zeros(x.shape)
#     e = y
#     normFFTX = np.zeros(TN)
#     FFTW = np.zeros((TN, M))
#     N = int(TN / 2)
#     ntrB = int(np.floor(len(x) / N))
#     FFTX = np.zeros((TN, M))
#     E = np.zeros(TN)
#     X = np.zeros(TN)
#     lam = 1
#     ZNM = np.zeros((N, M))
#     OMt = np.ones(M)  # [:,None]
#     print("OMt", OMt.shape)
#     CNon = 0
#     wins = np.append(0, np.power(np.hanning(TN - 1), 1 / 2))
#     dIdx = 1
#     D = np.zeros(TN)
#     xfwm = np.zeros((TN, M))
#     Se = np.zeros(TN)
#     Sd = np.zeros(TN)
#     Sx = np.zeros(TN)
#     Sed = np.zeros(TN)
#     Sxd = np.zeros(TN)
#     gamma = 0.93
#     echoBandRange = np.arange(math.ceil(300 * 2 / fs * TN), np.floor(1800 * 2 / fs * TN), step=1)
#     cohxdLocalMin = 1
#     hnlLocalMin = 1
#     hnlNewMin = 0
#     hnlMinCtr = 0
#     mult = 2
#     hnlMin = 1
#     ovrdSm = 2
#     ovrd = 2
#     divergeState = 0
#     hnlLocalMinV = np.zeros(ntrB)
#     cohxdLocalMinV = np.zeros(ntrB)
#     hnlMinV = np.zeros(ntrB)
#     dkEnV = np.zeros(ntrB)
#     ekEnV = np.zeros(ntrB)
#     ovrdV = np.zeros(ntrB)
#     dIdxV = np.zeros(ntrB)
#     SLxV = np.zeros(ntrB)
#     hnlSortQV = np.zeros(ntrB)
#     hnlPrefAvgV = np.zeros(ntrB)
#     mutInfAvg = np.zeros(ntrB)
#     hnledAvg = np.zeros(ntrB)
#     hnlxdAvg = np.zeros(ntrB)
#     Sym = 1e7 * np.ones(TN)
#     mbuf = np.zeros(TN)
#     for n in range(ntrB):
#         # nn = n * N :(n+1) * N
#         X[0: N] = X[N: TN]
#         X[N: TN] = x[n * N:(n + 1) * N]
#         FFTX[:, 1: M] = FFTX[:, 0: M - 1]
#         FFTX[:, 0] = np.fft.fft(X)
#         # Y = np.fft.ifft(sum(FFTW. * FFTX, 2))
#         Y = np.fft.ifft(np.multiply(FFTW, FFTX).sum(axis=1))
#         y[n * N:(n + 1) * N] = np.real(Y[N:TN])
#         e[n * N:(n + 1) * N] = d[n * N:(n + 1) * N] - y[n * N:(n + 1) * N]
#         E[N:TN] = mu * e[n * N:(n + 1) * N]
#         normFFTX = bet * normFFTX + (1 - bet) * np.real(np.multiply(FFTX[:, 0], FFTX[:, 0].conjugate()))
#         # c = a/np.linalg.inv(b)
#         aaaa = np.fft.fft(E) / (M * normFFTX + np.spacing(1))
#         print(aaaa[:, None].shape)
#         FFTEinvnormFFTX = np.multiply(aaaa[:, None], OMt)
#         print(FFTEinvnormFFTX.shape)
#         G = np.real(np.fft.ifft(np.multiply(FFTEinvnormFFTX, FFTX.conjugate())))
#         G[N: TN, :] = ZNM
#         FFTW = lam * FFTW + np.fft.fft(G)
#         # nFFTW = np.real(np.fft.ifft(FFTW))
#         # wm = nFFTW[0:N,:]
#         # w = wm[:]
#         # # mis[n] = np.power(np.linalg.norm(w - w_cut), 2) / np.power(np.linalg.norm(w_cut), 2)
#         # if np.mod(n, 16*2)==0:
#         #     WFbEn = np.sum(np.real(np.dot(FFTW, FFTW.conjugate())))
#         #     tmp = np.max(WFbEn)
#         #     dIdx=np.argmax(WFbEn)
#         # dIdxV[n] = dIdx
#         # if NLPon:
#         #     D[0: N] = D[N : TN]
#         #     D[N : TN] = SinS[n * N :(n+1) * N]
#         #     xf = np.fft.fft(np.dot(X, wins))
#         #     df = np.fft.fft(np.dot(D,wins))
#         #     ef = np.fft.fft(np.dot(E,wins))
#         #     xfwm[:, 1: ] = xfwm[:, 0: end - 1]
#         #     xfwm[:, 0] = xf
#         #     xf = xfwm[:, dIdx]
#         #
#         #     Se = gamma * Se + (1 - gamma) * np.real(np.dot(ef, ef.conjugate()))
#         #     Sd = gamma * Sd + (1 - gamma) * np.real(np.dot(df, df.conjugate()))
#         #     Sx = gamma * Sx + (1 - gamma) * np.real(np.dot(xf, xf.conjugate()))
#         #     Sxd = gamma * Sxd + (1 - gamma) * np.dot(xf, df.conjugate())
#         #     Sed = gamma * Sed + (1 - gamma) * np.dot(ef, df.conjugate())
#         #     cohed = np.real(np.dot(Sed, Sed.conjugate())) / (np.dot(Se, Sd) + 1e-10)
#         #     cohxd = np.real(np.dot(Sxd, Sxd.conjugate())) / (np.dot(Sx, Sd) + 1e-10)
#         #     hnled = np.min(1 - cohxd, cohed)
#         #     cohedMean = np.mean(cohed(echoBandRange))
#         #     hnlSort = np.sort(1 - cohxd(echoBandRange))
#         #     hnlSortQ = np.mean(1 - cohxd(echoBandRange))
#         #     hnlSort2 = np.sort(hnled(echoBandRange))
#         #     hnlQuant = 0.75
#         #     hnlQuantLow = 0.5
#         #     qIdx = np.floor(hnlQuant * len(hnlSort2))
#         #     qIdxLow = np.floor(hnlQuantLow * len(hnlSort2))
#         #     hnlPrefAvg = hnlSort2[qIdx]
#         #     hnlPrefAvgLow = hnlSort2[qIdxLow]
#         #     if cohedMean > 0.98 and hnlSortQ > 0.9:
#         #         suppState = 0
#         #     elif cohedMean < 0.95 or hnlSortQ < 0.8:
#         #         suppState = 1
#         #     if hnlSortQ < np.min(cohxdLocalMin, 0.75):
#         #         cohxdLocalMin = hnlSortQ
#         #     if cohxdLocalMin == 1:
#         #         ovrd = 3
#         #         hnled = 1 - cohxd
#         #         hnlPrefAvg = hnlSortQ
#         #         hnlPrefAvgLow = hnlSortQ
#         #     if suppState == 0:
#         #         hnled = cohed
#         #         hnlPrefAvg = cohedMean
#         #         hnlPrefAvgLow = cohedMean
#         #     if hnlPrefAvgLow < np.min(hnlLocalMin, 0.6):
#         #         hnlLocalMin = hnlPrefAvgLow
#         #         hnlMin = hnlPrefAvgLow
#         #         hnlNewMin = 1
#         #         hnlMinCtr = 0
#         #     if hnlNewMin == 1:
#         #         hnlMinCtr = hnlMinCtr + 1
#         #     if hnlMinCtr == 2:
#         #         hnlNewMin = 0
#         #         hnlMinCtr = 0
#         #         ovrd = np.max(np.log(0.00001) / (np.log(hnlMin + 1e-10) + 1e-10), 3)
#         #         hnlLocalMin = np.min(hnlLocalMin + 0.0008 / mult, 1)
#         #         cohxdLocalMin = np.min(cohxdLocalMin + 0.0004 / mult, 1)
#         #     if ovrd < ovrdSm:
#         #         ovrdSm = 0.99 * ovrdSm + 0.01 * ovrd
#         #     else:
#         #         ovrdSm = 0.9 * ovrdSm + 0.1 * ovrd
#         #     ekEn = np.sum(Se)
#         #     dkEn = np.sum(Sd)
#         #     if divergeState == 0:
#         #         if ekEn > dkEn:
#         #             ef = df
#         #             divergeState = 1
#         #     else:
#         #         if ekEn * 1.05 < dkEn:
#         #             divergeState = 0
#         #         else:
#         #             ef = df
#         #     if ekEn > dkEn * 19.95:
#         #         WFb = np.zeros(TN, M)
#         #     ekEnV[n] = ekEn
#         #     dkEnV[n] = dkEn
#         #     hnlLocalMinV[n] = hnlLocalMin
#         #     cohxdLocalMinV[n] = cohxdLocalMin
#         #     hnlMinV[n] = hnlMin
#         #     ovrdV[n] = ovrdSm
#         #     hnledAvg[n] = 1 - np.mean(1 - cohed[echoBandRange])
#         #     hnlxdAvg[n] = 1 - np.mean(cohxd[echoBandRange])
#         #     hnlSortQV[n] = hnlPrefAvgLow
#         #     hnlPrefAvgV[n] = hnlPrefAvg
#         #     aggrFact = 0.3
#         #     weight = np.array(aggrFact*np.sqrt(np.linspace(0,1,TN)).T+0.1)
#         #     hnled = np.dot(weight, min(hnlPrefAvg, hnled)) + np.dot((1 - weight), hnled)
#         #     od = ovrdSm * (np.sqrt(np.linspace(0, 1, TN)).T + 1)
#         #     sshift = np.ones(TN)
#         #     hnled = np.power(hnled, (od * sshift))
#         #     hnl = hnled
#         #     ef = ef * hnl
#         #     if CNon:
#         #         snn = np.sqrt(Sym)
#         #         snn[1] = 0
#         #         # Un = snn * np.exp(j * 2 * pi. * [0;rand(TN - 1, 1)])
#     return e
