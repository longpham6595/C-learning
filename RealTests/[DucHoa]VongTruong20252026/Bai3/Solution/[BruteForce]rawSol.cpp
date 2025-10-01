// (t<=10)
// (1 <= m <= n <= 1000000000, n - m <= 100000)

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
int n, m, t, i, j, s, flag;
int main()
{
    fast_io;
#ifdef LOCAL
    freopen("bai3.in", "r", stdin);
    freopen("bai3.out", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (i = n; i <= m; i++)
        {
            flag = 0;
            if (i == 1)
                flag = 1;
            s = sqrt(i);
            for (j = 2; j <= s; j++)
            {
                if (i % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << i << endl;
        }
    }
    return 0;
    // getchar();
}