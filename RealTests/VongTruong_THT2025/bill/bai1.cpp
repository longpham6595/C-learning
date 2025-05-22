#include <bits/stdc++.h>

using namespace std;

using ll= long long;

ll t;
ll check(ll k, ll a, ll b, ll c) {
	ll s = 0;
	if(a > k) s += a - k;
	if(b > k) s += b - k;
	if(c > k) s += c - k;
	return s;
}

int main() {
	cin >> t;

	while(t--) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll tong= a + b + c;
		ll bien= (tong - 3)/6;

		if(bien < 1) {
			cout << "NO" << endl;
			continue;
		}

		ll left = 1, right = bien, res = -1;
		while(left <= right) {
			ll mid= (left + right) / 2;
			ll temp= check(mid, a, b, c);
			if(temp<= 6*mid) {
				res= mid;
				right= mid - 1;
			} else {
				left= mid + 1;
			}
		}

		if(res != -1){
			cout << "YES" << endl;
		}	
		else
			cout << "NO" << endl;
	}
}
