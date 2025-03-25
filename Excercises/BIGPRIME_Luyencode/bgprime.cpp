#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int MAX_SIZE = 1000001;
vector<bool> isprime(MAX_SIZE, true);
vector<int> primes;

// Sieve: tính danh sách số nguyên tố dưới MAX_SIZE
void sieve()
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < MAX_SIZE; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            if ((long long)i * i < MAX_SIZE)
            {
                for (int j = i * i; j < MAX_SIZE; j += i)
                    isprime[j] = false;
            }
        }
    }
}

// Hàm nhân modulo sử dụng __int128 để tránh tràn số
ull modMul(ull a, ull b, ull mod)
{
    __int128 t = a;
    t *= b;
    t %= mod;
    return (ull)t;
}

// Hàm tính lũy thừa modulo
ull modPow(ull a, ull b, ull mod)
{
    ull res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = modMul(res, a, mod);
        a = modMul(a, a, mod);
        b >>= 1;
    }
    return res;
}

// Một bước của thuật toán Miller–Rabin
bool millerRabinTest(ull d, ull n, ull a)
{
    ull x = modPow(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1)
    {
        x = modMul(x, x, n);
        d *= 2;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}

// Kiểm tra số nguyên tố cho số lớn (>= MAX_SIZE)
// Trước tiên thực hiện thử chia với các số nhỏ (p < 1000),
// sau đó dùng Miller–Rabin với các cơ số cố định.
bool isPrimeMR(ull n)
{
    if (n < 2)
        return false;
    // Kiểm tra nhanh với một số số nhỏ (tối đa các số nguyên tố dưới 1000)
    for (int p : primes)
    {
        if (p >= 1000)
            break;
        if (n % p == 0)
            return (n == (ull)p);
    }
    // Viết n-1 dưới dạng d * 2^s với d lẻ
    ull d = n - 1;
    while ((d & 1ULL) == 0)
        d /= 2;
    // Các cơ số cố định đủ để kiểm tra số 64-bit
    ull testPrimes[7] = {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL};
    for (ull a : testPrimes)
    {
        if (a % n == 0)
            continue;
        if (!millerRabinTest(d, n, a))
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    ull x;
    while (cin >> x)
    {
        if (x < MAX_SIZE)
        {
            cout << (isprime[x] ? "1\n" : "0\n");
        }
        else
        {
            if (x % 2ULL == 0)
                cout << "0\n";
            else
                cout << (isPrimeMR(x) ? "1\n" : "0\n");
        }
    }
    return 0;
}
