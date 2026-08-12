/*
 * Next Permutation (LeetCode #31, Medium)
 *
 * Honestly the first time I saw this I had no idea. The epiphany:
 * the "next" permutation is about finding the rightmost dip.
 * Walk from the end while the numbers rise; that rising tail is
 * already the biggest arrangement of those digits. Then the next
 * bigger number has to bump the element before the dip, and the
 * tail gets sorted ascending after the swap.
 * If there is no dip, the whole array is descending - flip it.
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static void reverse(int *arr, int lo, int hi)
{
    while (lo < hi)
        swap(&arr[lo++], &arr[hi--]);
}

void nextPermutation(int *nums, int numsSize)
{
    int i = numsSize - 2;

    /* find the dip */
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0)
    {
        /* smallest element bigger than nums[i], scanning from the right */
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
    int a[] = {1, 2, 3}; /* -> 1 3 2 */
    int b[] = {3, 2, 1}; /* -> 1 2 3 */
    int c[] = {1, 1, 5}; /* -> 1 5 1 */

    nextPermutation(a, 3);
    printArr(a, 3);
    nextPermutation(b, 3);
    printArr(b, 3);
    nextPermutation(c, 3);
    printArr(c, 3);

    return 0;
}