# Best Time to Buy and Sell Stock — Explanation

## Approach: Track Minimum Price

One pass through the prices. Keep the lowest price seen so far as the best buy day. At each price, compute the profit if we sold today; keep the maximum.

### Algorithm

1. `minPrice = prices[0]`, `maxProfit = 0`.
2. For `i = 1` to `n-1`:
   - If `prices[i] < minPrice`: update `minPrice`.
   - Else if `prices[i] - minPrice > maxProfit`: update `maxProfit`.
3. Return `maxProfit`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — constant extra space |