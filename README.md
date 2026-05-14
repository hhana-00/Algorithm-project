# Algorithm-project
# Longest Common Subsequence — Algorithm Comparison

Implementation of the **Longest Common Subsequence (LCS)** problem using three different algorithmic approaches in C++, with a focus on comparing their logic, performance, and complexity.

##  Algorithms Implemented

| Approach | Time Complexity | Space Complexity |
|---|---|---|
| Brute Force | O(2ⁿ × 2ᵐ) | O(2ⁿ) |
| Divide & Conquer | O(2^(m+n)) | O(m+n) |
| Dynamic Programming | O(m × n) | O(m × n) |

##  What Each Approach Does

**Brute Force**
Generates all possible subsequences of both strings and compares them to find the longest match. Simple but exponentially slow — useful as a baseline.

**Divide & Conquer**
Recursively breaks the problem into subproblems by comparing characters and branching on matches/mismatches. Cleaner logic than brute force but still suffers from overlapping subproblems.

**Dynamic Programming**
Builds a 2D table bottom-up to avoid recomputation. Most efficient approach — reconstructs the LCS string by backtracking through the table.


##  Key Takeaway

All three approaches solve the same problem correctly, but Dynamic Programming is the clear winner for any practical input size. This project demonstrates how algorithm design choices directly impact scalability.

---
*Academic project — Misr International University, Algorithm Design & Analysis coursework*
