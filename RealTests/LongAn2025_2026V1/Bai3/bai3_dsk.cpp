#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> boxes(N);
    for (auto &box : boxes)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        box = {a, b};
    }

    sort(boxes.begin(), boxes.end(), [](const auto &x, const auto &y)
         {
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second; });

    for (auto &box : boxes)
        cout << box.first << " " << box.second << "\n";

    vector<int> lis;
    for (const auto &box : boxes)
    {
        int h = box.second;
        auto it = lower_bound(lis.begin(), lis.end(), h);
        if (it == lis.end())
        {
            lis.push_back(h);
        }
        else
        {
            *it = h;
        }
        cout << "TEST: ";
        for (auto it : lis)
            cout
                << it << " ";
        cout << "\n";
    }

    cout << lis.size() << "\n";
    return 0;
}