#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubArray(int* nums, int numsSize) {
    int res = nums[0];
    int total = 0;

    for (int i = 0; i < numsSize; ++i) {
        total += nums[i];
        res = max(res, total);
        if (total < 0) {
            total = 0;
        }
    }

    return res;
}

// Runtime1: 0ms, beats 100%
// Memory1: 14.58MB, beats 61.03%

// Runtime2: 0ms, beats 100%
// Memory2: 14.64MB, beats 36.10%

// Runtime3: 0ms, beats 100%
// Memory3: 14.53MB, beats 61.03%

// Runtime reduced by a factor of 10 to not skew data visualization