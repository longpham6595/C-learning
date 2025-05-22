#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el endl
int num[1000001];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	 int n; cin>>n;
	 int res=0;
	 num[0]=-1;
	 int cnt=0;
	 for(int i=1;i<=n;i++){
	 cin>>num[i];
	 if(num[i]==0) res++;
	 else if(num[num[i]]==0) {
	 cnt++; num[num[i]]=1;
	}
}
	if(cnt!=0) cout<<res+(n-cnt*2);
	else cout<<res;
}
