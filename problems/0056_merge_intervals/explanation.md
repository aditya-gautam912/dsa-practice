# Merge Intervals — Explanation

## Approach: Sort + Greedy Merge

Sort intervals by start time, then iterate merging any interval that overlaps with the last merged one.

### Algorithm

1. Sort intervals by `start`.
2. For each interval:
   - If `merged` is empty or the interval starts after the last merged end, append it.
   - Otherwise, extend the last merged interval's end to the max of the two.
3. Return `merged`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n log n)** — dominated by sorting |
| Space  | **O(n)** — output storage (sorting uses O(log n) stack) |
