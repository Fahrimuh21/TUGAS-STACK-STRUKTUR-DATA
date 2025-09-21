/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
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
   {Proses:
      - Jika token operand → tambahkan langsung ke postfix
      - Jika token '(' → push ke stack
      - Jika token ')' → pop semua operator hingga '('
      - Jika token operator:
          • Pop operator di stack selama precedence(top) ≥ precedence(current)
          • Push operator sekarang ke stack
      - Setelah semua token diproses → pop semua sisa operator ke postfix}
   {Contoh:
      infix="3+(4*3)/4" → postfix="3 4 3 * 4 / +"
      infix="3*(4+5)/2" → postfix="3 4 5 + * 2 /"
      infix="3+(4*5)-2" → postfix="3 4 5 * + 2 -"} */

/* function infixToPostfix(infix:string) → string
   {I.S.: infix terdefinisi, berisi operand (0–9), operator (+,-,*,/), dan tanda kurung}
   {F.S.: Menghasilkan string postfix sesuai aturan prioritas operator}
   {CATATAN: Menggunakan static array - tidak thread-safe tetapi sesuai header file}
   {Proses:
      - Jika token operand → tambahkan langsung ke postfix
      - Jika token '(' → push ke stack
      - Jika token ')' → pop semua operator hingga '('
      - Jika token operator:
          • Pop operator di stack selama precedence(top) ≥ precedence(current)
          • Push operator sekarang ke stack
      - Setelah semua token diproses → pop semua sisa operator ke postfix}
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

    while ((ch = infix[i]) != '\0')
    {
        if (ch >= '0' && ch <= '9')
        {
            // Operand: tambahkan langsung ke postfix
            postfix[j++] = ch;
            postfix[j++] = ' ';
        }
        else if (ch == '(')
        {
            // Kurung buka: push ke stack
            push(&S, ch);
        }
        else if (ch == ')')
        {
            // Kurung tutup: pop semua operator hingga '('
            while (!isEmptyStack(S) && infotop(S) != '(')
            {
                pop(&S, &topOp);
                postfix[j++] = topOp;
                postfix[j++] = ' ';
            }
            // Pop '(' dari stack tanpa memasukkan ke postfix
            if (!isEmptyStack(S))
            {
                pop(&S, &topOp);
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            // Operator: pop operator dengan precedence >= current operator
            while (!isEmptyStack(S) && infotop(S) != '(' &&
                   precedence(infotop(S)) >= precedence(ch))
            {
                pop(&S, &topOp);
                postfix[j++] = topOp;
                postfix[j++] = ' ';
            }
            push(&S, ch);
        }
        i++;
    }

    // Pop semua sisa operator ke postfix
    while (!isEmptyStack(S))
    {
        pop(&S, &topOp);
        postfix[j++] = topOp;
        postfix[j++] = ' ';
    }

    // Hapus trailing space jika ada
    if (j > 0 && postfix[j - 1] == ' ')
    {
        j--;
    }
    postfix[j] = '\0';
    return postfix;
}