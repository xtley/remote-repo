from speechlib import *
from scipy.signal import lfilter

(fs,data)=wavfile.read('C4_3_y.wav')
u = lfilter([1,-0.99],[1], data)
cepstL = 6
wlen = len(u)
wlen2 = wlen //2
u2 = np.multiply(u, np.hamming(wlen))
p = 12
freq = [i * fs / 512 for i in range(256)]
df = fs/512
n_frmnt = 4
F,Bw, U = Formant_Root(u2,p,fs,n_frmnt)
t = np.divide(F,df)
m = np.floor(t)
U = U[0:256]
plt.plot(freq,U)
plt.xlabel('频率/Hz')
plt.ylabel('幅值/dB')
plt.title('LPC求根法的共振峰估计')

for i in range(len(F)):
    plt.plot([F[i],F[i]], [np.min(u), U[int(m[i])]],'-.k')
    plt.text(F[i], U[i], 'Freq={:.0f}Hz\n'.format(F[i]))
    plt.legend(['功率谱’,共振峰位置'])
plt.show()