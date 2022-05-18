/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 1. Two Sum

#define HASH_SIZE 10000

struct HashNode {
    int key;
    int val;
    struct HashNode* next;
};

typedef struct {
    struct HashNode** hashTable;
    int size;
} MyHashMap;

int getIndex(int key) {
    return (key % HASH_SIZE);
}

MyHashMap* myHashMapCreate() 
{
    MyHashMap* obj = (MyHashMap*)calloc(1, sizeof(MyHashMap));
    obj->hashTable = (struct HashNode**)calloc(HASH_SIZE, sizeof(struct HashNode*));
    obj->size = HASH_SIZE;
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) 
{
    int index = getIndex(key);
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

int myHashMapGet(MyHashMap* obj, int key) 
{
    int index = getIndex(key);
    struct HashNode* curList = obj->hashTable[index];
    
    while (curList) {
        if(curList->key == key) {
            return curList->val;
        }
        curList = curList->next;
    }
    return -1;
}

// void myHashMapRemove(MyHashMap* obj, int key) 
// {
//     int index = getIndex(key);
//     struct HashNode* curList = obj->hashTable[index];
//     struct HashNode* preNode = NULL;
    
//     while(curList) {
//         if (curList->key == key) {
//             struct HashNode* delNode = curList;
//             if (preNode) {
//                 preNode->next = curList->next;
//             } else {
//                 obj->hashTable[index] = curList->next;
//             }
//             free(delNode);
//             return;
//         }
//         preNode = curList;
//         curList = curList->next;
//     }
//     return;
// }

void myHashMapFree(MyHashMap* obj) 
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
    MyHashMap* hashMap = myHashMapCreate();
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int)*2);
    for (int i = 0; i < numsSize; i++) {
        if (myHashMapGet(hashMap, target - nums[i]) != -1) {
            res[0] = myHashMapGet(hashMap, target - nums[i]);
            res[1] = i;
            myHashMapFree(hashMap);
            *returnSize = 2;
            return res;
        }
        myHashMapPut(hashMap, nums[i], i);
    }
    myHashMapFree(hashMap);
    *returnSize = 0;
    return NULL;
}

// typedef struct {
//     int val;
//     int idx;
//     UT_hash_handle hh;
// } hash_table;

// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     int* res = calloc((*returnSize=2), sizeof(int));
//     hash_table *numsHash=NULL, *elm=NULL, *tmp=NULL;
    
//     for(int i=0; i<numsSize; i++) {
//         int another = target-nums[i];
//         HASH_FIND_INT(numsHash, &another, elm);
//         if (elm) {
//             res[0] = elm->idx;
//             res[1] = i;
//             break;
//         } else {
//             elm = malloc(sizeof(hash_table));
//             elm->val = nums[i]; 
//             elm->idx = i;
//             HASH_ADD_INT(numsHash, val, elm);
//         }
//     }
//     HASH_ITER(hh, numsHash, elm, tmp) {
//         HASH_DEL(numsHash, elm); 
//         free(elm); 
//     }
//     return res;
// }

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
