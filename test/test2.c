#include <stdio.h>
#include <string.h>

int countSubstr(const char *mainStr, const char *subStr) {
    int count = 0;
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);

    for (int i = 0; i <= mainLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (mainStr[i + j] != subStr[j]) {
                break;
            }
        }
        if (j == subLen) {
            count++;
        }
    }
    return count;
}

int main() {
    char mainStr[100], subStr[100];
    printf("Enter the main string: ");
    gets(mainStr);
    printf("Enter the substring: ");
    gets(subStr);

    int count = countSubstr(mainStr, subStr);
    printf("The substring '%s' occurs %d times in the main string.\n", subStr, count);

    return 0;
}