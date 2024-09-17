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

long long m, n, temptVal, temptArea, maxValOup = 0, minAreaOup = 0, maxId = 1, val[1002][1002];
bool dat[1002][1002], tracker[1002][1002];
pair<long long, long long> nextNode, node;

// Graph transitions
inline bool validCoor(int x, int y, int maxX, int maxY)
{
    return (x >= 1 && x <= maxX && y >= 1 && y <= maxY);
}

vector<pair<long long, long long>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
stack<pair<long long, long long>> st;

int main()
{
    fast_io;
#ifdef LOCAL
    freopen("khaithac.inp", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // MAIN PROGRAM
    // Input Data
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> dat[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> val[i][j];

    // Prebuild
    for (int i = 0; i <= m + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            if (dat[i][j])
                tracker[i][j] = false;
            else
                tracker[i][j] = true;

    // Process
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (!tracker[i][j])
            {
                st.push({i, j});
                temptVal = 0, temptArea = 0;
                while (!st.empty())
                {
                    node = st.top();
                    st.pop();

                    temptVal += val[node.first][node.second], temptArea++;
                    if (temptVal > maxValOup || (temptVal == maxValOup && temptArea < minAreaOup))
                        maxValOup = temptVal, minAreaOup = temptArea;
                    tracker[node.first][node.second] = true;
                    for (auto it : dir)
                    {
                        nextNode = {node.first + it.first, node.second + it.second};
                        if (!tracker[nextNode.first][nextNode.second] && validCoor(nextNode.first, nextNode.second, m, n))
                            st.push(nextNode);
                    }
                }
            }

    cout << maxValOup << " " << minAreaOup;
    // getchar();
}