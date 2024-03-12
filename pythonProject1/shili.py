import pygame

pygame.init()       # 初始化pygame模块
window = pygame.display.set_mode((1000,1000))  # 设置窗口大小
window.fill((255,255,255))   # 为窗口填充颜色 白色RGB(255,255,255)
pygame.display.update()      # 刷新窗口
pygame.display.set_caption("迷宫生成")  # 设置窗口标题

# windown 所在窗口 (0,0,0) 黑色的RGB设置填充颜色 (100,100,50,50)
# 矩形左上角坐标为(100,100) 长和宽为(50,50) 0 设置矩形线宽为0 充满黑色
pygame.draw.rect(window,(0,0,0),(100,100,50,50),0)
pygame.display.update()


while True:     # 利用死循环 持续运行窗口
    for event in pygame.event.get():    # 捕获用户操作
        if event.type == pygame.QUIT:   # 当按下右上角的退出时 结束程序运行
            exit()





