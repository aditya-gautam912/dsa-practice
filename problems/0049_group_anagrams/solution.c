/*
 * Group Anagrams (LeetCode #49, Medium)
 *
 * Anagrams = same letters, different order. So sort the letters of
 * every word and anagrams collapse to the same "signature". Bucket
 * words by signature and print the buckets. Simple, and it was my
 * intro to "hash by canonical form".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 104

static int cmpChar(const void *a, const void *b)
{
    return *(const char *)a - *(const char *)b;
}

/* Prints the groups directly, keeps main() short. */
void groupAnagrams(char str[][MAX], int count)
{
    char signatures[count][MAX];
    char buckets[count][MAX][MAX];
    int sizes[count];
    int groups = 0;

    for (int i = 0; i < count; i++)
    {
        char sig[MAX];
        strcpy(sig, str[i]);
        qsort(sig, strlen(sig), sizeof(char), cmpChar);

        int idx = -1;
        for (int g = 0; g < groups; g++)
            if (strcmp(signatures[g], sig) == 0)
            {
                idx = g;
                break;
            }

        if (idx == -1)
        {
            idx = groups;
            groups++;
            strcpy(signatures[idx], sig);
            sizes[idx] = 0;
        }

        strcpy(buckets[idx][sizes[idx]++], str[i]);
    }

    for (int g = 0; g < groups; g++)
    {
        printf("[");
        for (int k = 0; k < sizes[g]; k++)
        {
            printf("%s", buckets[g][k]);
            if (k + 1 < sizes[g])
                printf(", ");
        }
        printf("]\n");
    }
}

int main(void)
{
    char input[][MAX] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(input, 6);
    return 0;
}