#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }

    qsort(result, numsSize, sizeof(int), compare);

    *returnSize = numsSize;
    return result;
}

// Runtime1: 30ms, beats 98.76%
// Memory1: 62.67MB, beats 31.55%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3:

// Runtime reduced by a factor of 10 to not skew data visualization