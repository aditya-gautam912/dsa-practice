The problem asks us to find the single element in an array where every other element appears twice.
The constraints are linear time complexity O(n) and constant space complexity O(1).
We can use the XOR bitwise operator to solve this.
XOR properties:
1. a ^ a = 0
2. a ^ 0 = a
3. XOR is commutative and associative.
If we XOR all elements in the array, the elements that appear twice will cancel each other out (become 0), and we will be left with the single element.
