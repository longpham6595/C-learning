#include <iostream>
#include <cmath>

long long findCharacterPosition(long long position)
{
    long long length = 0;
    long long digitCount = 1;
    long long start = 1;

    while (true)
    {
        long long end = start * 10 - 1;
        long long rangeLength = (end - start + 1) * digitCount;

        if (position <= length + rangeLength)
        {
            long long offset = position - length - 1;
            long long number = start + offset / digitCount;
            int digitIndex = offset % digitCount;
            std::string numberStr = std::to_string(number);
            return numberStr[digitIndex] - '0';
        }

        length += rangeLength;
        start *= 10;
        digitCount++;
    }
}

int main()
{
    long long position = 672274832941907421;
    std::cout << "Character at position " << position << " is: " << findCharacterPosition(position) << std::endl;
    return 0;
}