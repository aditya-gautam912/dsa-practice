# Longest Consecutive Sequence — Explanation

## Approach: Hash Set + Start-of-Run Detection

Use a hash set for O(1) lookups. A number is the **start** of a consecutive run only if `num - 1` is not in the set. From each start, count upward until the run breaks. Each element is counted at most once as part of its run, giving O(n) total.

### Algorithm

1. Insert all numbers into a hash set.
2. For each number `num`:
   - If `num - 1` is in the set: skip (not a start).
   - Else: count `num, num+1, num+2, ...` while present.
   - Track the longest run.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — each element touched at most twice |
| Space  | **O(n)** — hash set |