use itertools::Itertools;
use std::time::Instant;

fn main() {
    let players: [String; 13] = [
        "M1".to_string(),
        "M2".to_string(),
        "M3".to_string(),
        "M4".to_string(),
        "M5".to_string(),
        "M6".to_string(),
        "F1".to_string(),
        "F2".to_string(),
        "F3".to_string(),
        "F4".to_string(),
        "F5".to_string(),
        "F6".to_string(),
        "F7".to_string(),
    ];

    // Lấy tất cả các tổ hợp chọn 10 người từ 13 người
    let ran10_permutations = (0..13).combinations(10);

    // Bắt đầu theo dõi thời gian thực thi
    let start_time = Instant::now();
    let mut ans = 0;

    for ran10_indices in ran10_permutations {
        // Chọn 10 người tương ứng với tổ hợp hiện tại
        let chosen_players: Vec<String> =
            ran10_indices.iter().map(|&i| players[i].clone()).collect();

        // Tạo hoán vị cho 10 người đã chọn
        let permutations = chosen_players.iter().permutations(chosen_players.len());

        for permutation in permutations {
            // Chia thành 2 dãy ghế (dãy 1 và dãy 2)
            let pairs: Vec<(&String, &String)> = vec![
                (permutation[0], permutation[5]),
                (permutation[1], permutation[6]),
                (permutation[2], permutation[7]),
                (permutation[3], permutation[8]),
                (permutation[4], permutation[9]),
            ];

            // Kiểm tra tính hợp lệ của từng cặp
            let valid = pairs.iter().all(|(a, b)| {
                let a_char = a.chars().next().unwrap();
                let b_char = b.chars().next().unwrap();
                (a_char == 'M' && b_char == 'F') || (a_char == 'F' && b_char == 'M')
            });

            let elapsed_time = start_time.elapsed();
            let seconds = elapsed_time.as_secs();
            let minutes = seconds / 60;
            let remaining_seconds = seconds % 60;

            if valid {
                ans += 1;
                println!(
                    "Valid arrangement: {} | Current ans: {} | Elapsed time: {} minutes, {} seconds",
                    permutation.iter().map(|x| x.to_string()).join(", "),
                    ans,
                    minutes,
                    remaining_seconds
                );
            } else {
                println!(
                    "Invalid arrangement: {} | Current ans: {} | Elapsed time: {} minutes, {} seconds",
                    permutation.iter().map(|x| x.to_string()).join(", "),
                    ans,
                    minutes,
                    remaining_seconds
                );
            }
        }
    }

    // Xuất kết quả cuối cùng
    println!("Final count of valid arrangements (ans): {}", ans);
    println!(
        "Total execution time: {} minutes and {} seconds",
        start_time.elapsed().as_secs() / 60,
        start_time.elapsed().as_secs() % 60
    );
}
