#include <stdio.h>
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, int startIndex, int* currentCombination, int currentSize, int** result, int* resultSize, int* resultColSizes);

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(150 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(150 * sizeof(int));

    int* currentCombination = (int*)malloc(1000 * sizeof(int));
    int resultSize = 0;

    backtrack(candidates, candidatesSize, target, 0, currentCombination, 0, result, &resultSize, *returnColumnSizes);

    *returnSize = resultSize;

    free(currentCombination);
    return result;
}

void backtrack(int* candidates, int candidatesSize, int target, int startIndex, int* currentCombination, int currentSize, int** result, int* resultSize, int* resultColSizes) {
    if (target == 0) {
        result[*resultSize] = (int*)malloc(currentSize * sizeof(int));
        for (int i = 0; i < currentSize; ++i) {
            result[*resultSize][i] = currentCombination[i];
        }
        resultColSizes[*resultSize] = currentSize;
        (*resultSize)++;
        return;
    }

    for (int i = startIndex; i < candidatesSize; ++i) {
        if (candidates[i] > target) continue;

        currentCombination[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i, currentCombination, currentSize + 1, result, resultSize, resultColSizes);
    }
}

// Runtime1: 0ms, beats 100%
// Memory1: 13.20MB, beats 33.23%

// Runtime2: 0ms, beats 100%
// Memory2: 12.82MB, beats 40.97%

// Runtime3: 0ms, beats 100%
// Memory3: 13.20MB, beats 33.23%