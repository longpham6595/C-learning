#include <bits/stdc++.h>

using namespace std;
using ll= long long;
ll n, k, a[100000], cnt, best, worst;
string s;
int main(){
	cin >> n >> k;
	ll gido=n;
	ll tam=0;
	while(gido--){
		string temp;
		cin >> temp;
		a[tam]= temp.size();
		tam++;
	}
	cin >> s;
	ll temp= s.size();
	for(ll i=0;i<tam;i++){
		if(a[i] < temp){
			cnt++;
		}
	}
	ll temp2= cnt/k;
	ll best= cnt+ temp2*5 + 1;
	ll temp3= (n-1)/k;
	ll worst= temp3*5+n;
	cout << best << " " << worst;
}