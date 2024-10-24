#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int charIndex[128] = {0};
    int l = 0, res = 0;

    for (int r = 0; r < n; ++r) {
        while (charIndex[(int)s[r]] > 0) {
            charIndex[(int)s[l]]--;
            l++;
        }
        
        charIndex[(int)s[r]]++;
        
        if (r - l + 1 > res) {
            res = r - l + 1;
        }
    }

    return res;
}

// Runtime1: 0ms, beats 100%
// Memory1: 9.60MB, beats 60.99%

// Runtime2: 0ms, beats 100%
// Memory2: 9.77MB, beats 31.91%

// Runtime3: 0ms, beats 100%
// Memory3: 9.64MB, beats 47.55%