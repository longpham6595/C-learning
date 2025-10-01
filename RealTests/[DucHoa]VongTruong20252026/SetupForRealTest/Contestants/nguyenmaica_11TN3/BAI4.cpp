#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bai4.in", "r", stdin);
	freopen("bai4.out", "w", stdout);
	long n, x, q, m;
	cin >> n;
	int a[n];
	for (int &x : a)
	{
		cin >> x;
	}
	cin >> q;
	while (q--)
	{
		cin >> m;
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			if (m >= a[i])
			{
				c += 1;
			}
		}
		cout << c << endl;
	}
}