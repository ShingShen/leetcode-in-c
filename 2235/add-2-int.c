#include <stdio.h>

int sum(int num1, int num2);

int main()
{
    int a = 17, b = 19;
    int c = sum(a, b);

    printf("%d\n", c);

    return 0;
}

int sum(int num1, int num2)
{
    return num1 + num2;
}