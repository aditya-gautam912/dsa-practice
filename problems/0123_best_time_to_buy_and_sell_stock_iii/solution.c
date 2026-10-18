/*
 * Best Time to Buy and Sell Stock III (LeetCode #123, Hard)
 *
 * At most TWO transactions. Track four states across days:
 *   buy1  — max profit after first buy  (most negative cost)
 *   sell1  — max profit after first sell
 *   buy2   — max profit after second buy (sell1 - price)
 *   sell2  — max profit after second sell (final answer)
 * One pass, O(1) space.
 */

#include <stdio.h>
#include <limits.h>

/* LeetCode solution. Returns maximum profit from at most
 * two buy-sell transactions. */
int maxProfit(int *prices, int pricesSize)
{
    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;

    for (int i = 0; i < pricesSize; i++)
    {
        int p = prices[i];
        if (-p > buy1)   buy1 = -p;          /* first buy */
        if (buy1 + p > sell1) sell1 = buy1 + p;  /* first sell */
        if (sell1 - p > buy2) buy2 = sell1 - p;    /* second buy */
        if (buy2 + p > sell2) sell2 = buy2 + p;    /* second sell */
    }
    return sell2;
}

int main(void)
{
    int p1[] = {3, 3, 5, 0, 0, 3, 1, 4};
    printf("[3,3,5,0,0,3,1,4] -> %d (expected 6)\n", maxProfit(p1, 8));

    int p2[] = {1, 2, 3, 4, 5};
    printf("[1,2,3,4,5]         -> %d (expected 4)\n", maxProfit(p2, 5));

    int p3[] = {7, 6, 4, 3, 1};
    printf("[7,6,4,3,1]         -> %d (expected 0)\n", maxProfit(p3, 5));
    return 0;
}