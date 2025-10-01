#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int x) {
	if (x < 2) return false;
	if (x <= 3) return true;
	if (x % 2 == 0 || x % 3 == 0) return false;
	for (int i = 5; i * i <= x; i += 6) {
		if (x % i == 0 || x % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("bai3.in", "r", stdin);
	freopen("bai3.out", "w", stdout);
	cin.tie(0) -> ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		int l, u;
		cin >> l >> u;
		for (int i = l; i <= u; i++) {
			if (check(i)) {
				cout << i << '\n';
			}
		}
	}
}