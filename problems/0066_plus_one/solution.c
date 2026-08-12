/*
 * Plus One (LeetCode #66, Easy)
 *
 * Walk from the units digit. Below 9? Add one and we're done.
 * It's a 9: becomes 0, carry the 1 left. Only gotcha is when the
 * whole number is 9s - then we need one extra slot up front.
 */

#include <stdio.h>
#include <stdlib.h>

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
    int n, *out;

    out = plusOne(n1, 3, &n);
    printf("got: ");
    for (int i = 0; i < n; i++)
        printf("%d", out[i]);
    printf(" (want 124)\n");
    free(out);

    out = plusOne(n2, 1, &n);
    printf("got: ");
    for (int i = 0; i < n; i++)
        printf("%d", out[i]);
    printf(" (want 10)\n");
    free(out);

    out = plusOne(n3, 3, &n);
    printf("got: ");
    for (int i = 0; i < n; i++)
        printf("%d", out[i]);
    printf(" (want 1000)\n");
    free(out);

    return 0;
}