# Word Break II — Explanation

## Approach: DFS with Memoization

For every starting position, try dictionary words that match there. Recursively solve the remaining suffix and prepend the chosen word to every sentence returned by the suffix. Cache the results for each position so the same suffix is never recomputed.

### Algorithm

1. Define `solve_from(start)` as all sentences that can be formed from `s[start..]`.
2. If `start == s.length`, return one empty suffix. This lets callers append their final word without special handling.
3. For each dictionary word matching at `start`:
   - Recursively get sentences from after that word.
   - Combine the word with every suffix sentence.
4. Memoize the list for `start` and return the list for position 0.

### Complexity

The problem has output-size complexity: the number of valid sentences can be exponential. With memoization, repeated suffix searches are avoided; the total work is **O(number of generated sentences × sentence length)** plus dictionary matching. Extra space is proportional to the memoized output.
