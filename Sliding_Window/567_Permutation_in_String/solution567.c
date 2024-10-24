#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);

    if (len1 > len2) {
        return false;
    }

    int s1Count[26] = {0}, s2Count[26] = {0};

    for (int i = 0; i < len1; ++i) {
        s1Count[s1[i] - 'a']++;
        s2Count[s2[i] - 'a']++;
    }

    int matches = 0;
    for (int i = 0; i < 26; ++i) {
        if (s1Count[i] == s2Count[i]) {
            matches++;
        }
    }

    int l = 0;
    for (int r = len1; r < len2; ++r) {
        if (matches == 26) {
            return true;
        }

        int index = s2[r] - 'a';
        s2Count[index]++;
        if (s1Count[index] == s2Count[index]) {
            matches++;
        } else if (s1Count[index] + 1 == s2Count[index]) {
            matches--;
        }

        index = s2[l] - 'a';
        s2Count[index]--;
        if (s1Count[index] == s2Count[index]) {
            matches++;
        } else if (s1Count[index] - 1 == s2Count[index]) {
            matches--;
        }
        l++;
    }

    return matches == 26;
}

// Runtime1: 0ms, beats 100%
// Memory1: 8.20MB, beats 68.62%

// Runtime2: 0ms, beats 100%
// Memory2: 8.34MB, beats 34.42%

// Runtime3: 2ms, beats 73.04%
// Memory3: 8MB, beats 99.28%