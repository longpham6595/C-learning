#include <bits/stdc++.h>
#include <vector>
using namespace std;
// File define
// #define fileName "BUS"
// #define inputFile fileName ".INP"
// #define outputFile fileName ".OUT"
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
//============================================================================
// START PROGRAM
//============================================================================
long long t;
long long a[4];
int main()
{
    fast_io;
    ifstream cin("bai2.in");
    ofstream cout("bai2.out");
    cin >> t;
    while (t--)
    {
        for (long long i = 0; i < 4; i++)
            cin >> a[i];
        sort(a, a + 4);
        long long c = a[3] - a[0];
        long long d = a[2] - c;
        long long e = a[3] - (c + d);
        cout << c << " " << d << " " << e << endl;
    }
    // getchar();
}