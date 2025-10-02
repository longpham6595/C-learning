import os
import random

# --- CẤU HÌNH ---
# Đường dẫn tuyệt đối đến thư mục chứa test cases
TEST_DIR = r"D:\HSG\C-learning\RealTests\[DucHoa]VongTruong20252026\Bai2\TestCases"
# Số lượng file test case muốn sinh ra
NUM_FILES_TO_GENERATE = 40

# --- RÀNG BUỘC CỦA BÀI TOÁN ---
# a, b, c phải là số nguyên dương
VAL_MIN = 1
# a+b+c <= 10^9, suy ra giá trị lớn nhất của mỗi số cũng bị giới hạn
# Đặt một giới hạn thực tế để tránh tràn số và tổng quá lớn
MAX_SUM = 1_000_000_000


def solve(n1, n2, n3, n4):
    """
    Hàm giải bài toán từ 4 số đầu vào để kiểm tra tính đúng đắn.
    (Hàm này không dùng để sinh test, chỉ để tham khảo logic)
    """
    nums = sorted([n1, n2, n3, n4])
    s_total = nums[3] # s_total phải là a+b+c
    
    # a = (a+b+c) - (b+c)
    # b = (a+b+c) - (a+c)
    # c = (a+b+c) - (a+b)
    # Các tổng theo cặp là 3 số nhỏ hơn
    c = s_total - nums[2]
    b = s_total - nums[1]
    a = s_total - nums[0]

    return sorted([a, b, c])


def generate_and_write_case(file_index, a, b, c):
    """
    Từ a, b, c cho trước, tạo ra file .in và .out tương ứng.
    """
    # 1. Tính toán 4 giá trị đầu vào
    input_values = [a + b, a + c, b + c, a + b + c]
    
    # 2. Xáo trộn thứ tự các giá trị này
    random.shuffle(input_values)
    
    # 3. Chuẩn bị giá trị đầu ra (sắp xếp cho nhất quán)
    output_values = sorted([a, b, c])

    # 4. Ghi vào file
    in_path = os.path.join(TEST_DIR, f"{file_index}.in")
    out_path = os.path.join(TEST_DIR, f"{file_index}.out")

    with open(in_path, 'w') as f_in:
        f_in.write(" ".join(map(str, input_values)) + "\n")
        
    with open(out_path, 'w') as f_out:
        f_out.write(" ".join(map(str, output_values)) + "\n")

    print(f" -> Đã tạo file test: {file_index}.in / {file_index}.out")


def main():
    """
    Hàm chính để sinh tất cả các file test case.
    """
    # Tạo thư mục đích, exist_ok=True sẽ không báo lỗi nếu thư mục đã tồn tại
    os.makedirs(TEST_DIR, exist_ok=True)
    print(f"Các test case sẽ được lưu vào: '{TEST_DIR}'")

    # ----- Định nghĩa các bộ test case đặc biệt (biên, ví dụ) -----
    # Dạng (a, b, c)
    edge_cases = [
        # Các case từ ví dụ trong đề bài
        (1, 2, 3),          # -> 3 4 5 6
        (20, 20, 20),       # -> 40 40 40 60
        (1, 100, 100),      # -> 101 101 200 201
        # Các case biên cơ bản
        (1, 1, 1),          # -> 2 2 2 3
        (1, 1, 2),          # -> 2 3 3 4
        # Các case với số lớn
        (300000000, 300000000, 300000000), # a,b,c lớn bằng nhau
        (1, 1, MAX_SUM - 2),               # 2 số nhỏ, 1 số rất lớn
        (1, (MAX_SUM - 1) // 2, (MAX_SUM - 1) - (MAX_SUM - 1) // 2), # a nhỏ, b,c lớn
        (MAX_SUM // 3, MAX_SUM // 3, MAX_SUM // 3), # gần max
    ]

    print("Bắt đầu sinh các file test...")
    
    # Sinh các test case đặc biệt trước
    num_edge_cases = len(edge_cases)
    for i in range(num_edge_cases):
        a, b, c = edge_cases[i]
        generate_and_write_case(i + 1, a, b, c)

    # Sinh các file test case ngẫu nhiên còn lại
    for i in range(num_edge_cases + 1, NUM_FILES_TO_GENERATE + 1):
        # Tạo a, b, c ngẫu nhiên đảm bảo tổng không vượt MAX_SUM
        # Chia MAX_SUM làm 3 phần để a, b, c có độ lớn tương đối
        part1 = random.randint(VAL_MIN, MAX_SUM // 3)
        part2 = random.randint(VAL_MIN, MAX_SUM // 3)
        remains = MAX_SUM - part1 - part2
        part3 = random.randint(VAL_MIN, remains)
        
        # Gán ngẫu nhiên các phần cho a, b, c
        parts = [part1, part2, part3]
        random.shuffle(parts)
        a, b, c = parts
        
        generate_and_write_case(i, a, b, c)

    print(f"\nHoàn tất! Đã sinh {NUM_FILES_TO_GENERATE} bộ test case trong thư mục '{TEST_DIR}'.")

if __name__ == "__main__":
    main()
