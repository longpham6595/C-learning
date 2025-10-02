#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#include <algorithm>

// Sử dụng namespace std để code ngắn gọn hơn
using namespace std;

// Hằng số cho giá trị tối đa của c_i, cộng thêm một chút để tránh lỗi tràn chỉ số
const int C_MAX = 200005;

int main()
{
    // Tăng tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("bai5.in");
    ofstream cout("bai5.out");
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long y;
        cin >> n >> y;

        // Sử dụng vector để tự động quản lý bộ nhớ và tránh lỗi giữa các test case
        vector<long long> count(C_MAX, 0);
        int max_c = 0;
        for (int i = 0; i < n; ++i)
        {
            int c;
            cin >> c;
            count[c]++;
            max_c = max(max_c, c);
        }

        // Tính mảng tổng tiền tố (prefix sum) để tính nhanh số lượng trong một khoảng
        vector<long long> prefix_count(C_MAX, 0);
        prefix_count[0] = count[0];
        for (int i = 1; i < C_MAX; ++i)
        {
            prefix_count[i] = prefix_count[i - 1] + count[i];
        }

        // Hàm lambda để tính số lượng phần tử trong khoảng [a, b-1]
        auto range_count = [&](int a, int b) -> long long
        {
            if (a >= b)
                return 0;
            int end = min(b - 1, C_MAX - 1);
            int start = a;
            if (start > end)
                return 0;
            if (start == 0)
                return prefix_count[end];
            return prefix_count[end] - prefix_count[start - 1];
        };

        // Chuẩn bị các mảng để tính nhanh tổng giá trị mới
        // ceil(c/x) = floor((c-1)/x) + 1
        // Ta sẽ tính sum(floor((c_i-1)/x))
        vector<long long> count_prime(C_MAX, 0);
        for (int i = 0; i < C_MAX - 1; ++i)
        {
            count_prime[i] = count[i + 1];
        }

        // Mảng tổng hậu tố (suffix sum) của count_prime
        vector<long long> ge_count_prime(C_MAX, 0);
        for (int i = C_MAX - 2; i >= 0; --i)
        {
            ge_count_prime[i] = ge_count_prime[i + 1] + count_prime[i];
        }

        // Khởi tạo doanh thu tối đa với một giá trị rất nhỏ
        long long max_income = -4e18;

        // Duyệt qua các giá trị của x từ 2 đến C_MAX
        for (long long x = 2; x <= max_c + 1; ++x)
        {
            // 1. Tính tổng giá trị mới của tất cả các mặt hàng
            long long sum_floor_prime = 0;
            for (long long j = 1; j * x < C_MAX; ++j)
            {
                sum_floor_prime += ge_count_prime[j * x];
            }
            long long total_new_value = n + sum_floor_prime;

            // 2. Tính số lượng tem giá có thể tái sử dụng
            long long reused_tags = 0;
            // Giá mới p = ceil(c/x) <=> (p-1)*x < c <= p*x
            for (long long p = 1; (p - 1) * x < C_MAX; ++p)
            {
                // Số lượng mặt hàng có giá mới là p
                long long num_new_p = range_count((p - 1) * x + 1, p * x + 1);
                if (num_new_p == 0)
                    continue;

                // Số lượng mặt hàng có giá ban đầu là p
                long long num_old_p = (p < C_MAX) ? count[p] : 0;

                reused_tags += min(num_new_p, num_old_p);
            }

            // 3. Tính doanh thu hiện tại và cập nhật doanh thu tối đa
            long long current_income = total_new_value - (n - reused_tags) * y;
            max_income = max(max_income, current_income);
        }

        cout << max_income << endl;
    }
}
