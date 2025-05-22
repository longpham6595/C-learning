#include <bits/stdc++.h>
using namespace std;

// Tổ hợp và xử lý chẳn lẽ, nguyên lý trò chơi thuần
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Đọc dữ liệu từ file
    ifstream in("TROCHOI.INP");
    ofstream out("TROCHOI.OUT");

    int n;
    in >> n;
    vector<int> a(n);
    long long total_sum = 0;
    int even = 0, odd = 0;

    for (int i = 0; i < n; ++i)
    {
        in >> a[i];
        total_sum += a[i];
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    long long result = 0;
    if (total_sum % 2 == 0)
    {
        // Tổng chẵn: chọn 2 chẵn hoặc 2 lẻ
        result += (1LL * even * (even - 1)) / 2;
        result += (1LL * odd * (odd - 1)) / 2;
    }
    else
    {
        // Tổng lẻ: chọn 1 chẵn và 1 lẻ
        result = 1LL * even * odd;
    }

    out << result << "\n";

    in.close();
    out.close();
    return 0;
}