#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("bai1.in", "r", stdin);
	freopen("bai1.out", "w", stdout);
	cin.tie(0) -> ios_base::sync_with_stdio(false);
	
	vector<ll> powerOfTen(19, 1);
	for (int i = 1; i < 19; i++) {
		powerOfTen[i] = powerOfTen[i - 1] * 10;
	}
	int q; 
	cin >> q;
	while (q--) {
		ll k; 
		cin >> k;
		ll digitsBeforeActualBlock = 0;
		ll digitsSoFar = 0;
		int numberOfDigits = 0;
		for (int i = 1; i <= 18; i++) {
			digitsSoFar += (powerOfTen[i] - powerOfTen[i - 1]) * i;
			if (digitsSoFar >= k) {
				numberOfDigits = i;
				break;
			}
			digitsBeforeActualBlock += (powerOfTen[i] - powerOfTen[i - 1]) * i;
		}
		ll low = powerOfTen[numberOfDigits - 1];
		ll high = powerOfTen[numberOfDigits] - 1;
		ll posOfBestValue = 0;
		ll bestValue = 0;
		while (low < high) {
			ll actualValue = (low + high) / 2;
			ll posOfActualValue = digitsBeforeActualBlock + 1 + (actualValue - powerOfTen[numberOfDigits - 1]) * numberOfDigits;
			if (posOfActualValue <= k) {
				if (actualValue > bestValue) {
					bestValue = actualValue;
					posOfBestValue = posOfActualValue;
				}
				low = posOfActualValue + 1;
			} else {
				high = posOfActualValue - 1;
			}
		}
		string number = to_string(bestValue);
		cout << number[k - posOfBestValue] << '\n';
	}
}