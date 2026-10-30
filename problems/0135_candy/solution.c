/*
 * Candy (LeetCode #135, Hard)
 *
 * Two passes enforce the rating rule from each direction. Taking the larger
 * requirement at every position satisfies both adjacent comparisons.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution. Returns the minimum number of candies. */
int candy(int *ratings, int ratingsSize)
{
    if (ratings == NULL || ratingsSize <= 0)
        return 0;

    int *candies = (int *)malloc((size_t)ratingsSize * sizeof(int));
    if (candies == NULL)
        return 0;

    for (int i = 0; i < ratingsSize; i++)
        candies[i] = 1;

    for (int i = 1; i < ratingsSize; i++)
    {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    for (int i = ratingsSize - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1] &&
            candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    }

    int total = 0;
    for (int i = 0; i < ratingsSize; i++)
        total += candies[i];

    free(candies);
    return total;
}

int main(void)
{
    int ratings1[] = {1, 0, 2};
    printf("[1,0,2] -> %d (expected 5)\n", candy(ratings1, 3));

    int ratings2[] = {1, 2, 2};
    printf("[1,2,2] -> %d (expected 4)\n", candy(ratings2, 3));
    return 0;
}
