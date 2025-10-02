import os
import random

# --- CẤU HÌNH ---
# Đường dẫn đầy đủ đến thư mục TestCases
TEST_DIR = r"D:\HSG\C-learning\RealTests\[DucHoa]VongTruong20252026\Bai4\TestCases"
# Số lượng file test case muốn sinh ra
NUM_FILES_TO_GENERATE = 40

# --- RÀNG BUỘC CỦA BÀI TOÁN ---
T_MAX = 20  # Giới hạn số test trong 1 file để không quá lớn
N_MIN, N_MAX = 1, 100
VAL_MIN, VAL_MAX = 1, 1000
MOD = 998244353

def solve(n, a, b):
    """
    Giải bài toán bằng phương pháp Quy hoạch động để tạo file output.
    """
    mins = [0] * n
    maxs = [0] * n
    for i in range(n):
        if a[i] < b[i]:
            mins[i], maxs[i] = a[i], b[i]
        else:
            mins[i], maxs[i] = b[i], a[i]

    # Kiểm tra điều kiện cần: mảng các min và max phải được sắp xếp
    for i in range(n - 1):
        if mins[i] > mins[i+1] or maxs[i] > maxs[i+1]:
            return 0
    
    # dp[i][0]: số cách xếp đến vị trí i, kết thúc bằng cặp (min_i, max_i)
    # dp[i][1]: số cách xếp đến vị trí i, kết thúc bằng cặp (max_i, min_i)
    dp = [[0, 0] for _ in range(n)]

    # Khởi tạo cho vị trí đầu tiên
    dp[0][0] = 1
    if mins[0] != maxs[0]:
        dp[0][1] = 1
    else:
        dp[0][1] = 0

    for i in range(1, n):
        min_prev, max_prev = mins[i-1], maxs[i-1]
        min_curr, max_curr = mins[i], maxs[i]
        
        # Tính dp[i][0] - kết thúc bằng (min_curr, max_curr)
        ways = 0
        if min_prev <= min_curr and max_prev <= max_curr:
            ways = (ways + dp[i-1][0]) % MOD
        if max_prev <= min_curr and min_prev <= max_curr:
            ways = (ways + dp[i-1][1]) % MOD
        dp[i][0] = ways

        # Tính dp[i][1] - kết thúc bằng (max_curr, min_curr)
        if min_curr != max_curr:
            ways = 0
            if min_prev <= max_curr and max_prev <= min_curr:
                 ways = (ways + dp[i-1][0]) % MOD
            if max_prev <= max_curr and min_prev <= min_curr:
                 ways = (ways + dp[i-1][1]) % MOD
            dp[i][1] = ways
            
    return (dp[n-1][0] + dp[n-1][1]) % MOD

def generate_guaranteed_yes_case(n):
    """Tạo test case chắc chắn có đáp án."""
    mins = sorted([random.randint(VAL_MIN, VAL_MAX) for _ in range(n)])
    maxs = sorted([random.randint(mins[i], VAL_MAX) for i in range(n)])
    
    a, b = [0] * n, [0] * n
    for i in range(n):
        if random.choice([True, False]):
            a[i], b[i] = mins[i], maxs[i]
        else:
            a[i], b[i] = maxs[i], mins[i]
    return n, a, b

def generate_guaranteed_no_case(n):
    """Tạo test case chắc chắn không có đáp án."""
    a = sorted([random.randint(VAL_MIN, VAL_MAX) for _ in range(n)])
    b = sorted([random.randint(VAL_MIN, VAL_MAX) for _ in range(n)])
    # Phá vỡ điều kiện cần
    if n > 1:
        idx = random.randint(0, n - 2)
        if random.choice([True,False]):
            a[idx], a[idx+1] = a[idx+1], a[idx] # Phá tính sắp xếp
        else:
            b[idx], b[idx+1] = b[idx+1], b[idx]

    return n, a, b

def generate_random_case(n):
    """Tạo test case hoàn toàn ngẫu nhiên."""
    a = [random.randint(VAL_MIN, VAL_MAX) for _ in range(n)]
    b = [random.randint(VAL_MIN, VAL_MAX) for _ in range(n)]
    return n, a, b

def main():
    os.makedirs(TEST_DIR, exist_ok=True)
    print(f"Các test case sẽ được lưu vào: '{TEST_DIR}'")
    
    for i in range(1, NUM_FILES_TO_GENERATE + 1):
        in_path = os.path.join(TEST_DIR, f"{i}.in")
        out_path = os.path.join(TEST_DIR, f"{i}.out")
        
        num_tests = random.randint(1, T_MAX)
        
        with open(in_path, 'w') as f_in, open(out_path, 'w') as f_out:
            f_in.write(f"{num_tests}\n")
            
            for j in range(num_tests):
                n = random.randint(N_MIN, N_MAX)
                
                # Chọn loại test case để sinh
                case_type = random.random()
                if i <= 5: # Mấy file đầu ưu tiên case đặc biệt
                    if case_type < 0.7:
                        n_case, a, b = generate_guaranteed_yes_case(n)
                    else:
                        n_case, a, b = generate_guaranteed_no_case(n)
                else: # Các file sau ngẫu nhiên hơn
                     n_case, a, b = generate_random_case(n)

                # Ghi vào file .in
                f_in.write(f"{n_case}\n")
                f_in.write(" ".join(map(str, a)) + "\n")
                f_in.write(" ".join(map(str, b)) + "\n")

                # Giải và ghi vào file .out
                result = solve(n_case, a, b)
                f_out.write(f"{result}\n")
                
        print(f" -> Đã tạo file test: {i}.in / {i}.out")
        
    print(f"\nHoàn tất! Đã sinh {NUM_FILES_TO_GENERATE} bộ test case.")

if __name__ == "__main__":
    main()

