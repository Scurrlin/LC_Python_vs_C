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

int kthSmallest(struct TreeNode* root, int k) {
    struct Stack* stack = createStack(100);
    struct TreeNode* curr = root;

    while (curr != NULL || !isEmpty(stack)) {
        while (curr != NULL) {
            push(stack, curr);
            curr = curr->left;
        }

        curr = pop(stack);
        k--;

        if (k == 0) {
            int result = curr->val;
            freeStack(stack);
            return result;
        }

        curr = curr->right;
    }

    freeStack(stack);
    return -1;
}

// Runtime1: 0ms, beats 100%
// Memory1: 13.59MB, beasts 57.49%

// Runtime2: 0ms, beats 100%
// Memory2: 13.71MB, beats 26.23%

// Runtime3: 0ms, beats 100%
// Memory3: 13.76MB, beats 26.23%