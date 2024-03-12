from speechlib import *
import numpy as np
import scipy.io.wavfile as wavfile

# 读取波形数据
(framerate, wave_data) = wavfile.read("C3_2_y.wav")
wave_data = wave_data / 32768
time = np.array([i / framerate for i in range(wave_data.size)])
N = len(wave_data)

wlen = 200
inc = 100
win = np.hanning(wlen)

En = STEn(wave_data, win, inc)
Mn = STMn(wave_data, win, inc)
Zcr = STZcr(wave_data, win, inc)

X = enframe(wave_data, win, inc)
X = X.T

Ac = STAc(X)
Ac = Ac.T

# 短时能量
# 短时平均幅度
# 短时过零率
# 短时自相关

A = Ac.flatten()
X = X.T

Amdf = STAmdf(X)
fn = len(En)

plt.figure(1)

plt.subplot(311)
plt.plot(time, wave_data, 'b')
plt.axis("tight")
plt.title("(a)语音波形")
plt.ylabel("幅值")
plt.xlabel("时间/s")

Amdf = STAmdf(X) # 短时平均幅度差
fn = len(En)
plt.figure(1)
plt.subplot(311)
plt.plot(time, wave_data, 'b')
plt.axis("tight")
plt.title(u"(a)语音波形")
plt.ylabel(u"幅值")
plt.xlabel(u"时间/s")


frameTime = FrameTimeC(fn, wlen, inc, framerate)
plt.subplot(312)
plt.plot(frameTime, Mn, 'b')
plt.title(u"(b)短时幅度")
plt.ylabel(u"幅值")
plt.xlabel(u"时间/s")

plt.subplot(313)
plt.plot(frameTime, En, 'b')
plt.title(u"(c)短时能量")
plt.ylabel(u"幅值")
plt.xlabel(u"时间/s")

plt.figure(2)
plt.subplot(211)
plt.plot(time, wave_data, 'b')
plt.title(u"(a)语音波形")
plt.ylabel(u"幅值")
plt.xlabel(u"时间/s")

plt.subplot(212)
plt.plot(frameTime, Zcr, 'b')
plt.title(u"(d)短时过零率")
plt.ylabel(u"幅值")
plt.xlabel(u"时间/s")

plt.figure(3)
plt.subplot(211)
plt.plot(time, wave_data, 'b')
plt.title(u"(a)语音波形")
plt.ylabel(u"幅值")
plt.xlabel(u"时间/s")

plt.subplot(212)
plt.plot(Ac, 'b')
plt.title(u"(e)短时自相关")
plt.ylabel(u"幅值")
plt.xlabel(u"点数")

plt.figure(4)
plt.subplot(211)
plt.plot(time, wave_data, 'b')
plt.title(u"(a)语音波形")
plt.ylabel(u"幅值")
plt.xlabel(u"时间/s")

plt.subplot(212)
plt.plot(Amdf, 'b')
plt.title("(f)短时幅度差")
plt.ylabel("幅值")
plt.xlabel("时间/s")

plt.show()
