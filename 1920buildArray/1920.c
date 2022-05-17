// 1920. Build Array from Permutation
#include <stdio.h>
#include <stdlib.h>

int* buildArray(int* nums, int numsSize, int* returnSize);
void printArr(int* nums, int numsSize);

int main()
{
    int arr[] = {0, 2, 1, 5, 3, 4};
    int arrSize = sizeof arr / sizeof *arr;
    int returnSize;
    int* newArr = buildArray(arr, arrSize, &returnSize);

    printArr(newArr, arrSize);

    return 0;
}

int* buildArray(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int* ans = (int*)malloc(sizeof(int)*(numsSize));
    for (int i = 0; i< numsSize; i++) {
        ans[i] = nums[nums[i]];
    }
    return ans;
}

void printArr(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}