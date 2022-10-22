// 1. Two Sum

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10000

typedef struct _HashNode {
    int key;
    int val;
    struct _HashNode* next;
} HashNode;

typedef struct {
    HashNode** hashTable;
    int size;
} HashMap;

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
void priArr(int* arr, int arrSize);

int main() 
{
    int arr[] = {7, 2, 13, 5, 1};
    int arrSize = sizeof arr / sizeof *arr;
    int target = 28;
    int* returnSize;
    
    int* ans = twoSum(arr, arrSize, target, returnSize);
    
    printf("sizeof(arr) is: %ld\n", sizeof(arr));
    printf("sizeof(*arr) is: %ld\n", sizeof(*arr));
    printf("Array size is: %d\n", arrSize);
    priArr(arr, arrSize);
    printf("The index of two sum is: [ %d, %d ]\n", ans[0], ans[1]);
    
    return 0;
}

int getIdx(int key) 
{
    return (abs(key) % HASH_SIZE);
}

HashMap* hashMapCreate() 
{
    HashMap* obj = (HashMap*)calloc(1, sizeof(HashMap));
    obj->hashTable = (HashNode**)calloc(HASH_SIZE, sizeof(HashNode*));
    obj->size = HASH_SIZE;
    return obj;
}

void hashMapPut(HashMap* obj, int key, int val) 
{
    int idx = getIdx(key);
    HashNode* curList = obj->hashTable[idx];
    HashNode* preNode = NULL;
    
    while (curList) {
        if (curList->key == key) {
            curList->val = val;
            return;
        }
        preNode = curList;
        curList = curList->next;
    }
    
    HashNode* newNode = (HashNode*)calloc(1, sizeof(HashNode));
    newNode->key = key;
    newNode->val = val;
    
    if (obj->hashTable[idx] == NULL) {
        obj->hashTable[idx] = newNode;
    } else {
        preNode->next = newNode;
    }
    return;
}

int hashMapGet(HashMap* obj, int key) 
{
    int idx = getIdx(key);
    HashNode* curList = obj->hashTable[idx];
    
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
        HashNode* curList = obj->hashTable[i];
        while (curList) {
            HashNode* delNode = curList;
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
    HashMap* idx = hashMapCreate();
    int* res = calloc((*returnSize = 2), sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (hashMapGet(idx, target - nums[i]) != -1) {
            res[0] = hashMapGet(idx, target - nums[i]);
            res[1] = i;
            return res;
        }
        hashMapPut(idx, nums[i], i);
    }
    hashMapFree(idx);
    
    res[0] = -1;
    res[1] = -1;
    return res;
}

void priArr(int* arr, int arrSize) {
    printf("Array is: [");
    for(int i = 0; i < arrSize; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
}
