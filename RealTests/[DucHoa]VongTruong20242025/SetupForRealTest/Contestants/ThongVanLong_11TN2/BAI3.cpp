#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> prime;
int sum;
void sieve(int L, int R)
{
	prime.assign(R - L + 1, true);
	for(int i = 2; i <= R; i++)
		for(int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
			prime[j - L] = false;
	if(1 >= L)
		prime[1 - L] = false;
	for(int x = L; x <= R; x++)
		if(prime[x - L])
			cout << x << "\n";
}
int main()
{
	freopen("bai3.in", "r", stdin);
	freopen("bai3.out", "w", stdout);
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t;
	while(t--)
	{
		int l , r;
		cin >> l >> r;
		sieve(l , r);
	}
}