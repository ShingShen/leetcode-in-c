#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int accounts[][2], int accountsSize, int* accountsColSize);

int main() 
{
    int arr[][2] = {{1,5},{7,3},{3,5}};
    int arrSize = sizeof arr / sizeof *arr;
    int colSize = sizeof *arr / sizeof **arr;
    int maxSum = maximumWealth(arr, arrSize, &colSize);
    
    
    // printf("arrSize: %d\n", arrSize);
    // printf("arrSize: %d\n", colSize);
    
    printf("%d\n", maxSum);
    
    return 0;
}

int maximumWealth(int accounts[][2], int accountsSize, int* accountsColSize)
{
    int max = 0;
    for (int i = 0; i < accountsSize; i++) {
        int sum = 0;
        for (int j = 0; j < *accountsColSize; j++) {
            sum += accounts[i][j];
        }
        if (max < sum) max = sum;
    }
    return max;
}
