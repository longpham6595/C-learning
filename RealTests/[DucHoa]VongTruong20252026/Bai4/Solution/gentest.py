import random
import os
# Get the directory of the current script
script_dir = os.path.dirname(os.path.abspath(__file__))
# Create the file path within the script's directory
file_path = os.path.join(script_dir, "genPy.in")

# 1 <= n,q <= 100000
# 1 <= x <= 1000000
n = 100000
q = 100000
with open(file_path, "w") as f:
    f.write(f"{n} \n")
    for i in range(n):
        x = random.randint(10000, 100000)
        f.write(f"{x} \n")
    f.write(f"{q} \n")
    for i in range(q):
        m = random.randint(100000, 999999999)
        f.write(f"{m} \n")
