#include <iostream>
#include <cstdint>
using namespace std;
// SPEED UP
// #pragma GCC optimize("O2")
// #pragma GCC optimize("-ftree-vectorize")
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
unsigned long long h, w, prod_hw, sum_hw, result;
int main()
{
    fast_io;
    cin >> h >> w;
    prod_hw = h * w, sum_hw = h + w;
    result = ((prod_hw * sum_hw) / 2) + (2 * prod_hw) - sum_hw;
    cout << result;
    // getchar();
}
