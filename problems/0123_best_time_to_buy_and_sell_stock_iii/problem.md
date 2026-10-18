# Best Time to Buy and Sell Stock III

**LeetCode #123** | Difficulty: Hard

## Problem

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

Find the maximum profit you can achieve. You may complete **at most two transactions**.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Example

```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 3.
Total profit = 3 + 3 = 6.
```

### Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`