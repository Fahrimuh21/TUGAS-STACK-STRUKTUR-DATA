/* Test manual untuk debugging edge cases */
#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

int main()
{
    Tstack Undo, Redo;
    char cmd;

    printf("=== MANUAL EDGE CASE TESTING ===\n\n");

    // Test 1: Empty stack undo/redo
    createStack(&Undo);
    createStack(&Redo);

    printf("Test: Undo on empty stack\n");
    printf("Before: cmd='X' (initial value)\n");
    cmd = 'X';
    undoCommand(&Undo, &Redo, &cmd);
    printf("After undo: cmd='%c' (ASCII=%d)\n", cmd, (int)cmd);
    printf("Expected: cmd='\\0' (ASCII=0)\n\n");

    printf("Test: Redo on empty stack\n");
    printf("Before: cmd='Y' (initial value)\n");
    cmd = 'Y';
    redoCommand(&Undo, &Redo, &cmd);
    printf("After redo: cmd='%c' (ASCII=%d)\n", cmd, (int)cmd);
    printf("Expected: cmd='\\0' (ASCII=0)\n\n");

    // Test 2: Normal operation then empty
    printf("Test: Normal then empty\n");
    addCommand(&Undo, &Redo, 'A');
    printf("Added A, now undo:\n");
    undoCommand(&Undo, &Redo, &cmd);
    printf("Undo result: '%c'\n", cmd);

    printf("Try undo again on now-empty stack:\n");
    cmd = 'Z'; // Reset to known value
    undoCommand(&Undo, &Redo, &cmd);
    printf("Undo result: '%c' (ASCII=%d)\n", cmd, (int)cmd);

    return 0;
}