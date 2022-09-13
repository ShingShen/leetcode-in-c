// 1. Two Sum

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10000

struct HashNode {
    int key;
    int val;
    struct HashNode* next;
};

typedef struct {
    struct HashNode** hashTable;
    int size;
} HashMap;

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() 
{
    int arr[] = {7, 2, 13, 5};
    int numsSize = sizeof arr / sizeof *arr;
    int target = 18;
    int* returnSize;
    
    int* ans = twoSum(arr, numsSize, target, returnSize);
    
    printf("[%d, %d]\n", ans[0], ans[1]);
    
    return 0;
}

int getIdx(int key) 
{
    return (abs(key) % HASH_SIZE);
}

HashMap* hashMapCreate() 
{
    HashMap* obj = (HashMap*)calloc(1, sizeof(HashMap));
    obj->hashTable = (struct HashNode**)calloc(HASH_SIZE, sizeof(struct HashNode*));
    obj->size = HASH_SIZE;
    return obj;
}

void hashMapPut(HashMap* obj, int key, int value) 
{
    int index = getIdx(key);
    struct HashNode* curList = obj->hashTable[index];
    struct HashNode* preNode = NULL;
    
    while (curList) {
        if (curList->key == key) {
            curList->val = value;
            return;
        }
        preNode = curList;
        curList = curList->next;
    }
    
    struct HashNode* newNode = (struct HashNode*)calloc(1, sizeof(struct HashNode));
    newNode->key = key;
    newNode->val = value;
    
    if (obj->hashTable[index] == NULL) {
        obj->hashTable[index] = newNode;
    } else {
        preNode->next = newNode;
    }
    return;
}

int hashMapGet(HashMap* obj, int key) 
{
    int idx = getIdx(key);
    struct HashNode* curList = obj->hashTable[idx];
    
    while (curList) {
        if(curList->key == key) {
            return curList->val;
        }
        curList = curList->next;
    }
    return -1;
}

void hashMapFree(HashMap* obj) 
{
    for (int i = 0; i < obj->size; i++) {
        struct HashNode* curList = obj->hashTable[i];
        while (curList) {
            struct HashNode* delNode = curList;
            curList = curList->next;
            free(delNode);
        }
        obj->hashTable[i] = NULL;
    }
    free(obj->hashTable);
    free(obj);
    return;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    HashMap* hashMap = hashMapCreate();
    int* res = calloc((*returnSize = 2), sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (hashMapGet(hashMap, target - nums[i]) != -1) {
            res[0] = hashMapGet(hashMap, target - nums[i]);
            res[1] = i;
            return res;
        }
        hashMapPut(hashMap, nums[i], i);
    }
    hashMapFree(hashMap);
    
    res[0] = -1;
    res[1] = -1;
    return res;
}
