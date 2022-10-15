#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize);
struct TreeNode* newNode(int newVal);
int treeSize(struct TreeNode* node);

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    int* returnSize = (int*)malloc(sizeof(int));
    int* res = inorderTraversal(root, returnSize);

    printf("Tree size is: %d\n", treeSize(root));
    printf("Inorder traversal: [");
    for (int i = 0; i < treeSize(root); i++) {
        printf(" %d ", res[i]);
    }
    printf("]\n");  
    return 0;
}

void traverse(struct TreeNode* root, int* ans, int* size) {
    if(root == NULL) return;
    traverse(root->left, ans, size);
    ans[(*size)++] = root->val;
    traverse(root->right, ans, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ans = malloc(sizeof(int)*100);
    traverse(root, ans, returnSize);
    return ans;
}

struct TreeNode* newNode(int newVal) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = newVal;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int treeSize(struct TreeNode* node) {
    if(!node) return 0;
    return treeSize(node->left)+treeSize(node->right)+1;
}
