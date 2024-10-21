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

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: