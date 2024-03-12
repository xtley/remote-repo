import matplotlib.pyplot as plt

from SpeechEnh import *
(fs,data)=wavfile.read('C6_1_y.wav')

data = data - np.mean(data)
data = data/np.max(np.abs(data))
IS = 0.25
wlen = 200
inc = 80
SNR = 5
N = len(data)
time = [i/fs for i in range(N)]
signal = awgn(data,SNR)
NIS = int((IS*fs-wlen)//inc+1)
snr1= SNR_Calc(data,signal)
a,b = 4,0.001
output = SpectralSub(signal, wlen, inc,NIS,a, b)
# output =output- np .mean(output)
# output = output/np .max(np.abs(output))
snr2 = SNR_Calc(data, output)
time1 = [i / fs for i in range(len(output))]
print('加入噪声SNR:{:.4f}\t基本谱减滤波后噪声SNR:{:.4f}\tSNR提升:{:.4f}'.format(snr1, snr2, snr2 - snr1))
plt.figure()
plt.subplot(3,1,1)
plt.plot(time,data)
plt.ylabel("幅值")
plt.title("纯语音波形")
plt.subplot(3,1,2)
plt.plot(time,signal)
plt.title('带噪语音波形')
plt.ylabel("幅值")
plt.subplot(3,1,3)
plt.title('谱减后波形')
plt.plot(time1, output)
plt.ylabel("幅值")
plt.xlabel("时间")
plt.show()