import pygame
import random
import numpy
import algorithm
import sys  # 导入sys模块

sys.setrecursionlimit(30000)  # 将默认的递归深度修改为30000


class produce:
    def __init__(self, m, n, sx, sy, fx, fy, window, L, s_x, s_y):
        self.m = 2 * m + 1
        self.n = 2 * n + 1
        self.g = numpy.random.randint(0, 1, (self.m, self.n))
        # self.g = [[0]*self.n for i in range(self.m)]
        self.sx = 1 + 2 * sx
        self.sy = 1 + 2 * sy
        self.fx = 1 + 2 * fx
        self.fy = 1 + 2 * fy
        self.window = window
        self.L = L
        self.s_x = s_x
        self.s_y = s_y

        self.dy = [0, 1, 0, -1]
        self.dx = [1, 0, -1, 0]
        self.vis = [[0 for i in range(2 * m + 1)] for j in range(2 * n + 1)]
        for i in range(self.m):
            for j in range(self.n):
                if i % 2 and j % 2:
                    self.g[i][j] = 0
                else:
                    self.g[i][j] = 1
        self.chose = []
        self.a, self.b = 0, 0

    def violence(self):
        self.g = numpy.random.randint(0, 2, (self.m, self.n))
        ag = algorithm.get_path(self.g, self.m, self.n, self.sx, self.sy, self.fx, self.fy, self.window, self.L,
                                self.s_x, self.s_y)
        while ag.check() != 1:
            self.g = numpy.random.randint(0, 2, (self.m, self.n))

    def prim(self):
        self.point()
        pygame.display.update()
        vis = []
        r, c = 1, 1
        walls = []
        vis.append((1, 1))
        for i in range(4):
            rr, cc = r + self.dy[i], c + self.dx[i]
            if rr > 0 and rr < self.m - 1 and cc > 0 and cc < self.n - 1:
                walls.append((rr, cc))
        while walls:
            wall = walls[random.randint(0, len(walls) - 1)]
            chose_yes = []
            chose_no = []
            r, c = wall
            rr, cc = r, c
            for i in range(4):
                rr, cc = r + self.dy[i], c + self.dx[i]
                if rr > 0 and rr < self.n - 1 and cc > 0 and cc < self.m - 1:
                    if self.g[rr][cc] == 0 and (rr, cc) in vis:
                        chose_yes.append((rr, cc))
                    elif self.g[rr][cc] == 0:
                        chose_no.append((rr, cc))
            if len(chose_yes) == 1:
                walls.remove(wall)
                self.g[r][c] = 2
                pygame.draw.rect(self.window, (255, 255, 255),
                                 (self.s_y + c * self.L, self.s_x + r * self.L, self.L, self.L), 0)
                pygame.display.flip()
                vis.append(chose_no[0])
                r, c = chose_no[0]
                for i in range(4):
                    rr, cc = r + self.dy[i], c + self.dx[i]
                    if rr > 0 and rr < self.n - 1 and cc > 0 and cc < self.m - 1:
                        walls.append((rr, cc))

            if len(chose_yes) == 2:
                walls.remove(wall)

    def dfs(self, x, y):
        self.dx = [0, -2, 0, 2]
        self.dy = [2, 0, -2, 0]
        self.chose = []
        self.vis[x][y] = 1
        for i in range(4):
            self.a, self.b = x + self.dx[i], y + self.dy[i]
            if self.a >= 0 and self.a < self.m and self.b >= 0 and self.b < self.n and self.vis[self.a][self.b] == 0:
                self.chose.append((self.a, self.b))
        # print(x, y,len(self.chose))
        if len(self.chose) == 0:
            return
        num = 0
        while num <= 100:
            num += 1
        xx, yy = self.chose[random.randint(0, len(self.chose) - 1)]
        if xx == x and yy < y:
            self.g[x][y - 1] = 0
            # self.vis[xx][yy] = 1
            pygame.draw.rect(self.window, (255, 255, 255),
                             (self.s_y + (y - 1) * self.L, self.s_x + x * self.L, self.L, self.L), 0)
            pygame.display.flip()
        if xx == x and yy > y:
            self.g[x][y + 1] = 0
            # self.vis[xx][yy] = 1
            pygame.draw.rect(self.window, (255, 255, 255),
                             (self.s_y + (y + 1) * self.L, self.s_x + x * self.L, self.L, self.L), 0)
            pygame.display.flip()
        if xx < x and yy == y:
            self.g[x - 1][y] = 0
            # self.vis[xx][yy] = 1
            pygame.draw.rect(self.window, (255, 255, 255),
                             (self.s_y + y * self.L, self.s_x + (x - 1) * self.L, self.L, self.L), 0)
            pygame.display.flip()
        if xx > x and yy == y:
            self.g[x + 1][y] = 0
            # self.vis[xx][yy] = 1
            pygame.draw.rect(self.window, (255, 255, 255),
                             (self.s_y + y * self.L, self.s_x + (x + 1) * self.L, self.L, self.L), 0)
            pygame.display.flip()

        self.dfs(xx, yy)

        self.chose = []
        for i in range(4):
            self.a, self.b = x + self.dx[i], y + self.dy[i]
            if self.a >= 0 and self.a < self.m and self.b >= 0 and self.b < self.n and self.vis[self.a][self.b] == 0:
                self.chose.append((self.a, self.b))
        if len(self.chose) >= 1:
            self.dfs(x, y)

    def point(self):
        for i in range(self.m):
            for j in range(self.n):
                if self.g[i][j] == 0 or self.g[i][j] == 2:
                    pygame.draw.rect(self.window, (255, 255, 255),
                                     (self.s_y + j * self.L, self.s_x + i * self.L, self.L, self.L), 0)
                    # pygame.display.flip()
                    self.g[i][j] = 0
                else:
                    # print(i, j)
                    pygame.draw.rect(self.window, (0, 0, 0),
                                     (self.s_y + j * self.L, self.s_x + i * self.L, self.L, self.L), 0)
                    # pygame.display.flip()
                    self.g[i][j] = 1
