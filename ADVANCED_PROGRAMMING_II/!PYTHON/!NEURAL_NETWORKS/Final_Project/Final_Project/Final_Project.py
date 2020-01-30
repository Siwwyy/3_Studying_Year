
import pygame, sys
import random
from Cube import Cube
from Obstacle import Obstacle

class Game(object):

    def __init__(self):
        #configuration down here
        self.fps_max = 60.0
        self.fps_delta = 0.0

        #initialization
        pygame.init() #initialize whole pygame's modules as creators set up, add always, right behavior
        self.screen = pygame.display.set_mode((1000,1000))
        self.fps_clock = pygame.time.Clock() #clock object, remember ! pygame.init() first !

        self.player = Cube(self,self.screen.get_size()[0]/2 - 100,self.screen.get_size()[1]-100)
        self.obstacles = [Obstacle(self,0,0),Obstacle(self,200,0),Obstacle(self,300,200),Obstacle(self,600,100),Obstacle(self,800,300)]
        #self.obstacle1 = Cube(self,0,200)
        #self.obstacle2 = Cube(self,0,300)
        #self.obstacle3 = Cube(self,0,300)
        #self.obstacle4 = Cube(self,100,700)
        while True:
            #if self.obstacle.Get_Position().y > self.screen.get_size()[1]:
            #    self.obstacle = Cube(self,0,0)
            #    #self.obstacle1 = Cube(self,200,0)
            #    #self.obstacle2 = Cube(self,300,0)
            #    #self.obstacle3 = Cube(self,0,300)
            #    #self.obstacle4 = Cube(self,100,700)
            #handle events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit(0)
                elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                    sys.exit(0)
                self.player.move(event)


            #Ticking (clock ticking) ! for instance, make something 20 times per second
            self.fps_delta += self.fps_clock.tick()/11000.0 #time between two frames
            while self.fps_delta > 1/self.fps_max: #delay
                #self.player.move(event)
                for obstacle_pos in self.obstacles:
                    obstacle_pos.move_by_coordinates(0,100)
                #self.obstacle.move_by_coordinates(0,-100)
                #self.tick() #everything drawing,moving etc. x times pers second
                self.fps_delta -= 1/self.fps_max
  

            #Rendering
            self.screen.fill((0,0,0)) #erase screen
            self.draw()
            self.drawGrid()
            pygame.display.flip()

            #game logic
            for index,obstacle_pos in enumerate(self.obstacles,start=0):
                if self.player.Get_Position() == obstacle_pos.Get_Position():
                    sys.exit(0)
                if obstacle_pos.Get_Position().y > self.screen.get_size()[1]:
                    #self.obstacles[index] = Obstacle(self,random.randrange(0, 1000, 100),0)
                    self.obstacles[index] = Obstacle(self,obstacle_pos.Get_Basic_Position().x,0) 
                    
         
    def tick(self):
        #self.player.tick()
        #pressed_keys = pygame.key.get_pressed()
        #if pressed_keys[pygame.K_RIGHT]:
        #    rectangle.x += 2
        #if pressed_keys[pygame.K_LEFT]:
        #    rectangle.x -= 2
        pass

    def draw(self):
        #drawing
        self.player.draw()
        for obstacles_draw in self.obstacles:
            obstacles_draw.draw()

    def drawGrid(self):
        size = self.screen.get_size()[0]//10
        x = 0
        y = 0
        for l in range(self.screen.get_size()[0]):
            x = x + size
            y = y + size
            pygame.draw.line(self.screen, (255,255,255), (x,0),(x,self.screen.get_size()[0]))
            pygame.draw.line(self.screen, (255,255,255), (0,y),(self.screen.get_size()[0],y))

    def draw_obstacle(self):
        pass
        

   
if __name__ == "__main__":  #if program is not imported
    Game()