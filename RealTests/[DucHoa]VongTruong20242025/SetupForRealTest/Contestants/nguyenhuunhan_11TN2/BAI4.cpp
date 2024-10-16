#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("bai4.in", "r", stdin);
	freopen("bai4.out", "w", stdout);
	int n, q, a;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	cin >> q;
	int B[q];
	for (int i = 0; i < q; i++){
		cin >> B[i];
	}
	for(int i = 0; i < q; i++){
		for (int j = 0; j < n; j++){
			if(A[j] <= B[i]){
				a+=1;
			}
		}
		cout << a << endl;
		a=0;
	}
}