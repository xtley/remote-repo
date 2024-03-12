from speechlib import *
from scipy.signal import lfilter
import numpy as np
(fs, data) = wavfile.read('C4_3_y.wav')
data=data/32768
u = lfilter([1,-0.99],[1], data)
cepstL = 6
wlen = len(u)
wlen2 = wlen // 2
u2 = np.multiply(u, np.hamming(wlen))
U_abs = np.log(np.abs(np.fft.fft(u2))[:wlen2])
freq = [i * fs /wlen for i in range(wlen2)]
val, loc, spec= Formant_Cepst(u2, cepstL)
plt.subplot(2,1,1)
plt.plot(freq, U_abs,'k')
plt.xlabel('频率/Hz')
plt.ylabel('幅值/dB')
plt.title('(a)信号对数谱')
plt.subplot(2,1,2)
plt.plot(freq, spec,'k')
plt.xlabel('频率/HZ')
plt.ylabel('幅值/dB')
plt.title('(b)包络线和共振峰值')
plt.ylim(np.min(spec),1)
for i in range(len(loc)):
    plt.subplot(2,1,2)
    plt.plot([freq[loc[i]],freq[loc[i]]],[np.min(spec),spec[loc[i]]],'-r.')
    plt.text(freq[loc[i]], spec[loc[i]],'Freq={}Hz'.format(int(freq[loc[i]])))

plt.show()

