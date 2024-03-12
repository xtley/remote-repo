import pygame

class square:
    def __init__(self,x,y,len,window):
        self.x   = x
        self.y   = y
        self.len = len
        self.window = window
        self.paint()
    def paint(self):
        x   = self.x
        y   = self.y
        len = self.len
        window =self.window
        pygame.draw.rect(window,(0,0,0),(x,y,len,len),1)
        #pygame.display.flip()
