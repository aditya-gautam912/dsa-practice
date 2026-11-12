# Single Number II — Explanation

## Approach: Bit Counting

Every repeated number contributes each of its 32 bits exactly three times. Therefore, after counting each bit across the whole array, any bit whose count is not divisible by three belongs to the unique number.

### Algorithm

1. Inspect each of the 32 bit positions.
2. Count how many input numbers have that bit set.
3. If `count % 3 != 0`, set that bit in the answer.
4. Return the reconstructed integer.

Casting to `unsigned int` while applying masks handles the sign bit safely, so negative answers work too.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(32n) = O(n)** |
| Space  | **O(1)** |
