#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_map<string, int> countMap;
    string s;

    for (int i = 0; i < 2 * N - 1; ++i)
    {
        cin >> s;
        countMap[s]++;
    }

    for (auto &pair : countMap)
    {
        if (pair.second % 2 != 0)
        {
            cout << pair.first << endl;
            break;
        }
    }

    return 0;
}