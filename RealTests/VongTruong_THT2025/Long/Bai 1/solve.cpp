#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
    {
        ll a, b, c; cin >> a >> b >> c;
        ll sum = a + b + c;
        ll limit = sum / 7;
        if(a < limit || b < limit || c < limit)
        {
            cout << "NO\n";
            continue;
        }
        ll res = limit;
        a -= limit, b -= limit; c -= limit;
        res += a; res += b; res += c;
        cout << (res % 7 == 0 ? "YES" : "NO") << "\n";
    }
}
