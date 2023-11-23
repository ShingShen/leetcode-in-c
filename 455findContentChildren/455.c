#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int contentChildren = 0;
    int gIndex = 0;
    int sIndex = 0;
    while (gIndex < gSize && sIndex < sSize) {
        if (s[sIndex] >= g[gIndex]) {
            contentChildren++;
            gIndex++;
        }
        sIndex++;
    }

    return contentChildren;
}

int main() {
    int g[] = {1, 2, 3};
    int gSize = sizeof(g) / sizeof(g[0]);
    int s[] = {1, 1};
    int sSize = sizeof(s) / sizeof(s[0]);

    int result = findContentChildren(g, gSize, s, sSize);

    printf("Result: %d\n", result);

    return 0;
}
