import math
L =int(input())
U =int(input())
if U<0 or L<0:
    print("Nhap so tu nhien")
elif L > U:
    print("So thu nhat lon hon so thu hai")
else:
    for i in range(L, U+1):
        if i>1:
            for j in range(2, int(math.sqrt(i))+1):
                if i % j == 0:
                    break
            else:
                print (i, end= ' ')

