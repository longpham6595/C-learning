import os
import random

# --- CẤU HÌNH ---
# Tên thư mục chứa test cases
# Sử dụng r"..." để xử lý đường dẫn trên Windows một cách chính xác
TEST_DIR = r"D:\HSG\C-learning\RealTests\[DucHoa]VongTruong20252026\Bai1\TestCases"
# Số lượng file test case muốn sinh ra
NUM_FILES_TO_GENERATE = 40

# --- RÀNG BUỘC CỦA BÀI TOÁN ---
T_MIN, T_MAX = 1, 9261
VAL_MIN, VAL_MAX = 0, 20

def solve(a, b, c):
    """
    Hàm giải quyết bài toán cho một bộ ba số a, b, c.
    Trả về "YES" nếu một số là tổng của hai số còn lại, ngược lại "NO".

    Lưu ý: Theo logic này, 0 0 0 sẽ cho kết quả là "YES" (vì 0 + 0 = 0),
    có thể khác với một ví dụ trong đề bài. Đây là cách diễn giải trực tiếp
    và phổ biến nhất cho yêu cầu "một số là tổng của hai số còn lại".
    """
    # Sắp xếp các số để dễ kiểm tra
    nums = sorted([a, b, c])
    if nums[0] + nums[1] == nums[2]:
        return "YES"
    return "NO"

def generate_random_case():
    """
    Tạo ngẫu nhiên một test case (một bộ ba số a, b, c) và kết quả tương ứng.
    """
    # 50% cơ hội tạo ra test case "YES"
    if random.choice([True, False]):
        # Tạo trường hợp "YES"
        # Để đảm bảo tổng không vượt quá VAL_MAX
        x = random.randint(VAL_MIN, VAL_MAX // 2)
        y = random.randint(VAL_MIN, VAL_MAX - x)
        z = x + y
        nums = [x, y, z]
        random.shuffle(nums)
        a, b, c = nums
    else:
        # Tạo trường hợp "NO"
        # Lặp cho đến khi tìm được một bộ ba số không thỏa mãn điều kiện
        while True:
            a = random.randint(VAL_MIN, VAL_MAX)
            b = random.randint(VAL_MIN, VAL_MAX)
            c = random.randint(VAL_MIN, VAL_MAX)
            if solve(a, b, c) == "NO":
                break
    
    return (a, b, c), solve(a, b, c)

def main():
    """
    Hàm chính để sinh tất cả các file test case.
    """
    # Tạo thư mục TestCases nếu chưa tồn tại
    if not os.path.exists(TEST_DIR):
        os.makedirs(TEST_DIR)
        print(f"Đã tạo thư mục '{TEST_DIR}'.")

    # ----- Định nghĩa các bộ test case đặc biệt (biên, ví dụ) -----
    edge_cases = [
        # Các case từ ví dụ trong đề bài
        (1, 4, 3),
        (2, 5, 8),
        (9, 11, 20),
        (0, 0, 0),
        (20, 20, 20),
        (4, 12, 3),
        (15, 7, 8),
        # Các case biên quan trọng khác
        (0, VAL_MAX, VAL_MAX),
        (VAL_MAX, 0, VAL_MAX),
        (10, 10, VAL_MAX),
        (VAL_MAX // 2, VAL_MAX - (VAL_MAX // 2), VAL_MAX),
        (1, 1, 1),
        (0, 0, 1),
    ]

    # Sinh file test case đầu tiên chứa các case đặc biệt
    print("Bắt đầu sinh các file test...")
    in_path_1 = os.path.join(TEST_DIR, "1.in")
    out_path_1 = os.path.join(TEST_DIR, "1.out")

    with open(in_path_1, 'w') as f_in, open(out_path_1, 'w') as f_out:
        t = len(edge_cases)
        f_in.write(f"{t}\n")
        for a, b, c in edge_cases:
            f_in.write(f"{a} {b} {c}\n")
            f_out.write(f"{solve(a, b, c)}\n")
    print(f" -> Đã tạo file test đặc biệt: 1.in / 1.out")

    # Sinh các file test case ngẫu nhiên còn lại
    for i in range(2, NUM_FILES_TO_GENERATE + 1):
        in_path = os.path.join(TEST_DIR, f"{i}.in")
        out_path = os.path.join(TEST_DIR, f"{i}.out")

        with open(in_path, 'w') as f_in, open(out_path, 'w') as f_out:
            # Chọn số lượng test case t ngẫu nhiên, tăng dần độ khó
            if i <= 5:
                t = random.randint(100, 500)
            elif i <= 15:
                t = random.randint(1000, 5000)
            else:
                t = random.randint(8000, T_MAX)
            
            f_in.write(f"{t}\n")

            for _ in range(t):
                case, result = generate_random_case()
                a, b, c = case
                f_in.write(f"{a} {b} {c}\n")
                f_out.write(f"{result}\n")
        
        print(f" -> Đã tạo file test ngẫu nhiên: {i}.in / {i}.out")

    print(f"\nHoàn tất! Đã sinh {NUM_FILES_TO_GENERATE} bộ test case trong thư mục '{TEST_DIR}'.")

if __name__ == "__main__":
    main()

