#include<bits/stdc++.h>
#define int long long

using namespace std;
int n, x;
pair<int,int> a[300005];

main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("bai2.in", "r", stdin);
	freopen("bai2.out", "w", stdout);
	
	cin >> n >> x;

	for(int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a + n + 1);
	
	bool check = 0;

	int r = n, l = 1;

	while(l < r) {
		if(a[l].first + a[r].first > x)
			r--;
		if(a[l].first + a[r].first < x)
			l++;
		if(a[l].first + a[r].first == x) {
			cout << a[l].second << " " << a[r].second;
			check = 1;
			return 0;
		}
	}
	
	if(!check) cout << "IMPOSSIBLE";
}