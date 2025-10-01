#include<bits/stdc++.h>
#define int long long

using namespace std;

int dsu[100], val[100], res = 0;
pair<int,int> tar = {1e9, 1e9};

int parent(int x) {
	if(dsu[x] == x) return x;
	dsu[x] = parent(dsu[x]);
	return dsu[x];
}

void join(int a, int b) {
	a = parent(a);
	b = parent(b);
	if(a != b) {
		if(val[a] < val[b]) swap(a,b);
		dsu[a] = b;
	}
}

main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("bai5.in","r",stdin);
	freopen("bai5.out","w",stdout);
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		cin >> val[i];
		if(val[i] < tar.first) {
			tar.first = val[i];
			tar.second = i;
		}
		dsu[i] = i;
	}
	int a,b,x;
	cin >> a >> b >> x;

	if(tar.second == a) {
		res += x;
	}
} else if(tar.second == b) {
	if(tar.second + val[a] >= x && tar.first != parent(a)) {
		join(tar.first, a);
		res += x;
	}
}
res += x;
join(tar.second, i);
}

cout << res << "\n";
}