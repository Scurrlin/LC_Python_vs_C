#include <stdio.h>

void reverseString(char* s, int sSize) {
    int l = 0, r = sSize - 1;

    while (l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;

        l++;
        r--;
    }
}

// Runtime1: 0ms, beats 100%
// Memory1: 17.17MB, beats 28.75%

// Runtime2: 2ms, beats 91.54%
// Memory2: 17.31MB, beats 16.10%

// Runtime3: 0ms, beats 100%
// Memory3: 17.26MB, beats 16.10%