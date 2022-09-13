#include <stdio.h>

int search(int* nums, int numsSize, int target);

int main() {
    int arr[] = {2, 7, 11, 15, 23, 56, 71};
    int arrSize = sizeof arr / sizeof* arr;
    int targetIdx = search(arr, arrSize, 15);

    printf("The array size is: %d\n", arrSize);
    printf("The target index is: %d\n", targetIdx);

    return 0;
}

int search(int* nums, int numsSize, int target) {
    int l=0, r = numsSize-1;

    while (l<=r) {
        int m = l+(r-l)/2;
        if (nums[m] == target) return m;
        else if (nums[m] < target) l = m+1;
        else r = m-1;
    }
    return -1;
}