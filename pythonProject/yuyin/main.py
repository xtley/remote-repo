# -*- coding: utf-8 -*
import pyaudio
import wave
import time
from speechlib import *
import numpy as np
from scipy.io import wavfile
import matplotlib.pyplot as plt
# 定义数据流参数信息
CHUNK = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 16000
RECORD_SECONDS = 5
nframes = int(RATE / CHUNK * RECORD_SECONDS)  # 计算出所需采集帧的数量
WAVE_OUTPUT_FILENAME = "C2_1_y_1.wav"

# 实例化一个 Pyaudio对象
p = pyaudio.PyAudio()

# 使用该对象打开声卡，并用上述参数信息对数据流进行赋值
stream = p.open(format=FORMAT,
                channels=CHANNELS,
                rate=RATE,
                input=True,
                frames_per_buffer=CHUNK)

# 开始录音
print("* recording")
frames = []
for i in range(0, nframes):
    data = stream.read(CHUNK)
    frames.append(data)
print("* done recording")

# 关闭数据流，声卡；终止 Pyaudio
stream.stop_stream()
stream.close()
p.terminate()

# 设定存储录音的 WAV文件的基本信息
wf = wave.open(WAVE_OUTPUT_FILENAME, 'wb')
wf.setnchannels(CHANNELS)
wf.setsampwidth(p.get_sample_size(FORMAT))
wf.setframerate(RATE)
wf.writeframes(b''.join(frames))
wf.close()

# 只读模式打开需要播放的文件
wf = wave.open(WAVE_OUTPUT_FILENAME, 'rb')

# 实例化一个 pyaudio对象
p = pyaudio.PyAudio()

# 定义回调函数
def callback(in_data, frame_count, time_info, status):
    data = wf.readframes(frame_count)
    return (data, pyaudio.paContinue)

# 以回调函数的形式打开声卡，创建数据流
stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
                channels=wf.getnchannels(),
                rate=wf.getframerate(),
                output=True,
                stream_callback=callback)

# 打开数据流
stream.start_stream()

# 等待数据流停止
while stream.is_active():
    time.sleep(0.1)

# 停止数据流，关闭声卡、音频文件；终止 Pyaudio
stream.stop_stream()
stream.close()
wf.close()
p.terminate()

(fs, sound) = wavfile.read(WAVE_OUTPUT_FILENAME)
t = np.array([i / fs for i in range(sound.size)])
plt.plot(t, sound)
plt.title('录制信号')
plt.xlabel('时间/s')
plt.ylabel('幅度')
plt.show()
