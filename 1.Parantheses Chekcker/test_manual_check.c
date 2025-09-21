/* Program   : test_manual_check.c */
/* Deskripsi : Manual check untuk debugging */

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

int main()
{
    printf("=== MANUAL DEBUGGING ===\n\n");

    // Test dengan counting manual
    char test1[] = "((((((((((()))))))))))"; // 10 buka, 10 tutup - seharusnya valid
    char test2[] = "(((((((((())))))))))";   // 9 buka, 9 tutup - seharusnya valid

    printf("Test 1: \"%s\"\n", test1);
    printf("Manual count: 10 opening, 10 closing brackets\n");
    printf("Max nesting level: 10 (should hit stack limit)\n");
    printf("Result: %s\n\n", isValidKurung(test1) ? "Valid" : "Invalid");

    printf("Test 2: \"%s\"\n", test2);
    printf("Manual count: 9 opening, 9 closing brackets\n");
    printf("Max nesting level: 9 (within stack limit)\n");
    printf("Result: %s\n\n", isValidKurung(test2) ? "Valid" : "Invalid");

    // Test step by step untuk 10 level
    printf("=== STEP BY STEP DEBUG FOR 10 LEVELS ===\n");
    Tstack S;
    createStack(&S);
    char test[] = "((((((((((()))))))))))";
    int i = 0;
    char ch;

    printf("Processing: %s\n", test);
    while ((ch = test[i]) != '\0')
    {
        printf("Step %d: char='%c', stack_top=%d, stack_full=%s\n",
               i + 1, ch, S.top, isFullStack(S) ? "Yes" : "No");

        if (ch == '(')
        {
            if (isFullStack(S))
            {
                printf("  -> STACK OVERFLOW! Cannot push more.\n");
                break;
            }
            else
            {
                push(&S, ch);
                printf("  -> Pushed '(', new top=%d\n", S.top);
            }
        }
        else if (ch == ')')
        {
            if (isEmptyStack(S))
            {
                printf("  -> ERROR: Stack empty but found closing bracket\n");
                break;
            }
            else
            {
                char popped;
                pop(&S, &popped);
                printf("  -> Popped '%c', new top=%d\n", popped, S.top);
            }
        }
        i++;
    }

    printf("Final stack empty: %s\n", isEmptyStack(S) ? "Yes" : "No");

    return 0;
}