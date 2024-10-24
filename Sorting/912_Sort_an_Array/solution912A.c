#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int L, int M, int R) {
    int leftSize = M - L + 1;
    int rightSize = R - M;

    int* left = (int*)malloc(leftSize * sizeof(int));
    int* right = (int*)malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; ++i) {
        left[i] = arr[L + i];
    }
    for (int j = 0; j < rightSize; ++j) {
        right[j] = arr[M + 1 + j];
    }

    int i = 0, j = 0, k = L;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }

    free(left);
    free(right);
}

void mergeSort(int* arr, int L, int R) {
    if (L < R) {
        int M = L + (R - L) / 2;

        mergeSort(arr, L, M);
        mergeSort(arr, M + 1, R);

        merge(arr, L, M, R);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }

    mergeSort(result, 0, numsSize - 1);

    *returnSize = numsSize;
    return result;
}

// Runtime1: 351ms, beats 84.36%
// Memory1: 154.59MB, beats 5.55%

// Runtime2: 337ms, beats 84.57%
// Memory2: 154.40MB, beats 7.41%

// Runtime3: 326ms, beats 84.98%
// Memory3: 154.63MB, beats 5.55%

// Runtime reduced by a factor of 10 to not skew data visualization
// Memory reduced by a factor of 10 to not skew data visualization