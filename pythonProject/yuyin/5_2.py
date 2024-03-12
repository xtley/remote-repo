import matplotlib.pyplot as plt

from SpeechEnh import *
(fs,data) = wavfile.read('C6_1_y.wav')
data = data - np.mean(data)
data = data/np.max(np.abs(data))
SNR = 10
signal = awgn(data,SNR)
N = len(data)
time = [i/fs for i in range(N)]
IS = 0.15
wlen = 200
inc = 80
Gamma =1
Beta =0.03
NIS = int((IS*fs-wlen)//inc+1)
output = SpectralSubIm(signal,wlen,inc,NIS,Gamma,Beta)
output = output/np.max(np.abs(output))
time1 = [i/fs for i in range(len(output))]

plt.figure()
plt.subplot(3,1,1)
plt.plot(time,data)
plt.title('原始信号')
plt.ylabel('幅值')
plt.xlabel('时间/s')
plt.subplot(3,1,2)
plt.plot(time,signal)
plt.title('加噪语音信号')
plt.ylabel('幅值')
plt.xlabel('时间/s')
plt.subplot(3,1,3)
plt.plot(time1,output)
plt.title('滤波信号')
plt.ylabel('幅值')
plt.xlabel('时间/s')
plt.show()