import scipy.io as scio
import time
import wave
from AECAlgor import *
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif']=['SimHei']
plt.rcParams['axes.unicode_minus']=False

f1 = wave.open("../data/单远端_speech_yb.wav","rb")
params1 = f1.getparams()
nchannels1,sampwidth1,framerate1,nframes1 =params1[:4]
str_data1 = f1.readframes(nframes1)
f1.close()
wave_data1 = np.frombuffer(str_data1,dtype =np.int16)
wave_data1 = wave_data1*1.0/(max(abs(wave_data1)))
wave_data1 = np.reshape(wave_data1,[nframes1,nchannels1])
path = '../data/h_yb.mat'
data = scio.loadmat(path)
h_yb = data['h_yb'][0]
h_yb=h_yb*0.7
Mh = 256

w_cut = h_yb[0:Mh].T

RinS =wave_data1[:,0]
tdata = np.convolve(RinS,w_cut)
SinS=tdata[0:len(RinS)]
lengraph = np.floor(len(RinS)/Mh)

plt.figure(1)
plt.subplot(311)
plt.plot(SinS)
plt.ylabel('幅度')
plt.title('(a)近端输入信号')
plt.subplot(312)
plt.plot(RinS)
plt.ylabel('幅度')
plt.title('(b)远端参考信号')

alpha =0.1
lambda1= 0.1

start_time = time.time()
enh4,wnh4,misnh4,ERLE4 = FLMS(RinS,SinS,w_cut,alpha,lambda1)
end_time = time.time()
print('FLMS_Took: %f second'%(end_time - start_time))

misnh4 = 10*np.log10(misnh4+np.spacing(1))

plt.subplot(313)
plt.plot(enh4)
plt.ylabel('幅度')
plt.title('(c)FLMS算法处理后信号')

plt.figure(2)
interval0=Mh


plt.plot(misnh4,'r')
plt.title('FLMS算法的失调系数')
plt.xlabel('Blocks/2048')
plt.ylabel('失调系数/dB')
plt.xlim([10,lengraph-5])

plt.figure(3)
plt.plot(ERLE4,'r')
plt.title('FLMS算法的ERLE')
plt.xlabel('Block/2048')
plt.ylabel('ERLE/db')
plt.xlim([10,lengraph-5])

plt.show()
