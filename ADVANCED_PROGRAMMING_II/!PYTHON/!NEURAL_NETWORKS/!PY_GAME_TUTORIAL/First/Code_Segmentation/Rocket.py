import pygame, sys
from pygame.math import Vector2

class Rocket(object):

    def __init__(self,game):
        self.game = game
        self.position = Vector2(615,650)    #basic draw coordinates
        self.velocity = Vector2(0,0)
        self.acceleration = Vector2(0,0)

        #self.size = self.game.screen.get_size() #will return width and height of screen, returns tuple


    def add_force(self,force):
        self.acceleration += force

    def tick(self):
        #Input
        pressed_keys = pygame.key.get_pressed()
        if pressed_keys[pygame.K_RIGHT]:
            self.add_force(Vector2(2,0))
        if pressed_keys[pygame.K_LEFT]:
            self.add_force(Vector2(-2,0))

        #physics
        self.velocity *= 0.8    #air resistance
        #self.velocity -= Vector2(0,-0.1)    #custom gravity, currently disabled
        self.velocity += self.acceleration
        self.position += self.velocity
        self.acceleration *= 0  #set acceleration vector2 to 0 each coordinate

    def draw(self):
        rectangle = pygame.Rect(self.position.x,self.position.y,50,50)
        pygame.draw.rect(self.game.screen, (0,150,255), rectangle)

