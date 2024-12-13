#include <iostream>
#include <vector>

using namespace std;

class FenwickTree
{
    vector<int> bit, data;
    int n;

    void update(int idx, int delta)
    {
        while (idx <= n)
        {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) const
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

public:
    FenwickTree(int size) : n(size)
    {
        bit.assign(n + 1, 0);
        data.assign(n + 1, 0);
    }

    FenwickTree(const vector<int> &a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] == 1)
            {
                update(i + 1, 1);
                data[i + 1] = 1;
            }
        }
    }

    void rangeUpdate(int l, int r)
    {
        for (int i = l; i <= r; ++i)
        {
            if (data[i] == 1)
            {
                update(i, -1); // If it's 1, flip to 0
                data[i] = 0;
            }
            else
            {
                update(i, 1); // If it's 0, flip to 1
                data[i] = 1;
            }
        }
    }

    int rangeQuery(int l, int r) const
    {
        return query(r) - query(l - 1);
    }

    void checkBIT() const
    {
        cout << "BIT: ";
        for (auto it : bit)
        {
            cout << it << " ";
        }
        cout << "\nData: ";
        for (auto it : data)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
};

int main()
{
    vector<int> a = {1, 0, 1, 0, 1}; // Initial state of bits
    FenwickTree ft(a);

    ft.checkBIT(); // Initial state of BIT

    cout << "Sum of range [1, 4]: " << ft.rangeQuery(1, 4) << endl; // Before update

    ft.rangeUpdate(1, 3); // Range update [1, 3] to flip bits

    cout << "Sum of range [1, 4]: " << ft.rangeQuery(1, 4) << endl; // After update

    ft.checkBIT(); // State of BIT after update

    return 0;
}
