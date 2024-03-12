import pygame
import maze
import numpy
import random
pygame.init()

MAX_W,MAX_H = 1050,1000
window = pygame.display.set_mode((MAX_W,MAX_H))
pygame.display.set_caption("迷宫游戏")
window.fill((255,255,255))
pygame.display.flip()

n,m = 30,30
len = 30
g = numpy.random.randint(1, 2, (n, m))
print(g)
x,y = 75,75
x1,y1 = x,y
for i in range(n):
    for j in range(m):
        print(x1, y1)
        square = maze.square(x1, y1, len, window)
        x1 += len
    x1 = x
    y1 += len

pygame.draw.line(window, (0, 0, 0), (x, y), (x, y + m * len), 2)
pygame.draw.line(window, (0, 0, 0), (x + n * len, y + m * len), (x + n * len, y), 1)
pygame.draw.line(window,(0,0,0),(x,y),(x+n*len,y),2)
pygame.draw.line(window,(0,0,0),(x+n*len,y+m*len),(x,y+m*len),1)
pygame.display.update()

A = []
A.append((0,0))

while A != []:
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    t = random.randint(len(A))
    x,y = A[t]





while True:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
