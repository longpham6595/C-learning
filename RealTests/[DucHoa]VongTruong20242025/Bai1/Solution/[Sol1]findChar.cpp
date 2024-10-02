#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O2")
#pragma GCC optimize("-ftree-vectorize")
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
// Define local for input and output files
// #define LOCAL
//============================================================================
// START PROGRAM
//============================================================================
long long n, tempt;

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
    fast_io;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> tempt, cout << findCharacterPosition(tempt) << "\n";
    // getchar();
}