#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
struct ListNode* newNode(int key);
void printList(struct ListNode* listNode);

int main() {
    struct ListNode* list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(4);

    struct ListNode* list2 = newNode(1);
    list2->next = newNode(3);
    list2->next->next = newNode(4);

    struct ListNode* mergeHead = mergeTwoLists(list1, list2);

    printList(mergeHead);

    printf("\n");

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode* h = &head;

    if (l1 == NULL && l2 == NULL) return NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            h->next = l1;
            l1 = l1->next;
            h = h->next;
        } else {
            h->next = l2;
            l2 = l2->next;
            h = h->next;
        }
    }

    if (l1) h->next = l1;
    if (l2) h->next = l2;

    return head.next;
}

struct ListNode* newNode(int key) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(ListNode));
    temp->val = key;
    temp->next = NULL;
    return temp;
}

void printList(struct ListNode* listNode) {
    while (listNode != NULL) {
        printf("%d ", listNode->val);
        listNode = listNode->next;
    }
}