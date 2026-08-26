/*
 * Permutations (LeetCode #46, Medium)
 *
 * Classic backtracking by swapping: fix each element at the
 * current position and recurse on the rest. When we reach the
 * end, we have a complete permutation. Swapping back restores
 * the array for the next branch. No extra "used" array needed.
 */

#include <stdio.h>
#include <stdlib.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static void backtrack(int *nums, int n, int start,
                      int **res, int *cols, int *count)
{
    if (start == n)
    {
        int *perm = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            perm[i] = nums[i];
        res[*count] = perm;
        cols[*count] = n;
        (*count)++;
        return;
    }

    for (int i = start; i < n; i++)
    {
        swap(&nums[start], &nums[i]);
        backtrack(nums, n, start + 1, res, cols, count);
        swap(&nums[start], &nums[i]); /* restore */
    }
}

/* LeetCode solution. Returns all permutations of nums. */
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int fact = 1;
    for (int i = 2; i <= numsSize; i++)
        fact *= i;

    int **res = (int **)malloc(fact * sizeof(int *));
    int *cols = (int *)malloc(fact * sizeof(int));
    int count = 0;

    backtrack(nums, numsSize, 0, res, cols, &count);

    *returnSize = count;
    *returnColumnSizes = cols;
    return res;
}

static void print_perms(int **res, int count, int *cols)
{
    printf("%d permutation(s):\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("[");
        for (int j = 0; j < cols[i]; j++)
        {
            printf("%d", res[i][j]);
            if (j + 1 < cols[i])
                printf(", ");
        }
        printf("]\n");
        free(res[i]);
    }
    free(res);
    free(cols);
}

int main(void)
{
    int n1[] = {1, 2, 3};
    int sz1, *cols1;
    int **r1 = permute(n1, 3, &sz1, &cols1);
    printf("[1,2,3]\n");
    print_perms(r1, sz1, cols1);

    int n2[] = {0, 1};
    int sz2, *cols2;
    int **r2 = permute(n2, 2, &sz2, &cols2);
    printf("[0,1]\n");
    print_perms(r2, sz2, cols2);

    int n3[] = {1};
    int sz3, *cols3;
    int **r3 = permute(n3, 1, &sz3, &cols3);
    printf("[1]\n");
    print_perms(r3, sz3, cols3);
    return 0;
}