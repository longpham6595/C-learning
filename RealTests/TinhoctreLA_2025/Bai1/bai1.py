n = int(input())
unique = set()
for _ in range(2 * n - 1):
    word = input().strip()
    if word in unique:
        unique.remove(word)
    else:
        unique.add(word)
print(unique.pop())