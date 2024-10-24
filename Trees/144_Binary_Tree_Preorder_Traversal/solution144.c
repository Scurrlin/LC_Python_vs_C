#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Stack {
    struct TreeNode** data;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct TreeNode* node) {
    stack->data[++stack->top] = node;
}

struct TreeNode* pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

void freeStack(struct Stack* stack) {
    free(stack->data);
    free(stack);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    if (root == NULL) {
        return NULL;
    }

    int* result = (int*)malloc(100 * sizeof(int));
    struct Stack* stack = createStack(100);

    struct TreeNode* cur = root;
    while (cur != NULL || !isEmpty(stack)) {
        if (cur != NULL) {
            result[(*returnSize)++] = cur->val;

            if (cur->right != NULL) {
                push(stack, cur->right);
            }

            cur = cur->left;
        } else {
            cur = pop(stack);
        }
    }

    freeStack(stack);

    return result;
}

// Runtime1: 0ms, beats 100%
// Memory1: 8.74MB, beats 11.27%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: