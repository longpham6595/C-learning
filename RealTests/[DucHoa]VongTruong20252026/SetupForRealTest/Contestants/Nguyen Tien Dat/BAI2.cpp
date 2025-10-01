#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("bai2.in", "r", stdin);
	freopen("bai2.out", "w", stdout);
	cin.tie(0) -> ios_base::sync_with_stdio(false);
	
	int n, x;
	cin >> n >> x;
	ll a[n];
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		int y = x - a[i];
		if (mp.find(y) != mp.end() && mp[y] != i) {
			cout << i + 1 << ' ' << mp[y] + 1;
			exit(0);
		}
	}
	cout << "IMPOSSIBLE";
}