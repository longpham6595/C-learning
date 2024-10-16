#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("bai2.in", "r", stdin);
	freopen("bai2.out", "w", stdout);
	long long n, x; cin >> n >> x;
	long long A[n];
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i=0; i < n; i++){
		for (int j = n; j >= 0; j--){
			if(A[i] + A[j] == x){
				cout << i+1 << " " << j+1;
				return 0;
			}
		}
	}
}