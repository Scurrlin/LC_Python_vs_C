#include <stdio.h>
#include <stdlib.h>

void dfs(int* nums, int numsSize, int index, int* currentSubset, int currentSize, int** result, int* resultSize, int* resultColSizes);

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(1024 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1024 * sizeof(int));

    int* currentSubset = (int*)malloc(numsSize * sizeof(int));
    int resultSize = 0;

    dfs(nums, numsSize, 0, currentSubset, 0, result, &resultSize, *returnColumnSizes);

    *returnSize = resultSize;

    free(currentSubset);
    return result;
}

void dfs(int* nums, int numsSize, int index, int* currentSubset, int currentSize, int** result, int* resultSize, int* resultColSizes) {
    result[*resultSize] = (int*)malloc(currentSize * sizeof(int));
    for (int i = 0; i < currentSize; ++i) {
        result[*resultSize][i] = currentSubset[i];
    }
    resultColSizes[*resultSize] = currentSize;
    (*resultSize)++;

    for (int i = index; i < numsSize; ++i) {
        currentSubset[currentSize] = nums[i];
        dfs(nums, numsSize, i + 1, currentSubset, currentSize + 1, result, resultSize, resultColSizes);
    }
}

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: