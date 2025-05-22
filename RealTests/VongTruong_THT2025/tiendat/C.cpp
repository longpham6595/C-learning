#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define el '\n'

int main() {
    cin.tie(0) -> sync_with_stdio(false);

	int n;
	cin >> n;
	int ans = 1;
	map<int,int> mp;
	mp[1] = 0;
	for (int i = 1; i <= n; i++) {
		int time;
		cin >> time;
		bool found = false;
		for (auto it : mp) {
			if (it.second == time) {
				mp[it.first] = i;
				found = true;
				break;
			}
		}
		if (!found) {
			mp[++ans] = i;
		}
	}
	cout << ans;
}