#include <stdio.h>
#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize);
void printArray(int* nums, int numsSize); 

int main()
{
    int arr[] = {1, 2, 1};
    int numsSize = 3;
    int returnSize;
    int* new_arr = getConcatenation(arr, numsSize, &returnSize);

    printArray(new_arr, 6);

    return 0;
}

int* getConcatenation(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = numsSize*2;
    int* ans = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }
    return ans;
}

void printArray(int* nums, int numsSize) 
{
    for (int i = 0; i < numsSize; i++) {
        printf(" %d ", nums[i]);
    }
    printf("\n");
}