#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome1(char* s);
bool isPalindrome2(char* s);

int main()
{
    char* str = "aabbaaaaa";

    puts("Solution1:");
    if(isPalindrome1(str)) {
        puts("str is Palindrome.");
    } else {
        puts("str is not Palindrome.");
    }

    puts("Solution2:");
    if(isPalindrome2(str)) {
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

bool isPalindrome1(char* s) {
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

bool isPalindrome2(char* s) {
    int l = 0;
    int r = strlen(s)-1;

    while(l < r) {
        if(!isalnum(s[l])) ++l;
        else if(!isalnum(s[r])) --r;
        else if((s[l]+32-'a')%32 != (s[r]+32-'a')%32) return false;
        else { ++l; --r; }
    }
    return true;
}