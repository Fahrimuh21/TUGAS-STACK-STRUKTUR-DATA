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

/* function evaluatePostfix(postfix:string) → float
   {I.S.: postfix terdefinisi, berisi operand (0–9) dan operator (+,-,*,/)}
   {F.S.: Menghasilkan nilai hasil evaluasi ekspresi postfix}
   {CATATAN: Menggunakan Tstack karakter - terbatas untuk hasil 0-9}
   {IMPROVED FEATURES:
      - Basic input validation
      - Whitespace handling
      - Division by zero protection
      - Stack underflow checking}
   {KETERBATASAN:
      - Hasil hanya akurat untuk single digit (0-9)
      - Hasil > 9 akan mengalami character overflow
      - Floating point division akan dibulatkan ke integer}
   {Proses:
      - Baca token postfix satu per satu
      - Skip whitespace
      - Jika token operand (angka) → push ke stack
      - Jika token operator → pop 2 operand (b, a), hitung a op b, lalu push hasilnya kembali ke stack
      - Setelah semua token selesai, elemen terakhir di stack adalah hasil akhir}
   {Contoh:
      postfix="3 4 +" → result=7 ✅
      postfix="9 9 *" → result=81 ❌ (akan overflow karena 81+'0' > 127)} */
float evaluatePostfix(char *postfix)
{
    Tstack S;
    createStack(&S);
    int i = 0;
    char ch, op1, op2;
    float a, b, result;

    while ((ch = postfix[i]) != '\0')
    {
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            i++;
            continue;
        }

        if (ch >= '0' && ch <= '9')
        {
            push(&S, ch);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (isEmptyStack(S))
            {
                return 0.0f;
            }
            pop(&S, &op2);

            if (isEmptyStack(S))
            {
                return 0.0f;
            }
            pop(&S, &op1);

            a = op1 - '0';
            b = op2 - '0';

            switch (ch)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0.0f)
                {
                    return 0.0f;
                }
                result = a / b;
                break;
            }

            if (result >= 0 && result <= 9)
            {
                push(&S, (char)(result + '0'));
            }
            else
            {
                push(&S, '?');
            }
        }

        i++;
    }

    if (!isEmptyStack(S))
    {
        pop(&S, &op1);

        if (op1 == '?')
        {
            return -1.0f;
        }

        return op1 - '0';
    }
    else
    {
        return 0.0f;
    }
}
