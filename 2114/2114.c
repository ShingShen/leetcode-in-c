// 2114. Maximum Number of Words Found in Sentences
#include <stdio.h>

int mostWordsFound(char* sentences[], int sentencesSize);

int main() 
{
    char* arr[] = {
        "alice and bob love leetcode\0", 
        "i think so too\0", 
        "this is great thanks very much\0"};
    
    printf("%d\n", mostWordsFound(arr, 3));
    
    return 0;
}

int mostWordsFound(char* sentences[], int sentencesSize)
{
    int ans = 0;
    for (int i = 0; i < sentencesSize; i++){
        int cur = 1;
        int j = 0;
        while(sentences[i][j]){
            if (sentences[i][j] == ' ')
                cur++;
            j++;
        }
        ans = (cur > ans) ? cur : ans;
    }
    return ans;
}
