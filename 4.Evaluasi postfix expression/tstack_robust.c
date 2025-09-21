/* Program   : tstack_float.c */
/* Deskripsi : ROBUST version of evaluatePostfix using float stack */
/* NIM/Nama  : Enhanced by Copilot */
/* Tanggal   : 22 September 2025*/
/***********************************/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "boolean.h"

/* Float Stack Implementation for Robust Postfix Evaluation */
#define MAX_STACK_SIZE 100

typedef struct
{
    float data[MAX_STACK_SIZE];
    int top;
} FloatStack;

typedef enum
{
    EVAL_SUCCESS = 0,
    EVAL_ERROR_EMPTY_INPUT,
    EVAL_ERROR_INVALID_CHARACTER,
    EVAL_ERROR_STACK_UNDERFLOW,
    EVAL_ERROR_STACK_OVERFLOW,
    EVAL_ERROR_DIVISION_BY_ZERO,
    EVAL_ERROR_TOO_MANY_OPERANDS,
    EVAL_ERROR_INSUFFICIENT_OPERANDS
} EvaluationResult;

/* Float Stack Operations */
void createFloatStack(FloatStack *S)
{
    S->top = -1;
}

boolean isEmptyFloatStack(FloatStack S)
{
    return (S.top == -1);
}

boolean isFullFloatStack(FloatStack S)
{
    return (S.top == MAX_STACK_SIZE - 1);
}

EvaluationResult pushFloat(FloatStack *S, float value)
{
    if (isFullFloatStack(*S))
    {
        return EVAL_ERROR_STACK_OVERFLOW;
    }
    S->data[++S->top] = value;
    return EVAL_SUCCESS;
}

EvaluationResult popFloat(FloatStack *S, float *value)
{
    if (isEmptyFloatStack(*S))
    {
        return EVAL_ERROR_STACK_UNDERFLOW;
    }
    *value = S->data[S->top--];
    return EVAL_SUCCESS;
}

/* Helper Functions */
boolean isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

boolean isOperand(char c)
{
    return (c >= '0' && c <= '9');
}

boolean shouldSkip(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

/* Error message function */
const char *getErrorMessage(EvaluationResult result)
{
    switch (result)
    {
    case EVAL_SUCCESS:
        return "Success";
    case EVAL_ERROR_EMPTY_INPUT:
        return "Empty or whitespace-only input";
    case EVAL_ERROR_INVALID_CHARACTER:
        return "Invalid character in expression";
    case EVAL_ERROR_STACK_UNDERFLOW:
        return "Stack underflow - insufficient operands";
    case EVAL_ERROR_STACK_OVERFLOW:
        return "Stack overflow - expression too complex";
    case EVAL_ERROR_DIVISION_BY_ZERO:
        return "Division by zero";
    case EVAL_ERROR_TOO_MANY_OPERANDS:
        return "Too many operands - missing operators";
    case EVAL_ERROR_INSUFFICIENT_OPERANDS:
        return "Insufficient operands for operator";
    default:
        return "Unknown error";
    }
}

/* ROBUST Postfix Evaluation Function */
EvaluationResult evaluatePostfixRobust(char *postfix, float *result)
{
    FloatStack S;
    createFloatStack(&S);

    int i = 0;
    char ch;
    float operand1, operand2, computation;
    boolean hasValidToken = false;

    // Input validation
    if (postfix == NULL)
    {
        return EVAL_ERROR_EMPTY_INPUT;
    }

    // Process each character
    while ((ch = postfix[i]) != '\0')
    {

        if (shouldSkip(ch))
        {
            // Skip whitespace
            i++;
            continue;
        }

        if (isOperand(ch))
        {
            // Convert character digit to float and push
            float value = (float)(ch - '0');
            EvaluationResult pushResult = pushFloat(&S, value);
            if (pushResult != EVAL_SUCCESS)
            {
                return pushResult;
            }
            hasValidToken = true;
        }
        else if (isOperator(ch))
        {
            // Check if we have enough operands
            if (S.top < 1)
            {
                return EVAL_ERROR_INSUFFICIENT_OPERANDS;
            }

            // Pop two operands (order matters!)
            EvaluationResult pop2 = popFloat(&S, &operand2); // Second operand (right)
            EvaluationResult pop1 = popFloat(&S, &operand1); // First operand (left)

            if (pop1 != EVAL_SUCCESS || pop2 != EVAL_SUCCESS)
            {
                return EVAL_ERROR_STACK_UNDERFLOW;
            }

            // Perform operation: operand1 operator operand2
            switch (ch)
            {
            case '+':
                computation = operand1 + operand2;
                break;
            case '-':
                computation = operand1 - operand2;
                break;
            case '*':
                computation = operand1 * operand2;
                break;
            case '/':
                if (fabs(operand2) < 1e-10)
                { // Check for division by zero
                    return EVAL_ERROR_DIVISION_BY_ZERO;
                }
                computation = operand1 / operand2;
                break;
            default:
                return EVAL_ERROR_INVALID_CHARACTER;
            }

            // Push result back to stack
            EvaluationResult pushResult = pushFloat(&S, computation);
            if (pushResult != EVAL_SUCCESS)
            {
                return pushResult;
            }
            hasValidToken = true;
        }
        else
        {
            // Invalid character
            return EVAL_ERROR_INVALID_CHARACTER;
        }

        i++;
    }

    // Check if we processed any valid tokens
    if (!hasValidToken)
    {
        return EVAL_ERROR_EMPTY_INPUT;
    }

    // Final validation - should have exactly one value left
    if (S.top == -1)
    {
        return EVAL_ERROR_EMPTY_INPUT;
    }
    else if (S.top > 0)
    {
        return EVAL_ERROR_TOO_MANY_OPERANDS;
    }

    // Pop the final result
    EvaluationResult finalPop = popFloat(&S, result);
    return finalPop;
}

/* Wrapper function to maintain compatibility with original signature */
float evaluatePostfix(char *postfix)
{
    float result;
    EvaluationResult status = evaluatePostfixRobust(postfix, &result);

    if (status == EVAL_SUCCESS)
    {
        return result;
    }
    else
    {
        // For compatibility, return a special error value
        // In a real implementation, you'd want proper error handling
        printf("ERROR in evaluatePostfix: %s\n", getErrorMessage(status));
        return -999.0f; // Error indicator
    }
}

/* Test function for robust version */
void testRobustEvaluation()
{
    printf("\n=== TESTING ROBUST POSTFIX EVALUATION ===\n");

    char testCases[][20] = {
        "34+",       // 7
        "99*",       // 81
        "52/",       // 2.5
        "934*8+4/-", // Should work correctly now
        "",          // Error: empty
        "3++",       // Error: insufficient operands
        "30/",       // Error: division by zero
        "3 4 +",     // 7 (with spaces)
        "abc"        // Error: invalid character
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTests; i++)
    {
        float result;
        EvaluationResult status = evaluatePostfixRobust(testCases[i], &result);

        printf("Input: \"%s\" → ", testCases[i]);
        if (status == EVAL_SUCCESS)
        {
            printf("Result: %.2f\n", result);
        }
        else
        {
            printf("ERROR: %s\n", getErrorMessage(status));
        }
    }
}