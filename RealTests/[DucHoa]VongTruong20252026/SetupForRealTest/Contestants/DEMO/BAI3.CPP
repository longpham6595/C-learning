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
string s;
long long t;

int main()
{
    fast_io;
    ifstream cin("bai3.in");
    ofstream cout("bai3.out");
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s.size() & 1)
            cout << "NO\n";
        else
        {
            string s1 = s.substr(0, s.size() / 2);
            string s2 = s.substr(s.size() / 2, s.size() / 2);
            cout << (s1 == s2 ? "YES\n" : "NO\n");
        }
    }
    // getchar();
}