import pygame
import random
import sys

sys.setrecursionlimit(900000000)  #设置递归深度，其中100000是你需要设置的新的递归次数。

pygame.init()

m,n = 50,50
m,n = m*2+1,n*2+1
L,W = 1000,1000
sz = 4*L//5//n
s_y,s_x = (L-m*sz)//2,(W-n*sz)//2
window = pygame.display.set_mode((L,W))
window.fill((255,255,255))
pygame.display.update()
pygame.display.set_caption("迷宫生成")

maze = [[1 for i in range(m)] for j in range(n)]
for i in range(m):
    for j in range(n):
        if i%2 and j%2:
            maze[i][j] = 0
        else:
            pygame.draw.rect(window,(0,0,0),(s_y+i*sz,s_x+j*sz,sz,sz),0)
pygame.display.update()


dy = [2,0,-2,0]
dx = [0,2,0,-2]
vis = [[0 for i in range(m)] for j in range(n)]
chose = []
def dfs(y,x):
    chose = []
    vis[1][1] = 1
    ny,nx = y,x
    for i in range(4):
        ny,nx= y+dy[i],x+dx[i]
        if ny>=0 and ny<m and nx>=0 and nx<n and vis[ny][nx]== 0:
            chose.append((ny,nx))
    if len(chose) == 0:
        return
    ny,nx = chose[random.randint(0,len(chose)-1)]

    num =0
    while num<=1000:
        num+=1
    if x == nx and y < ny:  # 下
        maze[y+1][x] = 0
        pygame.draw.rect(window, (255, 255, 255),
                         (s_x + x * sz, s_y + (y+1) * sz, sz, sz), 0)
        pygame.display.flip()
    if y == ny and x < nx: # 右
        maze[y][x+1] = 0
        pygame.draw.rect(window, (255, 255, 255),
                         (s_x + (x + 1) * sz, s_y + y * sz, sz, sz), 0)
        pygame.display.flip()
    if x == nx and y > ny: # 上
        maze[y-1][x] = 0
        pygame.draw.rect(window, (255, 255, 255),
                         (s_x + x * sz, s_y + (y-1) * sz, sz, sz), 0)
        pygame.display.flip()
    if y == ny and x > nx: # 左
        maze[y][x-1] = 0
        pygame.draw.rect(window, (255, 255, 255),
                         (s_x + (x - 1) * sz, s_y + y * sz, sz, sz), 0)
        pygame.display.flip()

    vis[ny][nx] = 1

    dfs(ny,nx)

    chose = []
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if ny >= 0 and ny < m and nx >= 0 and nx < n and vis[ny][nx] == 0:
            chose.append((ny, nx))
    if len(chose)>=1:
        dfs(y,x)



dfs(1,1)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()





