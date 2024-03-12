import urllib.request
import pydub
import re
import time
from pydub import AudioSegment
with open('word_test.txt') as file:
    list_url = [line.rstrip() for line in file]
spd = '3'  # default is 3 数字越小越慢
lan = 'uk'  # uk or en uk英音 en美音
_ = AudioSegment.silent(duration=100)
_.export("audio_1.mp3", format="mp3")
audio_1 = AudioSegment.from_file("audio_1.mp3")
second_of_silence = AudioSegment.silent(duration=400)
second_of_silence.export("second_of_silence.mp3", format="mp3")
cnt = -1
ok = 0
audio_1 = AudioSegment.silent(duration=100)
audio_1.export("List1.mp3", format="mp3")
for i in list_url:
    print(i)
    for _ in range(3):
        audio_2 = AudioSegment.from_file(i + ".mp3")
        audio_1 = audio_1 + second_of_silence
        audio_1 = audio_1 + audio_2
        audio_1.export("List1.mp3", format="mp3")
