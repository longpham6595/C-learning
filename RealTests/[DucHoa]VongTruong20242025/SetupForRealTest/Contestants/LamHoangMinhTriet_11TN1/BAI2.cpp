#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void find(ll a[], ll k, ll n) {


    ll left = 0; 
    ll right = n - 1; 

    while (left < right) {
        ll sum = a[left] + a[right];
        if (sum == k) {
            cout << left+1 <<  " "<<  right+1;
            return;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
	freopen("bai2.in","r",stdin);
	freopen("bai2.out","w", stdout);
    ll n, k;
    cin >> n >> k;
    ll a[n+7];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    find(a, k,n);

}
