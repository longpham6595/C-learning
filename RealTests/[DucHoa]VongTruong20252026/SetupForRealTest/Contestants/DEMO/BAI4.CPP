#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, dp[110][2], a[110], b[110];

signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ifstream cin("bai4.in");
	ofstream cout("bai4.out");
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] >= a[i - 1] && b[i] >= b[i - 1])
				dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
			if (a[i] >= a[i - 1] && b[i] >= b[i - 1])
				dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
			if (b[i] >= a[i - 1] && a[i] >= b[i - 1])
				dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
			if (b[i] >= a[i - 1] && a[i] >= b[i - 1])
				dp[i][0] = (dp[i][0] + dp[i - 1][1]) % mod;
		}
		cout << (dp[n][0] + dp[n][1]) % mod << '\n';
	}
}