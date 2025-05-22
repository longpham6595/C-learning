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
//============================================================================
// START PROGRAM
//============================================================================
int n;
long long a, b;
vector<pair<long long, long long>> dat;
vector<bool> sig;
bool sortPair(pair<long long, long long> &x, pair<long long, long long> &y)
{
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}
bool contained(pair<long long, long long> &x, pair<long long, long long> &y)
{
    if (x.first < y.first && x.second < y.second)
        return true;
    return false;
}
int main()
{
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        dat.push_back({a, b});
    }
    sort(dat.begin(), dat.end(), sortPair);
    // for (auto it : dat)
    //     cout << it.first << " " << it.second << "\n";

    sig.resize(n);
    memset(sig, false, sizeof(sig));
    while (true)
    {
        if (find(sig.begin(), sig.end(), false) != sig.end())
            break;
        auto init = find(sig.begin(),sig.end(),false);
        sig[init - sig.begin()] = true;
    }

    // getchar();
}