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
unsigned long long compute_next(unsigned long long prev)
{
    unsigned long long next_val = prev * 2;
    string s = to_string(next_val);
    sort(s.begin(), s.end());
    size_t first_non_zero = s.find_first_not_of('0');
    if (first_non_zero != string::npos)
        s = s.substr(first_non_zero);
    else
        s = "0";
    return stoull(s);
}
// Mấu chốt bài toán này nằm ở chỗ
// Từ phần tử thứ 26 trở đi dãy số lặp lại
// theo chu kì là 6
int main()
{
    unsigned long long n;
    cin >> n;

    vector<unsigned long long> F;
    F.push_back(1); // F1

    // Precompute up to F32 (index 31)
    for (int i = 1; i < 32; ++i)
        F.push_back(compute_next(F[i - 1]));

    vector<unsigned long long> cycle_list = {
        F[26], // F27
        F[27], // F28
        F[28], // F29
        F[29], // F30
        F[30], // F31
        F[31]  // F32
    };

    if (n <= 32)
    {
        cout << F[n - 1] << endl;
    }
    else
    {
        int64_t offset = (n - 27) % 6;
        if (offset < 0)
            offset += 6;
        cout << cycle_list[offset] << endl;
    }

    return 0;
}