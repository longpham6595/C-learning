#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,a[100008],q;
ll binary(ll temp){

    ll l= 0, r= n-1;
    while(l<=r){
        ll mid = l+(r-l)/2;
 		 if(a[mid] <= temp){
            l=mid+1;
        }
        else   
        	r=mid-1;
    }

    return l;

}
int main(){
	freopen("bai4.in", "r", stdin);
	freopen("bai4.out", "w", stdout);
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> a[i];
	}
	cin >> q;
	while(q--){
		ll x;
		cin >> x;
		ll res=binary(x);
		cout << res << '\n';
	}
	
	
}