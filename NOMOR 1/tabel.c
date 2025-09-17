#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/* Deskripsi : header file modul tabel*/
/* NIM/Nama :  24060124120037/Muhammad Fahri*/
/* Tanggal : 11 September 2025*/


/*KONSTRUKTOR/				 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T){
    //kamus lokal 
    int i;

    //algoritma 
    T->size = 0;
    for (i = 1; i < 11; i++){
        T->wadah[i] = ' ';
    }
}

/*SELEKTOR/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T){
   return T.size;
}

/*PREDIKAT*/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T){
    return getSize(T)==0;
}

/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T){
    return getSize(T)==10;
}

/*OPERASI PENCARIAN*/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos){
    //kamus lokal
    int i;

    //algoritma 
    // for(i=1; i<getSize(T)+1; i++){
    //     if(T.wadah[i]==x){
    //         *pos = i;
    //     }else if(i==getSize(T)){
    //         *pos = -999;
    //     }

    // }
    i=1;
    while(i==getSize(T) || T.wadah[i]==x){
        i++;
    }
    if (i==getSize(T)) *pos = -999;
    else *pos =i;
}

/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x){
    //kamus lokal
    int i, count=0;

    //algoritma 
    for(i=1; i<getSize(T); i++){
        if(T.wadah[i]==x){
            count++;
        }
    }
    return count;
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T){
    //kamus lokal
    int i, count=0;;

    //algoritma
    for(i=1; i<getSize(T); i++){
        if(T.wadah[i]=='A' || T.wadah[i]=='I' || T.wadah[i]=='U' || T.wadah[i]=='E' || T.wadah[i]=='O'){
            count++;
        }
    }
    return count;
}

/*MUTATOR*/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x){
    if(!isFullTable(*T)){
        T->wadah[T->size+1]=x;
        T->size++;
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x){
    //kamus lokal
    int pos;
    searchX(*T, x, &pos);

    //algoritma
    if(pos==-999 && !isFullTable(*T)){
        T->wadah[T->size+1]=x;
    }
}

/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x){
    //kamus lokal
    int i, pos;
    searchX(*T, x, &pos);

    //algoritma
    if(!(pos==-999) && !isEmptyTable(*T)){
        for(i =pos; i<=getSize(*T); i++){
            T->wadah[i]=T->wadah[i+1];
        }
        T->wadah[T->size]=' ';
        T->size--;
    }
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx){
    //kamus lokal 
    int i;

    //algoritma
    if(!isEmptyTable(*T)){
        for(i=idx; i<=getSize(*T); i++){
            T->wadah[i]=T->wadah[i+1];
        }
        T->wadah[T->size]=' ';
        T->size--;
    }
    
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x){
    //kamus lokal
    int pos;
    //algoritma
    while(!pos==-999){
        delXTable(&(*T), x);
        searchX(*T, x, &pos);
    }
     
}

/*OPERASI BACA/TULIS*/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T){
    //kamus lokal
    int i;

    //algoritma
    for(i=1; i<11; i++){
        printf("%c", T.wadah[i]);
    }
}

/* procedure viewTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T){
    //kamus lokal
    int i;

    //algoritma
    for(i=1; i<=getSize(T); i++){
        printf("%c", T.wadah[i]);
    }
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N){
    //kamus lokal 
    int i;

    //algoritma
    T->size=0;
    for(i=1; i<=N; i++){
        char x;
        scanf(" %c", &x);
        T->wadah[i]=x;
        T->size++;
    }
}

/*OPERASI STATISTIK*/
/*function Modus (T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus(Tabel T){
    //kamus lokal 
    int i, ukuran, maks=0;
    char answer;

    //algoritma
    for(i=1; i<=getSize(T); i++){
        ukuran = countX(T, T.wadah[i]);
        if(ukuran> maks){
            maks=ukuran;
            answer=T.wadah[i];
        }
    }
    return answer;
}

/*OPERASI RELASIONAL*/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean 
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2){
    //kamus lokal 
    int i, count=0;

    //algoritma
    if(getSize(T1) != getSize(T2)){
        return false;
    }
    else {
        for(i=1; i<=getSize(T1); i++){
            if(T1.wadah[i]==T2.wadah[i]){
                count++;
            }
        }
        if(count==getSize(T1)) return true;
        else return false;
        
    }
}

/*OPERASI LAINNYA*/
/* function getInverseTable(T:Tabel) -> Tabel 
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T){
    //kamus lokal 
    Tabel T1;
    int i;

    //algoritma
    T1=T;
    for(i=1; i<=getSize(T); i++){
        T.wadah[i]=T1.wadah[getSize(T1)+1-i];
    }
    return T;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T){

    //KAMUS LOKAL
    Tabel T1;
    int i;


    //algoritma
    T1=*T;
    for(i=1; i<=getSize(*T); i++){
        (*T).wadah[i]=T1.wadah[getSize(T1)+1-i];
    }
}


/*OPERASI PENGURUTAN*/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T){
    //kamus lokal
    char temp ;
    int i, j;
    //algoritma
     for(i=1; i<=getSize(*T); i++) {
        for(j=1; j<=getSize(*T)-1; j++) {
            if(T->wadah[j]>T->wadah[j+1]) {
                // tukar elemen
                temp = T->wadah[j];
                T->wadah[j] = T->wadah[j+1];
                T->wadah[j+1] = temp;
            }
        }
    }
}

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T){
    //kamus lokal
    char temp ;
    int i, j;
    //algoritma
     for(i=1; i<=getSize(*T)+1; i++) {
        for(j=1; j<=getSize(*T); j++) {
            if(T->wadah[j]<T->wadah[j+1]) {
                // tukar elemen
                temp = T->wadah[j];
                T->wadah[j] = T->wadah[j+1];
                T->wadah[j+1] = temp;
            }
        }
    }

}
#endif