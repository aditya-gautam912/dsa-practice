/*
 * LeetCode #66: Plus One
 * Difficulty: Easy
 *
 * Human approach:
 * Work from the last digit. If it is below 9, just add one and we are
 * done. If it is 9, it becomes 0 and we carry the 1 to the next digit.
 * If every digit was 9, we need a new leading 1 and all other digits 0.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution.
 * Returns a freshly allocated array. *returnSize gives its length. */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            int *res = (int *)malloc(digitsSize * sizeof(int));
            for (int k = 0; k < digitsSize; k++)
                res[k] = digits[k];
            res[i]++;
            *returnSize = digitsSize;
            return res;
        }
        digits[i] = 0;
    }

    int *res = (int *)malloc((digitsSize + 1) * sizeof(int));
    res[0] = 1;
    for (int k = 1; k <= digitsSize; k++)
        res[k] = 0;
    *returnSize = digitsSize + 1;
    return res;
}

int main(void)
{
    int n1[] = {1, 2, 3};
    int n2[] = {9};
    int n3[] = {9, 9, 9};
    int retSize;
    int *res;

    res = plusOne(n1, 3, &retSize);
    printf("Test 1: ");
    for (int i = 0; i < retSize; i++)
        printf("%d", res[i]);
    printf("\n");
    free(res);

    res = plusOne(n2, 1, &retSize);
    printf("Test 2: ");
    for (int i = 0; i < retSize; i++)
        printf("%d", res[i]);
    printf("\n");
    free(res);

    res = plusOne(n3, 3, &retSize);
    printf("Test 3: ");
    for (int i = 0; i < retSize; i++)
        printf("%d", res[i]);
    printf("\n");
    free(res);

    return 0;
}