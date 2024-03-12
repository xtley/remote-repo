import librosa.display
import librosa
import matplotlib.pyplot as plt
y,sr = librosa.load('./wav_data/1.wav',sr=None)
plt.figure()
librosa.display.waveplot(y,sr=sr)
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('waveform')
plt.savefig('./wave.png')
plt.show()

y,sr = librosa.load('./wav_data/1.wav',sr=None)
plt.figure()
plt.specgram(y,Fs=16000,scale_by_freq=True,sides = 'default',cmap='jet')
plt.xlabel('Time')
plt.ylabel('Frequency/Hz')
plt.title('Spectrogram')
plt.savefig('./spectrogram.png')
plt.show()


