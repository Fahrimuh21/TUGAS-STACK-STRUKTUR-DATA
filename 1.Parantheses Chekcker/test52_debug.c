/* Test spesifik untuk test 52 */
#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "boolean.h"

int main()
{
    char test52[] = "((((((((()))))))))"; // Test 52 yang gagal

    printf("Testing: %s\n", test52);
    printf("Length: %ld characters\n", strlen(test52));

    // Manual counting
    int open = 0, close = 0;
    for (int i = 0; test52[i] != '\0'; i++)
    {
        if (test52[i] == '(')
            open++;
        if (test52[i] == ')')
            close++;
    }

    printf("Opening brackets: %d\n", open);
    printf("Closing brackets: %d\n", close);
    printf("Max nesting level: %d\n", open); // Assuming all opens come first
    printf("Stack limit: 10\n");
    printf("Should be: %s (within stack limit)\n", open <= 10 ? "Valid" : "Invalid due to stack overflow");
    printf("Actual result: %s\n", isValidKurung(test52) ? "Valid" : "Invalid");

    return 0;
}