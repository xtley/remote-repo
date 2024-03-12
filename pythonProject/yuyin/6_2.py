import wavfile

from SpeechEnh import *

(fs, data) = wavfile.read("C6_2_y.wav")
data = data - np.mean(data)
data = data / np.max(np.abs(data))
IS = 0.25
wlen = 200
inc = 80
SNR = 5
NIS = int((IS * fs - wlen) // inc + 1)
alpha = 0.95
N = len(data)
time = [i / fs for i in range(N)]
signal = awgn(data, SNR)
output = weina_Im(signal, wlen, inc, NIS, alpha)
output = output / np.max(np.abs(output))

plt.subplot(3, 1, 1)
plt.plot(time, data)
plt.title('原始信号')
plt.ylabel('幅值')
plt.subplot(3, 1, 2)
plt.plot(time, signal)
plt.title('加噪声信号')
plt.ylabel('幅值')
plt.subplot(3, 1, 3)
plt.plot(time, output)
plt.title('改进维纳滤波后信号')
plt.ylabel('幅值')
plt.xlabel('时间')
plt.show()
