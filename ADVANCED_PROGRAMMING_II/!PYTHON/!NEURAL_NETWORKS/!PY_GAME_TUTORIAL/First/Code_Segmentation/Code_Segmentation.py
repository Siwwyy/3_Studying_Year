
import pygame, sys
from Rocket import Rocket

class Game(object):

    def __init__(self):
        #configuration down here
        self.fps_max = 60.0
        self.fps_delta = 0.0

        #initialization
        pygame.init() #initialize whole pygame's modules as creators set up, add always, right behavior
        self.screen = pygame.display.set_mode((1280,720))
        self.fps_clock = pygame.time.Clock() #clock object, remember ! pygame.init() first !

        self.player = Rocket(self)

        while True:
            #handle events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit(0)
                elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                    sys.exit(0)

            #Ticking (clock ticking) ! for instance, make something 20 times per second
            self.fps_delta += self.fps_clock.tick()/1000.0 #time between two frames
            while self.fps_delta > 1/self.fps_max: #delay
                self.tick() #everything drawing,moving etc. x times pers second
                self.fps_delta -= 1/self.fps_max

            #Rendering
            self.screen.fill((0,0,0)) #erase screen
            self.draw()
            self.drawGrid(self.screen.get_size()[0],self.screen.get_size()[1],self.screen)
            pygame.display.flip()

    def tick(self):
        self.player.tick()
        #pressed_keys = pygame.key.get_pressed()
        #if pressed_keys[pygame.K_RIGHT]:
        #    rectangle.x += 2
        #if pressed_keys[pygame.K_LEFT]:
        #    rectangle.x -= 2
        pass

    def draw(self):
        #drawing
        self.player.draw()
  
    def drawGrid(w, rows, surface):
        sizeBtwn = w // rows
 
        x = 0
        y = 0
        for l in range(rows):
            x = x + sizeBtwn
            y = y + sizeBtwn
            pygame.draw.line(surface, (255,255,255), (x,0),(x,w))
            pygame.draw.line(surface, (255,255,255), (0,y),(w,y))
        
if __name__ == "__main__":  #if program is not imported
    Game()