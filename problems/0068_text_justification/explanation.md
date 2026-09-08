# Text Justification — Explanation

## Approach: Greedy Line Packing + Space Distribution

Pack as many words as possible per line, then distribute extra spaces.

### Algorithm

1. Iterate words, tracking `start` (first word index in current line) and `len` (sum of word lengths).
2. If adding `words[i]` would exceed `maxWidth` (including at least one space between words), finalize the current line `words[start..i-1]`:
   - `spaces = maxWidth - len` (total extra spaces needed).
   - `gaps = word_count - 1`.
   - For each gap, assign `base = spaces / gaps` spaces; the first `extra = spaces % gaps` gaps get one additional space.
   - Build the line string.
   - Single-word line: left-justify, pad right.
3. After loop, build the last line: left-justify with single spaces, pad right.
4. Return all lines.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(N · maxWidth)** — N words, each processed once |
| Space  | **O(N · maxWidth)** — output |