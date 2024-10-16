#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll q;
int main() {
	freopen("bai1.in","r",stdin);
	freopen("bai1.out","w",stdout);
    cin >> q;

    while (q--) {
        int k;

        cin >> k;

        string s;
        int number = 1;

        while (s.length() < k) {
            s += to_string(number);
            number++;
        }

        char res = s[k - 1];
        cout << res << endl;
    }

    
}
