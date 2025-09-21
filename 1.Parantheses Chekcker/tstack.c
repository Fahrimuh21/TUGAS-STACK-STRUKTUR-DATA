/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h" 

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack(Tstack *T)
{	/* kamus lokal */
    int i;
    /* algoritma */
    T->top = 0;
    for (i=1; i<=10; i++) {
        T->wadah[i] = '#';
    }
}

/*function isEmptyStack( T: Tstack) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T){
    return (T.top == 0);   
}          

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T){
    return (T.top == 10);
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E) {
    if (!isFullStack(*T)) {
        T->top++;
        T->wadah[T->top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop(Tstack *T, char *X)   {
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
void printStack(Tstack T){
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
void viewStack(Tstack T){
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
void pushN(Tstack *T, int N){
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
void pushBabel1(Tstack *T, char E){
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
void pushZuma(Tstack *T, char E){
    if (!isEmptyStack(*T) && infotop(*T) == E) {
        char X;
        pop(T, &X);
    } else {
        push(T, E);
    }
}

/* function isValidKurung(kata:string) → boolean
   {I.S.: kata terdefinisi}
   {F.S.: Mengembalikan true jika seluruh tanda kurung di kata sesuai pasangan}
   {Proses:
      - Jika kurung buka → push ke stack
      - Jika kurung tutup → pop dari stack lalu cek pasangannya
      - Jika tidak cocok → return false
      - Setelah semua karakter diproses, jika stack kosong → return true}
   {Contoh:
      kata = "{[(A+B)]}" → true
      kata = "{[(A+B)]"  → false } */
boolean isValidKurung(char *kata) {
    Tstack S;
    createStack(&S);
    char ch, topChar;
    int i = 0;
    while ((ch = kata[i]) != '\0') {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&S, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmptyStack(S)) {
                return false;
            }
            pop(&S, &topChar);
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
        i++;
    }
    return isEmptyStack(S);
}