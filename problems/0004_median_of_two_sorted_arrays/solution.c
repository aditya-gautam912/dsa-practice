/*
 * LeetCode #4: Median of Two Sorted Arrays
 * Difficulty: Hard
 *
 * Human approach:
 * Pretend both arrays are already merged. We don't actually merge them;
 * instead we find the correct "cut" position in the smaller array so the
 * left half of the merged result and the right half split evenly.
 * We binary-search the cut. When the cut is right, the numbers on the
 * left of both cuts are all smaller than the numbers on the right.
 * Then the median is just around the boundary - done in log time.
 */

#include <stdio.h>
#include <math.h>

/* LeetCode solution. */
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    /* Always work on the smaller array first for good performance. */
    if (nums1Size > nums2Size)
    {
        int *tmpArr = nums1;
        int tmpSize = nums1Size;
        nums1 = nums2;
        nums1Size = nums2Size;
        nums2 = tmpArr;
        nums2Size = tmpSize;
    }

    int total = nums1Size + nums2Size;
    int half = total / 2;
    int low = 0, high = nums1Size;

    while (low <= high)
    {
        int i = (low + high) / 2;         /* cut in nums1 */
        int j = half - i;                 /* cut in nums2 */

        int left1 = (i > 0) ? nums1[i - 1] : -2147483648;
        int right1 = (i < nums1Size) ? nums1[i] : 2147483647;
        int left2 = (j > 0) ? nums2[j - 1] : -2147483648;
        int right2 = (j < nums2Size) ? nums2[j] : 2147483647;

        if (left1 <= right2 && left2 <= right1)
        {
            double leftMax = left1 > left2 ? left1 : left2;
            double rightMin = right1 < right2 ? right1 : right2;
            if (total % 2 == 0)
                return (leftMax + rightMin) / 2.0;
            return rightMin;
        }
        else if (left1 > right2)
        {
            high = i - 1;     /* too far right, move cut left */
        }
        else
        {
            low = i + 1;    /* too far left, move cut right */
        }
    }
    return 0.0; /* unreachable */
}

int main(void)
{
    int a1[] = {1, 3};
    int a2[] = {2};
    printf("Test 1: %0.2f\n", findMedianSortedArrays(a1, 2, a2, 1));

    int b1[] = {1, 2};
    int b2[] = {3, 4};
    printf("Test 2: %0.2f\n", findMedianSortedArrays(b1, 2, b2, 2));

    int c1[] = {0, 0};
    int c2[] = {0, 0};
    printf("Test 3: %0.2f\n", findMedianSortedArrays(c1, 2, c2, 2));

    return 0;
}