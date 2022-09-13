// 146. LRU Cache

#include <stdlib.h>
#include <stdbool.h>


#define HASHSIZE 10000

struct node {
    int value;
    bool valid;
    struct node* prev;
    struct node* next;
};

typedef struct {
    struct node* head;
    struct node* tail;
    struct node* myhash;
    int capacity;
    int size;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity);
int lRUCacheGet(LRUCache* obj, int key);
void lRUCachePut(LRUCache* obj, int key, int value);
void lRUCacheFree(LRUCache* obj);

int main()
{
    LRUCache* obj = lRUCacheCreate(2);
}

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->myhash = (struct node*)calloc(HASHSIZE, sizeof(struct node));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = NULL;
    obj->tail = NULL;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    int value;
    if(obj->myhash[key].valid) {

    }
}

void lRUCachePut(LRUCache* obj, int key, int value)
{

}

void lRUCacheFree(LRUCache* obj)
{
    free(obj->myhash);
    free(obj);
}

void rmLru(LRUCache* obj)
{
    struct node* rmNode = obj->tail;
    
}

void bringFront(LRUCache* obj, struct node* recentNode, int value)
{

}

void add(LRUCache* obj, struct node* newNode, int value)
{
    
}