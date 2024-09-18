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
#include <iostream>
using namespace std;

// Init Prefix sum 2D on an array size m x n
//  PSA - Prefix Sum Array
long long psa[1002][1002] = {0}, dat[1002][1002], m, n, maxOup;
void prefixSum2D()
{
    // Initialize the first element
    psa[1][1] = dat[1][1];
    // Fill the first row
    for (int j = 2; j <= n; j++)
        psa[1][j] = psa[1][j - 1] + dat[1][j];
    // Fill the first column
    for (int i = 1; i <= m; i++)
    {
        psa[i][1] = psa[i - 1][1] + dat[i][1];
    }
    // Fill the rest of the prefix sum array
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + dat[i][j];
        }
    }
}
long long sumPSA(long long x1, long long y1, long long x2, long long y2)
{
    // [(x1;y1);(x2;y2)] = [x2;y2]-([x1-1;y2]-[x2;y1-1]+[x1-1;y2-1])
    return (psa[x2][y2] - psa[x1 - 1][y2] - psa[x2][y1 - 1] + psa[x1 - 1][y1 - 1]);
}
void outputPSA()
{
    // Print the prefix sum array (optional)
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            cout << setw(3) << psa[i][j] << " \n"[j == n];
}
// End of prefix Sum 2D algorithm
// Start Kadane's Algorithm for maximum subarray sum
long long kadane(long long arr[], long long arrSize)
{
    long long max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < arrSize; i++)
    {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
// End of Kadane's Algorithm

// // Init Prefix sum 2D on an array size m x n
// //  PSA - Prefix Sum Array
// const long long maxM = 1002, maxN = 1002;
// long long psa[maxM][maxN] = {0}, dat[maxM][maxN], m, n, maxOup;
// // Create a prefix Sum 2D array table size ipm x ipn
// void prefixSum2D()
// {

//     // Initialize the first element
//     psa[1][1] = dat[1][1];

//     // Fill the first row
//     for (int j = 2; j <= n; j++)
//         psa[1][j] = psa[1][j - 1] + dat[1][j];

//     // Fill the first column
//     for (int i = 1; i <= m; i++)
//     {
//         psa[i][1] = psa[i - 1][1] + dat[i][1];
//     }

//     // Fill the rest of the prefix sum array
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + dat[i][j];
//         }
//     }
// }

// long long sumPSA(long long x1, long long y1, long long x2, long long y2)
// {
//     // [(x1;y1);(x2;y2)] = [x2;y2]-([x1-1;y2]-[x2;y1-1]+[x1-1;y2-1])
//     return (psa[x2][y2] - psa[x1 - 1][y2] - psa[x2][y1 - 1] + psa[x1 - 1][y1 - 1]);
// }

// void outputPSA()
// {
//     // Print the prefix sum array (optional)
//     for (int i = 0; i <= m; i++)
//         for (int j = 0; j <= n; j++)
//             cout << setw(3) << psa[i][j] << " \n"[j == n];
// }

// // End of prefix Sum 2D algorithm

// // Start Kadane's Algorithm for maximum subarray sum
// long long kadane(long long arr[], long long arrSize)
// {
//     long long max_so_far = 0, max_ending_here = 0;
//     for (int i = 0; i < arrSize; i++)
//     {
//         max_ending_here = max(arr[i], max_ending_here + arr[i]);
//         max_so_far = max(max_so_far, max_ending_here);
//     }
//     return max_so_far;
// }
// // End of Kadane's Algorithm

// For this problem only
void solve()
{
    long long temptDat[m];

    maxOup = dat[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            for (int k = 0; k < m; k++)
                temptDat[k] = sumPSA(k + 1, i, k + 1, j);

            maxOup = max(maxOup, kadane(temptDat, m));
        }
}

int main()
{
    fast_io;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // MAIN PROGRAM
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> dat[i][j];

    prefixSum2D();

    solve();
    cout << maxOup;

    // getchar();
}