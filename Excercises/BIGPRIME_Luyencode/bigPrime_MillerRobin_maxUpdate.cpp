#include <bits/stdc++.h>
using namespace std;
// SPEED UP
// #pragma GCC optimize("O2")
// #pragma GCC optimize("-ftree-vectorize")
#pragma GCC optimize("O3") // how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
// Miller-Rabin algorithm for prime numbers

// BẮT ĐẦU HÀM
// Function to perform modular multiplication
uint64_t modmul(uint64_t a, uint64_t b, uint64_t M)
{
    long long ret = (uint64_t)(1L - ((1L / M) * M)) * a * b; // Calculate (a * b) % M using floating-point arithmetic to avoid overflow
    return ret + M * (ret < 0) - M * (ret >= (long long)M);  // Adjust the result to ensure it is within the range [0, M-1]
}
uint64_t modpow(uint64_t b, uint64_t e, uint64_t mod)
{
    if (mod == 1)
        return 0;
    uint64_t ans = 1;
    b %= mod;
    for (; e; b = modmul(b, b, mod), e >>= 1)
        if (e & 1)
            ans = modmul(ans, b, mod);
    return ans;
}
// Function to check if a number is prime using the Miller-Rabin test
bool isPrime(uint64_t n)
{
    if (n < 2 || n % 6 % 4 != 1)                                       // Quick checks for small numbers and numbers not of the form 6k ± 1
        return (n | 1) == 3;                                           // Return true if n is 2 or 3, false otherwise
    uint64_t A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, // Bases for the Miller-Rabin test
        s = __builtin_ctzll(n - 1), d = n >> s;                        // Decompose n-1 into d * 2^s
    for (uint64_t a : A)                                               // Loop through each base a
    {                                                                  // ^ count trailing zeroes
        uint64_t i = s, p = modpow(a % n, d, n);                       // Calculate p = a^d % n and initialize i to s
        while (p != 1 && p != n - 1 && a % n && --i)                   // Square p repeatedly while checking conditions
            p = modmul(p, p, n);                                       // Square p
        if (p != n - 1 && i != s)                                      // If p is not n-1 and i is not s
            return 0;                                                  // n is composite
    }
    return 1; // If all bases pass, n is probably prime
}
// KẾT THÚC HÀM
long long n;
int main()
{
    fast_io;
    while (cin >> n)
        cout << isPrime(n) << '\n';
    // getchar();
}