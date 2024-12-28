from random import *

f = open("1.in", "w")

n = 750
f.write(f"{n} {n}\n");
for i in range(n):
        for j in range(n):
                f.write(f"1")
        f.write("\n")
