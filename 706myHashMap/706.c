// 706. Design HashMap

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1000000

typedef struct _HashNode {
    int key;
    int val;
    struct _HashNode* next;
} HashNode;

typedef struct {
    struct HashNode** hashTable;
    int size;
} MyHashMap;

int getIndex(int key);
MyHashMap* myHashMapCreate();
void myHashMapPut(MyHashMap* obj, int key, int value);
int myHashMapGet(MyHashMap* obj, int key);
void myHashMapRemove(MyHashMap* obj, int key);
void myHashMapFree(MyHashMap* obj);
void printHashMap(MyHashMap* obj);

int main() {
    MyHashMap* hashMap = myHashMapCreate();
    myHashMapPut(hashMap, 0, 12);
    myHashMapPut(hashMap, 1, 2);
    myHashMapPut(hashMap, 3, 17);
    myHashMapPut(hashMap, 4, 17);
    myHashMapPut(hashMap, 5, 23);
    myHashMapPut(hashMap, 6, 100);
    myHashMapPut(hashMap, 7, 27);
    
    myHashMapRemove(hashMap, 6);
    
    // myHashMapFree(hashMap);

    printHashMap(hashMap);
    
    printf("The value of key 0 is: %d\n", myHashMapGet(hashMap, 0));
    printf("The value of key 2 is: %d\n", myHashMapGet(hashMap, 2));

    return 0;
}

int getIndex(int key) {
    return (abs(key) % HASH_SIZE);
}

MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)calloc(1, sizeof(MyHashMap));
    obj->hashTable = (HashNode**)calloc(HASH_SIZE, sizeof(HashNode*));
    obj->size = HASH_SIZE;
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = getIndex(key);
    HashNode* curList = obj->hashTable[index];
    HashNode* preNode = NULL;
    
    while (curList) {
        if (curList->key == key) {
            curList->val = value;
            return;
        }
        preNode = curList;
        curList = curList->next;
    }
    
    HashNode* newNode = (HashNode*)calloc(1, sizeof(HashNode));
    newNode->key = key;
    newNode->val = value;
    
    if (obj->hashTable[index] == NULL) {
        obj->hashTable[index] = newNode;
    } else {
        preNode->next = newNode;
    }
    return;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int index = getIndex(key);
    HashNode* curList = obj->hashTable[index];
    
    while (curList) {
        if(curList->key == key) {
            return curList->val;
        }
        curList = curList->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index = getIndex(key);
    HashNode* curList = obj->hashTable[index];
    HashNode* preNode = NULL;
    
    while(curList) {
        if (curList->key == key) {
            HashNode* delNode = curList;
            if (preNode) {
                preNode->next = curList->next;
            } else {
                obj->hashTable[index] = curList->next;
            }
            free(delNode);
            return;
        }
        preNode = curList;
        curList = curList->next;
    }
    return;
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < obj->size; i++) {
        HashNode* curList = obj->hashTable[i];
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

void printHashMap(MyHashMap* obj) {
    if(obj->hashTable == NULL) return;
    
    for (int i = 0; i < obj->size; i++) {
        HashNode* curNode = obj->hashTable[i];
        while(curNode != NULL) {
            printf("i = %d, {%d, %d}\n", i, curNode->key, curNode->val);
            curNode = curNode->next;
        }
    }
    return;
}
