#include <stdbool.h>

bool divide_and_conquer(int** matrix, int min_i, int min_j, int max_i, int max_j, int target);

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return false;
    }

    return divide_and_conquer(matrix, 0, 0, matrixSize - 1, matrixColSize[0] - 1, target);
}

bool divide_and_conquer(int** matrix, int min_i, int min_j, int max_i, int max_j, int target) {
    if (min_i > max_i || min_j > max_j) {
        return false;
    }

    int med_i = (min_i + max_i) / 2;
    int med_j = (min_j + max_j) / 2;

    if (matrix[med_i][med_j] == target) {
        return true;
    }

    if (matrix[med_i][med_j] > target) {
        if (divide_and_conquer(matrix, min_i, min_j, max_i, med_j - 1, target)) {
            return true;
        }
        if (divide_and_conquer(matrix, min_i, med_j, med_i - 1, max_j, target)) {
            return true;
        }
    } else {
        if (divide_and_conquer(matrix, med_i + 1, min_j, max_i, max_j, target)) {
            return true;
        }
        if (divide_and_conquer(matrix, min_i, med_j + 1, med_i, max_j, target)) {
            return true;
        }
    }

    return false;
}

// Runtime1: 144ms, beats 37.68%
// Memory1: 11.70MB, beats 98.07%

// Runtime2: 147ms, beats 37.68%
// Memory2: 11.86MB, beats 57.49%

// Runtime3: 145ms, beats 37.68%
// Memory3: 11.72MB, beats 84.54%