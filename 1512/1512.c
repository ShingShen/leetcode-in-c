// 1512. Number of Good Pairs
#include <stdio.h>

int numIdenticalPairs(int* nums, int numsSize);

int main()
{
    int arr[] = {1, 2, 3, 1, 1, 3};
    int arrSize = sizeof arr / sizeof *arr;
    int numberOfGoodPairs = numIdenticalPairs(arr, arrSize);

    printf("The number if good pairs: %d\n", numberOfGoodPairs);
}

int numIdenticalPairs(int* nums, int numsSize)
{
    int ans = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j] && i < j) ans++;
        }
    }
    return ans;
}