#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el endl
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll t,a,b,c,sum;cin>>t;
	while(t--){
		cin>>a>>b>>c;
		ll sum=a+b+c;
		if(sum==9){
		cout<<"YES"<<el;
		continue;
	}
		if(sum%9==0 and a!=1 and b!=1 and c!=1) cout<<"YES"<<el;
		else cout<<"NO"<<el;
	}
}