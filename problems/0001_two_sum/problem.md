# Two Sum

**LeetCode #1** | Difficulty: Easy

## Problem

Given an array of integers `nums` and an integer `target`, return indices of the two numbers that add up to `target`.

You may assume that each input has **exactly one solution**, and you may not use the same element twice.

Return the answer in any order.

### Examples

**Example 1:**
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] == 9, so return [0, 1].
```

**Example 2:**
```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**
```
Input: nums = [3,3], target = 6
Output: [0,1]
```

### Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

**Follow-up:** Can you implement an algorithm with O(n) time complexity?
