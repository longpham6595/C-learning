#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+1;
int main()
{
	freopen("bai2.in", "r", stdin);
	freopen("bai2.out", "w", stdout);
	cin.tie(NULL) -> sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	int a[n], b[n];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		b[i] = a[i];
	bool valid = false;
	int l = 1, r = n;
	int vti = -1, vtj = -1;
	sort(a + 1, a + n + 1);
	while(l < r)
	{
		if(a[l] + a[r] >= x)
		{
			if(a[l] + a[r] == x)
			{
				vti = l;
				vtj = r;
				valid = true;
			}
			r--;
		}
		else l++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[vti] == b[i]) vti = i;
		if(a[vtj] == b[i]) vtj = i;
		
	}
	if(valid)
		cout << vti << " " << vtj; 
	else
		cout << "IMPOSSIBLE";    
}
	