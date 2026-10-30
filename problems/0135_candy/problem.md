# Candy

**LeetCode #135** | Difficulty: Hard

## Problem

There are `n` children standing in a line. Each child has a rating value
given by the integer array `ratings`.

You are giving candies to these children subject to:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their adjacent
  neighbors.

Return the minimum number of candies you need to have to distribute the
candies to the children.

### Example

```
Input:  ratings = [1,0,2]
Output: 5
Explanation: You can give 2, 1, 2 candies to the children.
```

### Constraints

- `n == ratings.length`
- `1 <= n <= 2 * 10^4`
- `-10^5 <= ratings[i] <= 10^5`
