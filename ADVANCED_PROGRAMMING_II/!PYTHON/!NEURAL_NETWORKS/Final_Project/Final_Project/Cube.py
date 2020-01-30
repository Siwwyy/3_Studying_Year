import pygame, sys
from pygame.math import Vector2

class Cube(object):

    def __init__(self,game,pos_x, pos_y):
        self.game = game
        #self.position = Vector2(self.game.screen.get_size()[0]/2 - 100,self.game.screen.get_size()[1]-100)    #basic draw coordinates
        self.position = Vector2(pos_x,pos_y)    #basic draw coordinates
        self.velocity = Vector2(0,0)
        #self.acceleration = Vector2(0,0)

        #self.size = self.game.screen.get_size() #will return width and height of screen, returns tuple


    def add_force(self,force):
        #self.acceleration += force
        pass

    #def tick(self, event_type):
    def move(self, event_type):
        #Inputif 
        if event_type.type == pygame.KEYDOWN and event_type.key == pygame.K_RIGHT:
            if self.position.x + 100 < self.game.screen.get_size()[0]:
                self.position.x += 100
        if event_type.type == pygame.KEYDOWN and event_type.key == pygame.K_LEFT:
            if self.position.x - 100 >= 0:
                self.position.x += -100
        #pressed_keys = pygame.key.get_pressed()
        #if pressed_keys[pygame.K_RIGHT]:
        #    #self.add_force(Vector2(4,0))
        #    self.position.x += 20
        #if pressed_keys[pygame.K_LEFT]:
        #    #self.add_force(Vector2(-4,0))
        #    self.position.x += -20
        #if pressed_keys[pygame.K_UP]:
        #    self.add_force(Vector2(0,-2))
        #if pressed_keys[pygame.K_DOWN]:
        #    self.add_force(Vector2(0,2))

        #physics
        #self.velocity *= 0.8    #air resistance
        #self.velocity -= Vector2(0,-0.1)    #custom gravity, currently disabled
        #self.velocity += self.acceleration
        #self.position += self.velocity
        #self.acceleration *= 0  #set acceleration vector2 to 0 each coordinate

    def draw(self):
        #base triangle
        #points = [Vector2(0,-10),Vector2(5,5), Vector2(-5,5)]
        #rotate points
        #angle = self.velocity.angle_to(Vector2(0,1))
        #points = [p.rotate(angle) for p in points]
        #fix y axis
        #points = [Vector2(p.x,p.y*-1) for p in points]
        #add current position
        #points = [self.position+p*3 for p in points]

        #draw triangle via linears
        #pygame.draw.polygon(self.game.screen, (0,150,255),points)
        rectangle = pygame.Rect(self.position.x,self.position.y,100,100)
        pygame.draw.rect(self.game.screen, (0,150,255), rectangle)


    def Get_Position(self):
        return Vector2(self.position)


