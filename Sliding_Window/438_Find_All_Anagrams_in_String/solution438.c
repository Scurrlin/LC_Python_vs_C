#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int sLen = strlen(s), pLen = strlen(p);
    *returnSize = 0;

    if (sLen < pLen) {
        return NULL;
    }

    int pMap[26] = {0}, sMap[26] = {0};
    int* res = (int*)malloc(sLen * sizeof(int));

    for (int i = 0; i < pLen; ++i) {
        pMap[p[i] - 'a']++;
        sMap[s[i] - 'a']++;
    }

    for (int i = pLen; i <= sLen; ++i) {
        int isAnagram = 1;
        for (int j = 0; j < 26; ++j) {
            if (pMap[j] != sMap[j]) {
                isAnagram = 0;
                break;
            }
        }
        
        if (isAnagram) {
            res[*returnSize] = i - pLen;
            (*returnSize)++;
        }

        if (i < sLen) {
            sMap[s[i - pLen] - 'a']--;
            sMap[s[i] - 'a']++;
        }
    }

    return res;
}

// Runtime1: 0ms, beats 100%
// Memory1: 13.95MB, beats 65.38%

// Runtime2: 4ms, beats 96.25%
// Memory2: 13.93MB, beats 65%

// Runtime3: 4ms, beats 96.25%
// Memory3: 13.92MB, beats 65%