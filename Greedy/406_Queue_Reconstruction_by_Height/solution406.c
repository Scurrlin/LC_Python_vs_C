#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* personA = *(int**)a;
    int* personB = *(int**)b;
    
    if (personA[0] > personB[0]) {
        return -1;
    } else if (personA[0] < personB[0]) {
        return 1;
    } else {
        return personA[1] - personB[1];
    }
}

void insert(int** result, int* returnSize, int* person, int pos) {
    for (int i = *returnSize; i > pos; --i) {
        result[i][0] = result[i - 1][0];
        result[i][1] = result[i - 1][1];
    }
    result[pos][0] = person[0];
    result[pos][1] = person[1];
    (*returnSize)++;
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {
    qsort(people, peopleSize, sizeof(int*), compare);

    int** result = (int**)malloc(peopleSize * sizeof(int*));
    for (int i = 0; i < peopleSize; ++i) {
        result[i] = (int*)malloc(2 * sizeof(int));
    }

    *returnSize = 0;

    for (int i = 0; i < peopleSize; ++i) {
        insert(result, returnSize, people[i], people[i][1]);
    }

    *returnColumnSizes = (int*)malloc(peopleSize * sizeof(int));
    for (int i = 0; i < peopleSize; ++i) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: