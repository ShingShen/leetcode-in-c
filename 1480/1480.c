// 1480. Running Sum of 1d Array
# include <stdio.h>
# include <stdlib.h>

int* runningSum(int* nums, int numsSzie, int* returnSize);
void printArr(int* nums, int numsSizr);

int main()
{
    int arr[] = {1, 2, 3, 4};
    int arrSize = sizeof arr / sizeof *arr;
    int returnSize;
    int* newArr = runningSum(arr, arrSize, &returnSize);

    printArr(newArr, arrSize);

    return 0;
}

int* runningSum(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int* ans = (int*)malloc(sizeof(int)*(*returnSize));
    ans[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        ans[i] = ans[i - 1] + nums[i];
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