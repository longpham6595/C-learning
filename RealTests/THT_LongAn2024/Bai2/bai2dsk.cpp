#include <bits/stdc++.h>
using namespace std;

// Binary search ở mức độ phức tạp hơn
int main()
{
    ifstream cin("BUS.INP");
    ofstream cout("BUS.OUT");
    int N, k;
    cin >> N >> k;
    vector<int> x(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];

    int left = 0, right = x.back() - x[0];
    int Y = right;

    auto check = [&](int D) { // Capture [&] để truy cập biến x
        int count = 0, current = 0;
        while (current < N)
        {
            count++;
            if (count > k)
                return false; // Tối ưu: dừng sớm nếu vượt k

            int target = x[current] + D;
            auto it = upper_bound(x.begin() + current, x.end(), target);
            int j = it - x.begin() - 1;

            // Kiểm tra j có hợp lệ không
            if (j < current)
                j = current; // Tránh trường hợp không tìm thấy
            current = upper_bound(x.begin() + j, x.end(), x[j] + D) - x.begin();
        }
        return count <= k;
    };

    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (check(mid))
        {
            Y = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << Y << endl;
    return 0;
}