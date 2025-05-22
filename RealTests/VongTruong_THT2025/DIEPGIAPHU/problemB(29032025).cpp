#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el endl
int num[101];
pair<int,int> chuoi[101];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	 int n,k; cin>>n>>k;
	 string s,pass;
	 for(int i=1;i<=n;i++){
	 	cin>>s;
	 	num[i]=s.length();
		}
	cin>>pass;
	int temp=pass.length();
	sort(num+1,num+n+1);
	int last = num[0];
	for(int i=1;i<=n;i++){
	if(last!=num[i]) chuoi[num[i]].first=i;
	if(chuoi[num[i]].first!=0) chuoi[num[i]].second=i;
	last=num[i];
	}
	int res=(chuoi[temp].first/k)*5+(chuoi[temp].first);
	int res2=(chuoi[temp].second/k)*5+(chuoi[temp].second);
	cout<<res<<" "<<res2;
	}