#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

#ifdef LOCAL
#include "assets/debug.h"
#else
#define dd(x...)
#define ExeTime
#endif

void testCase();

void init() {}

int main()
{
    init();
    testCase();
}

mt19937 rng(23478);

void testCase()
{
    int n;
    cin >> n;

    vector<array<long long, 2>> a(n);
    for (auto &x : a)
    {
        cin >> x[0] >> x[1];
    }

    auto dis = [](long long x1, long long y1, long long x2, long long y2)
    {
        return sqrt((double)(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    double ans = 0;
    int limit = 1e7;
    cout << fixed << setprecision(12);

    for (int i = 0; i < limit; i++)
    {
        int x = rng() % n, y = rng() % n;
        ans += dis(a[x][0], a[x][1], a[y][0], a[y][1]);
    }
    ans = ans * n * n / 2.0 / limit;
    cout << ans << endl;
}