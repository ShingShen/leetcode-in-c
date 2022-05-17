#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
struct ListNode* newNode(int key);
void printList(struct ListNode* node);

int main() {
    struct ListNode* list1 = newNode(3);
    list1->next = newNode(9);
    list1->next->next = newNode(7);

    struct ListNode* list2 = newNode(3);
    list2->next = newNode(9);
    list2->next->next = newNode(7);

    struct ListNode* newList = addTwoNumbers(list1, list2);

    printList(newList);
    printf("\n"); 
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode* node = &head;
    int extraVal = 0;
    while(l1 || l2 || extraVal) {
        int sum  = (l1 ? l1->val : 0) + (l2 ? l2->val :0) + extraVal;
        extraVal = sum / 10;
        node->next = malloc(sizeof(ListNode));
        node->next->val = sum % 10;
        node->next->next = NULL;
        node = node->next;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    return head.next;
}

struct ListNode* newNode(int key) {
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(ListNode));
    tmp->val = key;
    tmp->next = NULL;
    return tmp;
}

void printList(struct ListNode* node) {
    while(node != NULL) {
        printf(" %d ", node->val);
        node = node->next;
    }
}