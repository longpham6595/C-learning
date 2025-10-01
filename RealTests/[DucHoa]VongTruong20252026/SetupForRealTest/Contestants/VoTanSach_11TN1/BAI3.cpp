#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<int> prime;
int m, n;

void simpleSieve(int x) {
	bool a[x + 1];
	memset(a, 1, sizeof(a));
	for(int i = 2; i * i <= x; i++) {
		if(a[i] == 1)
			for(int j = i * i; j <= x; j += i) a[j] = 0;
	}

	for(int i = 2; i <= x; i++) {
		if(a[i] && m <= i && i <= n) cout << i << "\n";
		if(a[i]) prime.push_back(i);
	}
}

void segmentedSieve(int m, int n) {
	int lim = floor(sqrt(n)) + 1;

	simpleSieve(lim);

	int l = floor(m / lim) * lim;
	
	int r = l + lim;

	while(l < n) {
		if(r > n) r = n;

		bool check[lim + 1];
		memset(check, 1, sizeof(check));

		for(auto a : prime) {
			int loLim = floor(l / a) * a;
			if(loLim < l) loLim += a;

			for(int i = loLim; i <= r; i += a) {
				check[i - l] = 0;
			}
		}

		for(int i = l; i <= r; i++) {
			if(check[i - l] && m <= i && i <= n) cout << i << "\n";
		}

		l += lim;
		r += lim;
	}
}


main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("bai3.in", "r", stdin);
	freopen("bai3.out", "w", stdout);

	int t;
	cin >> t;

	while(t--) {
		cin >> m >> n;

		segmentedSieve(m, n);
	}
}