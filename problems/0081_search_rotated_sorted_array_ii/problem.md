# Search in Rotated Sorted Array II

**LeetCode #81** | Difficulty: Medium

## Problem

An integer array `nums` sorted in non-decreasing order is rotated at an unknown pivot index `k` (0-indexed) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`.

Given the rotated sorted array `nums` that may contain duplicates and an integer `target`, return `true` if target is in `nums`, or `false` if it is not.

### Examples

**Example 1:**
```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**
```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

### Constraints

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is guaranteed to be rotated at some pivot.
- `-10^4 <= target <= 10^4`

### Follow-up

This is a follow-up to [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/), where `nums` may contain duplicates. Does the presence of duplicates affect the runtime complexity? How and why?