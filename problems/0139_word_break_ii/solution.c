/*
 * Word Break II (LeetCode #139, Hard)
 *
 * DFS with memoization. At a starting position, try every
 * dictionary word that matches the string there, then append
 * each sentence returned for the remaining suffix. Memoizing
 * each position prevents solving the same suffix repeatedly.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char **items;
    int count;
    int capacity;
} Sentences;

static char *text;
static char **dictionary;
static int dictionarySize;
static int textLength;
static Sentences *memo;
static char *solved;

static void add_sentence(Sentences *list, const char *word,
                          const char *suffix)
{
    int wordLen = (int)strlen(word);
    int suffixLen = (int)strlen(suffix);
    int totalLen = wordLen + (suffixLen == 0 ? 0 : suffixLen + 1);
    char *sentence = (char *)malloc((totalLen + 1) * sizeof(char));

    strcpy(sentence, word);
    if (suffixLen > 0)
    {
        sentence[wordLen] = ' ';
        strcpy(sentence + wordLen + 1, suffix);
    }

    if (list->count == list->capacity)
    {
        list->capacity = list->capacity == 0 ? 4 : list->capacity * 2;
        list->items = (char **)realloc(list->items,
                                       list->capacity * sizeof(char *));
    }
    list->items[list->count++] = sentence;
}

static Sentences *solve_from(int start)
{
    if (solved[start])
        return &memo[start];
    solved[start] = 1;

    Sentences *answer = &memo[start];
    if (start == textLength)
    {
        answer->items = (char **)malloc(sizeof(char *));
        answer->items[0] = (char *)malloc(1);
        answer->items[0][0] = '\0';
        answer->count = 1;
        answer->capacity = 1;
        return answer;
    }

    for (int d = 0; d < dictionarySize; d++)
    {
        int wordLen = (int)strlen(dictionary[d]);
        if (start + wordLen > textLength)
            continue;
        if (strncmp(text + start, dictionary[d], wordLen) != 0)
            continue;

        Sentences *suffixes = solve_from(start + wordLen);
        for (int s = 0; s < suffixes->count; s++)
            add_sentence(answer, dictionary[d], suffixes->items[s]);
    }
    return answer;
}

/* LeetCode solution. Returns every valid sentence. */
char **wordBreak(char *s, char **wordDict, int wordDictSize,
                 int *returnSize)
{
    text = s;
    dictionary = wordDict;
    dictionarySize = wordDictSize;
    textLength = (int)strlen(s);
    memo = (Sentences *)calloc(textLength + 1, sizeof(Sentences));
    solved = (char *)calloc(textLength + 1, sizeof(char));

    Sentences *answer = solve_from(0);
    char **result = answer->items;
    *returnSize = answer->count;

    /* The root's array is returned; all other memoized strings are temporary. */
    for (int i = 1; i <= textLength; i++)
    {
        for (int j = 0; j < memo[i].count; j++)
            free(memo[i].items[j]);
        free(memo[i].items);
    }
    free(memo);
    free(solved);
    return result;
}

static void print_sentences(char **result, int count)
{
    printf("[");
    for (int i = 0; i < count; i++)
    {
        printf("\"%s\"", result[i]);
        if (i + 1 < count)
            printf(", ");
        free(result[i]);
    }
    printf("]\n");
    free(result);
}

int main(void)
{
    char s1[] = "catsanddog";
    char *dict1[] = {"cat", "cats", "and", "sand", "dog"};
    int count1;
    char **r1 = wordBreak(s1, dict1, 5, &count1);
    printf("catsanddog -> ");
    print_sentences(r1, count1);

    char s2[] = "pineapplepenapple";
    char *dict2[] = {"apple", "pen", "applepen", "pine", "pineapple"};
    int count2;
    char **r2 = wordBreak(s2, dict2, 5, &count2);
    printf("pineapplepenapple -> ");
    print_sentences(r2, count2);

    char s3[] = "catsandog";
    char *dict3[] = {"cats", "dog", "sand", "and", "cat"};
    int count3;
    char **r3 = wordBreak(s3, dict3, 5, &count3);
    printf("catsandog -> ");
    print_sentences(r3, count3);
    return 0;
}
