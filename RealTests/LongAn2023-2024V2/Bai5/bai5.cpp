#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sử dụng một số lớn để đại diện cho âm vô cùng
const long long INF = 1e18;

// Cấu trúc cho ma trận 2x2
struct Matrix
{
    long long mat[2][2];

    Matrix()
    {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = -INF;
    }
};

// Hàm nhân hai ma trận trong đại số (max, +)
Matrix multiply(Matrix A, Matrix B)
{
    Matrix C;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // C[i][j] = max(A[i][k] + B[k][j])
            for (int k = 0; k < 2; k++)
            {
                if (A.mat[i][k] != -INF && B.mat[k][j] != -INF)
                {
                    C.mat[i][j] = max(C.mat[i][j], A.mat[i][k] + B.mat[k][j]);
                }
            }
        }
    }
    return C;
}

int N, D;
vector<long long> M; // Mảng lưu công suất các lò nướng
vector<Matrix> tree; // Cây phân đoạn

// Hàm xây dựng cây phân đoạn
// node: chỉ số của nút hiện tại trong mảng tree
// start, end: đoạn [start, end] mà nút quản lý
void build(int node, int start, int end)
{
    if (start == end)
    {
        // Nút lá: lưu ma trận chuyển T_i
        tree[node].mat[0][0] = 0;
        tree[node].mat[0][1] = 0;
        tree[node].mat[1][0] = M[start];
        tree[node].mat[1][1] = -INF;
    }
    else
    {
        int mid = start + (end - start) / 2;
        // Xây dựng cây cho con trái và con phải
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        // Nút trong: là tích của hai nút con
        // Thứ tự nhân quan trọng: T_{right} * T_{left}
        tree[node] = multiply(tree[2 * node + 1], tree[2 * node]);
    }
}

// Hàm cập nhật một giá trị trên cây
// idx: vị trí lò nướng cần cập nhật
// val: giá trị công suất mới
void update(int node, int start, int end, int idx, long long val)
{
    if (start == end)
    {
        // Đã đến nút lá cần cập nhật
        M[idx] = val;
        tree[node].mat[0][0] = 0;
        tree[node].mat[0][1] = 0;
        tree[node].mat[1][0] = M[idx];
        tree[node].mat[1][1] = -INF;
    }
    else
    {
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid)
        {
            // Cập nhật ở cây con trái
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            // Cập nhật ở cây con phải
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        // Cập nhật lại nút cha
        tree[node] = multiply(tree[2 * node + 1], tree[2 * node]);
    }
}

void solve()
{
    // Đọc dữ liệu đầu vào
    cin >> N >> D;
    M.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> M[i];
    }

    // Khởi tạo cây phân đoạn
    tree.resize(4 * N + 4);
    build(1, 1, N);

    long long total_cakes = 0;

    // Vòng lặp qua D ngày
    for (int day = 0; day < D; ++day)
    {
        int k;
        long long c;
        cin >> k >> c;

        // Cập nhật công suất lò k thành c trên cây
        update(1, 1, N, k, c);

        // Ma trận chuyển tổng hợp nằm ở gốc của cây
        Matrix total_transform = tree[1];

        // Vector trạng thái ban đầu V_0 = [0, 0]^T
        // Tính vector trạng thái cuối cùng V_N = total_transform * V_0
        long long dp_N_0 = max(total_transform.mat[0][0], total_transform.mat[0][1]);
        long long dp_N_1 = max(total_transform.mat[1][0], total_transform.mat[1][1]);

        // Kết quả của ngày là giá trị lớn nhất trong vector trạng thái cuối cùng
        total_cakes += max(dp_N_0, dp_N_1);
    }

    cout << total_cakes << endl;
}

int main()
{
    // Tăng tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Mở file để đọc và ghi (nếu nộp bài)
    // freopen("MOONCAKE.INP", "r", stdin);
    // freopen("MOONCAKE.OUT", "w", stdout);

    solve();

    return 0;
}
