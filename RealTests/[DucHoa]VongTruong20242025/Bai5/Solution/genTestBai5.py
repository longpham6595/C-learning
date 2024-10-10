import random
import os
# Get the directory of the current script
script_dir = os.path.dirname(os.path.abspath(__file__))
# Create the file path within the script's directory
file_path = os.path.join(script_dir, "genPy.in")

n = random.randint(1, 200000)
m = random.randint(1, 200000)

with open(file_path, "w") as f:
    f.write(f"{n} {m}\n")
    for i in range(n):
        a = random.randint(1, 1000000000000)
        f.write(f"{a} ")
    for i in range(m):
        x = random.randint(1, n)
        y = random.randint(1, n)
        w = random.randint(1, 1000000000000)
        f.write(f"{x} {y} {w}\n")
