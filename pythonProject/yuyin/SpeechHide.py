import numpy as np

def hide_message(x, meg, nBits=1):
    if nBits != 1:
        exit('Only nBits=1 support now......')
    xx = np.zeros(len(x))
    xx[:] = x[:]
    l = len(meg)
    pads = np.mod(l, nBits)
    if pads:
        l += nBits - pads
        meg_l = np.zeros(l)
        meg_l[:l] = meg
        meg = meg_l
    m_len = l // nBits
    meg_n = meg.reshape(m_len, nBits)
    for i in range(nBits):
        for j in range(m_len):
            if meg_n[j, i]:
                xx[j] = x[j] // 2 * 2
            else:
                xx[j] = x[j] // 2 * 2 + 1
    return xx, m_len


def extract_message(x, m_len, nBits=1):
    if nBits != 1:
        exit('Only nBits=1 support now......')
    meg = np.zeros((m_len, nBits))
    for i in range(nBits):
        for j in range(m_len):
            meg[j, i] = x[j] % 2
    return meg


def rceps(x):
    y=np.abs(np.fft.fft(x))
    z = np.fft.ifft(np.log(y))
    H = np.real(z)
    return H



def hide_EchoExtract(x_embeded,N,m0,m1,len):
    message = np.zeros(len)
    for i in range(len):
        x = x_embeded[(i*N):((i+1)*N)-1]
        xwhat = rceps(x)                  # matlab的帮助文档中利用公式real(ifft(log(abs(fft(y)))))计算
        if xwhat[m0+1] > xwhat[m1+1]:
            message[i] = 0
        else:
            message[i] = 1
    return message


def hide_EchoEmbed(x,message,N,m0,m1,a):
    x_embed = x
    nf = int(np.min([len(message),len(x)/N]))
    for i in range(nf):   # 遍历每一段
        if message[i]:     # 对每一个脉冲点
            for j in range(800):
                if i*N+j-1>m1:
                    x_embed[i*N+j-1] = x[i*N+j-1] + x[i*N+j-1-m1]*a
        else:
            for j in range(800):
                if i*N+j-1>m0:
                    x_embed[i*N+j-1] = x[i*N+j-1] + x[i*N+j-1-m0]*a

    return x_embed

