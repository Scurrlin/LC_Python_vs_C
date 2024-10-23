#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* pointA = *(int**)a;
    int* pointB = *(int**)b;
    
    if (pointA[1] < pointB[1]) {
        return -1;
    } else if (pointA[1] > pointB[1]) {
        return 1;
    } else {
        return 0;
    }
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) {
        return 0;
    }

    qsort(points, pointsSize, sizeof(int*), compare);

    int arrows = 1;
    int end = points[0][1];

    for (int i = 1; i < pointsSize; ++i) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }

    return arrows;
}

// Runtime1: 29ms, beats 100%
// Memory1: 36.66MB, beats 27.96%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3:

// Runtime reduced by a factor of 10 to not skew data visualization