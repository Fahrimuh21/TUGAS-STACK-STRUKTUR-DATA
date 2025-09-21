/* Program   : tstack_robust.c */
/* Deskripsi : ROBUST version of infixToPostfix with comprehensive error handling */
/* NIM/Nama  : Enhanced by Copilot */
/* Tanggal   : 22 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

/* Helper function: Check if character is valid operand */
boolean isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}

/* Helper function: Check if character is valid operator */
boolean isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

/* Helper function: Check if character should be ignored (whitespace, invalid) */
boolean shouldIgnore(char ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\n' ||
            (!isOperand(ch) && !isOperator(ch) && ch != '(' && ch != ')'));
}

/* Helper function: Validate expression before processing */
boolean validateExpression(char *infix)
{
    int i = 0;
    int parenCount = 0;
    boolean lastWasOperator = true; // Start as true to handle leading operators
    boolean hasOperand = false;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (shouldIgnore(ch))
        {
            i++;
            continue;
        }

        if (ch == '(')
        {
            parenCount++;
            lastWasOperator = true;
        }
        else if (ch == ')')
        {
            parenCount--;
            if (parenCount < 0)
                return false; // Unmatched close paren
            lastWasOperator = false;
        }
        else if (isOperand(ch))
        {
            hasOperand = true;
            lastWasOperator = false;
        }
        else if (isOperator(ch))
        {
            if (lastWasOperator)
                return false; // Consecutive operators or leading operator
            lastWasOperator = true;
        }

        i++;
    }

    return (parenCount == 0 && !lastWasOperator && hasOperand);
}

/* function precedence(op:char) → integer - Enhanced version */
int precedenceRobust(char op)
{
    if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* function infixToPostfixRobust(infix:string) → string
   {I.S.: infix terdefinisi}
   {F.S.: Menghasilkan string postfix yang valid atau string kosong jika input invalid}
   {ENHANCED: Input validation, error handling, edge case protection}
   {ROBUST FEATURES:
      - Pre-validation of input expression
      - Handles unmatched parentheses
      - Filters invalid characters
      - Prevents consecutive operators
      - Handles empty/whitespace-only input
      - Memory safety with bounds checking} */
char *infixToPostfixRobust(char *infix)
{
    static char postfix[100]; // Static array untuk menyimpan hasil
    Tstack S;
    createStack(&S);
    int i = 0, j = 0;
    char ch, topOp;

    // Clear output buffer
    postfix[0] = '\0';

    // Handle NULL input
    if (infix == NULL)
    {
        return postfix;
    }

    // Validate expression first
    if (!validateExpression(infix))
    {
        return postfix; // Return empty string for invalid expression
    }

    while ((ch = infix[i]) != '\0' && j < 98) // Leave room for null terminator
    {
        // Skip whitespace and invalid characters
        if (shouldIgnore(ch))
        {
            i++;
            continue;
        }

        if (isOperand(ch))
        {
            // Operand: tambahkan langsung ke postfix
            if (j + 2 < 99)
            { // Bounds check
                postfix[j++] = ch;
                postfix[j++] = ' ';
            }
            else
            {
                break; // Buffer full
            }
        }
        else if (ch == '(')
        {
            // Kurung buka: push ke stack
            if (!isFullStack(S))
            {
                push(&S, ch);
            }
        }
        else if (ch == ')')
        {
            // Kurung tutup: pop semua operator hingga '('
            while (!isEmptyStack(S) && infotop(S) != '(')
            {
                if (j + 2 < 99)
                { // Bounds check
                    pop(&S, &topOp);
                    postfix[j++] = topOp;
                    postfix[j++] = ' ';
                }
                else
                {
                    break;
                }
            }
            // Pop '(' dari stack (jangan masukkan ke postfix)
            if (!isEmptyStack(S) && infotop(S) == '(')
            {
                pop(&S, &topOp);
            }
        }
        else if (isOperator(ch))
        {
            // Operator: pop operator dengan precedence >= current operator
            while (!isEmptyStack(S) && infotop(S) != '(' &&
                   precedenceRobust(infotop(S)) >= precedenceRobust(ch))
            {
                if (j + 2 < 99)
                { // Bounds check
                    pop(&S, &topOp);
                    postfix[j++] = topOp;
                    postfix[j++] = ' ';
                }
                else
                {
                    break;
                }
            }
            if (!isFullStack(S))
            {
                push(&S, ch);
            }
        }
        i++;
    }

    // Pop semua sisa operator ke postfix (kecuali unmatched parentheses)
    while (!isEmptyStack(S) && j < 98)
    {
        topOp = infotop(S);
        if (topOp != '(' && topOp != ')')
        { // Skip unmatched parentheses
            if (j + 2 < 99)
            {
                pop(&S, &topOp);
                postfix[j++] = topOp;
                postfix[j++] = ' ';
            }
            else
            {
                break;
            }
        }
        else
        {
            // Remove unmatched parenthesis without adding to output
            pop(&S, &topOp);
        }
    }

    // Hapus trailing space jika ada
    if (j > 0 && postfix[j - 1] == ' ')
    {
        j--;
    }
    postfix[j] = '\0';
    return postfix;
}

/* Original function wrapper untuk kompatibilitas */
char *infixToPostfix(char *infix)
{
    return infixToPostfixRobust(infix);
}