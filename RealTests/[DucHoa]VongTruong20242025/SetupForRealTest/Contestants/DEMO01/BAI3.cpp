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
// Segment Sieve of eratostenes
vector<char> segmentedSieve(long long L, long long R)
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
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

long long n, a, b;
int main()
{
    fast_io;
#ifdef LOCAL
    freopen("bai3.in", "r", stdin);
    freopen("bai3.out", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vector<char> isPrime = segmentedSieve(a, b);
        for (int j = 0; j < isPrime.size(); j++)
            if (isPrime[j])
                cout << j + a << "\n";
    }
    // getchar();
}