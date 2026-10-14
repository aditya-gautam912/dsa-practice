/*
 * Best Time to Buy and Sell Stock (LeetCode #121, Easy)
 *
 * One pass: track the lowest price seen so far. At each
 * price, compute the profit if we sold today, and keep
 * the best profit. Single O(1) scan.
 */

#include <stdio.h>

/* LeetCode solution. Returns maximum profit (0 if no profit). */
int maxProfit(int *prices, int pricesSize)
{
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;
    }
    return maxProfit;
}

int main(void)
{
    int p1[] = {7, 1, 5, 3, 6, 4};
    printf("[7,1,5,3,6,4] -> %d (expected 5)\n", maxProfit(p1, 6));

    int p2[] = {7, 6, 4, 3, 1};
    printf("[7,6,4,3,1]   -> %d (expected 0)\n", maxProfit(p2, 5));
    return 0;
}