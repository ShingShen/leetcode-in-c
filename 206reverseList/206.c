// Time Complexity O(n)
// Space Complexity O(1)

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseListIterative(struct ListNode* head);
struct ListNode* reverseListRecursive(struct ListNode* head);
struct ListNode* newNode(int key);
void freeList(struct ListNode* head);
void printList(struct ListNode* listNode);

int main(void) 
{
    struct ListNode* headIterative = newNode(1);
    headIterative->next = newNode(2);
    headIterative->next->next = newNode(3);
    headIterative->next->next->next = newNode(4);
    headIterative->next->next->next->next = newNode(5);

    struct ListNode* headRecursive = newNode(1);
    headRecursive->next = newNode(2);
    headRecursive->next->next = newNode(3);
    headRecursive->next->next->next = newNode(4);
    headRecursive->next->next->next->next = newNode(5);

    // Time Complexity O(n)
    // Space Complexity O(1)
    struct ListNode* iterativeResult = reverseListIterative(headIterative);

    printf("Iterativce Solution:\n");
    printList(iterativeResult);
    printf("\n");

    // Time Complexity O(n)
    // Space Complexity O(n)
    struct ListNode* recursiveResult = reverseListRecursive(headRecursive);

    printf("Recursive Solution:\n");
    printList(recursiveResult);
    printf("\n");

    freeList(iterativeResult);
    freeList(recursiveResult);


    return 0;
}

struct ListNode* reverseListIterative(struct ListNode* head) 
{
    struct ListNode* newHead = NULL;
    while (head) {
        struct ListNode* tail = head->next;
        head->next = newHead;
        newHead = head;
        head = tail;
    }
    return newHead;
}

struct ListNode* reverseListRecursive(struct ListNode* head) 
{
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

struct ListNode* newNode(int key) 
{
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = key;
    temp->next = NULL;

    return temp;
}

void freeList(struct ListNode* head) 
{
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void printList(struct ListNode* listNode) 
{
    while(listNode != NULL) {
        printf("%d ", listNode->val);
        listNode = listNode->next;
    }
}