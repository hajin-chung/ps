from random import *

f = open("1.in", "w")

n = 100
f.write(f"{n} {n}\n")
for i in range(n):
        for j in range(n):
                f.write(f"{(i+j)%2} ")
        f.write("\n")
