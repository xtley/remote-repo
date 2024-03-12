import urllib.request
import re
import time
from pydub import AudioSegment
with open('word_test.txt') as file:
    list_url = [line.rstrip() for line in file]
spd = '3' #default is 3 数字越小越慢
lan = 'uk' #uk or en uk英音 en美音
_ = AudioSegment.silent(duration=100)
_.export("audio_1.mp3", format="mp3")
audio_1 = AudioSegment.from_file("audio_1.mp3")
second_of_silence = AudioSegment.silent(duration=400)
second_of_silence.export("second_of_silence.mp3", format="mp3")
cnt = -1
for i in list_url:
    text = re.sub("\s+", "%20", i.strip())
    print(text)
    task = int(ord(text[0]) - ord('a'))
    if cnt+1 == task:
        cnt += 1
        AudioSegment.silent(duration=100)
        _.export(cnt + ".mp3", format="mp3")
        audio_1 = AudioSegment.from_file(cnt+".mp3")
    audio_2 = AudioSegment.from_file("E:/Documents/English/Baidu_Translation_Audio_Capture/"+text+".mp3")
    for _ in range(3):
        audio_1 = audio_1 + second_of_silence
        audio_1 = audio_1 + audio_2
        audio_1.export(cnt + ".mp3", format="mp3")


