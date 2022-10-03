// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

struct TreeNode* getTargetCopy(struct TreeNode* original, struct TreeNode* cloned, struct TreeNode* target);
struct TreeNode* newNode(int newVal);

int main()
{
    struct TreeNode* root = newNode(7);
    root->left = newNode(4);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(19);

    struct TreeNode* clonedRoot = root;
    struct TreeNode* target = root->right;

    int targetNum = getTargetCopy(root, clonedRoot, target)->val;
    printf("The target number is: %d\n", targetNum);
}

struct TreeNode* res;
struct TreeNode* getTargetCopy(struct TreeNode* original, struct TreeNode* cloned, struct TreeNode* target)
{
    if(!original) return NULL;
    if(original->val == target->val) return res = cloned;
    getTargetCopy(original->left, cloned->left, target);
    getTargetCopy(original->right, cloned->right, target);
    return res;
}

struct TreeNode* newNode(int newVal)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(TreeNode));
    node->val = newVal;
    node->left = NULL;
    node->right = NULL;
    return node;
}
