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
// Bai 1: Chu so trong day lien tuc (4 pts)
// 10 test cases: 0.4 pts/test case
//============================================================================
long long n, num;
long long numQ(long long x)
{
    long long cs = 1, powUp = 1, desNum;
    string st;
    while (x > cs * 9 * powUp)
        x -= cs++ * 9 * powUp, powUp *= 10;
    desNum = powUp + x / cs;
    if (x % cs == 0)
        return (desNum - 1) % 10;
    st = to_string(desNum);
    return st[x % cs - 1] - '0';
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
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        cout << numQ(num) << "\n";
    }

    // getchar();
}