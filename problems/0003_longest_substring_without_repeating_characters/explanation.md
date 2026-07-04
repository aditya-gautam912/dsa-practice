# Longest Substring Without Repeating Characters — Explanation

## Approach: Sliding Window with Hash Map

Use two pointers (`left` and `right`) to maintain a sliding window of unique characters. A dictionary maps each character to its most recent index.

### Algorithm

1. Initialize `left = 0`, `max_len = 0`, and an empty dict `seen`.
2. Iterate `right` over each index in `s`:
   - If `s[right]` is in `seen` and its last occurrence is at or after `left`, move `left` past it: `left = seen[s[right]] + 1`.
   - Update `seen[s[right]] = right`.
   - Compute window length: `right - left + 1`. Update `max_len`.
3. Return `max_len`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass, each character visited once |
| Space  | **O(min(m, n))** — dictionary stores at most the size of the character set |

### Why this works

The sliding window always contains unique characters. When a repeat is found, the left pointer jumps directly past the previous occurrence, avoiding O(n²) brute-force checks.
