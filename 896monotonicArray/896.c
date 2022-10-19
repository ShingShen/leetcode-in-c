// 896. Monotonic Array
#include<stdio.h>
#include<stdbool.h>

bool isMonotonic1(int* nums, int numsSize);
bool isMonotonic2(int* nums, int numsSize);
bool isMonotonic3(int* nums, int numsSize);

int main()
{
    int arr[] = {1, 2, 2, 3, 3};
    int arrSize = sizeof arr / sizeof *arr;
    printf("sizeof arr: %ld\n", sizeof arr);
    printf("sizeof *arr: %ld\n", sizeof *arr);
    printf("Array size is: %d\n", arrSize);
    puts("Solution 1:");
    if (isMonotonic1(arr, arrSize)) {
        puts("Array is monotonic");
    } else {
        puts("Array is not monotonic");
    }
    puts("Solution 2:");
    if (isMonotonic2(arr, arrSize)) {
        puts("Array is monotonic");
    } else {
        puts("Array is not monotonic");
    }
    puts("Solution 3:");
    if (isMonotonic3(arr, arrSize)) {
        puts("Array is monotonic");
    } else {
        puts("Array is not monotonic");
    }
}

bool isMonotonic1(int* nums, int numsSize)
{
    bool inc = false;
    bool dec = false;
    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] < nums[i+1]) inc = true;
        if (nums[i] > nums[i+1]) dec = true;
        if (inc && dec) return false;
    }
    return true;
}

bool isMonotonic2(int* nums, int numsSize)
{
    bool inc = true;
    bool dec = true;
    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] > nums[i+1]) inc = false;
        if (nums[i] < nums[i+1]) dec = false;
        if (inc == false && dec == false) return false;
    }
    return true;
}

bool isMonotonic3(int* nums, int numsSize)
{
    bool inc = true, dec = true;
    for(int i = 0; i < numsSize-1; i++) {
        inc &= (nums[i] <= nums[i+1]);
        dec &= (nums[i] >= nums[i+1]);
    }
    return inc || dec;
}