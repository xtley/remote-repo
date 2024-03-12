import random
import numpy as np
from matplotlib import pyplot as plt
import matplotlib.cm as cm

num_rows = 30  # number of rows
num_cols = 30  # number of columns

# 数组M将保存每个单元格的数组信息。
# 前四个坐标表示这些边是否有墙
# 第五个表示在搜索中是否访问过单元格。
# m(左，上，右，下，check_if_visited)
M = np.zeros((num_rows, num_cols, 5), dtype=np.uint8)
print(M)
# #数组图像将是要显示的输出图像
image = np.zeros((num_rows * 10, num_cols * 10), dtype=np.uint8)

# 设置起始行和列
r = 0
c = 0
history = [(r, c)]  # 历史记录是访问过的地点的堆栈
# 沿着迷宫的细胞和开放的墙壁追踪一条路径。
# 我们使用while循环，重复循环直到没有历史记录，
# 这意味着我们回到了最初的起点。

while history:
    # random choose a candidata cell from the cell set histroy
    r, c = random.choice(history)
    M[r, c, 4] = 1  # 指定此地点为访问过的地点
    history.remove((r, c))
    check = []
    # 如果随机选择的单元格有多条边
    # 把它和现有的迷宫连接起来，
    if c > 0:
        if M[r, c - 1, 4] == 1:
            check.append('L')
        elif M[r, c - 1, 4] == 0:
            history.append((r, c - 1))
            M[r, c - 1, 4] = 2
    if r > 0:
        if M[r - 1, c, 4] == 1:
            check.append('U')
        elif M[r - 1, c, 4] == 0:
            history.append((r - 1, c))
            M[r - 1, c, 4] = 2
    if c < num_cols - 1:
        if M[r, c + 1, 4] == 1:
            check.append('R')
        elif M[r, c + 1, 4] == 0:
            history.append((r, c + 1))
            M[r, c + 1, 4] = 2
    if r < num_rows - 1:
        if M[r + 1, c, 4] == 1:
            check.append('D')
        elif M[r + 1, c, 4] == 0:
            history.append((r + 1, c))
            M[r + 1, c, 4] = 2

    # 随机选择其中一条边。
    if len(check):
        move_direction = random.choice(check)
        if move_direction == 'L':
            M[r, c, 0] = 1
            c = c - 1
            M[r, c, 2] = 1
        if move_direction == 'U':
            M[r, c, 1] = 1
            r = r - 1
            M[r, c, 3] = 1
        if move_direction == 'R':
            M[r, c, 2] = 1
            c = c + 1
            M[r, c, 0] = 1
        if move_direction == 'D':
            M[r, c, 3] = 1
            r = r + 1
            M[r, c, 1] = 1








# 在开始和结束的时候打开墙
M[0, 0, 0] = 1
M[num_rows - 1, num_cols - 1, 2] = 1

# 生成用于显示的图像
for row in range(0, num_rows):
    for col in range(0, num_cols):
        cell_data = M[row, col]
        for i in range(10 * row + 2, 10 * row + 8):
            image[i, range(10 * col + 2, 10 * col + 8)] = 255
        if cell_data[0] == 1:
            image[range(10 * row + 2, 10 * row + 8), 10 * col] = 255
            image[range(10 * row + 2, 10 * row + 8), 10 * col + 1] = 255
        if cell_data[1] == 1:
            image[10 * row, range(10 * col + 2, 10 * col + 8)] = 255
            image[10 * row + 1, range(10 * col + 2, 10 * col + 8)] = 255
        if cell_data[2] == 1:
            image[range(10 * row + 2, 10 * row + 8), 10 * col + 9] = 255
            image[range(10 * row + 2, 10 * row + 8), 10 * col + 8] = 255
        if cell_data[3] == 1:
            image[10 * row + 9, range(10 * col + 2, 10 * col + 8)] = 255
            image[10 * row + 8, range(10 * col + 2, 10 * col + 8)] = 255

# Display the image
plt.imshow(image, cmap=cm.Greys_r, interpolation='none')
plt.show()