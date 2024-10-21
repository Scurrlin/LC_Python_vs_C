#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int* currentPerm, int currentSize, int* used, int** result, int* resultSize, int* resultColSizes);

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(720 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(720 * sizeof(int));
    
    int* currentPerm = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));
    
    int resultSize = 0;

    backtrack(nums, numsSize, currentPerm, 0, used, result, &resultSize, *returnColumnSizes);

    *returnSize = resultSize;

    free(currentPerm);
    free(used);

    return result;
}

void backtrack(int* nums, int numsSize, int* currentPerm, int currentSize, int* used, int** result, int* resultSize, int* resultColSizes) {
    if (currentSize == numsSize) {
        result[*resultSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; ++i) {
            result[*resultSize][i] = currentPerm[i];
        }
        resultColSizes[*resultSize] = numsSize;
        (*resultSize)++;
        return;
    }

    for (int i = 0; i < numsSize; ++i) {
        if (!used[i]) {
            used[i] = 1;
            currentPerm[currentSize] = nums[i];
            backtrack(nums, numsSize, currentPerm, currentSize + 1, used, result, resultSize, resultColSizes);
            used[i] = 0;
        }
    }
}

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: