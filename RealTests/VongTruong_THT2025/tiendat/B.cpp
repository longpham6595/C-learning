#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define el '\n'

int main() {
    cin.tie(0) -> sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	map<int,int> mp;
	set<string> se;
	string correct;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[(int)s.size()]++;
	}
	cin >> correct;
	
	int best = 0, worst = 0;
	for (auto it : mp) {
		if (it.first == (int)correct.size()) {
			best++;
		}
		else {
			best += it.second;
		}
		worst += it.second;
	}
	worst += (worst - 1) / k * 5;
	cout << best << ' ' << worst;
}