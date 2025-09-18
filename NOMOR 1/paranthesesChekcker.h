#define tabel_H 
#include <stdio.h>
#include "boolean.h"

/* type Stack = < wadah : array[1..10] of character,
                  top : integer >
   Stack berisi elemen karakter berupa huruf abjad kapital.
   Asumsi: indeks 0 tidak digunakan */
typedef struct {
    char wadah[10];
    int top;
} Stack;

// *********************** KONSTRUKTOR ***********************
/* procedure createStack (output T:Stack) 
   {I.S.: -}
   {F.S.: stack kosong, top = 0} */
void createStack(Stack *T);

// *********************** SELEKTOR ***********************
/* function getSize (T:Stack) -> integer 
   {mengembalikan banyak elemen dalam stack} */
int getSize(Stack T);

// *********************** PREDIKAT ***********************
/* function isEmptyStack (T:Stack) -> boolean 
   {mengembalikan true jika stack kosong} */
boolean isEmptyStack(Stack T);

/* function isFullStack (T:Stack) -> boolean 
   {mengembalikan true jika stack penuh} */
boolean isFullStack(Stack T);

// *********************** OPERASI PENCARIAN ***********************
/* procedure searchX (input T:Stack, input x:char, output pos:integer) 
   {I.S.: T terdefinisi, x terdefinisi}
   {F.S.: pos berisi posisi x atau -999 jika tidak ketemu} */
void searchX(Stack T, char x, int *pos);

/* function countX (T:Stack, x:char) -> integer 
   {mengembalikan banyaknya elemen bernilai x} */
int countX(Stack T, char x);

// *********************** AKSESOR ***********************
/* function infoTop (T:Stack) -> char 
   {mengembalikan elemen paling atas stack} */
char infoTop(Stack T);

/* function top (T:Stack) -> integer 
   {mengembalikan indeks elemen paling atas} */
int top(Stack T);

// *********************** MUTATOR ***********************
/* procedure push (input/output T:Stack, input e:char) 
   {I.S.: T terdefinisi, mungkin kosong/penuh}
   {F.S.: e ditambahkan ke stack jika belum penuh} */
void push(Stack *T, char *e);

/* procedure pop (input/output T:Stack, output e:char) 
   {I.S.: T terdefinisi, mungkin kosong}
   {F.S.: e berisi elemen teratas, stack berkurang satu elemen} */
void pop(Stack *T, char *e);

// *********************** OPERASI BACA/TULIS ***********************
/* procedure printStack (T:Stack) 
   {I.S.: T terdefinisi}
   {F.S.: isi stack ditampilkan ke layar} */
void printStack(Stack T);
