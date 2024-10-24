#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {

    int** result = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));

    int idx = 0;
    int inserted = 0;

    for (int i = 0; i < intervalsSize; ++i) {

        if (!inserted && newInterval[1] < intervals[i][0]) {
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = newInterval[0];
            result[idx][1] = newInterval[1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
            inserted = 1;
        }
        
        if (newInterval[0] > intervals[i][1]) {
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
        else if (!(newInterval[1] < intervals[i][0] || newInterval[0] > intervals[i][1])) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        else {
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    if (!inserted) {
        result[idx] = (int*)malloc(2 * sizeof(int));
        result[idx][0] = newInterval[0];
        result[idx][1] = newInterval[1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
    }

    *returnSize = idx;
    return result;
}

// Runtime1: 0ms, beats 100%
// Memory1: 13.66MB, beats 57.41%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: