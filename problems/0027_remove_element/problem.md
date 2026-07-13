# Remove Element

**LeetCode #27** | Difficulty: Easy

## Problem

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place. Return the number of elements not equal to `val`.

Change the array `nums` such that the first `k` elements contain the elements not equal to `val`. The remaining elements beyond `k` do not matter.

Return `k`.

### Examples

**Example 1:**
```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
```

**Example 2:**
```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
```

### Constraints

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`
