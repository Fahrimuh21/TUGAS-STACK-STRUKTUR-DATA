/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  :
Muhammad Akmal Fazli Riyadi 24060124130123
Muhammad Fikri 24060124130069
Khanza Qaila 24060124120011
Nayla Husna 24060124140158
Muhammad Fahri 24060124120037*/
/* Tanggal   : 21 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

/*procedure createStack( output T: Tstack)
    {I.S.: -}
    {F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
    {Proses: menginisialisasi T} */
void createStack(Tstack *T)
{ /* kamus lokal */
    int i;
    /* algoritma */
    T->top = 0;
    for (i = 1; i <= 10; i++)
    {
        T->wadah[i] = '#';
    }
}

boolean isEmptyStack(Tstack T)
{
    return (T.top == 0);
}

/*function isFullStack( T: Tstack) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T)
{
    return (T.top == 10);
}

/*procedure push ( input/output T:Tstack, input E: character )
    {I.S.: T,E terdefinisi}
    {F.S.: infotop tetap, atau berisi nilai E }
    {Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E)
{
    if (!isFullStack(*T))
    {
        T->top++;
        T->wadah[T->top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
    {I.S.: T terdefinisi}
    {F.S.: X= infotop stack lama, atau '#' }
    {Proses: mengambil elemen top, bila belum kosong }*/
void pop(Tstack *T, char *X)
{
    if (!isEmptyStack(*T))
    {
        *X = T->wadah[T->top];
        T->wadah[T->top] = '#';
        T->top--;
    }
    else
    {
        *X = '#';
    }
}

/*procedure printStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan kondisi wadah T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void printStack(Tstack T)
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("%c", T.wadah[i]);
        if (i < 10)
        {
            printf(";");
        }
    }
    printf("\n");
}

/*procedure viewStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen tak kosong T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void viewStack(Tstack T)
{
    int i;
    for (i = 1; i <= T.top; i++)
    {
        printf("%c", T.wadah[i]);
        if (i < T.top)
        {
            printf(";");
        }
    }
    printf("\n");
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
    {I.S.: T,N terdefinisi}
    {F.S.: infotop tetap, atau top=N }
    {Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN(Tstack *T, int N)
{
    char E;
    int i;
    for (i = 1; i <= N; i++)
    {
        if (!isFullStack(*T))
        {
            scanf(" %c", &E);
            push(T, E);
        }
        else
        {
            break;
        }
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
    {I.S.: T terdefinisi, E terdefinisi }
    {F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
    {Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1(Tstack *T, char E)
{
    if (isFullStack(*T))
    {
        createStack(T);
    }
    else
    {
        push(T, E);
    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
    {I.S.: T terdefinisi, E terdefinisi }
    {F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
    {Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma(Tstack *T, char E)
{
    if (!isEmptyStack(*T) && infotop(*T) == E)
    {
        char X;
        pop(T, &X);
    }
    else
    {
        push(T, E);
    }
}

/* Enhanced Helper Functions */
boolean isOperand(char c)
{
    return (c >= '0' && c <= '9');
}

boolean isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

boolean shouldSkip(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

/* Float Stack for handling results > 9 */
typedef struct
{
    float data[10];
    int top;
} FloatStack;

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
    return (S.top >= 9);
}

boolean pushFloat(FloatStack *S, float value)
{
    if (isFullFloatStack(*S))
    {
        return false;
    }
    S->data[++S->top] = value;
    return true;
}

boolean popFloat(FloatStack *S, float *value)
{
    if (isEmptyFloatStack(*S))
    {
        return false;
    }
    *value = S->data[S->top--];
    return true;
}

/* function evaluatePostfix(postfix:string) → float
   {I.S.: postfix terdefinisi, berisi operand (0–9) dan operator (+,-,*,/)}
   {F.S.: Menghasilkan nilai hasil evaluasi ekspresi postfix}
   {ENHANCED: Robust error handling, float arithmetic, whitespace handling}
   {ROBUST FEATURES:
      - Float stack untuk hasil > 9
      - Input validation dan error handling
      - Whitespace handling
      - Division by zero protection
      - Stack underflow/overflow checking}
   {Proses:
      - Baca token postfix satu per satu
      - Skip whitespace
      - Jika token operand (angka) → push ke stack
      - Jika token operator → pop 2 operand (b, a), hitung a op b, lalu push hasilnya kembali ke stack
      - Setelah semua token selesai, elemen terakhir di stack adalah hasil akhir}
   {Contoh:
      postfix="9 3 4 * 8 + 4 / -"
      langkah:
        push 9
        push 3
        push 4
        * → pop(4,3) → 3*4=12 → push 12
        push 8
        + → pop(8,12) → 12+8=20 → push 20
        push 4
        / → pop(4,20) → 20/4=5 → push 5
        - → pop(5,9) → 9-5=4 → push 4
      hasil = 4 } */
float evaluatePostfix(char *postfix)
{
    FloatStack S;
    createFloatStack(&S);
    int i = 0;
    char ch;
    float operand1, operand2, result;
    boolean hasValidToken = false;

    // Input validation
    if (postfix == NULL)
    {
        printf("ERROR: NULL input\n");
        return -999.0f;
    }

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
            if (!pushFloat(&S, value))
            {
                printf("ERROR: Stack overflow\n");
                return -999.0f;
            }
            hasValidToken = true;
        }
        else if (isOperator(ch))
        {
            // Check if we have enough operands
            if (S.top < 1)
            {
                printf("ERROR: Insufficient operands for operator '%c'\n", ch);
                return -999.0f;
            }

            // Pop two operands (order matters!)
            if (!popFloat(&S, &operand2) || !popFloat(&S, &operand1))
            {
                printf("ERROR: Stack underflow\n");
                return -999.0f;
            }

            // Perform operation: operand1 operator operand2
            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0.0f)
                {
                    printf("ERROR: Division by zero\n");
                    return -999.0f;
                }
                result = operand1 / operand2;
                break;
            default:
                printf("ERROR: Invalid operator '%c'\n", ch);
                return -999.0f;
            }

            // Push result back to stack
            if (!pushFloat(&S, result))
            {
                printf("ERROR: Stack overflow on result\n");
                return -999.0f;
            }
            hasValidToken = true;
        }
        else
        {
            // Invalid character - skip or report error
            printf("WARNING: Ignoring invalid character '%c'\n", ch);
        }

        i++;
    }

    // Check if we processed any valid tokens
    if (!hasValidToken)
    {
        printf("ERROR: No valid tokens found\n");
        return -999.0f;
    }

    // Final validation - should have exactly one value left
    if (S.top == -1)
    {
        printf("ERROR: Empty result stack\n");
        return -999.0f;
    }
    else if (S.top > 0)
    {
        printf("ERROR: Too many operands (missing operators)\n");
        return -999.0f;
    }

    // Pop and return the final result
    float finalResult;
    popFloat(&S, &finalResult);
    return finalResult;
}
