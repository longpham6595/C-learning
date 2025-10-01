#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("bai2.in", "r", stdin);
	freopen("bai2.out", "w", stdout);
	int n;
	ll x;
	cin >> n >> x;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int i = 1, j = n;
	while (i != j)
	{
		if (a[i] + a[j] > x)
		{
			// cout<<a[i]<<" "<<a[j]<<endl;
			--j;
		}
		if (a[i] + a[j] < x)
		{
			//	cout<<a[i]<<" "<<a[j]<<endl;
			++i;
		}
		if (a[i] + a[j] == x)
		{
			cout << i << " " << j;
			break;
		}
	}
	if (i == j)
		cout << "IMPOSSIBLE";
}