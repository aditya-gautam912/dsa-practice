/*
 * Text Justification (LeetCode #68, Hard)
 *
 * Greedy pack words into lines: keep adding words while the
 * total length + minimum one-space-between ≤ maxWidth. For
 * each full line (except the last), distribute extra spaces
 * as evenly as possible — left slots get the extra. Last line
 * is left-justified with single spaces and padded on the right.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LeetCode solution. Returns the fully justified lines. */
char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize)
{
    char **res = (char **)malloc(wordsSize * sizeof(char *));
    int count = 0;

    int start = 0;          /* first word in current line */
    int len = 0;            /* sum of word lengths in line */

    for (int i = 0; i < wordsSize; i++)
    {
        int wlen = strlen(words[i]);
        if (len + wlen + (i - start) > maxWidth)
        {
            /* words[start..i-1] fit in this line */
            int spaces = maxWidth - len;
            int gaps = i - start - 1;
            char *line = (char *)malloc((maxWidth + 1) * sizeof(char));
            int pos = 0;

            if (gaps == 0)
            {
                /* only one word — left justify */
                pos += sprintf(line, "%s", words[start]);
                while (pos < maxWidth)
                    line[pos++] = ' ';
            }
            else
            {
                int base = spaces / gaps;
                int extra = spaces % gaps;
                for (int j = 0; j < gaps; j++)
                {
                    pos += sprintf(line + pos, "%s", words[start + j]);
                    int sp = base + (j < extra ? 1 : 0);
                    for (int k = 0; k < sp; k++)
                        line[pos++] = ' ';
                }
                pos += sprintf(line + pos, "%s", words[i - 1]);
            }
            line[maxWidth] = '\0';
            res[count++] = line;

            start = i;
            len = wlen;
        }
        else
        {
            len += wlen;
        }
    }

    /* last line: left justify with single spaces */
    char *last = (char *)malloc((maxWidth + 1) * sizeof(char));
    int pos = 0;
    for (int i = start; i < wordsSize; i++)
    {
        pos += sprintf(last + pos, "%s", words[i]);
        if (i + 1 < wordsSize)
            last[pos++] = ' ';
    }
    while (pos < maxWidth)
        last[pos++] = ' ';
    last[maxWidth] = '\0';
    res[count++] = last;

    *returnSize = count;
    return res;
}

static void print_justify(char **lines, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("'%s'\n", lines[i]);
        free(lines[i]);
    }
    free(lines);
}

int main(void)
{
    char *words1[] = {"This", "is", "an", "example", "of", "text", "justification."};
    int sz1;
    char **res1 = fullJustify(words1, 7, 16, &sz1);
    printf("Test 1:\n");
    print_justify(res1, sz1);

    char *words2[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int sz2;
    char **res2 = fullJustify(words2, 6, 16, &sz2);
    printf("Test 2:\n");
    print_justify(res2, sz2);
    return 0;
}