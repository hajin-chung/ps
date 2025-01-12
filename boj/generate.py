from random import *

f = open("1.in", "w")

n = 10
a = []
for i in range(n):
        a.append((randint(1, 20), randint(1, 20)))
f.write(f"{n}\n");
for i in range(n):
        f.write(f"{a[i][0]} {a[i][1]}\n")
