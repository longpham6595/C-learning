# -*- coding: utf-8 -*-
import random
import os
import math
from collections import Counter
import time

# ===================================================================
# BỘ GIẢI BÀI TOÁN (SOLVER) - DỰA TRÊN THUẬT TOÁN C++ CỦA BẠN
# ===================================================================

def solve_from_cpp_logic(n, y, c_list):
    """
    Hàm giải mô phỏng thuật toán O(C_MAX * log(C_MAX)) từ code C++.
    Cực kỳ nhanh vì C_MAX được giới hạn.
    """
    if not c_list: return 0
    
    C_MAX = 200005
    count = [0] * C_MAX
    max_c = 0
    for c in c_list:
        if c < C_MAX:
            count[c] += 1
            max_c = max(max_c, c)

    prefix_count = [0] * C_MAX
    prefix_count[0] = count[0]
    for i in range(1, C_MAX):
        prefix_count[i] = prefix_count[i - 1] + count[i]

    def get_count_in_range(start, end): # Đếm số lượng trong khoảng [start, end]
        if start > end or start >= C_MAX: return 0
        end = min(end, C_MAX - 1)
        if start == 0: return prefix_count[end]
        return prefix_count[end] - prefix_count[start - 1]

    # Chuẩn bị cho việc tính doanh thu nhanh
    count_prime = [0] * C_MAX
    for i in range(C_MAX - 1): count_prime[i] = count[i + 1]
    
    ge_count_prime = [0] * C_MAX
    for i in range(C_MAX - 2, -1, -1):
        ge_count_prime[i] = ge_count_prime[i + 1] + count_prime[i]

    max_income = -float('inf')

    # Vòng lặp chính qua x, đây là phần O(C_MAX * log C_MAX)
    for x in range(2, max_c + 2):
        # 1. Tính doanh thu (Revenue)
        sum_floor_prime = 0
        j = 1
        while j * x < C_MAX:
            sum_floor_prime += ge_count_prime[j * x]
            j += 1
        total_new_value = n + sum_floor_prime

        # 2. Tính chi phí in tem (Cost)
        reused_tags = 0
        p = 1
        while (p - 1) * x < C_MAX:
            # Số lượng item có giá mới là p: ceil(c/x) = p <=> (p-1)*x < c <= p*x
            start_c = (p - 1) * x + 1
            end_c = p * x
            num_new_p = get_count_in_range(start_c, end_c)
            
            if num_new_p > 0:
                num_old_p = count[p] if p < C_MAX else 0
                reused_tags += min(num_new_p, num_old_p)
            p += 1
        
        # 3. Cập nhật lợi nhuận tối đa
        current_income = total_new_value - (n - reused_tags) * y
        max_income = max(max_income, current_income)
        
    return max_income if max_income != -float('inf') else 0

# ===================================================================
# BỘ SINH TEST CASE (GENERATOR) VÀ HÀM MAIN
# ===================================================================

class TestCaseGenerator:
    def __init__(self, base_path):
        self.base_path = base_path
        if not os.path.exists(self.base_path):
            os.makedirs(self.base_path)

    def generate(self, test_num, params):
        file_path_in = os.path.join(self.base_path, f"{test_num}.in")
        n, y, c_list = self._create_input_data(params)
        with open(file_path_in, 'w') as f:
            f.write("1\n") 
            f.write(f"{n} {y}\n")
            f.write(" ".join(map(str, c_list)) + "\n")

        file_path_out = os.path.join(self.base_path, f"{test_num}.out")
        print(f"Đang giải Test {test_num}... ", end="", flush=True)
        start_time = time.time()
        
        # Gọi hàm solve mới, siêu nhanh
        result = solve_from_cpp_logic(n, y, c_list)
        
        end_time = time.time()
        print(f"Xong! ({end_time - start_time:.2f}s)")

        with open(file_path_out, 'w') as f:
            f.write(str(result) + "\n")

    def _create_input_data(self, params):
        # Giới hạn C_MAX để phù hợp với thuật toán
        C_MAX_VAL = 200000 
        n_min, n_max = params.get("n_range", (1, 10))
        y_min, y_max = params.get("y_range", (1, 100))
        c_min, c_max = params.get("c_range", (1, C_MAX_VAL))
        c_dist = params.get("c_dist", "uniform")
        n = random.randint(n_min, n_max)
        y = random.randint(y_min, y_max)
        c_list = [random.randint(min(c_min, C_MAX_VAL), min(c_max, C_MAX_VAL)) for _ in range(n)]
        return n, y, c_list

def main():
    TOTAL_TEST_CASES = 40
    output_directory = r"D:\HSG\C-learning\RealTests\[DucHoa]VongTruong20252026\Bai5\TestCases"
    gen = TestCaseGenerator(output_directory)
    
    # Các test case giờ đây có thể có N rất lớn mà không sợ solver chạy chậm
    strategies = [
        {"name": "N lớn, c phân bố đều", "params": {"n_range": (180000, 200000)}},
        {"name": "N lớn, y lớn", "params": {"n_range": (180000, 200000), "y_range": (10**9 - 1000, 10**9)}},
        {"name": "N lớn, y nhỏ", "params": {"n_range": (180000, 200000), "y_range": (1, 100)}},
        {"name": "Giá trị c tập trung ở khoảng nhỏ", "params": {"n_range": (100000, 150000), "c_range": (1, 1000)}},
        {"name": "Giá trị c tập trung ở khoảng lớn", "params": {"n_range": (100000, 150000), "c_range": (190000, 200000)}},
    ]

    print(f"Bắt đầu sinh {TOTAL_TEST_CASES} test case cho thuật toán O(C_MAX * log(C_MAX))...")
    
    # Sinh các test case ví dụ (nếu có)
    # ...
    
    for i in range(1, TOTAL_TEST_CASES + 1):
        strategy = random.choice(strategies)
        print(f"--- Đang xử lý Test {i}: Chiến lược '{strategy['name']}' ---")
        gen.generate(i, strategy['params'])

    print(f"\n✅ Hoàn thành! Đã sinh {TOTAL_TEST_CASES} cặp file (.in và .out) trong thư mục:\n{output_directory}")

if __name__ == "__main__":
    main()