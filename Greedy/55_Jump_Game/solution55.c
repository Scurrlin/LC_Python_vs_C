#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int goal = numsSize - 1;

    for (int i = numsSize - 2; i >= 0; --i) {
        if (i + nums[i] >= goal) {
            goal = i;
        }
    }

    return goal == 0;
}

// Runtime1: 0ms, beats 100%
// Memory1: 10.45MB, beats 53%

// Runtime2: 0ms, beats 100%
// Memory2: 10.61MB, beats 25.05%

// Runtime3: 0ms, beats 100%
// Memory3: 10.69MB, beats 25.05%

// Runtime reduced by a factor of 10 to not skew data visualization