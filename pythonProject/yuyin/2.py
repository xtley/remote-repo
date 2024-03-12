from speechlib import *
(framerate, wave_data) = wavfile.read("C3_3_y.wav")

wlen = 256
nfft =wlen
inc =128

plt.specgram(wave_data,nfft,framerate,noverlap=inc,cmap='jet')

plt.xlabel("时间/s")
plt.ylabel("频率/HZ")
plt.title("(语谱图")
plt.show()