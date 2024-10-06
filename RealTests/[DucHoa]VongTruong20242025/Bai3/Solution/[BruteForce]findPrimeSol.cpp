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

bool isPrime(int x)
{
    if (x == 2 || x == 3)
        return true;
    else if (x < 2 || x % 2 == 0 || x % 3 == 0)
        return false;
    else
    {
        bool kq = true;
        for (int i = 1; i <= (sqrt(x) + 1) / 6; i++)
            if ((x % (6 * i + 1) == 0) || (x % (6 * i - 1) == 0))
            {
                kq = false;
                break;
            }
        return kq;
    }
}

int t;
long long n, m;

int main()
{
    fast_io;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        for (long long j = n; j <= m; j++)
            if (isPrime(j))
                cout << j << endl;
    }
    // getchar();
}