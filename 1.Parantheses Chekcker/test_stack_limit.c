/* Program   : test_stack_limit.c */
/* Deskripsi : Menguji batasan stack untuk isValidKurung */

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

int main()
{
    printf("=== TESTING STACK LIMIT FOR isValidKurung ===\n\n");

    // Test dengan berbagai panjang
    char test1[] = "(())";                      // 2 level nesting - OK
    char test2[] = "((()))";                    // 3 level nesting - OK
    char test3[] = "(((())))";                  // 4 level nesting - OK
    char test4[] = "((((()))))";                // 5 level nesting - OK
    char test5[] = "(((((())))";                // 6 level nesting - tidak seimbang
    char test6[] = "((((((()))))))";            // 6 level nesting - seimbang
    char test7[] = "(((((((())))))))";          // 7 level nesting - seimbang
    char test8[] = "(((((((())))))))";          // 8 level nesting - seimbang
    char test9[] = "(((((((((())))))))))";      // 9 level nesting - seimbang
    char test10[] = "((((((((((()))))))))))";   // 10 level nesting - seimbang (stack limit)
    char test11[] = "(((((((((((())))))))))))"; // 11 level nesting - melebihi stack

    printf("Stack capacity: 10 elements\n\n");

    printf("Test 1 (2 levels): \"%s\" -> %s\n", test1,
           isValidKurung(test1) ? "Valid" : "Invalid");
    printf("Test 2 (3 levels): \"%s\" -> %s\n", test2,
           isValidKurung(test2) ? "Valid" : "Invalid");
    printf("Test 3 (4 levels): \"%s\" -> %s\n", test3,
           isValidKurung(test3) ? "Valid" : "Invalid");
    printf("Test 4 (5 levels): \"%s\" -> %s\n", test4,
           isValidKurung(test4) ? "Valid" : "Invalid");
    printf("Test 5 (6 levels unbalanced): \"%s\" -> %s\n", test5,
           isValidKurung(test5) ? "Valid" : "Invalid");
    printf("Test 6 (6 levels balanced): \"%s\" -> %s\n", test6,
           isValidKurung(test6) ? "Valid" : "Invalid");
    printf("Test 7 (7 levels balanced): \"%s\" -> %s\n", test7,
           isValidKurung(test7) ? "Valid" : "Invalid");
    printf("Test 8 (8 levels balanced): \"%s\" -> %s\n", test8,
           isValidKurung(test8) ? "Valid" : "Invalid");
    printf("Test 9 (9 levels balanced): \"%s\" -> %s\n", test9,
           isValidKurung(test9) ? "Valid" : "Invalid");
    printf("Test 10 (10 levels - stack limit): \"%s\" -> %s\n", test10,
           isValidKurung(test10) ? "Valid" : "Invalid");
    printf("Test 11 (11 levels - exceeds stack): \"%s\" -> %s\n", test11,
           isValidKurung(test11) ? "Valid" : "Invalid");

    printf("\n=== ANALYSIS ===\n");
    printf("The function can handle up to 10 nested levels due to stack limit.\n");
    printf("Beyond that, it may not work correctly because push() fails when stack is full.\n");

    // Test what happens when stack overflows
    printf("\n=== OVERFLOW BEHAVIOR TEST ===\n");
    char overflow_test[] = "(((((((((((("; // 12 opening brackets
    printf("12 opening brackets: \"%s\" -> %s\n", overflow_test,
           isValidKurung(overflow_test) ? "Valid" : "Invalid");
    printf("(Should be Invalid due to stack overflow and unbalanced)\n");

    return 0;
}