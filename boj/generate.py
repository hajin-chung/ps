from random import *

f = open("1.in", "w")

n = 16
f.write(f"{n}\n");
for i in range(n):
        for j in range(n):
                x = randint(0, 35);
                f.write(f"{x} ")
        f.write("\n")

mask = ""
for i in range(n):
        if randint(0, 10) > 5:
                mask += "Y"
        else:
                mask += "N"
f.write(f"{mask}\n")
f.write(f"{n}\n")
