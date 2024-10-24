#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int rob(int* nums, int numsSize) {
    int rob1 = 0, rob2 = 0;

    for (int i = 0; i < numsSize; ++i) {
        int temp = max(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }

    return rob2;
}

// Runtime1: 0ms, beats 100%
// Memory1: 8.22MB, beats 8.53%

// Runtime2: 0ms, beats 100%
// Memory2: 7.99MB, beats 59.18%

// Runtime3: 0ms, beats 100%
// Memory3: 7.88MB, beats 88.13%