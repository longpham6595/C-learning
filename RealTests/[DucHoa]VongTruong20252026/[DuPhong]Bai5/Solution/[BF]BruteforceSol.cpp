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
long long n;
vector<array<long long, 2>> vec;

double dist(long long x1, long long y1, long long x2, long long y2)
{
    return sqrt((double)(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i][0] >> vec[i][1];

    double ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += dist(vec[i][0], vec[i][1], vec[j][0], vec[j][1]);
    cout << fixed << setprecision(10) << ans;
    // getchar();
}