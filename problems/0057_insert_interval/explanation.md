# Insert Interval — Explanation

## Approach: Three-Phase One Pass

Since intervals are sorted and non-overlapping, we can insert and merge in a single scan with three phases.

### Algorithm

1. **Phase 1** — add all intervals that end before `newInterval` starts (no overlap, come before).
2. **Phase 2** — merge all intervals that overlap with `newInterval`: expand `newInterval` to cover each overlapping interval.
3. **Phase 3** — add all remaining intervals (no overlap, come after).

An interval overlaps with `newInterval` if its start ≤ `newInterval`'s end.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(n)** — output array |