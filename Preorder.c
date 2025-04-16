#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform preorder traversal
void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    result[(*index)++] = root->val;
    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

// Main function to return preorder traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // max 100 nodes
    *returnSize = 0;
    preorder(root, result, returnSize);
    return result;
}





int main() {
    // Creating tree: [1,null,2,3]
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    struct TreeNode* node2 = malloc(sizeof(struct TreeNode));
    struct TreeNode* node3 = malloc(sizeof(struct TreeNode));

    root->val = 1;
    root->left = NULL;
    root->right = node2;

    node2->val = 2;
    node2->left = node3;
    node2->right = NULL;

    node3->val = 3;
    node3->left = NULL;
    node3->right = NULL;

    int returnSize;
    int* result = preorderTraversal(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    // Free memory (important in C!)
    free(result);
    free(node3);
    free(node2);
    free(root);

    return 0;
}