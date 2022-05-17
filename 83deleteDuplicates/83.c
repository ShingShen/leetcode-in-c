#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head);
struct ListNode* newNode(int key);
void printList(struct ListNode* listNode);

int main() {
    struct ListNode* l = newNode(1);
    l->next = newNode(1);
    l->next->next = newNode(2);
    l->next->next->next = newNode(2);
    l->next->next->next->next = newNode(2);
    l->next->next->next->next->next = newNode(3);
    l->next->next->next->next->next->next = newNode(3);
    l->next->next->next->next->next->next->next = newNode(3);
    l->next->next->next->next->next->next->next->next = newNode(4);
    l->next->next->next->next->next->next->next->next->next = newNode(4);
    l->next->next->next->next->next->next->next->next->next->next = newNode(4);
    l->next->next->next->next->next->next->next->next->next->next->next = newNode(4);

    struct ListNode* newList = deleteDuplicates(l);

    printList(newList);

    printf("\n");

    return 0;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* node = head;

    while (node && node->next) {
        if (node->val == node->next->val) {
            node->next = node->next->next;
        } else {
            node = node->next;
        }
    }
    return head;
}

struct ListNode* newNode(int key) {
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->val = key;
    tmp->next = NULL;
    return tmp;
}

void printList(struct ListNode* listNode) {
    while (listNode != NULL) {
        printf("%d ", listNode->val);
        listNode = listNode->next;
    }
}