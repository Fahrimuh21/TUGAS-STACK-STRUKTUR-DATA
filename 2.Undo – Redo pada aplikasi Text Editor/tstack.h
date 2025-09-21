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

/* procedure addCommand (input/output Undo:Stack, Redo:Stack, input Cmd:string)
   {I.S.: Undo & Redo terdefinisi, Cmd terdefinisi}
   {F.S.: Cmd masuk ke Undo (push), Redo dikosongkan}
   {Proses: push Cmd ke Undo, initStack(Redo)}
   {Contoh: Undo=['open'], Cmd="save" → Undo=['open','save'], Redo=[]} */
void addCommand (Tstack *Undo, Tstack *Redo, char Cmd);

/* procedure undoCommand (input/output Undo:Stack, Redo:Stack, output Cmd:string)
   {I.S.: Undo tidak kosong, Redo terdefinisi}
   {F.S.: elemen top Undo dipindah ke Redo, Cmd berisi elemen tersebut}
   {Proses: pop dari Undo → push ke Redo}
   {Contoh: Undo=['a','b','c'], Redo=[] → Undo=['a','b'], Redo=['c']} */
void undoCommand (Tstack *Undo, Tstack *Redo, char *Cmd);

/* procedure redoCommand (input/output Undo:Stack, Redo:Stack, output Cmd:string)
   {I.S.: Redo tidak kosong, Undo terdefinisi}
   {F.S.: elemen top Redo dipindah ke Undo, Cmd berisi elemen tersebut}
   {Proses: pop dari Redo → push ke Undo}
   {Contoh: Undo=['a','b'], Redo=['c'] → Undo=['a','b','c'], Redo=[]} */
void redoCommand (Tstack *Undo, Tstack *Redo, char *Cmd);

/* procedure tampilkanStack (input Undo:Stack, Redo:Stack)
   {I.S.: Undo & Redo terdefinisi}
   {F.S.: -}
   {Proses: menampilkan isi kedua stack ke layar}*/
void tampilkanStack (Tstack Undo, Tstack Redo);
#endif
