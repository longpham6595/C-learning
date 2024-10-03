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
long long n, x, tempt, l, r;
vector<pair<int, int>> values;
pair<int, int> ans;
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
    values.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempt;
        values[i] = {tempt, i + 1};
    }

    sort(values.begin(), values.end());

    l = 0, r = n - 1;
    while (l < r)
    {
        if (values[l].first + values[r].first == x)
        {
            ans = {values[l].second, values[r].second};
            sig = true;
            break;
        }
        else if (values[l].first + values[r].first < x)
            l++;
        else
            r--;
    }
    if (sig)
        cout << ans.first << " " << ans.second;
    else
        cout << "IMPOSSIBLE";
    // getchar();
}