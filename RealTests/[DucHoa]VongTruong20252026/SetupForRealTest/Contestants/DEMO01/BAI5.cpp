#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cstdlib>
#include <queue>
#define rep(i, a, n) for (ll i = a; i <= n; i++)
#define rev(i, n, a) for (ll i = n; i >= a; i--)
#define INF 1e18
#define ll long long
#define err cout << "error" << endl;
#define o(a) cout << a << endl;
#define mod(a, b, m) (a % m) * (b % m) % m
#define r(a) cout << a << ' ';
using namespace std;

inline ll read()
{
    char c = getchar();
    ll x = 0, f = 1;
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    return x * f;
}

struct node
{
    ll e1, e2;
    ll val;
    node(ll e1, ll e2, ll val) : e1(e1), e2(e2), val(val) {};
    node() : e1(0), e2(0), val(0) {};
    bool operator<(const node &c) const
    {
        return val < c.val;
    }
} b[200010];

ll n, m, a[200010], minn = INF, minp = -1, sum = 0;
ll fa[200010], val[200010];

ll f(int x)
{
    return fa[x] == x ? x : fa[x] = f(fa[x]);
}

int main()
{

    freopen("bai5.in", "r", stdin);
    freopen("bai5.out", "w", stdout);
    cin >> n >> m;
    rep(i, 1, n)
    {
        a[i] = read();
        if (minn > a[i])
        {
            minn = a[i];
            minp = i;
        }
        sum += a[i];
    }
    sum += (n - 2) * a[minp];
    rep(i, 1, n)
    {
        val[i] = a[i] + a[minp];
    }
    rep(i, 1, n)
    {
        if (i == minp)
        {
            fa[i] = -1;
            continue;
        }
        fa[i] = i;
    }
    rep(i, 1, m)
    {
        ll t1, t2, w;
        t1 = read();
        t2 = read();
        w = read();
        b[i] = node(t1, t2, w);
    }
    sort(b + 1, b + m + 1);
    rep(i, 1, m)
    {
        ll x = b[i].e1, y = b[i].e2, w = b[i].val;
        if (x != minp && y != minp)
        {
            ll fx = f(x), fy = f(y);
            if (fx != fy)
            {
                if (w < max(val[fx], val[fy]))
                {
                    sum += w - max(val[fx], val[fy]);
                    if (val[fx] > val[fy])
                    {
                        fa[fx] = fy;
                    }
                    else
                    {
                        fa[fy] = fx;
                    }
                }
            }
        }
        else
        {
            if (x == minp && w < val[f(y)])
            {
                sum += w - val[f(y)];
                fa[f(y)] = y;
                fa[y] = y;
                val[y] = w;
            }
            else if (y == minp && w < val[f(x)])
            {
                sum += w - val[f(x)];
                fa[f(x)] = x;
                fa[x] = x;
                val[x] = w;
            }
        }
    }
    cout << sum << "\n";

    return 0;
}
