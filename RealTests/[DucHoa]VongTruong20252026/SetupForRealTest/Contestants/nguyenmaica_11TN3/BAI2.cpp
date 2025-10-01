#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bai2.in", "r", stdin);
	freopen("bai2.out", "w", stdout);
	long n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] + a[j] == x)
			{
				c += 1;
			}
		}
	}
	if (c == 0)
		cout << "IMPOSSIBLE";
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (a[i] + a[j] == x)
				{
					cout << j + 1 << " " << i + 1;
					break;
				}
			}
		}
	}
}