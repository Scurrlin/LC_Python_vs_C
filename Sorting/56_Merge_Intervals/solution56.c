#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    result[0] = (int*)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;
    *returnSize = 1;

    for (int i = 1; i < intervalsSize; ++i) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        int* lastInterval = result[*returnSize - 1];

        if (start <= lastInterval[1]) {

            if (end > lastInterval[1]) {
                lastInterval[1] = end;
            }
        } else {
            result[*returnSize] = (int*)malloc(2 * sizeof(int));
            result[*returnSize][0] = start;
            result[*returnSize][1] = end;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }

    return result;
}

// Runtime1: 4ms, beats 95.77%
// Memory1: 17.88MB, beats 69.05%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: