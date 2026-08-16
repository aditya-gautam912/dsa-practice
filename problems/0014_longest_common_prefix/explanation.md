# Longest Common Prefix — Explanation

## Approach: Horizontal Scanning

Start with the first string as the candidate prefix. For each remaining string, trim the prefix down to the longest part that the next string also starts with. The final trimmed prefix is the answer.

### Algorithm

1. Copy `strs[0]` into `prefix`.
2. For each next string `strs[i]`:
   - Find the longest `len` such that `prefix[0..len)` matches `strs[i]` from the start.
   - Cut `prefix` at `len`.
   - If `len == 0`, no common prefix exists — stop early.
3. Return `prefix`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(S)** — S = sum of all characters in all strings |
| Space  | **O(1)** — only the prefix copy |