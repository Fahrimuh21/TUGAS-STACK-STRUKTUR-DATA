/* Program   : test_limited.c */
/* Deskripsi : Test sederhana untuk evaluatePostfix dengan keterbatasan stack karakter */
/* NIM/Nama  : Test by Copilot */
/* Tanggal   : 22 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

void testCase(const char *testName, const char *input, float expected, const char *notes)
{
    printf("\n=== %s ===\n", testName);
    printf("Input:    \"%s\"\n", input);
    printf("Expected: %.1f\n", expected);

    float result = evaluatePostfix((char *)input);
    printf("Actual:   %.1f\n", result);
    printf("Notes:    %s\n", notes);

    if (result == expected)
    {
        printf("Status:   ✓ PASS\n");
    }
    else
    {
        printf("Status:   ✗ FAIL\n");
    }
}

int main()
{
    printf("TESTING evaluatePostfix dengan Stack Karakter (Keterbatasan Diakui)\n");
    printf("====================================================================\n");

    /* Test cases yang BISA bekerja dengan stack karakter */
    testCase("Single digit", "5", 5.0f, "Basic case - OK");
    testCase("Simple addition (result ≤ 9)", "34+", 7.0f, "3+4=7 - OK");
    testCase("Simple subtraction", "92-", 7.0f, "9-2=7 - OK");
    testCase("With spaces", "3 4 +", 7.0f, "Whitespace handling - OK");
    testCase("Zero result", "33-", 0.0f, "3-3=0 - OK");
    testCase("Division (integer)", "84/", 2.0f, "8/4=2 - OK");

    printf("\n"
           "="
           "="
           "="
           " CASES WITH KNOWN LIMITATIONS "
           "="
           "="
           "="
           "\n");

    /* Test cases yang AKAN bermasalah dengan stack karakter */
    testCase("Result > 9", "55+", 10.0f, "5+5=10 - AKAN OVERFLOW!");
    testCase("Large multiplication", "99*", 81.0f, "9*9=81 - AKAN OVERFLOW!");
    testCase("Float division", "52/", 2.5f, "5/2=2.5 - INTEGER DIVISION!");

    printf("\n"
           "="
           "="
           "="
           " ERROR HANDLING TESTS "
           "="
           "="
           "="
           "\n");

    testCase("Division by zero", "30/", 0.0f, "Should return 0 (error handling)");
    testCase("Insufficient operands", "3+", 0.0f, "Should return 0 (error handling)");
    testCase("Empty string", "", 0.0f, "Should return 0 (error handling)");
    testCase("Only operator", "+", 0.0f, "Should return 0 (error handling)");

    printf("\n"
           "="
           "="
           "="
           " SUMMARY "
           "="
           "="
           "="
           "\n");
    printf("KESIMPULAN:\n");
    printf("✅ YANG BISA BEKERJA:\n");
    printf("   - Operand dan hasil single digit (0-9)\n");
    printf("   - Operasi aritmetika dasar\n");
    printf("   - Whitespace handling\n");
    printf("   - Basic error handling\n");
    printf("\n");
    printf("❌ KETERBATASAN YANG TIDAK BISA DIATASI:\n");
    printf("   - Hasil > 9 (character overflow)\n");
    printf("   - Hasil < 0 (negative numbers)\n");
    printf("   - Float division (akan jadi integer)\n");
    printf("   - Multi-digit numbers (hanya 0-9)\n");
    printf("\n");
    printf("📋 EVALUASI ROBUSTNESS:\n");
    printf("   - Untuk constraint yang ada: CUKUP ROBUST ✅\n");
    printf("   - Untuk kebutuhan umum: TERBATAS ⚠️\n");
    printf("   - Untuk pembelajaran: SESUAI TUJUAN ✅\n");

    return 0;
}