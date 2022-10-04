// 1302. Deepest Leaves Sum

#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

// fmax is in math.h
// gcc 1302.c -o 1302 -lm
// -lm: To link math.h

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


int deepestLeavesSum(struct TreeNode* root);
struct TreeNode* newNode(int newVal);

int main()
{
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->right->right->right = newNode(8);

    printf("sizeof(TreeNode): %ld bytes\n", sizeof(TreeNode));
    printf("The Deepest leaves sum is: %d\n", deepestLeavesSum(root));
}

int depthHelper(struct TreeNode* root)
{
    if(!root) return 0;
    return fmax(depthHelper(root->left)+1, depthHelper(root->right)+1);
}

int sumHelper(struct TreeNode* root, int depth, int maxDepth)
{
    if(!root) return 0;
    if(depth == maxDepth) return root->val;
    return sumHelper(root->left, depth+1, maxDepth)+sumHelper(root->right, depth+1, maxDepth);
}

int deepestLeavesSum(struct TreeNode* root)
{
    return sumHelper(root, 1, depthHelper(root));
}

struct TreeNode* newNode(int newVal)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(TreeNode));
    node->val = newVal;
    node->left = NULL;
    node->right = NULL;
    return node;
}