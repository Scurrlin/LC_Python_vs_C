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

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: