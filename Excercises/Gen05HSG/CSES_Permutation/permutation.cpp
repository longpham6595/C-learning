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
long long n;
vector<long long> evens, odds;
int main()
{
    fast_io;
    // ifstream cin(inputFile);
    // ofstream cout(outputFile);
    cin >> n;
    if (n < 4 && n > 1)
        cout << "NO SOLUTION";
    else
    {
        for (int i = 1; i <= n; i++)
            if (i & 1)
                odds.push_back(i);
            else
                evens.push_back(i);
        for (auto it : evens)
            cout << it << " ";
        for (auto it : odds)
            cout << it << " ";
    }
    // getchar();
}