/*
 * Longest Consecutive Sequence (LeetCode #128, Medium)
 *
 * O(n) with a hash set. Put every number in a set. A number
 * is the START of a sequence only if num-1 is not in the set;
 * from each start, count upward until the run breaks.
 * Each element is visited at most twice, so total is O(n).
 */

#include <stdio.h>
#include <stdlib.h>

#define CAP 100003

typedef struct
{
    int *key;
    char *used;
} HashSet;

static unsigned int hashInt(int k)
{
    return ((unsigned int)k * 2654435761u) % CAP;
}

static void hsInit(HashSet *s)
{
    s->key = (int *)malloc(CAP * sizeof(int));
    s->used = (char *)calloc(CAP, sizeof(char));
}

static void hsInsert(HashSet *s, int k)
{
    unsigned int i = hashInt(k);
    while (s->used[i])
    {
        if (s->key[i] == k)
            return;         /* already present */
        i = (i + 1) % CAP;
    }
    s->key[i] = k;
    s->used[i] = 1;
}

static int hsContains(HashSet *s, int k)
{
    unsigned int i = hashInt(k);
    while (s->used[i])
    {
        if (s->key[i] == k)
            return 1;
        i = (i + 1) % CAP;
    }
    return 0;
}

static void hsFree(HashSet *s)
{
    free(s->key);
    free(s->used);
}

/* LeetCode solution. Returns length of longest consecutive run. */
int longestConsecutive(int *nums, int numsSize)
{
    HashSet s;
    hsInit(&s);
    for (int i = 0; i < numsSize; i++)
        hsInsert(&s, nums[i]);

    int longest = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (hsContains(&s, nums[i] - 1))
            continue;               /* not the start of a run */

        int len = 1;
        while (hsContains(&s, nums[i] + len))
            len++;
        if (len > longest)
            longest = len;
    }

    hsFree(&s);
    return longest;
}

int main(void)
{
    int n1[] = {100, 4, 200, 1, 3, 2};
    printf("[100,4,200,1,3,2] -> %d (expected 4)\n", longestConsecutive(n1, 6));

    int n2[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    printf("[0,3,7,2,5,8,4,6,0,1] -> %d (expected 9)\n", longestConsecutive(n2, 10));
    return 0;
}