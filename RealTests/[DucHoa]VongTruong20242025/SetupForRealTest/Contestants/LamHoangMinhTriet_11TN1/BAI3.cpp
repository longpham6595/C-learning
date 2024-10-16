#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll t;
void erathos(ll limit, vector<ll>& primes) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false; 

    for (ll i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void erathos2(ll l, ll r) {
    if (r < 2) return; 
    if (l < 2) l = 2;

    ll limit = sqrt(r);
    vector<ll> primes;
    erathos(limit, primes);

    vector<bool> newprime(r - l + 1, true);

    for (ll p : primes) {

        ll start = max(p * p, (l + p - 1) / p * p);

        for (ll j = start; j <= r; j += p) {
            if (j >= l) {
                newprime[j - l] = false;
            }
        }
    }

    for (ll i = l; i <= r; i++) {
        if (newprime[i - l]) {
            cout << i << '\n';
        }
    }
}

int main() {
	freopen("bai3.in", "r", stdin);
	freopen("bai3.out", "w", stdout);
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		erathos2(a,b);
	}
    

}
