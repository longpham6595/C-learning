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
long long n, a[1008], maxIt = 0;
string st = "";

int main()
{
    fast_io;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // MAIN PROGRAM

    // Solve
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxIt = max(maxIt, a[i]);
    }
    // build st
    for (int i = 1; i <= maxIt; i++)
        st += to_string(i);
    // Cout results
    for (int i = 0; i < n; i++)
        cout << st[a[i]-1] << "\n";
    // getchar();
}