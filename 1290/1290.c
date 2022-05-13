// 1290. Convert Binary Number in a Linked List to Integer
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

int getDecimalValue(struct ListNode* head);
struct ListNode* newNode(int newVal);

int main()
{
    struct ListNode* list = newNode(1);
    list->next = newNode(0);
    list->next->next = newNode(1);

    printf("The decimal value of the number: %d\n", getDecimalValue(list));

    return 0;
}

int getDecimalValue(struct ListNode* head)
{
    while (head->next) {
        head->val = (head->val)*2;
        head->next->val = head->val + head->next->val;
        head = head->next;
    }
    return head->val;
}

struct ListNode* newNode(int newVal)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(ListNode));
    node->val = newVal;
    node->next = NULL;
    return node;
}