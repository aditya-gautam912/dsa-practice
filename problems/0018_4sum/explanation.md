# 4Sum — Explanation

## Approach: Sort + Fix Two + Two Pointers

Extends the 3Sum pattern. Sort the array, fix the first two numbers with loops, then solve the remaining 2Sum part with two pointers over the rest of the array.

### Algorithm

1. Sort `nums`.
2. Loop `i` over the first number; skip duplicate values of `nums[i]`.
3. Loop `j` over the second number; skip duplicate values of `nums[j]`.
4. Two-pointer sweep with `left = j + 1` and `right = numsSize - 1`:
   - `sum = nums[i] + nums[j] + nums[left] + nums[right]`
   - If `sum == target`: record the quadruplet, skip duplicates on both pointers, move both inward.
   - If `sum < target`: move `left` right.
   - If `sum > target`: move `right` left.
5. Return all recorded quadruplets.

A `long long` is used for the sum because values can reach ±10⁹.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n³)** — two fixed loops + two-pointer sweep |
| Space  | **O(n)** — sorting + output |