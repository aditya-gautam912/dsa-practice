# Best Time to Buy and Sell Stock II — Explanation

## Approach: Peak-Valley (Sum of Positive Differences)

With unlimited transactions, the maximum profit is achieved by capturing every price increase. Simply sum up all positive differences between consecutive days.

### Algorithm

1. `totalProfit = 0`.
2. For `i = 1` to `pricesSize - 1`:
   - If `prices[i] > prices[i-1]`: add the difference to `totalProfit`.
3. Return `totalProfit`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — constant extra space |