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
// 1100 binary search - dp - implementation
long long n, x[100008], q, m;
long long bst(long long item)
{
    long long l = 0, r = n, mid, res = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        // cout << l << " " << r << " " << mid << " " << res << "\n";
        if (x[mid] <= item && res < mid)
            res = mid;
        if (x[mid] > item)
            r = mid - 1;
        else
            l = mid + 1;
    }
    while (x[res + 1] <= item && res + 1 <= n)
        res++;
    return res;
}

int main()
{
    fast_io;
#ifdef LOCAL
    freopen("bai4.in", "r", stdin);
    freopen("bai4.out", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> n;
    x[0] = LLONG_MIN;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    sort(x, x + n + 1);

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        cout << bst(m) << endl;
    }
}