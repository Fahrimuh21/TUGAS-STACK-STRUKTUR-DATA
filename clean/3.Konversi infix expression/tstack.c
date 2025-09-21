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

/*karakter kosong dilambangkan dengan '#'  */

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

/*function top( T: Tstack) -> integer
    {mengembalikan posisi puncak stack } */
int top(Tstack T)
{
    return T.top;
}
/*function infotop( T: Tstack) -> character
    {mengembalikan nilai elemen top stack } */
char infotop(Tstack T)
{
    return T.wadah[top(T)];
}

/*function isEmptyStack( T: Tstack) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T)
{
    return top(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T)
{
    return top(T) == 10;
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

boolean isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}

boolean isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

boolean shouldIgnore(char ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\n' ||
            (!isOperand(ch) && !isOperator(ch) && ch != '(' && ch != ')'));
}

boolean validateExpression(char *infix)
{
    int i = 0;
    int parenCount = 0;
    boolean lastWasOperator = true;
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
                return false;
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
                return false;
            lastWasOperator = true;
        }

        i++;
    }

    return (parenCount == 0 && !lastWasOperator && hasOperand);
}

/* function precedence(op:char) → integer
   {Mengembalikan tingkat prioritas operator}
   {Prioritas: * / = 2, + - = 1, lainnya = 0}
   {Contoh: op='*' → return 2} */
int precedence(char op)
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

/* function infixToPostfix(infix:string) → string
   {I.S.: infix terdefinisi, berisi operand (0–9), operator (+,-,*,/), dan tanda kurung}
   {F.S.: Menghasilkan string postfix sesuai aturan prioritas operator}
   {ENHANCED: Input validation, error handling, edge case protection}
   {ROBUST FEATURES:
      - Pre-validation of input expression
      - Handles unmatched parentheses
      - Filters invalid characters
      - Prevents consecutive operators
      - Handles empty/whitespace-only input
      - Memory safety with bounds checking}
   {Contoh:
      infix="3+(4*3)/4" → postfix="3 4 3 * 4 / +"
      infix="3*(4+5)/2" → postfix="3 4 5 + * 2 /"
      infix="3+(4*5)-2" → postfix="3 4 5 * + 2 -"} */
char *infixToPostfix(char *infix)
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
                break;
            }
        }
        else if (ch == '(')
        {
            if (!isFullStack(S))
            {
                push(&S, ch);
            }
        }
        else if (ch == ')')
        {
            while (!isEmptyStack(S) && infotop(S) != '(')
            {
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
            if (!isEmptyStack(S) && infotop(S) == '(')
            {
                pop(&S, &topOp);
            }
        }
        else if (isOperator(ch))
        {
            while (!isEmptyStack(S) && infotop(S) != '(' &&
                   precedence(infotop(S)) >= precedence(ch))
            {
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
            if (!isFullStack(S))
            {
                push(&S, ch);
            }
        }
        i++;
    }

    while (!isEmptyStack(S) && j < 98)
    {
        topOp = infotop(S);
        if (topOp != '(' && topOp != ')')
        {
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
            pop(&S, &topOp);
        }
    }

    if (j > 0 && postfix[j - 1] == ' ')
    {
        j--;
    }
    postfix[j] = '\0';
    return postfix;
}