/*
 * Merge Sorted Array (LeetCode #88, Easy)
 *
 * Merge nums2 into nums1 in-place. Both are sorted.
 * Since nums1 has extra space at the end, fill from the
 * back: compare the largest remaining elements of nums1
 * (index m-1) and nums2 (index n-1), write the larger one
 * at the end of nums1 (index m+n-1). No auxiliary array needed.
 */

#include <stdio.h>

/* LeetCode solution. Modifies nums1 in place. */
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i = m - 1;          /* last valid element of nums1 */
    int j = n - 1;          /* last element of nums2 */
    int k = m + n - 1;      /* write position */

    while (i >= 0 && j >= 0)
    {
        nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
    while (j >= 0)
        nums1[k--] = nums2[j--];
}

static void print_arr(int *a, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i + 1 < n)
            printf(",");
    }
    printf("]\n");
}

int main(void)
{
    int n1[] = {1, 2, 3, 0, 0, 0};
    int n2[] = {2, 5, 6};
    merge(n1, 6, 3, n2, 3, 3);
    printf("test1 -> ");
    print_arr(n1, 6);

    int n3[] = {1};
    int n4[] = {};
    merge(n3, 1, 1, n4, 0, 0);
    printf("test2 -> ");
    print_arr(n3, 1);

    int n5[] = {0};
    int n6[] = {1};
    merge(n5, 1, 0, n6, 1, 1);
    printf("test3 -> ");
    print_arr(n5, 1);
    return 0;
}