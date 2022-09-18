#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s);

int main()
{
    char* str = "aabbaaaaa";

    if(isPalindrome(str)) {
        puts("str is Palindrome.");
    } else {
        puts("str is not Palindrome.");
    }
}

bool isAlNum(char ch)
{
    if(ch >= 'a' && ch <= 'z') return true;
    if(ch >= 'A' && ch <= 'Z') return true;
    if(ch >= '0' && ch <= '9') return true;
    return false;
}

bool isPalindrome(char* s) {
    int l = 0;
    int r = strlen(s)-1;

    while(l < r) {
        if(!isAlNum(s[l])) ++l;
        else if(!isAlNum(s[r])) --r;
        else if((s[l]+32-'a')%32 != (s[r]+32-'a')%32) return false;
        else { ++l; --r; }
    }
    return true;
}