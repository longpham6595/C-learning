#include <bits/stdc++.h>

using namespace std;
#define mx 100005
#define ll long long
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mem(a) memset(a, 0, sizeof(a))
// int arr[mx];
int tree[mx * 3];
int lazy[mx * 3];
// int carry;

int query(int node, int b, int e, int i, int j)
{
    // cout<<"query= "<<carry<<endl;
    if (b > j || e < i)
        return 0;

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    if (lazy[node] == 1)
    {

        tree[node] = (e - b + 1) - tree[node]; // updating tree

        if (b != e)
        {
            lazy[Left] = 1 - lazy[Left];

            lazy[Right] = 1 - lazy[Right];
        }

        lazy[node] = 0;
    }

    if (b >= i && e <= j)
        return tree[node];
    int x = query(Left, b, mid, i, j);
    int y = query(Right, mid + 1, e, i, j);
    return x + y;
}

void update(int node, int b, int e, int i, int j)
{
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    if (lazy[node] == 1)
    {
        tree[node] = (e - b + 1) - tree[node];

        if (b != e)
        {

            lazy[Left] = 1 - lazy[Left];
            lazy[Right] = 1 - lazy[Right];
        }
        lazy[node] = 0;
    }

    if (b > j || e < i)
        return;

    if (b >= i && e <= j)
    {
        tree[node] = (e - b + 1) - tree[node];
        // cout<<"node = "<<node<<" "<<tree[node]<<endl;
        if (b != e)
        {

            lazy[Left] = 1 - lazy[Left];
            lazy[Right] = 1 - lazy[Right];
        }
        return;
    }

    update(Left, b, mid, i, j);
    update(Right, mid + 1, e, i, j);

    tree[node] = tree[Left] + tree[Right];
}

int main()
{
    // ios::sync_with_stdio(false);
    int n, m;
    scanf("%d%d", &n, &m);

    while (m--)
    {
        int t;
        scanf("%d", &t);

        if (t == 1)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            i++, j++;
            int d = query(1, 1, n, i, j);

            printf("%d\n", d);
        }

        else
        {
            int i, j;
            scanf("%d%d", &i, &j);
            i++, j++;
            update(1, 1, n, i, j);
        }
    }

    return 0;
}