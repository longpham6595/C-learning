#include <bits/stdc++.h>
using namespace std;
void nt(long a)
{
	int c = 0;
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			c += 1;
		}
	}
	if (c == 0)
	{
		cout << a << endl;
	}
}
int main()
{
	freopen("bai3.in", "r", stdin);
	freopen("bai3.out", "w", stdout);
	int TC;
	cin >> TC;
	while (TC--)
	{
		long a, b;
		cin >> a >> b;

		for (a; a <= b; a++)
		{
			nt(a);
		}
	}
}