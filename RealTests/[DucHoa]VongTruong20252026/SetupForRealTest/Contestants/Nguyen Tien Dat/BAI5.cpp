#include <bits/stdc++.h>
using namespace std;
#define ll long long

class UnionFind {
private:
	vector<int> parent, rank;
public:
	UnionFind(int n) : parent(n + 1), rank(n + 1, 1) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		return u == parent[u] ? u : parent[u] = find(parent[u]);
	}
	void join(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (rank[x] < rank[y]) {
				swap(x, y);
			}
			rank[x] += rank[y];
			parent[y] = x;
		}
	}
	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};

int main() {
	freopen("bai5.in", "r", stdin);
	freopen("bai5.out", "w", stdout);
	cin.tie(0) -> ios_base::sync_with_stdio(false);
	
	ll n, m;
	cin >> n >> m;
	UnionFind uf(n);
	ll a[n + 1];
	map<pair<ll, ll>, ll> cost;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		ll x, y, w;
		cin >> x >> y >> w;
		if (x > y) {
			swap(x, y);
		}
		cost[{x, y}] = w;
	}
	for (ll i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (cost.find({i, j}) == cost.end()) {
				cost[{i, j}] = a[i] + a[j];
			} else {
				cost[{i, j}] = min(a[i] + a[j], cost[{i, j}]);
			}
		}
	}
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
	ll res = 0;
	for (auto it : cost) {
		pq.push({it.second, it.first.first, it.first.second});
	}
	while (n > 1) {
		ll c = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
		if (uf.connected(x, y) == false) {
			uf.join(x, y);
			res += c;
			n--;
		}
		pq.pop();
	}
	cout << res;
}