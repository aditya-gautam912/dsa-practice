# Maximum Subarray — Explanation

## Approach: Kadane's Algorithm

Track the running sum of the current subarray. If the running sum ever drops below the current element alone, restart from that element.

### Algorithm

1. Initialize `current_sum = 0`, `max_sum = -inf`.
2. For each `num`:
   - `current_sum = max(num, current_sum + num)`.
   - `max_sum = max(max_sum, current_sum)`.
3. Return `max_sum`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** |
