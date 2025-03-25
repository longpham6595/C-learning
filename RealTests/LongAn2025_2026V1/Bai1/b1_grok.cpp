#include <bits/stdc++.h>
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
typedef unsigned long long ll;

bool is_beautiful(ll num)
{
    string s = to_string(num);
    if (s.find('0') != string::npos)
        return false;
    vector<int> freq(10, 0);
    for (char c : s)
    {
        freq[c - '0']++;
    }
    for (char c : s)
    {
        int d = c - '0';
        if (freq[d] != d)
            return false;
    }
    return true;
}
int main()
{
    fast_io;
    ll N;
    cin >> N;
    ll M = N + 1;
    while (true)
    {
        if (is_beautiful(M))
        {
            cout << M << endl;
            return 0;
        }
        M++;
    }
    // getchar();
}
// Lỗi test cuối TLE