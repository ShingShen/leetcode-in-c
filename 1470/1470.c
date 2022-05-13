// 1470. Shuffle the Array
#include <stdio.h>
#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize);
void printArr(int* nums, int numsSize);

int main()
{
    int arr[] = {2, 5, 1, 3, 4, 7};
    int arrSize = sizeof arr / sizeof *arr;
    int n = 3;
    int returnSize;

    int* newArr = shuffle(arr, arrSize, n, &returnSize);

    printArr(newArr, arrSize); 
}

int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{
    *returnSize = numsSize;
    int* ans = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < n; i++) {
        ans[2 * i] = nums[i];
        ans[(2 * i) + 1] = nums[n + i];
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

