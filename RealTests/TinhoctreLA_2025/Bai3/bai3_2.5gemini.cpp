#include <iostream>

/**
 * Problem: THT Long An 2025 - Bảng C - Bài 3
 * * Problem Description:
 * Given a container with base dimensions h x w, we need to pack rectangular carpets.
 * Packing follows specific rules:
 * 1. Carpets are placed either on the container base or on top of another carpet.
 * 2. When placing carpets on top of an existing carpet (or the base), they must perfectly tile the area below. That is, if we decide to cover an n x m area, we must use a set of smaller carpets {n_i x m_i} such that they exactly cover n x m without overlap.
 * 3. A crucial rule: If a carpet C2 (size n2 x m2) is placed upon another carpet C1 (size n1 x m1), the area of C2 must be strictly smaller than the area of C1 (n2*m2 < n1*m1), and C2 must lie entirely within C1's boundary. This rule applies to each individual carpet used in the tiling described in rule 2.
 * Goal: Calculate the maximum possible total area of all carpets that can be packed into the container.
 * * Input: Two integers h and w (1 <= h, w <= 10^6), the dimensions of the container base.
 * Output: A single integer representing the maximum total area.
 *
 * Examples Analysis:
 * S(n, m) denotes the maximum total area starting from an n x m rectangle.
 * S(1, 1) = 1 (base case, cannot place smaller area carpets).
 * S(2, 2) = 12: Includes 2x2 base (4) + two 1x2 carpets (2*2=4) + four 1x1 carpets (4*1=4).
 * S(3, 2) = 22: Includes 3x2 base (6) + best tiling (two 1x3 carpets giving sum S(1,3)+S(1,3)=8+8=16). Total = 6 + 16 = 22.
 *
 * Recursive Relation Derivation:
 * Let S(n, m) be the maximum total area obtainable starting with an n x m area.
 * S(n, m) = (Area of current base n*m) + (Max total area from carpets placed on top).
 * The carpets placed on top must tile the n x m area, and each tile (ni x mi) must satisfy ni*mi < n*m.
 * The total area from carpets on top is the sum of S(ni, mi) for the chosen optimal tiling.
 * S(n, m) = n * m + max_{Tilings T of n x m} { sum_{ (ni, mi) in T where ni*mi < n*m } S(ni, mi) }
 * * Observation and Simplification:
 * Analyzing small cases suggests that the optimal strategy might always involve making a single "guillotine" cut (either horizontal or vertical) that splits the n x m rectangle into two smaller rectangles.
 * Furthermore, empirical checks suggest the optimal cut is always one that splits off a single row or column (i.e., a cut creating a 1 x m or n x 1 piece).
 * This leads to a simplified recursion:
 * S(n, m) = n * m + max( S(1, m) + S(n-1, m),  S(n, 1) + S(n, m-1) )  for n, m > 1
 * Base cases and edge cases:
 * S(1, 1) = 1
 * S(1, m) = 1 * m + S(1, 1) + S(1, m-1) = m + 1 + S(1, m-1) for m > 1
 * S(n, 1) = n * 1 + S(1, 1) + S(n-1, 1) = n + 1 + S(n-1, 1) for n > 1
 *
 * Closed Form Derivation:
 * Solving the recurrence for S(1, m) yields: S(1, m) = (m^2 + 3m - 2) / 2.
 * By symmetry, S(n, 1) = (n^2 + 3n - 2) / 2.
 * Assuming that one branch of the 'max' in the main recursion is always optimal (e.g., the first branch S(1, m) + S(n-1, m) if n >= m), we can solve the full recurrence.
 * This derivation leads to the closed-form formula:
 * S(n, m) = (n * m * (n + m)) / 2 + 2 * n * m - (n + m)
 *
 * Validation:
 * This formula correctly reproduces the results for the provided examples (2x2 -> 12, 3x2 -> 22).
 * It also matches the correct outputs for the failed test cases provided in the prompt when calculated manually, suggesting the formula is correct.
 *
 * Implementation Notes:
 * The values of h, w can be up to 10^6.
 * Intermediate products like h*w and h*w*(h+w) can reach up to 10^12 and 2*10^18 respectively.
 * The final result S(h, w) can also be around 10^18.
 * Therefore, 64-bit integers (`long long` in C++) are necessary for all calculations.
 * The term (h * w * (h + w)) is always even because either h or w is even, or if both are odd, h+w is even. Thus, integer division by 2 is exact.
 * Use fast I/O (`ios_base::sync_with_stdio(false); cin.tie(NULL);`) for potentially large inputs, although it might not be strictly necessary given the O(1) calculation time.
 */
int main()
{
    // Optimize standard I/O operations for speed
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long h, w;

    // Read the dimensions h and w from standard input
    if (!(std::cin >> h >> w))
    {
        // Handle potential input error, though unlikely in typical contest scenarios
        std::cerr << "Failed to read input." << std::endl;
        return 1;
    }

    // Calculate intermediate terms using long long to prevent overflow
    long long prod_hw = h * w; // Product h * w
    long long sum_hw = h + w;  // Sum h + w

    // Apply the derived formula:
    // S(h, w) = (h * w * (h + w)) / 2 + 2 * h * w - (h + w)

    // Calculate the first part of the formula: (prod_hw * sum_hw) / 2
    // The product (h * w * (h + w)) fits within long long and is always even.
    long long term1_div_2 = (prod_hw * sum_hw) / 2;

    // Calculate the second part: 2 * prod_hw
    long long term2 = 2 * prod_hw;

    // The third part is simply the sum: sum_hw
    long long term3 = sum_hw;

    // Combine the terms to get the final result
    long long result = term1_div_2 + term2 - term3;

    // Print the final result to standard output
    std::cout << result << std::endl;

    return 0;
}