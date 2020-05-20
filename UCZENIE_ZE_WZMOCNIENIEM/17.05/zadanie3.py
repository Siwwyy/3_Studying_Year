#!/usr/bin/env python
# coding: utf-8

# In[5]:


import numpy as np
from frozen_lake import FrozenLakeEnv

environment = FrozenLakeEnv()
epochs = 1000
if_break = True


def Func(alpha,gamma):
    V = np.zeros(16)
    
    for epoch in range(epochs):
        state = 0   # stan poczatkowy kazdego epizodu
        if_break = True
        while if_break:
            random_action = np.random.randint(4)
            tupl = environment.P[state][random_action]
            next_state = tupl[0][1]
            
            if next_state == 15:
                R = 1
            else:
                R = 0
                
            V[state] = (V[state] + alpha * (R + gamma*V[next_state] - V[state]))
            state = next_state
            
            #stan terminalny oznacza koniec epizodu
            if state == 5 or state == 7 or state == 11 or state == 12 or state == 15:
                if_break = False
    return V



# In[11]:


print(Func(0.1,1.0))
print(Func(0.3,0.9))
print(Func(0.5,0.5))

