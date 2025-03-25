#include <iostream>
using namespace std;

typedef unsigned long long ull;
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// Hàm nhân mod: (a * b) % mod, tránh tràn số
ull mod_mul(ull a, ull b, ull mod)
{
    return ((__int128)a * b) % mod; // Sử dụng __int128 để tránh tràn
}

// Hàm tính a^b % mod bằng phương pháp lũy thừa nhị phân
ull mod_pow(ull a, ull b, ull mod)
{
    ull result = 1;
    a %= mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = mod_mul(result, a, mod);
        a = mod_mul(a, a, mod);
        b /= 2;
    }
    return result;
}

// Kiểm tra n có phải số nguyên tố bằng Miller-Rabin với các cơ sở cho trước
bool is_prime(ull n)
{
    // Xử lý các trường hợp đơn giản
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // Phân tích n-1 thành d * 2^s
    ull d = n - 1;
    int s = 0;
    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    // Các cơ sở kiểm tra (đảm bảo đúng với n < 2^64)
    ull bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    // Kiểm tra từng cơ sở
    for (ull a : bases)
    {
        if (a >= n) // a phải nhỏ hơn n
            continue;

        ull x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1)
            continue;

        // Lặp s-1 lần
        bool check = false;
        for (int i = 0; i < s - 1; i++)
        {
            x = mod_mul(x, x, n);
            if (x == n - 1)
            {
                check = true;
                break;
            }
        }

        if (!check) // Không thỏa điều kiện → n là hợp số
            return false;
    }

    return true; // Tất cả cơ sở đều thỏa → n có thể là nguyên tố
}

int main()
{
    fast_io;
    ull n;
    while (cin >> n)
    {
        if (is_prime(n))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}