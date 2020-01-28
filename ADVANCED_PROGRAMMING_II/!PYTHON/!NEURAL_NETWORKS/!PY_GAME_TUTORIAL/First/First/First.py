
import pygame, sys

screen = pygame.display.set_mode((1280,720))

while True:
    #handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit(0)
    #drawing
    pygame.draw.rect(screen, (0,150,255), pygame.Rect(10,50,200,100))
    pygame.display.flip()
    #notice that, in pygame we have 2 times buffering, u have two piece of paper, draw on first display second , flip, display first draw on second and so on