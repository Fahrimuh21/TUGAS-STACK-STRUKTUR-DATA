/* Program   : test_undo_redo_comprehensive.c */
/* Deskripsi : Testing komprehensif untuk sistem Undo-Redo */
/* Tanggal   : 21 September 2025*/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "boolean.h"

// Helper function untuk memeriksa isi stack
void checkStack(Tstack S, char expected[], char *stackName)
{
    printf("  %s: [", stackName);
    if (isEmptyStack(S))
    {
        printf("kosong");
    }
    else
    {
        for (int i = 1; i <= S.top; i++)
        {
            printf("%c", S.wadah[i]);
            if (i < S.top)
                printf("|");
        }
    }
    printf("] ");

    // Verifikasi dengan expected
    if (strlen(expected) == 0 && isEmptyStack(S))
    {
        printf("✓ OK\n");
    }
    else if (strlen(expected) == S.top)
    {
        boolean match = true;
        for (int i = 0; i < strlen(expected); i++)
        {
            if (expected[i] != S.wadah[i + 1])
            {
                match = false;
                break;
            }
        }
        printf(match ? "✓ OK\n" : "✗ FAIL\n");
    }
    else
    {
        printf("✗ FAIL\n");
    }
}

int main()
{
    printf("=== COMPREHENSIVE TESTING FOR UNDO-REDO SYSTEM ===\n\n");

    Tstack Undo, Redo;
    char cmd;
    int testNum = 1;

    // TEST 1: Inisialisasi
    printf("Test %d: Inisialisasi Stack\n", testNum++);
    createStack(&Undo);
    createStack(&Redo);
    checkStack(Undo, "", "Undo");
    checkStack(Redo, "", "Redo");
    printf("\n");

    // TEST 2: Add Command Normal
    printf("Test %d: Add Commands (a, b, c)\n", testNum++);
    addCommand(&Undo, &Redo, 'a');
    checkStack(Undo, "a", "Undo");
    checkStack(Redo, "", "Redo");

    addCommand(&Undo, &Redo, 'b');
    checkStack(Undo, "ab", "Undo");
    checkStack(Redo, "", "Redo");

    addCommand(&Undo, &Redo, 'c');
    checkStack(Undo, "abc", "Undo");
    checkStack(Redo, "", "Redo");
    printf("\n");

    // TEST 3: Undo Operations
    printf("Test %d: Undo Operations\n", testNum++);
    undoCommand(&Undo, &Redo, &cmd);
    printf("  Undo result: '%c'\n", cmd);
    checkStack(Undo, "ab", "Undo");
    checkStack(Redo, "c", "Redo");

    undoCommand(&Undo, &Redo, &cmd);
    printf("  Undo result: '%c'\n", cmd);
    checkStack(Undo, "a", "Undo");
    checkStack(Redo, "cb", "Redo");
    printf("\n");

    // TEST 4: Redo Operations
    printf("Test %d: Redo Operations\n", testNum++);
    redoCommand(&Undo, &Redo, &cmd);
    printf("  Redo result: '%c'\n", cmd);
    checkStack(Undo, "ab", "Undo");
    checkStack(Redo, "c", "Redo");

    redoCommand(&Undo, &Redo, &cmd);
    printf("  Redo result: '%c'\n", cmd);
    checkStack(Undo, "abc", "Undo");
    checkStack(Redo, "", "Redo");
    printf("\n");

    // TEST 5: Add Command setelah Undo (menghapus Redo)
    printf("Test %d: Add Command setelah Undo (Redo harus kosong)\n", testNum++);
    undoCommand(&Undo, &Redo, &cmd); // Undo c
    printf("  Undo c: Undo=[ab], Redo=[c]\n");
    addCommand(&Undo, &Redo, 'd'); // Add d, Redo harus kosong
    checkStack(Undo, "abd", "Undo");
    checkStack(Redo, "", "Redo");
    printf("\n");

    // TEST 6: Edge Case - Undo pada stack kosong
    printf("Test %d: Edge Case - Undo pada stack kosong\n", testNum++);
    createStack(&Undo); // Reset ke kosong
    createStack(&Redo);
    undoCommand(&Undo, &Redo, &cmd);
    printf("  Undo pada stack kosong: '%c' (should be '\\0')\n", cmd);
    checkStack(Undo, "", "Undo");
    checkStack(Redo, "", "Redo");
    printf("\n");

    // TEST 7: Edge Case - Redo pada stack kosong
    printf("Test %d: Edge Case - Redo pada stack kosong\n", testNum++);
    redoCommand(&Undo, &Redo, &cmd);
    printf("  Redo pada stack kosong: '%c' (should be '\\0')\n", cmd);
    checkStack(Undo, "", "Undo");
    checkStack(Redo, "", "Redo");
    printf("\n");

    // TEST 8: Stack Overflow Test
    printf("Test %d: Stack Overflow Test (11 commands)\n", testNum++);
    createStack(&Undo);
    createStack(&Redo);
    for (char c = 'A'; c <= 'K'; c++)
    { // 11 commands
        addCommand(&Undo, &Redo, c);
        printf("  Add '%c': Undo top=%d, full=%s\n", c, Undo.top, isFullStack(Undo) ? "Yes" : "No");
    }
    printf("  Final Undo stack (should only have 10 elements):\n");
    checkStack(Undo, "ABCDEFGHIJ", "Undo"); // K tidak masuk karena overflow
    printf("\n");

    // TEST 9: Complex Workflow
    printf("Test %d: Complex Workflow Simulation\n", testNum++);
    createStack(&Undo);
    createStack(&Redo);

    printf("  Workflow: Add(x) -> Add(y) -> Add(z) -> Undo -> Add(w) -> Undo -> Undo -> Redo\n");
    addCommand(&Undo, &Redo, 'x');
    addCommand(&Undo, &Redo, 'y');
    addCommand(&Undo, &Redo, 'z');
    printf("    After adds: ");
    checkStack(Undo, "xyz", "Undo");

    undoCommand(&Undo, &Redo, &cmd); // Undo z
    printf("    After undo z: ");
    checkStack(Undo, "xy", "Undo");
    checkStack(Redo, "z", "Redo");

    addCommand(&Undo, &Redo, 'w'); // Add w, Redo should clear
    printf("    After add w: ");
    checkStack(Undo, "xyw", "Undo");
    checkStack(Redo, "", "Redo");

    undoCommand(&Undo, &Redo, &cmd); // Undo w
    undoCommand(&Undo, &Redo, &cmd); // Undo y
    printf("    After undo w,y: ");
    checkStack(Undo, "x", "Undo");
    checkStack(Redo, "wy", "Redo");

    redoCommand(&Undo, &Redo, &cmd); // Redo y
    printf("    After redo y: ");
    checkStack(Undo, "xy", "Undo");
    checkStack(Redo, "w", "Redo");
    printf("\n");

    // TEST 10: Stress Test - Multiple Undo/Redo
    printf("Test %d: Stress Test - Multiple Undo/Redo cycles\n", testNum++);
    createStack(&Undo);
    createStack(&Redo);

    // Add 5 commands
    for (char c = '1'; c <= '5'; c++)
    {
        addCommand(&Undo, &Redo, c);
    }

    // Undo all
    for (int i = 0; i < 5; i++)
    {
        undoCommand(&Undo, &Redo, &cmd);
    }
    printf("  After undo all: ");
    checkStack(Undo, "", "Undo");
    checkStack(Redo, "54321", "Redo");

    // Redo all
    for (int i = 0; i < 5; i++)
    {
        redoCommand(&Undo, &Redo, &cmd);
    }
    printf("  After redo all: ");
    checkStack(Undo, "12345", "Undo");
    checkStack(Redo, "", "Redo");

    // Try extra undo/redo (should fail gracefully)
    undoCommand(&Undo, &Redo, &cmd);
    undoCommand(&Undo, &Redo, &cmd);
    redoCommand(&Undo, &Redo, &cmd);
    redoCommand(&Undo, &Redo, &cmd);
    redoCommand(&Undo, &Redo, &cmd); // Extra redo - should fail
    printf("  After extra operations: ");
    checkStack(Undo, "12345", "Undo");
    checkStack(Redo, "", "Redo");

    printf("\n=== SUMMARY ===\n");
    printf("Semua test cases telah dijalankan.\n");
    printf("Jika ada '✗ FAIL', berarti implementasi perlu diperbaiki.\n");
    printf("Jika semua '✓ OK', berarti implementasi sudah kokoh!\n");

    return 0;
}