#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> a(N);
    ll total_sum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        total_sum += a[i];
    }

    // Tìm tổng nhỏ nhất của một đoạn (sum_min_single)
    ll current_min = a[0];
    ll min_single = current_min;
    ll sum = current_min;
    for (int i = 1; i < N; ++i)
    {
        sum = min(a[i], sum + a[i]);
        current_min = min(current_min, sum);
        min_single = min(min_single, current_min);
    }

    // Tính left_min: tổng nhỏ nhất từ đầu đến vị trí i
    vector<ll> left_min(N);
    current_min = a[0];
    left_min[0] = current_min;
    sum = current_min;
    for (int i = 1; i < N; ++i)
    {
        sum = min(a[i], sum + a[i]);
        left_min[i] = min(left_min[i - 1], sum);
    }

    // Tính right_min: tổng nhỏ nhất từ vị trí i đến cuối
    vector<ll> right_min(N);
    current_min = a[N - 1];
    right_min[N - 1] = current_min;
    sum = current_min;
    for (int i = N - 2; i >= 0; --i)
    {
        sum = min(a[i], sum + a[i]);
        right_min[i] = min(right_min[i + 1], sum);
    }

    // Tìm tổng nhỏ nhất của hai đoạn không giao nhau (sum_min_double)
    ll min_double = LLONG_MAX;
    for (int i = 0; i < N - 1; ++i)
    {
        ll current = left_min[i] + right_min[i + 1];
        if (current < min_double)
        {
            min_double = current;
        }
    }

    // Tính các giá trị delta
    ll delta1 = (min_single < 0) ? (-2 * min_single) : 0;
    ll delta2 = (min_double < 0) ? (-2 * min_double) : 0;
    ll best = max({delta1, delta2, 0LL});

    // Kết quả là tổng ban đầu cộng với delta lớn nhất
    cout << (a[0] == -1 && N == 1 ? -1 : total_sum + best) << endl;

    return 0;
}