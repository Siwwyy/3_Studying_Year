
import pygame, sys

pygame.init() #initialize whole pygame's modules as creators set up
#screen = pygame.display.set_mode((1920,1080))
screen = pygame.display.set_mode((1280,720))
rectangle = pygame.Rect(615,650,50,50)

while True:
    #handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit(0)
        elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            sys.exit(0)

    #keyboard event (input) and if is continously pressed, change rectangle coord
    #if pygame.key.get_pressed()[pygame.K_RIGHT]:
    #    rectangle.x += 1
    pressed_keys = pygame.key.get_pressed()
    if pressed_keys[pygame.K_RIGHT]:
        rectangle.x += 1
    if pressed_keys[pygame.K_LEFT]:
        rectangle.x -= 1
    

    #drawing
    screen.fill((0,0,0)) #erase screen
    pygame.draw.rect(screen, (0,150,255), rectangle)
    pygame.draw.rect(screen, (255,150,255), pygame.Rect(30,30,50,50))
    pygame.display.flip()
