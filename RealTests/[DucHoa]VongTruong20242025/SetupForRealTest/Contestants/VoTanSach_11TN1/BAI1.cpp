#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("bai1.in", "r", stdin);
	freopen("bai1.out", "w",stdout);
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;

		string s;
		int temp = 1;
		while(s.size() < n) {
			s += to_string(temp);
			temp++;
		}

		cout << s[n - 1] << endl;
	}
}