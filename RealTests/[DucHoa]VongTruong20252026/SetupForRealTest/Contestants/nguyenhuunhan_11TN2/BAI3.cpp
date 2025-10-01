#include <bits/stdc++.h>
using namespace std;

void prime(long long n, long long x){
	bool Isprime[n];
	Isprime[0]= false;
	Isprime[1]= false;
	for (int i = 2; i <= n; i++){
		Isprime[i]=true;
	}
	for (int i = 2; i < sqrt(n); i++) if(Isprime){
		for(int j = i; j < n; j++){
			if (j*i > n) break;
			Isprime[j*i]=false;
		}
	}
	for (int i = x; i <= n; i++){
		if (Isprime[i]){
			cout << i << endl;
		}
	}



int main(){
	freopen("bai3.in", "r", stdin);
	freopen("bai3.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++){
		long long x, y; cin >> x >> y;
		prime(y, x);
	}
}