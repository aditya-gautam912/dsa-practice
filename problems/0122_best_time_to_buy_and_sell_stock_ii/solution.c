/*
 * Best Time to Buy and Sell Stock II (LeetCode #122, Medium)
 *
 * Unlimited transactions allowed. Peak-valley approach:
 * capture every upward slope — buy at each valley, sell at
 * each peak. Simply sum all positive price differences
 * between consecutive days.
 */

#include <stdio.h>

/* LeetCode solution. Returns maximum profit from multiple
 * buy-sell transactions. */
int maxProfit(int *prices, int pricesSize)
{
    int total = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] > prices[i - 1])
            total += prices[i] - prices[i - 1];
    }
    return total;
}

int main(void)
{
    int p1[] = {7, 1, 5, 3, 6, 4};
    printf("[7,1,5,3,6,4] -> %d (expected 7)\n", maxProfit(p1, 6));

    int p2[] = {1, 2, 3, 4, 5};
    printf("[1,2,3,4,5]   -> %d (expected 4)\n", maxProfit(p2, 5));

    int p3[] = {7, 6, 4, 3, 1};
    printf("[7,6,4,3,1]   -> %d (expected 0)\n", maxProfit(p3, 5));
    return 0;
}