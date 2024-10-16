#include <bits/stdc++.h>
using namespace std;
#define ll long long
char findK(ll k)
{
	ll cnt = 9;
	ll dd = 1;
	ll batdau = 1;
	while(k > dd * cnt)
	{
		k -= dd * cnt;
		dd++;
		cnt *= 10;
		batdau *= 10;
	}
	ll sigma = batdau + (k - 1) / dd;
	int beo = (k - 1) % dd;
	return to_string(sigma)[beo];
}
int main()
{
	freopen("bai1.in", "r", stdin);
	freopen("bai1.out", "w", stdout);
	cin.tie(NULL) -> sync_with_stdio(false);
	int q; cin >> q;
	while(q--)
	{
		int k; cin >> k;
		cout << findK(k) << " \n";
	}
}