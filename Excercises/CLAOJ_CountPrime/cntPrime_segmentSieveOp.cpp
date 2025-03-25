#include <bits/stdc++.h>
using namespace std;

const int MAX_R = 1e6 + 5;
vector<int> is_prime, prefix;

void optimized_sieve()
{
    is_prime.assign(MAX_R, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < MAX_R; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < MAX_R; j += i)
                is_prime[j] = 0;
        }
    }
    prefix.resize(MAX_R);
    int cnt = 0;
    for (int i = 2; i < MAX_R; ++i)
    {
        bool valid = (i == 2 || i == 3) || ((i % 6 == 1 || i % 6 == 5) && is_prime[i]);
        cnt += valid;
        prefix[i] = cnt;
    }
}

inline int count_primes_sieve(int L, int R)
{
    if (L > R)
        return 0;
    R = min(R, MAX_R - 1);
    L = max(L, 2);
    return prefix[R] - prefix[L - 1];
}

// Miller-Rabin functions (modmul, modpow, isPrime) remain the same as above
uint64_t modmul(uint64_t a, uint64_t b, uint64_t M)
{
    long long ret = a * b - M * (uint64_t)(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (long long)M);
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

bool isPrime(uint64_t n)
{
    if (n < 2 || n % 6 % 4 != 1)
        return (n | 1) == 3;
    uint64_t A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    uint64_t s = __builtin_ctzll(n - 1), d = n >> s;
    for (uint64_t a : A)
    {
        uint64_t i = s, p = modpow(a % n, d, n);
        while (p != 1 && p != n - 1 && a % n && --i)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s)
            return 0;
    }
    return 1;
}

void solve_small_m(int m, vector<pair<int, int>> &intervals)
{
    int minL = INT_MAX, maxR = 1;
    for (auto [l, r] : intervals)
    {
        minL = min(minL, l);
        maxR = max(maxR, r);
    }
    int prime6kMi1[166668] = {0}, prime6kPl1[166668] = {0};
    prime6kMi1[0] = 1; // 2
    prime6kPl1[0] = 1; // 3
    for (int i = max(1, (minL + 1) / 6); i < (maxR + 8) / 6; i++)
    {
        prime6kMi1[i] = isPrime((6 * i) - 1) + prime6kMi1[i - 1];
        prime6kPl1[i] = isPrime((6 * i) + 1) + prime6kPl1[i - 1];
    }
    for (auto [l, r] : intervals)
    {
        int l_alter = max(l, 4);
        int lcal = ((l_alter + 1) % 6) ? l_alter : l_alter - 1;
        int rcal = ((r + 1) % 6) ? r : r + 3;
        int l_minus = (lcal + 1) / 6;
        int r_minus = (rcal + 1) / 6;
        lcal = ((l_alter - 1) % 6) ? l_alter : l_alter - 1;
        rcal = ((r - 1) % 6) ? r : r + 3;
        int l_plus = (lcal - 1) / 6;
        int r_plus = (rcal - 1) / 6;
        int ans = prime6kMi1[r_minus] - prime6kMi1[l_minus] + prime6kPl1[r_plus] - prime6kPl1[l_plus];
        if (l <= 2)
            ans += (r >= 3) ? 2 : (r == 2) ? 1
                                           : 0;
        else if (l == 3 && r >= 3)
            ans += 1;
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    vector<pair<int, int>> intervals(m);
    for (int i = 0; i < m; i++)
    {
        cin >> intervals[i].first >> intervals[i].second;
    }

    if (m > 50000)
    {
        optimized_sieve();
        for (auto [L, R] : intervals)
        {
            cout << count_primes_sieve(L, R) << '\n';
        }
    }
    else
    {
        solve_small_m(m, intervals);
    }

    return 0;
}