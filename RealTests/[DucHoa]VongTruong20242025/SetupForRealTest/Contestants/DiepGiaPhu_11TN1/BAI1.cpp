#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("bai1.in", "r", stdin);
	freopen("bai1.out", "w", stdout);
	string s;
	for (int i = 1; i < 10000000; i++)
	{
		s += to_string(i);
	}
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		cout << s[x - 1] << endl;
	}
	return 0;
}