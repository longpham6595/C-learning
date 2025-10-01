#include<bits/stdc++.h>
#define int long long

using namespace std;
int n, a[100009], res;

void binSearch(int x) {
	int l = 1, r = n;

	while(l <= r) {
		int m = (l + r) / 2;
		if(a[m] <= x) {
			res = max(res, m);
			l = m + 1;
		} else if(a[m] > x) {
			r = m - 1;
		}
	}
}

main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("bai4.in", "r", stdin);
	freopen("bai4.out", "w", stdout);

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int t;
	cin >> t;

	while(t--) {
		int q;

		cin >> q;

		binSearch(q);

		cout << res << "\n";

		res = 0;
	}
}