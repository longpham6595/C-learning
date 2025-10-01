#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
int n, m;
int parent[100001];
const int IFN = 1e7;
const int maxn = 1e6;
vector<pair<int, int>> adj[maxn];
void input()
{
	cin >> n >> m;
	while (n--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
}
int find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	freopen("bai5.in", "r", stdin);
	freopen("bai5.out", "w", stdout);
}