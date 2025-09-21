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
/*function isEmptyStack( T: Tstack) -> boolean
    {mengembalikan True jika T kosong } */
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

/* procedure addCommand (input/output Undo:Stack, Redo:Stack, input Cmd:string)
   {I.S.: Undo & Redo terdefinisi, Cmd terdefinisi}
   {F.S.: Cmd masuk ke Undo (push), Redo dikosongkan}
   {Proses: push Cmd ke Undo, initStack(Redo)}
   {Contoh: Undo=['open'], Cmd="save" → Undo=['open','save'], Redo=[]} */
void addCommand(Tstack *Undo, Tstack *Redo, char Cmd)
{
    push(Undo, Cmd);
    createStack(Redo);
}

/* procedure undoCommand (input/output Undo:Stack, Redo:Stack, output Cmd:string)
   {I.S.: Undo tidak kosong, Redo terdefinisi}
   {F.S.: elemen top Undo dipindah ke Redo, Cmd berisi elemen tersebut}
   {Proses: pop dari Undo → push ke Redo}
   {Contoh: Undo=['a','b','c'], Redo=[] → Undo=['a','b'], Redo=['c']} */
void undoCommand(Tstack *Undo, Tstack *Redo, char *Cmd)
{
    if (!isEmptyStack(*Undo))
    {
        pop(Undo, Cmd);
        if (*Cmd != '#')
        {
            push(Redo, *Cmd);
        }
    }
}

/* procedure redoCommand (input/output Undo:Stack, Redo:Stack, output Cmd:string)
   {I.S.: Redo tidak kosong, Undo terdefinisi}
   {F.S.: elemen top Redo dipindah ke Undo, Cmd berisi elemen tersebut}
   {Proses: pop dari Redo → push ke Undo}
   {Contoh: Undo=['a','b'], Redo=['c'] → Undo=['a','b','c'], Redo=[]} */
void redoCommand(Tstack *Undo, Tstack *Redo, char *Cmd)
{
    if (!isEmptyStack(*Redo))
    {
        pop(Redo, Cmd);
        if (*Cmd != '#')
        {
            push(Undo, *Cmd);
        }
    }
}

/* procedure tampilkanStack (input Undo:Stack, Redo:Stack)
   {I.S.: Undo dan Redo terdefinisi}
   {F.S.: kondisi stack Undo & Redo ditampilkan ke layar}
   {Proses: memanggil printStack untuk masing-masing stack}
   {Contoh: Undo=['a','b'], Redo=['c'] → tampil di layar:
            Isi Undo: [a | b]
            Isi Redo: [c] } */
void tampilkanStack(Tstack Undo, Tstack Redo)
{
    printStack(Undo);
    printStack(Redo);
}