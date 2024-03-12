import wave
import contextlib
import numpy as np

def wav2pcm(wav_name,wav2pcm_name):
    '''
    读取 test.wav 文件，写为 pcm 格式
    '''
    with contextlib.closing(wave.open(wav_name, 'r')) as f:
        wav_params = f.getparams()
    # wav_params：_wave_params(nchannels=, sampwidth=, framerate=, nframes=,comptype =, compname =)
        print(f"读取 wav 文件：{wav_name}")
        print(f"声道数:{wav_params[0]}")
        print(f"量化位数:{wav_params[1] * 8}")
    # 量化位数 1,2,3 分别代表 8 位，16 位，24 位
        print(f"采样率:{wav_params[2]}")
        print(f"采样总数:{wav_params[3]}")
        print(f"音频时长:{wav_params[3] / wav_params[2]}")
        print(f"压缩格式:{wav_params[4]}")
    # 读取采样值，存为 bytes
        wav_bytes = f.readframes(wav_params[3])
    # 转为 array
        wave_data = np.frombuffer(wav_bytes, dtype=np.int16)
        wave_data.tofile(wav2pcm_name)
    print('done')

def pcm2wav(pcm_name,pcm2wav_name):
    '''
    读取 test.pcm 文件,写为 wav 文件
    '''
    f = open(pcm_name, 'rb')
    pcm_bytes = f.read()
    with contextlib.closing(wave.open(pcm2wav_name, 'wb')) as f:
        # 加入 wav 信息头，保存为 wav 格式
        f.setframerate(16000)  # 16KHZ（采样频率）
        f.setsampwidth(2)  # 量化位数分为 8 位，16 位，24 位三种
        f.setnchannels(1)  # 单声道振幅数据为 n*1 矩阵点，立体声为 n*2 矩阵点
        f.writeframes(pcm_bytes)
    print('done')

if __name__=='__main__':
    wav2pcm('test.wav','test.pcm')
    print('wav2pcm done')
    pcm2wav('test.pcm', 'test.wav')
    print('pcm2wav done')