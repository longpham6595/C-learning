#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("bai4.in", "r", stdin);
	freopen("bai4.out", "w", stdout);
	cin.tie(0) -> ios_base::sync_with_stdio(false);
	
	int n, q;
	long long m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cin >> q;
	while (q--) {
		cin >> m;
		if (m < a[0]) {
			cout << 0 << '\n';
		} else {
			auto it = lower_bound(a.begin(), a.end(), m) - a.begin();
			cout << it + 1 << '\n';
		} 
	}
}