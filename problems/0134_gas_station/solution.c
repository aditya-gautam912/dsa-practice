/*
 * Gas Station (LeetCode #134, Medium)
 *
 * If the total amount of gas is at least the total cost, a valid start exists.
 * When the running fuel becomes negative, every station up to that point is
 * invalid as a start, so the next station becomes the new candidate.
 */

#include <stdio.h>

/* LeetCode solution. Returns the valid starting station or -1. */
int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
    if (gas == NULL || cost == NULL || gasSize != costSize)
        return -1;

    int total = 0;
    int tank = 0;
    int start = 0;

    for (int i = 0; i < gasSize; i++)
    {
        int difference = gas[i] - cost[i];
        total += difference;
        tank += difference;

        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }

    return total >= 0 ? start : -1;
}

int main(void)
{
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    printf("start = %d (expected 3)\n",
           canCompleteCircuit(gas, 5, cost, 5));

    int gas2[] = {2, 3, 4};
    int cost2[] = {3, 4, 3};
    printf("start = %d (expected -1)\n",
           canCompleteCircuit(gas2, 3, cost2, 3));
    return 0;
}
