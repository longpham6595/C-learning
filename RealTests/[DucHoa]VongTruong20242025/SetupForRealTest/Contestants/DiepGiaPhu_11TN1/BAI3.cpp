#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e4 + 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool isprime[maxn];
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = 0, isprime[1] = 0;
	for (int i = 2; i <= maxn; i++)
	{
		if (isprime[i])
		{
			for (int j = i * i; j <= maxn; j += i)
			{
				isprime[j] = 0;
			}
		}
	}
	freopen("bai3.in", "r", stdin);
	freopen("bai3.out", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		for (int i = x; i <= y; i++)
		{
			if (isprime[i])
				cout << i << "\n";
		}
	}
	return 0;
}