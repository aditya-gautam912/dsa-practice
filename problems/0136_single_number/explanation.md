# Single Number ?? Explanation

## Approach: Bit Manipulation (XOR)

The problem asks us to find the unique element in an array where every other element appears exactly twice. Using the properties of the XOR operation, we can solve this efficiently.

XOR properties:
1. $a \oplus a = 0$ (Any number XORed with itself is 0)
2. $a \oplus 0 = a$ (Any number XORed with 0 is the number itself)
3. XOR is commutative and associative.

By XORing all elements of the array together, the pairs will cancel each other out and result in 0, leaving only the single unique element.

## Algorithm

1. Initialize a variable `result` to 0.
2. Iterate through every number in the `nums` array.
3. Perform a bitwise XOR operation between `result` and the current number.
4. Return the final value of `result`.

## Complexity

| Metric | Value |
|----------|----------|
| Time | O(n) |
| Space | O(1) |
