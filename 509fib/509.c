// 509. Fibonacci Number
#include <stdio.h>

int recursionFib(int n);
int dpFib(int n);

int main() 
{
    int num = 9;
    
    printf("(Recursion) The Fibonacci number is: %d\n", recursionFib(num));
    printf("(DP)        The Fibonacci number is: %d\n", dpFib(num));

    return 0;
}

int recursionFib(int n)
{
    if (n <= 1) return n;
    return recursionFib(n-2) + recursionFib(n-1);
}

int dpFib(int n)
{
    int f[n+2], i;
    f[0] = 0;
    f[1] = 1;
    
    for (i = 2; i <= n; i++) {
      f[i] = f[i-1] + f[i-2];
    }
    
    return f[n];
}
