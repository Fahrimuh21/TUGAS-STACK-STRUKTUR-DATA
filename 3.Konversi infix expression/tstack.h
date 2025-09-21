#ifndef tstack_H
#define tstack_H

/* Program   : tstack.h */
/* Deskripsi : file HEADER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include "boolean.h"

/* type Tstack = < wadah : array[1..10] of character,
				   top   : integer > */
typedef struct
{
	char wadah[11];
	int top;
} Tstack;
/*karakter kosong dilambangkan dengan '#'  */

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack(Tstack *T);

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
// int top (Tstack T);
// dalam praktikum ini, fungsi dapat direalisasikan
// menjadi macro dalam bahasa C.
int top(Tstack T);

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
// char infotop (Tstack T);
char infotop(Tstack T);

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T);

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T);

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E);

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop(Tstack *T, char *X);

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar}
	{setiap elemen dipisah tanda titik koma } */
void printStack(Tstack T);

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}
	{setiap elemen dipisah tanda titik koma } */
void viewStack(Tstack T);

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN(Tstack *T, int N);

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1(Tstack *T, char E);

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
	{contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma(Tstack *T, char E);

/* function precedence(op:char) → integer
   {Mengembalikan tingkat prioritas operator}
   {Prioritas: * / = 2, + - = 1, lainnya = 0}
   {Contoh: op='*' → return 2} */
int precedence(char op);

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
char *infixToPostfix(char *infix);

#endif
