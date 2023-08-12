#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

char ** binaryTreePaths(struct TreeNode* root, int* returnSize);
struct TreeNode* newNode(int val);

int main(void) 
{
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    int returnSize;
    char** paths = binaryTreePaths(root, &returnSize);

    printf("Paths:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", paths[i]);
        free(paths[i]); 
    }
    free(paths); 

    return 0;
}

char* intToString(int num) 
{
    char* str = (char*)malloc(12 * sizeof(char));
    snprintf(str, 12, "%d", num);
    return str;
}

char* concatStrings(const char* str1, const char* str2) 
{
    char* result = (char*)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

void traversePaths(struct TreeNode* node, char* currentPath, char*** paths, int* returnSize) 
{
    if(node == NULL) return;
    
    char* nodeStr = intToString(node->val);
    
    if (node->left == NULL && node->right == NULL) {
        char* path = concatStrings(currentPath, nodeStr);
        (*paths)[(*returnSize)++] = path;
    } else {
        char* newPath = concatStrings(currentPath, nodeStr);
        newPath = concatStrings(newPath, "->");
        
        traversePaths(node->left, newPath, paths, returnSize);
        traversePaths(node->right, newPath, paths, returnSize);
        
        free(newPath);
    }
    free(nodeStr);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize) 
{
    *returnSize = 0;
    char** paths = (char**)malloc(1000 * sizeof(char*));
    traversePaths(root, "", &paths, returnSize);

    return paths;
}

struct TreeNode* newNode(int val) 
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}