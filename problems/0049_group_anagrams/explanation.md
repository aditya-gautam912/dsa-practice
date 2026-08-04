# Group Anagrams — Explanation

## Approach: Hash Map with Sorted Key

Anagrams share the same sorted character sequence. Use the sorted string (as a tuple) as the dictionary key.

### Algorithm

1. Create a `defaultdict(list)`.
2. For each string, sort its characters to form a key.
3. Append the original string to the bucket for that key.
4. Return all bucket values.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n · k log k)** — sorting each string of length k |
| Space  | **O(n · k)** — storing all strings |
