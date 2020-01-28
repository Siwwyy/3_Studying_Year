
import pygame, sys

pygame.init() #initialize whole pygame's modules as creators set up, add always, right behavior
#screen = pygame.display.set_mode((1920,1080))
screen = pygame.display.set_mode((1280,720))
rectangle = pygame.Rect(615,650,50,50)

clock = pygame.time.Clock() #clock object, remember ! pygame.init() first !
current_delta = 0.0 #float
max_fps = 60.0

while True:
    #handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit(0)
        elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            sys.exit(0)

    #Ticking (clock ticking) ! for instance, make something 20 times per second
    current_delta += clock.tick()/1000.0 #time between two frames
    #current_delta /= 1000.0 #convert to seconds
    while current_delta > 1/max_fps:
        print("Hey")
        current_delta -= 1/max_fps
    
    #keyboard event (input) and if is continously pressed, change rectangle coord
    #if pygame.key.get_pressed()[pygame.K_RIGHT]:
    #    rectangle.x += 1
    pressed_keys = pygame.key.get_pressed()
    if pressed_keys[pygame.K_RIGHT]:
        rectangle.x += 2
    if pressed_keys[pygame.K_LEFT]:
        rectangle.x -= 2
    

    #drawing
    screen.fill((0,0,0)) #erase screen
    pygame.draw.rect(screen, (0,150,255), rectangle)
    pygame.display.flip()

