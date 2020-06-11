from cartpole import CartPoleEnv
import math

env = CartPoleEnv()
env.reset()

# polożenie, prędkość, kąt, prędkość kątowa
for i in range(1000):
    print("i=",i)
    env.render()
    action = env.action_space.sample()
    obs, reward, done, info = env.step(action)
    print("polozenie=",obs[0])
    print("predkosc=",obs[1])
    print("kat=",obs[2])
    print("predkosc katowa=",obs[3])
    print("nagroda=",reward)
    print("done=",done)
    if done == True:
        break

