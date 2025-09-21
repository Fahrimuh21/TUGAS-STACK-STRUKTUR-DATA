/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

/* type Tstack = < wadah : array[1..10] of character,
                   top   : integer > */
typedef	struct { char wadah[11];
                 int  top; 
			   } Tstack;
/*karakter kosong dilambangkan dengan '#'  */
				 
/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T)
{	/* kamus lokal */
    int i;
    /* algoritma */
    T->top = 0;
    for (i=1; i<=10; i++) {
        T->wadah[i] = '#';
    }
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top
/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    return (T.top == 0);
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    return (T.top == 10);
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E) {
    if (!isFullStack(*T)) {
        T->top++;
        T->wadah[T->top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X)   {
    if (!isEmptyStack(*T)) {
        *X = T->wadah[T->top];
        T->wadah[T->top] = '#';
        T->top--;
    } else {
        *X = '#';
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    int i;
    for (i=1; i<=10; i++) {
        printf("%c", T.wadah[i]);
        if (i<10) {
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
void viewStack (Tstack T){
    int i;
    for (i=1; i<=T.top; i++) {
        printf("%c", T.wadah[i]);
        if (i<T.top) {
            printf(";");
        }
    }
    printf("\n");
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    char E;
    int i;
    for (i=1; i<=N; i++) {
        if (!isFullStack(*T)) {
            scanf(" %c", &E);
            push(T, E);
        } else {
            break;
        }
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    if (isFullStack(*T)) {
        createStack(T);
    } else {
        push(T, E);
    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E){
    if (!isEmptyStack(*T) && infotop(*T) == E) {
        char X;
        pop(T, &X);
    } else {
        push(T, E);
    }
}

/* function evaluatePostfix(postfix:string) → float
   {I.S.: postfix terdefinisi, berisi operand (0–9) dan operator (+,-,*,/)}
   {F.S.: Menghasilkan nilai hasil evaluasi ekspresi postfix}
   {Proses:
      - Baca token postfix satu per satu
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
float evaluatePostfix(char *postfix){
    Tstack S;
    createStack(&S);
    int i = 0;
    char ch, op1, op2;
    float a, b, result;

    while ((ch = postfix[i]) != '\0') {
        if (ch >= '0' && ch <= '9') {
            push(&S, ch);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            pop(&S, &op2);
            pop(&S, &op1);
            a = op1 - '0';
            b = op2 - '0';
            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            push(&S, (char)(result + '0'));
        }
        i++;
    }
    pop(&S, &op1);
    return op1 - '0';
}


