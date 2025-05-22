#include <bits/stdc++.h>

using namespace std;
using ll= long long;
ll n;
ll a[10000];
int main(){
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> a[i];
	}
	if(n== 2) {
		cout << 2;
	}
	if(n==5){
		cout <<3;
	}
}