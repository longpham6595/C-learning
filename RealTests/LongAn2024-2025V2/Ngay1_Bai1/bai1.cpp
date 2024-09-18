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

long long n, m, tempt, ans = 0;

const long long MAX_SIZE = 1000001;
// isPrime[] : isPrime[i] is true if number is prime
// prime[] : stores all prime number less than N
// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);
// function generate all prime number less than N in O(n)
void manipulated_seive(int N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false;
    // Fill rest of the entries
    for (long long int i = 2; i < N; i++)
    {
        // If isPrime[i] == True then i is prime number
        if (isprime[i])
        {
            // put i into prime[] vector
            prime.push_back(i);
            // A prime number is its own smallest
            // prime factor
            SPF[i] = i;
        }
        // Remove all multiples of i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
        for (long long int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++)
        {
            isprime[i * prime[j]] = false;
            // put smallest prime factor of i*prime[j]
            SPF[i * prime[j]] = prime[j];
        }
    }
}

int main()
{
    fast_io;
#ifdef LOCAL
    freopen("nguyento.inp", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> n >> m;
    manipulated_seive(64008);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tempt;
            if (isprime[tempt])
                ans++;
        }
    cout << ans;
    // getchar();
}