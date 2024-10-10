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
long long n, x, y;
vector<array<long long, 2>> vec;

// Create a Mersenne Twister random number generator and seed it with 23478
mt19937 rng(23478);
int main()
{
    fast_io;
#ifdef LOCAL
    freopen("bai5.in", "r", stdin);
    freopen("bai5.out", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i][0] >> vec[i][1];

    auto distance = [](long long x1, long long y1, long long x2, long long y2)
    {
        return sqrt((double)(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    double ans = 0;
    int limit = 1e7;
    cout << fixed << setprecision(12);

    for (int i = 0; i < limit; i++)
    {
        int x = rng() % n, y = rng() % n;
        ans += distance(vec[x][0], vec[x][1], vec[y][0], vec[y][1]);
    }
    // Due to the Montecarlo method, here we randomly limit times of calculation
    // Including the calculation of the distance between 2 points (may be distance between a point to itself by random)
    // Then the total will be like this:
    // ans          limit
    //  ?           n*n/2
    ans = ans * n * n / 2.0 / limit;
    cout << ans;
    // getchar();
}