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
#define LOCAL
//============================================================================
// START PROGRAM
//============================================================================
long long n, x, a[200008];
bool sig = false;
int main()
{
    fast_io;
#ifdef LOCAL
    freopen("bai2.in", "r", stdin);
    freopen("bai2.out", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
            if (a[i] + a[j] == x)
            {
                cout << i + 1 << " " << j + 1;
                sig = true;
                break;
            }
        if (sig)
            break;
    }
    if (!sig)
        cout << "IMPOSSIBLE";
    // getchar();
}