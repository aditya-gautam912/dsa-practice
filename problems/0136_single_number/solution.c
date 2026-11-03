#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums1[] = {2, 2, 1};
    printf("Result 1: %d\n", singleNumber(nums1, 3)); // Expected: 1

    int nums2[] = {4, 1, 2, 1, 2};
    printf("Result 2: %d\n", singleNumber(nums2, 5)); // Expected: 4

    int nums3[] = {1};
    printf("Result 3: %d\n", singleNumber(nums3, 1)); // Expected: 1

    return 0;
}
