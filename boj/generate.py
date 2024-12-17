from random import *

f = open("1.in", "w")

n = 100
t = 1000
f.write(f"{n} {t}\n")
for i in range(n):
        y = randint(-10000, 10000)
        x = randint(-10000, 10000)
        vy = randint(-10000, 10000)
        vx = randint(-10000, 10000)
        f.write(f"{x} {y} {vx} {vy}\n")
