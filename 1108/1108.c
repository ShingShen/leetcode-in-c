// 1108. Defanging an IP Address
#include <stdio.h>
#include <stdlib.h>

char* defangIPaddr(char* address);

int main() 
{
    char* addr = "255.100.50.0";
    printf("%s\n", defangIPaddr(addr));
    return 0;
}

char* defangIPaddr(char* address)
{
    char* newAddr = (char*)malloc(30*sizeof(char));
    int a = 0, b = 0, c = 0, d = 0;
    sscanf(address, "%d.%d.%d.%d", &a, &b, &c, &d);
    sprintf(newAddr, "%d[.]%d[.]%d[.]%d", a, b, c, d);
    return newAddr;
}
