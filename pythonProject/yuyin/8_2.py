from speechlib import *
from scipy.signal import lfilter
import numpy as np
(fs, data) = wavfile.read('C4_3_y.wav')
u = lfilter([1,-0.99],[1], data)
cepstL = 6
wlen = len(u)
wlen2 = wlen // 2
u2 = np.multiply(u, np.hamming(wlen))
p = 12
freg = [i * fs /512 for i in range(256)]
F,Bw,pp,U,loc = Formant_Interpolation(u2,p,fs)
plt.plot(freg,U)
plt.xlabel('频率/Hz')
plt.ylabel('幅值/dB')
plt.title('LPC内插法的共振峰估计只')
plt.ylim(np.min(U),np.max(U)+5)
for i in range(len(Bw)):
    plt.plot([freg[loc[i]], freg[loc[i]]], [np.min(u),U[loc[i]]], '-.k')
    plt.text(freg[loc[i]], U[loc[i]],'Freq={:.0f}Hz\n'.format(F[i]))
    plt.legend(['功率谱’,共振峰位置'])
plt.show()