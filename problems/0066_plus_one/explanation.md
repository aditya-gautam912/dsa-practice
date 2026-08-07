# Plus One — Explanation

## Approach: Reverse Scan with Carry

Iterate from the least significant digit. If a digit is less than 9, increment and return immediately. If it's 9, set it to 0 and carry.

### Algorithm

1. Iterate `i` from last index to 0.
2. If `digits[i] < 9`, increment it and return `digits`.
3. Otherwise set `digits[i] = 0` and continue (carry propagates).
4. If all digits were 9, prepend `1`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — worst case scans all digits |
| Space  | **O(1)** — except when all 9s require a new leading 1 |
