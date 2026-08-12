/*
 * Sort Colors (LeetCode #75, Medium)
 *
 * Dutch national flag problem. Three values, sort in one pass.
 * Keep three pointers: one for the next 0 spot, one scanning,
 * one for the next 2 spot. Swap into place as you go.
 * The part that felt weird first: the scanner only moves on
 * 0s and 1s; when it hands a 2 to the end pointer, it must
 * re-check whatever came back.
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sortColors(int *nums, int numsSize)
{
    int lo = 0, mid = 0, hi = numsSize - 1;

    while (mid <= hi)
    {
        if (nums[mid] == 0)
            swap(&nums[lo++], &nums[mid++]);
        else if (nums[mid] == 2)
            swap(&nums[mid], &nums[hi--]);
        else
            mid++;
    }
}

int main(void)
{
    int a[] = {2, 0, 2, 1, 1, 0};
    int b[] = {2, 0, 1};

    sortColors(a, 6);
    printf("got: ");
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);
    printf("(want 0 0 1 1 2 2)\n");

    sortColors(b, 3);
    printf("got: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", b[i]);
    printf("(want 0 1 2)\n");

    return 0;
}