import numpy as np

from speechlib import *
(fs,data) = wavfile.read('C4_1_y.wav')

data = data - np.mean(data)
data = data / np.max(data)
IS =0.25
wlen=200
inc=80
N=len(data)
time = [i/fs for i in range(N)]
wnd = np.hamming(wlen)
NIS=int((IS*fs-wlen)//inc+1)
thr1 =1.1
thr2 =1.3
voiceseg,val,SF,NF,Rum = vad_corr(data,wnd,inc,NIS,thr1,thr2)
fn = len(SF)
frameTime = FrameTimeC(fn,wlen,inc,fs)

plt.subplot(2,1,1)
plt.plot(time,data)
plt.title('纯语音波形')
plt.ylabel('幅值')

plt.subplot(2,1,2)
plt.plot(frameTime,Rum)
plt.title('短时自相关函数')
plt.xlabel('时间/s')
plt.ylabel('幅值')

for i in range(val):
    nx1=voiceseg[i]['start']
    nx2=voiceseg[i]['end']
    plt.subplot(2,1,1)
    plt.axvline(frameTime[nx1],np.min(data),np.max(data),color='blue',linestyle='--')
    plt.axvline(frameTime[nx2],np.min(data),np.max(data),color='red', linestyle='-')
    plt.legend(['波形','起点','终点'])

    plt.subplot(2, 1, 2)
    plt.axvline(frameTime[nx1], np.min(Rum), np.max(Rum), color='blue', linestyle='--')
    plt.axvline(frameTime[nx2], np.min(Rum), np.max(Rum), color='red', linestyle='-')
    plt.legend(['短时自相关', '起点', '终点'])

plt.show()