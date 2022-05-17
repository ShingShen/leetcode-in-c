#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q);
struct TreeNode* newNode(int new_val);

int main() {
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(10);

    if(isSameTree(root1, root2)) {
        puts("true");
    } else {
        puts("false");
    }

    return 0;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode* newNode(int new_val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(TreeNode));
    node->val = new_val;
    node->left = NULL;
    node->right = NULL;

    return node;
}