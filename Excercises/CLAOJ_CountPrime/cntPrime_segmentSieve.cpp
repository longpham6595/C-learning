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
vector<long long> casePrefix;
// Segment Sieve of eratostenes
vector<long long> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    vector<char> isPrime(R - L + 1, true);
    vector<long long> prefixSum(R - L + 1, 0);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    for (long long i = 1; i < R - L + 1; i++)
        prefixSum[i] = prefixSum[i - 1] + isPrime[i];
    return prefixSum;
}
long long minL, maxR, m, l, r, ans;
vector<pair<int, int>> intervals;
int main()
{
    fast_io;
    minL = LLONG_MAX, maxR = 1;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        intervals.push_back({l, r});
        maxR = max(maxR, r), minL = min(minL, l);
    }
    casePrefix = segmentedSieve(minL, maxR);
    for (auto it : intervals)
        cout << casePrefix[it.second - minL] - casePrefix[(it.first - minL ? it.first - minL - 1 : it.first - minL)] << endl;
    // getchar();
}