#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int* LIS = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        LIS[i] = 1;
    }

    for (int i = numsSize - 1; i >= 0; --i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] < nums[j]) {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
    }

    int maxLIS = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (LIS[i] > maxLIS) {
            maxLIS = LIS[i];
        }
    }

    free(LIS);

    return maxLIS;
}

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3:

// Runtime reduced by a factor of 10 to not skew data visualization