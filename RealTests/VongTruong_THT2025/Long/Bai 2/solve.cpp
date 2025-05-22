#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, k; cin >> n >> k;
    map <ll, ll> mp;
    while(n--)
    {
        string s; cin >> s;
        mp[s.size()]++;
    }
    string mk; cin >> mk;
    ll kq = mk.size();
    ll res = 0, last = 0;
    for(auto [u, v] : mp)
    {
        if(u == kq)
            last = v;
        res += v;
    }
    ll penaltyb = ((res - last) / k) * 5;
    ll penaltyw = ((res - 1) / k) * 5;
    ll best = res - last + 1 + penaltyb ;
    ll worst = res + penaltyw;
    cout << best << " " << worst << " \n";
}
