#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int binary_search(int n, int x, int a[])
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = floor((l + r) / 2);
		if (x >= a[mid])
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return r + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("bai4.in", "w", stdin);
	freopen("bai4.out", "r", stdout);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int day;
	cin >> day;
	int money[day];
	for (int i = 0; i < day; i++)
		cin >> money[i];
	sort(a, a + n);
	for (int i = 0; i < day; i++)
	{
		int ket = binary_search(n, money[i], a);
		cout << ket << endl;
	}
}