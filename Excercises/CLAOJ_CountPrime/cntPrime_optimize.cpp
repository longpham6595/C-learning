#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O2")
#pragma GCC optimize("-ftree-vectorize")
// #pragma GCC optimize("O3") // how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
int m, prime6kMi1[166668], prime6kPl1[166668], l, r, l_minus, r_minus, l_plus, r_plus, lcal, rcal, l_alter, l_add, r_add, ans, maxR, minL;
vector<pair<int, int>> intervals;
// Miller-Rabin algorithm for prime numbers
// BẮT ĐẦU HÀM
// Function to perform modular multiplication
uint64_t modmul(uint64_t a, uint64_t b, uint64_t M)
{
    long long ret = a * b - M * (uint64_t)(1.L / M * a * b); // Calculate (a * b) % M using floating-point arithmetic to avoid overflow
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
void buildPrimes(int x, int y)
{
    memset(prime6kMi1, 0, sizeof(prime6kMi1));
    memset(prime6kPl1, 0, sizeof(prime6kPl1));
    prime6kMi1[0] = 1; // 2 là số nguyên tố
    prime6kPl1[0] = 1; // 3 là số nguyên tố

    for (int i = x; i < y; i++)
    {
        prime6kMi1[i] = isPrime((6 * i) - 1) + prime6kMi1[i - 1];
        prime6kPl1[i] = isPrime((6 * i) + 1) + prime6kPl1[i - 1];
    }
}

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
    buildPrimes(max(1, (int)(minL + 1) / 6), (maxR + 8) / 6);

    for (int i = 0; i < m; i++)
    {
        l = intervals[i].first;
        r = intervals[i].second;
        l_alter = max(l, 4);
        lcal = (((l_alter + 1) % 6) ? l_alter : l_alter - 1);
        rcal = (((r + 1) % 6) ? r : r + 3);

        l_minus = floor(((double)(lcal + 1)) / 6);
        r_minus = floor(((double)(rcal + 1)) / 6);

        lcal = (((l_alter - 1) % 6) ? l_alter : l_alter - 1);
        rcal = (((r - 1) % 6) ? r : r + 3);

        l_plus = floor(((double)(lcal - 1)) / 6);
        r_plus = floor(((double)(rcal - 1)) / 6);

        ans = 0;
        ans += prime6kMi1[r_minus] - prime6kMi1[l_minus];
        ans += prime6kPl1[r_plus] - prime6kPl1[l_plus];
        if (l <= 2)
        {
            if (r >= 3)
                ans += 2;
            if (r == 2)
                ans += 1;
        }
        else if (l == 3)
        {
            if (r >= 3)
                ans += 1;
        }
        // cout << "(l;r) = (" << l << "," << r << "): " << l_minus << "; " << r_minus << "; " << l_plus << "; " << r_plus << "; Ans = " << ans << "\n";
        cout << ans << "\n";
    }
    //     cout << "MaxR = " << maxR << "; MinL = " << minL << "\n";
    //     cout << "array 1: \n";
    //     for (int i = 0; i < 20; i++)
    //         cout << i << " -> " << (i ? 6 * i - 1 : 2) << " : " << prime6kMi1[i] << " \n";
    //     cout << "array 2: \n";
    //     for (int i = 0; i < 20; i++)
    //         cout << i << " -> " << (i ? 6 * i + 1 : 3) << " : " << prime6kPl1[i] << " \n";
}
