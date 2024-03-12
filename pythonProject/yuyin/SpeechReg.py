from speechlib import STMn,STZcr
import numpy as np

def my_vad(x):
    """
    端点检测
    :param X:输入为录入语音
    :return:输出为有用信号
    """
    Ini = 0.1  # 初始静默时间
    Ts = 0.01  # 窗的时长
    Tsh = 0.005  # 帧移时长
    Fs = 16000  # 采样频率
    counter1 = 0  # 以下四个参数用来寻找起始点和结束点
    counter2 = 0
    counter3 = 0
    counter4 = 0
    ZCRCountf = 0  # 用于存储过零率检测结果
    ZCRCountb = 0
    ZTh = 40  # 过零阈值
    w_sam = int(Ts * Fs)  # 窗口长度
    o_sam = int(Tsh * Fs)  # 帧移长度
    lengthX = len(x)
    segs = int((lengthX - w_sam) / o_sam) + 1
    sil = int((Ini - Ts) / Tsh) + 1
    win = np.hamming(w_sam)
    Limit = o_sam * (segs - 1) + 1
    FrmtIndex = [i for i in range(0, Limit, o_sam)]  # 每一帧的起始位置
    # 短时过零率
    ZCR_Vector = STZcr(x, w_sam, o_sam)
    # 能量
    Erg_Vector = STMn(x, w_sam, o_sam)
    IMN = np.mean(Erg_Vector[:sil])
    IMX = np.max(Erg_Vector)
    l1 = 0.03 * (IMX - IMN) + IMN
    l2 = 4 * IMN
    ITL = 100 * np.min((l1, l2))
    ITU = 10 * ITL
    IZC = np.mean(ZCR_Vector[:sil])
    stddev = np.std(ZCR_Vector[:sil])
    IZCT = np.min((ZTh, IZC + 2 * stddev))
    indexi = np.zeros(lengthX)
    indexj, indexk, indexl = indexi, indexi, indexi
    # 搜寻超过能量阈值上限的部分
    for i in range(len(Erg_Vector)):
        if Erg_Vector[i] > ITU:
            indexi[counter1] = i
            counter1 += 1
    ITUs = int(indexi[0])
    # 搜寻能量超过能量下限的部分
    for j in range(ITUs - 1, -1, -1):
        if Erg_Vector[j] < ITL:
            indexj[counter2] = j
            counter2 += 1
    start = int(indexj[0]) + 1
    Erg_Vectorf = np.flip(Erg_Vector, axis=0)
    # 重复上面过程相当于找结束帧
    for k in range(len(Erg_Vectorf)):
        if Erg_Vectorf[k] > ITU:
            indexi[counter3] = k
            counter3 += 1
    ITUs = int(indexk[0])
    for l in range(ITUs - 1, -1, -1):
        if Erg_Vectorf[l] < ITL:
            indexl[counter4] = l
            counter4 += 1
    finish = len(Erg_Vector) - int(indexl[0])  # 第一级判决结束帧
    # 从第一级判决起始帧开始进行第二判决（过零率）端点检测
    BackSearch = np.min((start, 25))
    for m in range(start, start - BackSearch, -1):
        rate = ZCR_Vector[m]
        if rate > IZCT:
            ZCRCountb += 1
            realstart = m
    if ZCRCountb > 3:
        start = realstart

    FwdSearch = np.min((len(Erg_Vector) - finish, 25))
    for n in range(finish, finish + FwdSearch):
        rate = ZCR_Vector[n]
        if rate > IZCT:
            ZCRCountf += 1
            realfinish = n
    if ZCRCountf > 3:
        finish = realfinish
    x_start = FrmtIndex[start]
    x_finish = FrmtIndex[finish-1]
    trimmed_X = x[x_start:x_finish]
    return trimmed_X


def DTWCompute(F, R):
    """
    动态时间规划
    :param F:为模板MFCC参数矩阵
    :param R:为当前语音MFCC参数矩阵
    :return:cost为最佳匹配距离
    """
    r1, c1 = F.shape
    r2, c2 = R.shape
    distence = np.zeros((r1, r2))
    for n in range(r1):
        for m in range(r2):
            FR = np.power(F[n, :] - R[m, :], 2)
            distence[n, m] = np.sqrt(np.sum(FR)) / c1

    D = np.zeros((r1 + 1, r2 + 1))
    D[0, :] = np.inf
    D[:, 0] = np.inf
    D[0, 0] = 0
    D[1:, 1:] = distence

    # 寻找整个过程的最短匹配距离
    for i in range(r1):
        for j in range(r2):
            dmin = min(D[i, j], D[i, j + 1], D[i + 1, j])
            D[i + 1, j + 1] += dmin

    cost = D[r1, r2]
    return cost

def DTWScores(r, features, N):
    """
    DTW寻找最小失真值
    :param r:为当前读入语音的MFCC参数矩阵
    :param features:模型参数
    :param N:为每个模板数量词汇数
    :return:
    """
    # 初始化判别矩阵
    scores1 = np.zeros(N)
    scores2 = np.zeros(N)
    scores3 = np.zeros(N)

    for i in range(N):
        scores1[i] = DTWCompute(features['p1_{}'.format(i)], r)
        scores2[i] = DTWCompute(features['p2_{}'.format(i)], r)
        scores3[i] = DTWCompute(features['p3_{}'.format(i)], r)
    return scores1, scores2, scores3

