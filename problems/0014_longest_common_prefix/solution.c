/*
 * Longest Common Prefix (LeetCode #14, Easy)
 *
 * Horizontal scanning: take the first string as the prefix and
 * shrink it character by character until every other string
 * starts with it. Since the prefix can only get shorter as we
 * compare more strings, this is the simplest O(n*m) approach.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LeetCode solution. Returns the longest common prefix of all
 * strings (caller frees the returned string). */
char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
        return strdup("");

    char *prefix = strdup(strs[0]);

    for (int i = 1; i < strsSize; i++)
    {
        int len = 0;
        while (prefix[len] != '\0' && strs[i][len] != '\0' &&
               prefix[len] == strs[i][len])
            len++;
        prefix[len] = '\0';
        if (len == 0)
            break; /* nothing in common with this string, done */
    }

    return prefix;
}

int main(void)
{
    char *s1[] = {"flower", "flow", "flight"};
    char *s2[] = {"dog", "racecar", "car"};
    char *s3[] = {"interspecies", "interstellar", "interstate"};

    char *p;

    p = longestCommonPrefix(s1, 3);
    printf("[\"flower\",\"flow\",\"flight\"] -> \"%s\"\n", p);
    free(p);

    p = longestCommonPrefix(s2, 3);
    printf("[\"dog\",\"racecar\",\"car\"]   -> \"%s\"\n", p);
    free(p);

    p = longestCommonPrefix(s3, 3);
    printf("[\"interspecies\",...]         -> \"%s\"\n", p);
    free(p);
    return 0;
}