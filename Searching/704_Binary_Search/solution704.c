#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] > target) {
            r = m - 1;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            return m;
        }
    }

    return -1;
}

// Runtime1: 0ms, beats 100%
// Memory1: 9.13MB, beats 55.56%

// Runtime2: 0ms, beats 100%
// Memory2: 9.16MB, beats 56.48%

// Runtime3: 0ms, beats 100%
// Memory3: 9.14MB, beats 56.48%