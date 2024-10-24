#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void resizeArray(int** array, int* capacity) {
    *capacity *= 2;
    *array = (int*)realloc(*array, *capacity * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void inorderHelper(struct TreeNode* root, int** result, int* returnSize, int* capacity) {
    if (root == NULL) {
        return;
    }

    inorderHelper(root->left, result, returnSize, capacity);

    if (*returnSize >= *capacity) {
        resizeArray(result, capacity);
    }
    (*result)[(*returnSize)++] = root->val;

    inorderHelper(root->right, result, returnSize, capacity);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int capacity = 10;
    int* result = (int*)malloc(capacity * sizeof(int));

    inorderHelper(root, &result, returnSize, &capacity);

    return result;
}

// Runtime1: 0ms, beats 100%
// Memory1: 8.49MB, beasts 61.01%

// Runtime2: 0ms, beats 100%
// Memory2: 8.40MB, beasts 86%

// Runtime3: 0ms, beats 100%
// Memory3: 8.48MB, beats 61.53%