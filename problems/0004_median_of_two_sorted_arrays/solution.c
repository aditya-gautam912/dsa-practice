/*
 * Median of Two Sorted Arrays (LeetCode #4, Hard)
 *
 * You could merge then take the middle, that's O(m+n). Fine but the
 * problem really wants you to notice you don't need the full merge.
 * Binary search the cut on the smaller array. The trick that took me
 * a while: the "cut" in array2 is forced once you pick the cut in
 * array1, because half of the combined array goes left. Then just
 * verify max(left) <= min(right).
 */

#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    /* smaller array is easier to binary search over */
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
    int lo = 0, hi = nums1Size;

    while (lo <= hi)
    {
        int i = (lo + hi) / 2;
        int j = half - i;

        int l1 = (i > 0) ? nums1[i - 1] : -2147483648;
        int r1 = (i < nums1Size) ? nums1[i] : 2147483647;
        int l2 = (j > 0) ? nums2[j - 1] : -2147483648;
        int r2 = (j < nums2Size) ? nums2[j] : 2147483647;

        if (l1 <= r2 && l2 <= r1)
        {
            /* perfect split! */
            double lMax = l1 > l2 ? l1 : l2;
            double rMin = r1 < r2 ? r1 : r2;
            if (total % 2 == 0)
                return (lMax + rMin) / 2.0;
            return rMin;
        }
        else if (l1 > r2)
            hi = i - 1;   /* left1 too big --> cut moves left */
        else
            lo = i + 1;   /* left2 too big --> cut moves right */
    }
    return 0.0; /* unreachable but compiler wants a return */
}

int main(void)
{
    int a1[] = {1, 3};
    int a2[] = {2};
    printf("%.2f (want 2.00)\n", findMedianSortedArrays(a1, 2, a2, 1));

    int b1[] = {1, 2};
    int b2[] = {3, 4};
    printf("%.2f (want 2.50)\n", findMedianSortedArrays(b1, 2, b2, 2));

    int c1[] = {0, 0};
    int c2[] = {0, 0};
    printf("%.2f (want 0.00)\n", findMedianSortedArrays(c1, 2, c2, 2));

    return 0;
}