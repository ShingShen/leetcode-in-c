#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char* findLongestWord(char* s, char** dictionary, int dictionarySize);

int main(void) 
{
    char* s = "abpcplea";
    char* dictionary[] = {"ale", "apple", "monkey", "plea"};
    int dictionarySize = 4;
    
    char* result = findLongestWord(s, dictionary, dictionarySize);
    printf("Output: %s\n", result);
    
    return 0;
}

bool isSubsequence(char* s, char* word) 
{
    int i = 0, j = 0;
    while (s[i] != '\0' && word[j] != '\0') {
        if (s[i] == word[j]) {
            j++;
        }
        i++;
    }
    return word[j] == '\0';
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) 
{
    char* longestWord = "";
    for (int i = 0; i < dictionarySize; i++) {
        if (isSubsequence(s, dictionary[i])) {
            if (strlen(dictionary[i]) > strlen(longestWord) ||
                (strlen(dictionary[i]) == strlen(longestWord) && strcmp(dictionary[i], longestWord) < 0)) {
                longestWord = dictionary[i];
            }
        }
    }
    return longestWord;
}
