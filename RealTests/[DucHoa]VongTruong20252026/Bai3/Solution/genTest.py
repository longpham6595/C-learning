import random
import os

# Get the directory of the current script
script_dir = os.path.dirname(os.path.abspath(__file__))

# Create the file path within the script's directory
file_path = os.path.join(script_dir, "genPy.in")

t = 125
minn = 2997400000
maxm = 3000000000

with open(file_path, "w") as f:
    f.write(str(t) + "\n")
    for i in range(t):
        n = random.randint(minn, maxm - (maxm - minn) // 2)
        m = random.randint(n + 1, maxm)
        f.write(f"{n} {m}\n")

# Limit: 0 <= n <= m < 3*10^9, Trong đề nhớ bỏ giới hạn khoảng cách giữa n và m
# Test 1: 1 - 10
# Test 2: 100 - 1000
# Test 3: 1000 - 10000
# Test 4: 1000 - 100000
# Test 5: 10000 - 1000000
# Test 6: 8000000 - 10000000
# Test 7: 500000000 - 100000000
# Test 8: 2998000000 - 3000000000
# Test 9: 2997500000 - 3000000000
# Test 10: 2997500000 - 3000000000
# Test 11: 29975000000 - 3000000000
# Test 12: 29975000000 - 3000000000
# Test 13: 29975000000 - 3000000000
# Test 14: 29975000000 - 3000000000
# Test 15: 29970000000 - 3000000000
# Test 16: 29972000000 - 3000000000
# Test 17: 29973000000 - 3000000000
# Test 18: 29974000000 - 3000000000
# Test 19: 29974000000 - 3000000000
# Test 20: 29975000000 - 3000000000
# On dealing:
