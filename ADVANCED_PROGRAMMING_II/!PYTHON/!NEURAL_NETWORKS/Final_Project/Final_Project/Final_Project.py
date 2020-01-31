
import pygame, sys
import random
import numpy as np
from Cube import Cube
from Obstacle import Obstacle
from Neural_Network import Neural_Network
from Perceptron import Perceptron

class Game(object):

    def __init__(self):
        #configuration down here
        self.fps_max = 60.0
        self.fps_delta = 0.0
        #self.Neural = Neural_Network()

        #initialization
        pygame.init() #initialize whole pygame's modules as creators set up, add always, right behavior
        pygame.display.set_caption("Siwy's Game")
        self.screen = pygame.display.set_mode((1000,1000))
        self.fps_clock = pygame.time.Clock() #clock object, remember ! pygame.init() first !
        self.player = Cube(self,self.screen.get_size()[0]/2 - 300,self.screen.get_size()[1]-100)
        self.obstacles = [Obstacle(self,0,0),Obstacle(self,200,0),Obstacle(self,300,200),Obstacle(self,600,100),Obstacle(self,800,300)]
        #1,0,1,1,0,0,1,0,1,0
        self.player_pos = self.player.Get_Position()
        print(np.array([[1,0,1,1,0,0,1,0,1,0]]).T)
        self.temp_array3 = np.array([[1,0,1,1,0,0,1,0,1,0]]).T
        self.Neural = Perceptron(self.temp_array3)
        self.outputs = self.Neural.Get_Output()
        self.temp_array = np.array([[0,0,0,0,0,0,0,0,0,0]]).T
        self.temp_array2 = np.array([[0,0,0,0,0,0,0,0,0,0]]).T
        self.temp_int = 0
        #np.resize(self.temp_array, (1,10))
        while True:
            self.player_pos = self.player.Get_Position()
            #handle events
            #for event in pygame.event.get():
            #    if event.type == pygame.QUIT:
            #        sys.exit(0)
            #    elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            #        sys.exit(0)
            #    self.player.move(event)


            #Ticking (clock ticking) ! for instance, make something 20 times per second
            self.fps_delta += self.fps_clock.tick()/11000.0 #time between two frames
            while self.fps_delta > 1/self.fps_max: #delay
                for obstacle_pos in self.obstacles:
                    obstacle_pos.move_by_coordinates(0,100)
                for index,out_pos in enumerate(self.outputs,start=0):
                    value = int(round(out_pos[0],0))
                    pos = 0
                    cos = int(self.player_pos.x/100)
                    if value == 1 and index == cos:
                        for index1,out_pos1 in enumerate(self.outputs,start=0):
                            value = int(round(out_pos1[0],0))
                            if value == 0:
                                index1 *= 100
                                val = self.player_pos.x - index1
                                if val < 0:
                                    val = 1
                                else:
                                    val = -1
                                pos += 100*val
                                break
                        #if self.player_pos.x + 100 < self.screen.get_size()[0]:
                        #    pos += 100
                        #elif self.player_pos.x - 100 >= 0:
                        #    pos += -100
                        self.player.move_by_coordinates(pos)
                        break
                    #else:
                    #    self.player.move_by_coordinates(pos)
                self.fps_delta -= 1/self.fps_max
  

            #Rendering
            self.screen.fill((0,0,0)) #erase screen
            self.draw()
            self.drawGrid()
            pygame.display.flip()

            #game logic
            for index,obstacle_pos in enumerate(self.obstacles,start=0):
                #self.temp_array[0][index] = 0;
                if self.player.Get_Position() == obstacle_pos.Get_Position():
                    sys.exit(0)
                if obstacle_pos.Get_Position().y > self.screen.get_size()[1]:
                    pos = int(random.randrange(0, 1000, 100))
                    self.obstacles[index] = Obstacle(self,pos,0)
                    #self.obstacles[index] = Obstacle(self,obstacle_pos.Get_Basic_Position().x,0) 
                    my_index = int(pos/100)
                    self.temp_array[my_index] = 1;
                    self.temp_int += 1
            if self.temp_int > 4:
                print("---------------------------------")
                print(self.temp_array)
                #self.Neural.Update_training_outputs(self.temp_array)
                self.Neural = Perceptron(self.temp_array)
                self.temp_int = 0
                for index,i in enumerate(self.temp_array,start=0):
                    self.temp_array[index] = 0
                #self.temp_array = self.temp_array2
                self.outputs = self.Neural.Get_Output()
                print(self.outputs)
                print("---------------------------------")
                #wait = input("PRESS ENTER TO CONTINUE.")
                    
         
    def tick(self):
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
        

def main(): 

    #episodes = 10
    #for e in range(episodes):
    Game()





if __name__ == "__main__":  #if program is not imported
    main()