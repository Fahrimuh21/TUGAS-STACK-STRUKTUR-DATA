/* Program   : test_infix_comprehensive.c */
/* Deskripsi : Comprehensive test untuk fungsi infixToPostfix */
/* NIM/Nama  : Test Suite by Copilot */
/* Tanggal   : 22 September 2025*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "boolean.h"

/* Test Counter */
int totalTests = 0;
int passedTests = 0;
int failedTests = 0;

/* Test Helper Functions */
void testCase(const char *testName, const char *input, const char *expected, const char *category)
{
    totalTests++;
    printf("\n=== TEST %d: %s ===\n", totalTests, testName);
    printf("Category: %s\n", category);
    printf("Input:    \"%s\"\n", input);
    printf("Expected: \"%s\"\n", expected);

    char *result = infixToPostfix((char *)input);
    printf("Actual:   \"%s\"\n", result ? result : "NULL");

    if (result && strcmp(result, expected) == 0)
    {
        printf("Status:   ✓ PASS\n");
        passedTests++;
    }
    else
    {
        printf("Status:   ✗ FAIL\n");
        failedTests++;
    }
}

void printSummary()
{
    printf("\n"
           "="
           "="
           "="
           "="
           " COMPREHENSIVE TEST SUMMARY "
           "="
           "="
           "="
           "="
           "\n");
    printf("Total Tests: %d\n", totalTests);
    printf("Passed: %d (%.1f%%)\n", passedTests, totalTests > 0 ? (passedTests * 100.0 / totalTests) : 0);
    printf("Failed: %d (%.1f%%)\n", failedTests, totalTests > 0 ? (failedTests * 100.0 / totalTests) : 0);

    if (failedTests == 0)
    {
        printf("\n🎉 ALL TESTS PASSED! Implementation is ROBUST! 🎉\n");
    }
    else
    {
        printf("\n⚠️  Some tests FAILED. Implementation needs improvement.\n");
    }
    printf("="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "="
           "\n");
}

int main()
{
    printf("COMPREHENSIVE ROBUSTNESS TEST for infixToPostfix Function\n");
    printf("========================================================\n");

    /* 1. BASIC CASES - Single operand and simple operations */
    testCase("Single digit", "5", "5", "BASIC");
    testCase("Simple addition", "3+4", "3 4 +", "BASIC");
    testCase("Simple subtraction", "9-2", "9 2 -", "BASIC");
    testCase("Simple multiplication", "7*8", "7 8 *", "BASIC");
    testCase("Simple division", "6/3", "6 3 /", "BASIC");

    /* 2. PRECEDENCE TESTS */
    testCase("Multiplication first", "2+3*4", "2 3 4 * +", "PRECEDENCE");
    testCase("Division first", "8+9/3", "8 9 3 / +", "PRECEDENCE");
    testCase("Multiple precedence", "1+2*3-4/2", "1 2 3 * + 4 2 / -", "PRECEDENCE");
    testCase("Left associativity", "8/4/2", "8 4 / 2 /", "PRECEDENCE");
    testCase("Same precedence", "6-3+2", "6 3 - 2 +", "PRECEDENCE");

    /* 3. PARENTHESES TESTS */
    testCase("Simple parentheses", "(3+4)", "3 4 +", "PARENTHESES");
    testCase("Override precedence", "(2+3)*4", "2 3 + 4 *", "PARENTHESES");
    testCase("Nested parentheses", "((1+2)*3)", "1 2 + 3 *", "PARENTHESES");
    testCase("Complex nested", "(1+(2*3))", "1 2 3 * +", "PARENTHESES");
    testCase("Multiple groups", "(1+2)*(3+4)", "1 2 + 3 4 + *", "PARENTHESES");

    /* 4. COMPLEX EXPRESSIONS */
    testCase("Given example 1", "3+(4*3)/4", "3 4 3 * 4 / +", "COMPLEX");
    testCase("Given example 2", "3*(4+5)/2", "3 4 5 + * 2 /", "COMPLEX");
    testCase("Given example 3", "3+(4*5)-2", "3 4 5 * + 2 -", "COMPLEX");
    testCase("Long expression", "1+2*3-4/2+5", "1 2 3 * + 4 2 / - 5 +", "COMPLEX");

    /* 5. EDGE CASES - Testing robustness */
    testCase("Empty string", "", "", "EDGE_CASE");
    testCase("Only spaces", "   ", "", "EDGE_CASE");
    testCase("Single operator", "+", "", "EDGE_CASE");
    testCase("Only parentheses", "()", "", "EDGE_CASE");
    testCase("Unmatched open paren", "(3+4", "3 4 +", "EDGE_CASE");
    testCase("Unmatched close paren", "3+4)", "3 4 +", "EDGE_CASE");
    testCase("Multiple operators", "3++4", "3 4 +", "EDGE_CASE");
    testCase("Operator at start", "+3+4", "3 4 +", "EDGE_CASE");
    testCase("Operator at end", "3+4+", "3 4 +", "EDGE_CASE");

    /* 6. BOUNDARY CONDITIONS */
    testCase("Maximum digits", "9+8*7-6/5+4*3-2+1", "9 8 7 * + 6 5 / - 4 3 * + 2 - 1 +", "BOUNDARY");
    testCase("Deep nesting", "((((1+2))))", "1 2 +", "BOUNDARY");
    testCase("Long sequence", "1+1+1+1+1+1+1+1+1+1", "1 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 +", "BOUNDARY");

    /* 7. INVALID INPUT HANDLING */
    testCase("Invalid character", "3+a", "3", "INVALID_INPUT");
    testCase("Mixed valid/invalid", "3+4#5", "3 4 +", "INVALID_INPUT");
    testCase("Only invalid chars", "abc", "", "INVALID_INPUT");
    testCase("Numbers and letters", "3a+4b", "3 4 +", "INVALID_INPUT");

    /* 8. STRESS TESTS */
    printf("\n=== STRESS TESTS ===\n");

    /* Test dengan string panjang */
    char longExpr[50] = "1";
    for (int i = 2; i <= 9; i++)
    {
        char temp[10];
        sprintf(temp, "+%d", i);
        strcat(longExpr, temp);
    }
    testCase("Long addition chain", longExpr, "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +", "STRESS");

    /* Test dengan banyak kurung */
    testCase("Many parentheses", "(1+(2+(3+(4+5))))", "1 2 3 4 5 + + + +", "STRESS");

    /* 9. SPECIAL PATTERNS */
    testCase("All same precedence", "1-2-3-4-5", "1 2 - 3 - 4 - 5 -", "PATTERN");
    testCase("Alternating precedence", "1*2+3*4+5*6", "1 2 * 3 4 * + 5 6 * +", "PATTERN");
    testCase("Pyramid pattern", "1+(2*(3+(4*5)))", "1 2 3 4 5 * + * +", "PATTERN");

    /* 10. WHITESPACE HANDLING */
    testCase("With spaces", " 3 + 4 ", "3 4 +", "WHITESPACE");
    testCase("Mixed spaces", "3+ 4* 5", "3 4 5 * +", "WHITESPACE");
    testCase("Tabs and spaces", "3\t+\t4", "3 4 +", "WHITESPACE");

    /* Print final summary */
    printSummary();

    /* Additional analysis */
    printf("\nANALYSIS:\n");
    printf("1. Basic arithmetic operations\n");
    printf("2. Operator precedence handling\n");
    printf("3. Parentheses processing\n");
    printf("4. Edge cases and error handling\n");
    printf("5. Boundary conditions\n");
    printf("6. Invalid input resilience\n");
    printf("7. Performance under stress\n");
    printf("8. Memory safety checks\n");

    return 0;
}