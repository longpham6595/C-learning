import os
import random
import string

# --- CẤU HÌNH ---
# Đường dẫn tuyệt đối đến thư mục chứa test cases
TEST_DIR = r"D:\HSG\C-learning\RealTests\[DucHoa]VongTruong20252026\Bai3\TestCases"
# Số lượng file test case muốn sinh ra
NUM_FILES_TO_GENERATE = 40

# --- RÀNG BUỘC CỦA BÀI TOÁN ---
T_MIN, T_MAX = 1, 100
LEN_MIN, LEN_MAX = 1, 100
CHARACTERS = string.ascii_lowercase

def is_square_string(s):
    """
    Kiểm tra xem một chuỗi có phải là chuỗi vuông hay không.
    """
    n = len(s)
    # Chuỗi có độ dài lẻ không thể là chuỗi vuông.
    if n % 2 != 0 or n == 0:
        return "NO"
    
    half = n // 2
    # So sánh nửa đầu và nửa sau của chuỗi.
    if s[:half] == s[half:]:
        return "YES"
    else:
        return "NO"

def generate_random_string(length):
    """
    Tạo một chuỗi ngẫu nhiên với độ dài cho trước.
    """
    return ''.join(random.choice(CHARACTERS) for _ in range(length))

def generate_case(force_yes=None):
    """
    Tạo một chuỗi test case, có thể ép tạo ra chuỗi vuông hoặc không.
    """
    if force_yes is None:
        force_yes = random.choice([True, False])

    if force_yes:
        # Tạo chuỗi vuông ("YES")
        half_len = random.randint(LEN_MIN, LEN_MAX // 2)
        half_str = generate_random_string(half_len)
        return half_str + half_str
    else:
        # Tạo chuỗi không phải chuỗi vuông ("NO")
        while True:
            length = random.randint(LEN_MIN, LEN_MAX)
            s = generate_random_string(length)
            if is_square_string(s) == "NO":
                return s

def main():
    """
    Hàm chính để sinh tất cả các file test case.
    """
    os.makedirs(TEST_DIR, exist_ok=True)
    print(f"Các test case sẽ được lưu vào: '{TEST_DIR}'")

    # ----- Định nghĩa các bộ test case đặc biệt (biên, ví dụ) -----
    edge_cases = [
        # Các case từ ví dụ
        "a", "aa", "aaa", "aaaa", "abab", "abcabc", 
        "abacaba", "xyxy", "xyyx",
        # Case biên độ dài
        "b", # min length, NO
        "z" * LEN_MAX, # max length, NO (odd length if LEN_MAX is odd)
        "y" * (LEN_MAX // 2) + "y" * (LEN_MAX // 2), # max length, YES
        # Case gần đúng
        "abcabd",
        "aaaaab",
        "baaaaa",
        "ab" * (LEN_MAX // 4) + "ac" + "ab" * (LEN_MAX // 4 -1), # max length, gần đúng
    ]

    print("Bắt đầu sinh các file test...")
    
    # Sinh file test đầu tiên chứa các case đặc biệt
    in_path_1 = os.path.join(TEST_DIR, "1.in")
    out_path_1 = os.path.join(TEST_DIR, "1.out")
    with open(in_path_1, 'w') as f_in, open(out_path_1, 'w') as f_out:
        t = len(edge_cases)
        f_in.write(f"{t}\n")
        for s in edge_cases:
            f_in.write(f"{s}\n")
            f_out.write(f"{is_square_string(s)}\n")
    print(f" -> Đã tạo file test đặc biệt: 1.in / 1.out")

    # Sinh các file test case ngẫu nhiên còn lại
    for i in range(2, NUM_FILES_TO_GENERATE + 1):
        in_path = os.path.join(TEST_DIR, f"{i}.in")
        out_path = os.path.join(TEST_DIR, f"{i}.out")
        with open(in_path, 'w') as f_in, open(out_path, 'w') as f_out:
            t = random.randint(T_MAX // 2, T_MAX)
            f_in.write(f"{t}\n")
            for _ in range(t):
                s = generate_case()
                f_in.write(f"{s}\n")
                f_out.write(f"{is_square_string(s)}\n")
        print(f" -> Đã tạo file test ngẫu nhiên: {i}.in / {i}.out")

    print(f"\nHoàn tất! Đã sinh {NUM_FILES_TO_GENERATE} bộ test case trong thư mục '{TEST_DIR}'.")

if __name__ == "__main__":
    main()
