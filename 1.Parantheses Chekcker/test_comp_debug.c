/* Test untuk string di comprehensive test */
#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "boolean.h"

int main()
{
    char testComp[] = "((((((((()))))))))"; // Dari comprehensive test

    printf("Testing comprehensive test case: %s\n", testComp);
    printf("Length: %ld characters\n", strlen(testComp));

    // Manual counting
    int open = 0, close = 0;
    for (int i = 0; testComp[i] != '\0'; i++)
    {
        if (testComp[i] == '(')
            open++;
        if (testComp[i] == ')')
            close++;
    }

    printf("Opening brackets: %d\n", open);
    printf("Closing brackets: %d\n", close);
    printf("Max nesting level: %d\n", open);
    printf("Stack limit: 10\n");
    printf("Should be: %s\n", open <= 10 ? "Valid" : "Invalid due to stack overflow");
    printf("Actual result: %s\n", isValidKurung(testComp) ? "Valid" : "Invalid");

    return 0;
}