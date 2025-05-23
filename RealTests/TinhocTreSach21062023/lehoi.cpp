#include <bits/stdc++.h>
#include <vector>
// Policy-based data structures - Co the build indexed_set
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
using namespace std;
// Pre Definitions DATA TYPES
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
// Pre Definitions CONSTANTS
#define FT front()
#define BK back()
#define PF push_front
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MOD 1e9 + 7
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define uniq(x) x.erase(unique(all(x)), x.end());
#define sz(x) (ll)(x).size()
#define all_r(x) x.rbegin(), x.rend()
#define clr(a) memset((a), 0, sizeof(a))
#define rsz resize
#define ins insert
// Graph transitions
// vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
// vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// Return wherehter an array contains an element with value x
#define FIND_X(vec, x) lower_bound(vec.begin(), vec.end(), x) - vec.begin();
// Return wherehter an array contains an element with value x return upper bound of item x
#define FIND_UB_X(vec, x) upper_bound(vec.begin(), vec.end(), x) - vec.begin();
// SPEED UP
#pragma GCC optimize("O3") // how good is this? lol
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
// Operations on bits
#define popcnt(x) __builtin_popcount(x)
#define popcntll(x) __builtin_popcountll(x)
#define trailz(x) __builtin_ctz(x)
#define trailzll(x) __builtin_ctzll(x)
#define leadz(x) __builtin_clz(x) // REMEMBER THE X SHOULD BE UNSIGNED
#define leadzll(x) __builtin_clzll(x)
#define oddparity(x) __builtin_parity(x)
// Define common use loops and functions
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPLL(i, a, b) for (ll i = a; i < b; i++)
#define SQ(a) (a) * (a);
#define output_all_vec(x)              \
    for (int i = 0; i < x.size(); i++) \
        cout << x[i] << " ";           \
    cout << endl;
// Some common templates
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v)
{
    for (auto &i : v)
        os << i << ' ';
    return os;
}
template <typename T, size_t sz>
istream &operator>>(istream &is, array<T, sz> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T, size_t sz>
ostream &operator<<(ostream &os, array<T, sz> v)
{
    for (auto &i : v)
        os << i << ' ';
    return os;
}
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using MaxHeap = priority_queue<T, vector<T>, less<T>>;
template <typename I>
struct _reversed_struct
{
    I &v_;
    explicit _reversed_struct(I &v) : v_{v} {}
    typename I::reverse_iterator begin() const { return v_.rbegin(); }
    typename I::reverse_iterator end() const { return v_.rend(); }
};
template <typename I>
_reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
template <typename T>
void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T>
void ckmax(T &a, const T &b) { a = max(a, b); }
template <typename T, typename P>
T cceil(const T &a, const P &b)
{
    ll x = a, y = b;
    return (x + y - 1) / y;
}
//============================================================================
// START PROGRAM
//============================================================================
long long n;
string s;
unordered_map<long long, set<long long>> umap;
int main()
{
    fast_io;
    cin >> n >> s;

    for (long long i = 0; i < n; i++)
        umap[s[i]].insert(i);

    if (umap.size() < 6)
        cout << 0;
    else
    {
        long long res = 1;

        // First round from beginning
        long long item_first = 0;
        long long item_last = s.size() - 1;
        while (umap[s[item_first]].size() > 1)
        {
            umap[s[item_first]].erase(item_first);
            item_first++;
            res++;
            // cout << res << " - " << item_first << " " << s[item_first] << " \n";
            // cout << "While 0 -> RES: " << res << " -> " << item_first << " " << item_last << "\n";
            // for (int i = item_first; i <= item_last; i++)
            //     cout << s[i];
            // cout << endl;
        }
        // Second round from ending

        while (item_first > 0 || umap[s[item_last]].size() > 1)
        {
            while (umap[s[item_last]].size() == 1)
            {
                item_first--;
                if (s[item_first] != s[item_last] || item_last != s.size()-1)
                    res++;
                umap[s[item_first]].insert(item_first);
                // cout << "While 1 -> RES: " << res << " -> " << item_first << " " << item_last << "\n";
                // for (int i = item_first; i <= item_last; i++)
                //     cout << s[i];
                // cout << endl;
            }

            while (umap[s[item_last]].size() > 1)
            {
                umap[s[item_last]].erase(item_last);
                item_last--;
                res++;
                // cout << "While 2 -> RES: " << res << " -> " << item_first << " " << item_last << "\n";
                // for (int i = item_first; i <= item_last; i++)
                //     cout << s[i];
                // cout << endl;
            }
        }
        cout << res;
    }

    // getchar();
}