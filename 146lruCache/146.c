// 146. LRU Cache

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10000

typedef struct _Node {
    int key;
    int val;
    struct _Node* prev;
    struct _Node* next;
} Node;

typedef struct {
    int maxCap;
    int curCap;
    Node* head;
    Node* tail;
} LRUCache;

Node* map[MAX_SIZE];

LRUCache* lRUCacheCreate(int capacity);
int lRUCacheGet(LRUCache* obj, int key);
void lRUCachePut(LRUCache* obj, int key, int value);
void lRUCacheFree(LRUCache* obj);

int main()
{
    int lRUMaxCap = 2;
    LRUCache* cache = lRUCacheCreate(lRUMaxCap);
    lRUCachePut(cache, 1, 1);
    puts("After Put [1, 1]:");
    puts("Cache is:");
    printf("[[%d, %d]]\n\n", cache->head->next->key, cache->head->next->val);
    
    lRUCachePut(cache, 2, 2);
    puts("After Put [2, 2]:");
    puts("Cache is:");
    printf("[[%d, %d], [%d, %d]]\n\n", cache->head->next->key, cache->head->next->val, cache->head->next->next->key, cache->head->next->next->val);
    
    printf("After Get key 1 = %d\n", lRUCacheGet(cache, 1));
    puts("Cache is:");
    printf("[[%d, %d], [%d, %d]]\n\n", cache->head->next->key, cache->head->next->val, cache->head->next->next->key, cache->head->next->next->val);
    
    lRUCachePut(cache, 3, 3);
    puts("After Put [3, 3]:");
    puts("Cache is:");
    printf("[[%d, %d], [%d, %d]]\n\n", cache->head->next->key, cache->head->next->val, cache->head->next->next->key, cache->head->next->next->val);

    printf("After Get key 2 = %d\n", lRUCacheGet(cache, 2));
    puts("Cache is:");
    printf("[[%d, %d], [%d, %d]]\n\n", cache->head->next->key, cache->head->next->val, cache->head->next->next->key, cache->head->next->next->val);

    lRUCachePut(cache, 4, 4);
    puts("After Put [4, 4]:");
    puts("Cache is:");
    printf("[[%d, %d], [%d, %d]]\n\n", cache->head->next->key, cache->head->next->val, cache->head->next->next->key, cache->head->next->next->val);

    printf("After Get key 1 = %d\n", lRUCacheGet(cache, 1));
    puts("Cache is:");
    printf("[[%d, %d], [%d, %d]]\n\n", cache->head->next->key, cache->head->next->val, cache->head->next->next->key, cache->head->next->next->val);

    printf("After Get key 3 = %d\n", lRUCacheGet(cache, 3));
    puts("Cache is:");
    printf("[[%d, %d], [%d, %d]]\n\n", cache->head->next->key, cache->head->next->val, cache->head->next->next->key, cache->head->next->next->val);
    
    printf("After Get key 4 = %d\n", lRUCacheGet(cache, 4));
    puts("Cache is:");
    printf("[[%d, %d], [%d, %d]]\n\n", cache->head->next->key, cache->head->next->val, cache->head->next->next->key, cache->head->next->next->val);
}

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache* cache;
    cache = malloc(sizeof(LRUCache));
    cache->maxCap = capacity;
    cache->curCap = 0;

    cache->head = malloc(sizeof(Node));
    cache->tail = malloc(sizeof(Node));
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    for(int i = 0; i < MAX_SIZE; i++) map[i] = NULL;

    return cache;
}

void rmNode(Node* currNode) 
{
    currNode->prev->next = currNode->next;
    currNode->next->prev = currNode->prev;
}

void rmTail(LRUCache* obj)
{
    Node* tmp;
    Node* tail = obj->tail;
    tmp = tail->prev;
    
    map[tmp->key] = NULL;
    rmNode(tmp);
    free(tmp);
}

void addFront(LRUCache* obj, Node* currNode)
{
    Node* head = obj->head;
    currNode->next = head->next;
    currNode->prev = head;
    head->next->prev = currNode;
    head->next = currNode;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    if(obj->curCap == 0) return -1;
    if(map[key] == NULL) return -1;
    int val = map[key]->val;
    rmNode(map[key]);
    addFront(obj, map[key]);
    return val;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    if(map[key] == NULL) {
        if(obj->curCap == obj->maxCap) {
            rmTail(obj);
            obj->curCap--;
        }
        obj->curCap++;
        Node* tmp = malloc(sizeof(Node));
        tmp->key = key;
        tmp->val = value;
        map[key] = tmp;
        addFront(obj, tmp);
    } else {
        rmNode(map[key]);
        map[key]->val = value;
        addFront(obj, map[key]);
    }
}

void lRUCacheFree(LRUCache* obj)
{
    for(int i = 0; i < MAX_SIZE; i++) {
        if(map[i]) free(map[i]);
    }
    free(obj->head);
    free(obj->tail);
    free(obj);
}