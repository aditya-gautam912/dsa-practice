/*
 * LeetCode #31: Next Permutation
 * Difficulty: Medium
 *
 * Human approach:
 * Imagine the numbers as digits of a word. To get the next bigger "word":
 * 1. Walk from the right and find the first spot where the number dips
 *    (the right side is bigger than where we are).
 * 2. Swap that number with the smallest number bigger than it on the right.
 * 3. Flip (reverse) everything to the right so it becomes the smallest
 *    possible order.
 * If the whole array is already descending, just reverse all of it.
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static void reverse(int *arr, int left, int right)
{
    while (left < right)
    {
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
}

/* LeetCode solution. Modifies the array in place. */
void nextPermutation(int *nums, int numsSize)
{
    int i = numsSize - 2;

    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0)
    {
        int j = numsSize - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(&nums[i], &nums[j]);
    }

    reverse(nums, i + 1, numsSize - 1);
}

static void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int a[] = {1, 2, 3};
    int b[] = {3, 2, 1};
    int c[] = {1, 1, 5};

    nextPermutation(a, 3);
    printf("Test 1: ");
    printArr(a, 3);

    nextPermutation(b, 3);
    printf("Test 2: ");
    printArr(b, 3);

    nextPermutation(c, 3);
    printf("Test 3: ");
    printArr(c, 3);

    return 0;
}
