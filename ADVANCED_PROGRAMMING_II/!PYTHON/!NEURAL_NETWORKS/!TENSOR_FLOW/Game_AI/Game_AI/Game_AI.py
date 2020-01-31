
##Snake Tutorial Python
 
#import math
#import random
#import pygame
#import tkinter as tk
#from tkinter import messagebox
 
#class cube(object):
#    rows = 20
#    w = 500
#    def __init__(self,start,dirnx=1,dirny=0,color=(255,0,0)):
#        self.pos = start
#        self.dirnx = 1
#        self.dirny = 0
#        self.color = color
 
       
#    def move(self, dirnx, dirny):
#        self.dirnx = dirnx
#        self.dirny = dirny
#        self.pos = (self.pos[0] + self.dirnx, self.pos[1] + self.dirny)
 
#    def draw(self, surface, eyes=False):
#        dis = self.w // self.rows
#        i = self.pos[0]
#        j = self.pos[1]
 
#        pygame.draw.rect(surface, self.color, (i*dis+1,j*dis+1, dis-2, dis-2))
#        if eyes:
#            centre = dis//2
#            radius = 3
#            circleMiddle = (i*dis+centre-radius,j*dis+8)
#            circleMiddle2 = (i*dis + dis -radius*2, j*dis+8)
#            pygame.draw.circle(surface, (0,0,0), circleMiddle, radius)
#            pygame.draw.circle(surface, (0,0,0), circleMiddle2, radius)
       
 
 
 
#class snake(object):
#    body = []
#    turns = {}
#    def __init__(self, color, pos):
#        self.color = color
#        self.head = cube(pos)
#        self.body.append(self.head)
#        self.dirnx = 0
#        self.dirny = 1
 
#    def move(self):
#        for event in pygame.event.get():
#            if event.type == pygame.QUIT:
#                pygame.quit()
 
#            keys = pygame.key.get_pressed()
 
#            for key in keys:
#                if keys[pygame.K_LEFT]:
#                    self.dirnx = -1
#                    self.dirny = 0
#                    self.turns[self.head.pos[:]] = [self.dirnx, self.dirny]
 
#                elif keys[pygame.K_RIGHT]:
#                    self.dirnx = 1
#                    self.dirny = 0
#                    self.turns[self.head.pos[:]] = [self.dirnx, self.dirny]
 
#                elif keys[pygame.K_UP]:
#                    self.dirnx = 0
#                    self.dirny = -1
#                    self.turns[self.head.pos[:]] = [self.dirnx, self.dirny]
 
#                elif keys[pygame.K_DOWN]:
#                    self.dirnx = 0
#                    self.dirny = 1
#                    self.turns[self.head.pos[:]] = [self.dirnx, self.dirny]
 
#        for i, c in enumerate(self.body):
#            p = c.pos[:]
#            if p in self.turns:
#                turn = self.turns[p]
#                c.move(turn[0],turn[1])
#                if i == len(self.body)-1:
#                    self.turns.pop(p)
#            else:
#                if c.dirnx == -1 and c.pos[0] <= 0: c.pos = (c.rows-1, c.pos[1])
#                elif c.dirnx == 1 and c.pos[0] >= c.rows-1: c.pos = (0,c.pos[1])
#                elif c.dirny == 1 and c.pos[1] >= c.rows-1: c.pos = (c.pos[0], 0)
#                elif c.dirny == -1 and c.pos[1] <= 0: c.pos = (c.pos[0],c.rows-1)
#                else: c.move(c.dirnx,c.dirny)
       
 
#    def reset(self, pos):
#        self.head = cube(pos)
#        self.body = []
#        self.body.append(self.head)
#        self.turns = {}
#        self.dirnx = 0
#        self.dirny = 1
 
 
#    def addCube(self):
#        tail = self.body[-1]
#        dx, dy = tail.dirnx, tail.dirny
 
#        if dx == 1 and dy == 0:
#            self.body.append(cube((tail.pos[0]-1,tail.pos[1])))
#        elif dx == -1 and dy == 0:
#            self.body.append(cube((tail.pos[0]+1,tail.pos[1])))
#        elif dx == 0 and dy == 1:
#            self.body.append(cube((tail.pos[0],tail.pos[1]-1)))
#        elif dx == 0 and dy == -1:
#            self.body.append(cube((tail.pos[0],tail.pos[1]+1)))
 
#        self.body[-1].dirnx = dx
#        self.body[-1].dirny = dy
       
 
#    def draw(self, surface):
#        for i, c in enumerate(self.body):
#            if i ==0:
#                c.draw(surface, True)
#            else:
#                c.draw(surface)
 
 
#def drawGrid(w, rows, surface):
#    sizeBtwn = w // rows
 
#    x = 0
#    y = 0
#    for l in range(rows):
#        x = x + sizeBtwn
#        y = y + sizeBtwn
 
#        pygame.draw.line(surface, (255,255,255), (x,0),(x,w))
#        pygame.draw.line(surface, (255,255,255), (0,y),(w,y))
       
 
#def redrawWindow(surface):
#    global rows, width, s, snack
#    surface.fill((0,0,0))
#    s.draw(surface)
#    snack.draw(surface)
#    drawGrid(width,rows, surface)
#    pygame.display.update()
 
 
#def randomSnack(rows, item):
 
#    positions = item.body
 
#    while True:
#        x = random.randrange(rows)
#        y = random.randrange(rows)
#        if len(list(filter(lambda z:z.pos == (x,y), positions))) > 0:
#            continue
#        else:
#            break
       
#    return (x,y)
 
 
#def message_box(subject, content):
#    root = tk.Tk()
#    root.attributes("-topmost", True)
#    root.withdraw()
#    messagebox.showinfo(subject, content)
#    try:
#        root.destroy()
#    except:
#        pass
 
 
#def main():
#    global width, rows, s, snack
#    width = 500
#    rows = 20
#    win = pygame.display.set_mode((width, width))
#    s = snake((255,0,0), (10,10))
#    snack = cube(randomSnack(rows, s), color=(0,255,0))
#    flag = True
 
#    clock = pygame.time.Clock()
   
#    while flag:
#        pygame.time.delay(50)
#        clock.tick(10)
#        s.move()
#        if s.body[0].pos == snack.pos:
#            s.addCube()
#            snack = cube(randomSnack(rows, s), color=(0,255,0))
 
#        for x in range(len(s.body)):
#            if s.body[x].pos in list(map(lambda z:z.pos,s.body[x+1:])):
#                #print('\'Score: \', len(s.body))
#                #message_box('\'You Lost!\', \'Play again...\')
#                s.reset((10,10))
#                break
 
           
#        redrawWindow(win)
 
       
#    pass
 
 
 
#main()


#main()  #invoke main function
import random
import gym
import numpy as np
from collections import deque
from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import Adam

EPISODES = 1000

class DQNAgent:
    def __init__(self, state_size, action_size):
        self.state_size = state_size
        self.action_size = action_size
        self.memory = deque(maxlen=2000)
        self.gamma = 0.95    # discount rate
        self.epsilon = 1.0  # exploration rate
        self.epsilon_min = 0.01
        self.epsilon_decay = 0.995
        self.learning_rate = 0.001
        self.model = self._build_model()

    def _build_model(self):
        # Neural Net for Deep-Q learning Model
        model = Sequential()
        model.add(Dense(24, input_dim=self.state_size, activation='relu'))
        model.add(Dense(24, activation='relu'))
        model.add(Dense(self.action_size, activation='linear'))
        model.compile(loss='mse',
                      optimizer=Adam(lr=self.learning_rate))
        return model

    def remember(self, state, action, reward, next_state, done):
        self.memory.append((state, action, reward, next_state, done))

    def act(self, state):
        if np.random.rand() <= self.epsilon:
            return random.randrange(self.action_size)
        act_values = self.model.predict(state)
        return np.argmax(act_values[0])  # returns action

    def replay(self, batch_size):
        minibatch = random.sample(self.memory, batch_size)
        for state, action, reward, next_state, done in minibatch:
            target = reward
            if not done:
                target = (reward + self.gamma *
                          np.amax(self.model.predict(next_state)[0]))
            target_f = self.model.predict(state)
            target_f[0][action] = target
            self.model.fit(state, target_f, epochs=1, verbose=0)
        if self.epsilon > self.epsilon_min:
            self.epsilon *= self.epsilon_decay

    def load(self, name):
        self.model.load_weights(name)

    def save(self, name):
        self.model.save_weights(name)


if __name__ == "__main__":
    env = gym.make('MountainCar-v0')
    state_size = env.observation_space.shape[0]
    action_size = env.action_space.n
    agent = DQNAgent(state_size, action_size)
    # agent.load("./save/cartpole-dqn.h5")
    done = False
    batch_size = 32

    for e in range(EPISODES):
        state = env.reset()
        state = np.reshape(state, [1, state_size])        
        for time in range(500):
            # env.render()
            action = agent.act(state)
            env.render()
            next_state, reward, done, _ = env.step(action)
            reward = reward if not done else -10
            next_state = np.reshape(next_state, [1, state_size])
            agent.remember(state, action, reward, next_state, done)
            state = next_state
            if done:
                print("episode: {}/{}, score: {}, e: {:.2}"
                      .format(e, EPISODES, time, agent.epsilon))
                break
            if len(agent.memory) > batch_size:
                agent.replay(batch_size)
        # if e % 10 == 0:
        #     agent.save("./save/cartpole-dqn.h5")
