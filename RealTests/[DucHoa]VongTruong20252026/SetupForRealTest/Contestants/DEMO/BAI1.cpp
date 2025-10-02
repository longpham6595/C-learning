#include <bits/stdc++.h>
using namespace std;

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
long long t, a, b, c;
int main()
{
    fast_io;
    ifstream cin("bai1.in");
    ofstream cout("bai1.out");
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        cout << (((a == (b + c)) || (b == (a + c)) || (c == (a + b))) ? "YES" : "NO") << endl;
    }
    // getchar();
}