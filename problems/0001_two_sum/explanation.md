# Two Sum — Explanation

## Approach: Hash Map (One Pass)

Use a dictionary to store each number's index as we iterate. For each `num`, compute `complement = target - num`. If the complement already exists in the dictionary, we've found the pair.

### Algorithm

1. Initialize an empty dictionary `seen = {}`.
2. Loop through `nums` with index `i` and value `num`:
   - Compute `complement = target - num`.
   - If `complement` is in `seen`, return `[seen[complement], i]`.
   - Otherwise, store `seen[num] = i`.
3. Return `[]` (should never reach here since a solution is guaranteed).

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass, O(1) dictionary lookups |
| Space  | **O(n)** — store up to n elements in dictionary |

### Why not brute force?

A nested loop checking every pair is O(n²). The hash map trades space for time, giving us linear runtime.
