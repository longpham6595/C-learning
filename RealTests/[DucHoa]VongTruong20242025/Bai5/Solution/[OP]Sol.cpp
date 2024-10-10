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
vector<array<long long, 3>> es;
long long a[200008], n, m, z, ans = 0;
// Start brief DSU
// Size of DSU map is N
const long long N = 200008;
long long parent[N];

long long getParent(long long x)
{
    return (x == parent[x] ? x : parent[x] = getParent(parent[x]));
}

bool merge(long long x, long long y)
{
    x = getParent(x), y = getParent(y);
    if (x == y)
        return false;
    parent[x] = y;
    return true;
}
// End brief DSU
int main()
{
    fast_io;
#ifdef LOCAL
    freopen("bai5.in", "r", stdin);
    freopen("bai5.out", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    es.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> es[i][1] >> es[i][2] >> es[i][0];
        es[i][1]--, es[i][2]--;
    }
    z = min_element(a, a + n) - a;
    for (int i = 0; i < n; i++)
        if (i != z)
            es.push_back({a[i] + a[z], i, z});
    sort(es.begin(), es.end());

    for (long long i = 0; i < n; i++)
        // Init for parent of i is i begin to DSU
        parent[i] = i;
    for (auto e : es)
        if (merge(e[1], e[2]))
            ans += e[0];

    cout << ans;
    // getchar();
}