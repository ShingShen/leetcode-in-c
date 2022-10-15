// 1290. Convert Binary Number in a Linked List to Integer
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

int getDecimalValue1(struct ListNode* head);
int getDecimalValue2(struct ListNode* head);
struct ListNode* newNode(int newVal);

int main()
{
    struct ListNode* list1 = newNode(1);
    list1->next = newNode(0);
    list1->next->next = newNode(1);

    int decimalVal1 = getDecimalValue1(list1);
    puts("Solution 1:");
    printf("The decimal value of the number: %d\n", decimalVal1);

    struct ListNode* list2 = newNode(1);
    list2->next = newNode(0);
    list2->next->next = newNode(1);

    int decimalVal2 = getDecimalValue2(list2);
    puts("Solution 2:");
    printf("The decimal value of the number: %d\n", decimalVal2);

    return 0;
}

int getDecimalValue1(struct ListNode* head)
{
    while (head->next) {
        head->val = (head->val)*2;
        head->next->val += head->val;
        head = head->next;
    }
    return head->val;
}

int getDecimalValue2(struct ListNode* head)
{
    while (head->next) {
        head->val = head->val<<1;
        head->next->val += head->val;
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