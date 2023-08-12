// Time Complexity O(n log n)
// Space Complexity O(1)

#include <stdio.h>

int findKthLargest(int* nums, int numsSize, int k);

int main(void) 
{
    int arr[] = {3, 2, 1, 5, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int result = findKthLargest(arr, size, k);
    printf("Output: %d\n", result);
    
    return 0;
}

void maxHeapify(int* arr, int size, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest]) largest = left;
    if(right < size && arr[right] > arr[largest]) largest = right;
    if(largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, size, largest);
    }
}

void buildMaxHeap(int* arr, int size) 
{
    for (int i = size / 2 - 1; i >= 0; i--) maxHeapify(arr, size, i);
}

int findKthLargest(int* nums, int numsSize, int k) 
{
    buildMaxHeap(nums, numsSize);
    for(int i = 0; i < k - 1; i++) {
        int temp = nums[0];
        nums[0] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = temp;
        maxHeapify(nums, numsSize - i - 1, 0);
    }
    return nums[0];
}