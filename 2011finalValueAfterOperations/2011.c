#include <stdio.h>

int finalValueAfterOperations(char operations[][3], int operationsSize);

int main() 
{
    char arr[][3] = {"++X","X++","X++"};
    int arrSize = sizeof arr / sizeof *arr;
    int finalVal = finalValueAfterOperations(arr, arrSize);
    
    printf("%d\n", finalVal);
    
    return 0;
}

int finalValueAfterOperations(char operations[][3], int operationsSize)
{
    int ans = 0;
    for (int i = 0; i < operationsSize; i++) {
        operations[i][1] == '+' ? ans++ : ans--;
    }
    return ans;
}
