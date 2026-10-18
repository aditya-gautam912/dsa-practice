# Best Time to Buy and Sell Stock III — Explanation

## Approach: State Machine DP (4 States)

Track four states across all days:
- `buy1` — max profit after first buy (stores negative cost)
- `sell1` — max profit after first sell
- `buy2` — max profit after second buy
- `sell2` — max profit after second sell

### Algorithm

1. Initialize `buy1 = buy2 = -infinity`, `sell1 = sell2 = 0`.
2. For each price `p`:
   - `buy1 = max(buy1, -p)` — cheapest first buy so far
   - `sell1 = max(sell1, buy1 + p)` — best first sell so far
   - `buy2 = max(buy2, sell1 - p)` — best second buy so far (using first sell profit)
   - `sell2 = max(sell2, buy2 + p)` — best second sell so far
3. Return `sell2`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — constant extra space |