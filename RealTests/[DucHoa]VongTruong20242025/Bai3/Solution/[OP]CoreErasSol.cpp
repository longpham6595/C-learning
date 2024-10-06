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
int t;
vector<pair<long long, long long>> adj(200);
long long maxIt = 0;
vector<bool> prime;
void sieve_of_eratosthenes(int n)
{
    // Create a boolean array prime[0..n] and mark all entries as true, meaning all the numbers are initially considered primes.
    prime.resize(n + 1);
    prime.assign(n + 1, true);
    // Start looking with the smallest prime number, i.e., 2.
    for (int p = 2; p * p <= n; p++)
    {
        // If it is the next prime, mark all its multiples as false, as they are composite and not prime.
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main()
{
    fast_io;
#ifdef LOCAL
    freopen("bai3.in", "r", stdin);
    freopen("bai3.out", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> adj[i].first >> adj[i].second;
        maxIt = max(maxIt, max(adj[i].first, adj[i].second));
    }

    sieve_of_eratosthenes(maxIt);

    for (int i = 0; i < t; i++)
        for (int j = adj[i].first; j <= adj[i].second; j++)
            if (prime[j])
                cout << j << "\n";
    // getchar();
}