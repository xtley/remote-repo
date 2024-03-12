import wavfile as wavfile

from SpeechEnh import *
fs, data = wavfile.read("C6_2_y.wav")
data = data - np.mean(data)
data = data / np.max(np.abs(data))
IS = 0.25
wlen = 200
inc = 80
SNR = 5
N = len(data)
time = [i / fs for i in range(N)]
r1 = awgn(data, SNR)
NIS = int((IS * fs - wlen) // inc + 1)

a, b = 4, 0.001
output = weina_Norm(r1, wlen, inc, NIS,a,b)
output = output / np.max(np.abs(output))

plt.figure()
plt.subplot(3, 1, 1)
plt.plot(time, data)
plt.title("纯语音波形")
plt.ylabel('幅值')
plt.subplot(3, 1, 2)
plt.plot(time, r1)
plt.title('带噪语音信号')
plt.ylabel('幅值')
plt.subplot(3, 1, 3)
plt.title('基本维纳滤波后波形')
plt.plot(time, output)
plt.ylabel('幅值')
plt.xlabel('时间')

plt.show()
