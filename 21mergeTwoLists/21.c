#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* l2ist);
struct ListNode* newNode(int key);
void printList(struct ListNode* listNode);

int main() {
    struct ListNode* l1 = newNode(1);
    l1->next = newNode(2);
    l1->next->next = newNode(4);

    struct ListNode* l2 = newNode(1);
    l2->next = newNode(3);
    l2->next->next = newNode(4);

    struct ListNode* mergedList = mergeTwoLists(l1, l2);

    printList(mergedList);

    printf("\n");

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode head;
    struct ListNode* node = &head;

    if (list1 == NULL && list2 == NULL) return NULL;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            node->next = list1;
            list1 = list1->next;
            node = node->next;
        } else {
            node->next = list2;
            list2 = list2->next;
            node = node->next;
        }
    }

    if (list1) node->next = list1;
    if (list2) node->next = list2;

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