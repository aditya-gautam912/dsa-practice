/*
 * LeetCode #49: Group Anagrams
 * Difficulty: Medium
 *
 * Human approach:
 * Anagrams are words made of the same letters. If we sort the letters of
 * every word, all anagrams look the same. So we sort each word, and use
 * that sorted word as a "label". Words sharing a label belong to the same
 * group. We put each word next to its label and print groups at the end.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 104
#define MAXGROUP 104

static int cmpChar(const void *a, const void *b)
{
    return *(const char *)a - *(const char *)b;
}

/* Human-readable grouping.
   Returns a newline-separated printout of the groups. */
void groupAnagrams(char str[][MAX], int count)
{
    /* store sorted label -> for each, a list of original words */
    char labels[count][MAX];
    char groups[count][MAX][MAX];  /* [group][slot][word] */
    int groupLen[count];
    int groupCount = 0;

    for (int i = 0; i < count; i++)
    {
        char sorted[MAX];
        strcpy(sorted, str[i]);
        qsort(sorted, strlen(sorted), sizeof(char), cmpChar);

        int found = -1;
        for (int g = 0; g < groupCount; g++)
        {
            if (strcmp(labels[g], sorted) == 0)
            {
                found = g;
                break;
            }
        }

        if (found == -1)
        {
            groupCount++;
            int g = groupCount - 1;
            strcpy(labels[g], sorted);
            groupLen[g] = 0;
            found = g;
        }

        strcpy(groups[found][groupLen[found]], str[i]);
        groupLen[found]++;
    }

    for (int g = 0; g < groupCount; g++)
    {
        printf("[");
        for (int k = 0; k < groupLen[g]; k++)
        {
            printf("%s", groups[g][k]);
            if (k < groupLen[g] - 1)
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