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

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3:

// Runtime reduced by a factor of 10 to not skew data visualization