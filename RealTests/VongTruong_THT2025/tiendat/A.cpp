#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define el '\n'

int main() {
    cin.tie(0) -> sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c == 9) {
			cout << "YES" << el;
		}
		else {
			cout << "NO" << el;
		}
	}
}