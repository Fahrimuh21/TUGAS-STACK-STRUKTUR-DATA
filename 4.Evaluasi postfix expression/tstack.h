#ifndef tstack_H
#define tstack_H 

/* Program   : tstack.h */
/* Deskripsi : file HEADER modul stack karakter */
/* NIM/Nama  : 
Muhammad Akmal Fazli Riyadi 24060124130123
Muhammad Fikri 24060124130069
Khanza Qaila 24060124120011
Nayla Husna 24060124140158
Muhammad Fahri 24060124120037*/
/* Tanggal   : 21 September 2025*/
/***********************************/

#include "boolean.h"

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
void createStack (Tstack *T);

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
boolean isEmptyStack (Tstack T);

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T);

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E);

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X);

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T);

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T);

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N);

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E);

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E);

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
float evaluatePostfix(char *postfix);

#endif
