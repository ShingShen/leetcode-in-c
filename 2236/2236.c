// 2236. Root Equals Sum of Children
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

bool checkTree(struct TreeNode* root);
struct TreeNode* newNode(int newVal);

int main()
{
    struct TreeNode* root = newNode(10);
    root->left = newNode(4);
    root->right = newNode(6);

    if (checkTree(root)) {
        puts("true");
    } else {
        puts("false");
    }
    
    return 0;
}

bool checkTree(struct TreeNode* root)
{
    return root->left->val + root->right->val == root->val;
}

struct TreeNode* newNode(int newVal)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(TreeNode));
    node->val = newVal;
    node->left = NULL;
    node->right = NULL;

    return node;
}
