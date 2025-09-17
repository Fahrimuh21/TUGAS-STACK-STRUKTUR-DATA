#include <stdio.h>
#include "tabel.h"
//Deskripsi : driver ADT tabel integer//
/* NIM/Nama : 24060124120037*/
/* Tanggal : 11 september 2025*/

int main() {
	 //kamus
    Tabel T, T2;
    int pos;

    //algoritma

    // KONSTRUKTOR
    createTable(&T);
	createTable(&T2);
    printf("Membuat Tabel");
    printTable(T); 
	printf("\n");
	printf("size = %d\n", getSize(T));

    // SELEKTOR/PREDIKAT
    printf("apakah tabel kosong? \n");
	if (isEmptyTable(T)) printf("ya \n");
	else printf("tidak \n");
    printf("apakah tabel penuh? ");
	if (isFullTable(T)) printf("ya \n");
	else printf("tidak \n");

    // MUTATOR addXTable
    addXTable(&T, 'A');
    addXTable(&T, 'B');
    addXTable(&T, 'C');
    printf("Tabel setelah ditambah A, B, C : ");
    viewTable(T); 
	printf("\n");

    // MUTATOR addUniqueXTable
    addUniqueXTable(&T, 'C'); 
    addUniqueXTable(&T, 'D'); 
    printf("Setelah menambahkan elemen unik C, D : ");
    viewTable(T);
	printf("\n");

    // OPERASI PENCARIAN
    searchX(T, 'B', &pos);
    if(pos != -999) printf("pencarian B ditemukan di index ke %d\n", pos);
    else printf("pencarian B tidak ditemukan \n");

    printf("menghitung banyak elemen  'A' : %d\n", countX(T, 'A'));
    printf("menghitung banyak elemen vocal : %d\n", countVocal(T));

    // OPERASI PENGHAPUSAN
    delXTable(&T, 'B');
    printf("Tabel setelah B dihapus : ");
    viewTable(T); 
	printf("\n");

    delTable(&T, 2);
    printf("setelah hapus elemen tabel di index ke 2 : ");
    viewTable(T); 
	printf("\n");

    addXTable(&T, 'A');
    addXTable(&T, 'A');
    addXTable(&T, 'E');
    addXTable(&T, 'I');
    printf("setelah tabel di tambah A, A, E, I : ");
    viewTable(T); 
	printf("\n");

    delAllXTable(&T, 'A');
    printf("tabel setelah A dihapus semua : ");
    viewTable(T);
	 printf("\n");

    // BACA/TULIS
    printf("printTable : ");
    printTable(T); 
	printf("\n");

    printf("viewTable : ");
    viewTable(T);
	printf("\n");

    createTable(&T2);
    printf("silahkan isi 3 char untuk populateTable : ");
    populateTable(&T2, 3);
    printf("Hasil populateTable : ");
    viewTable(T2); 
	printf("\n");

    // STATISTIK
    printf("modus dari T2 : %c \n", Modus(T2));


    // RELASIONAL
    printf("apakah tabel T2 dan T2 equal : ");
	if(isEqualTable(T2, T2)) printf("true \n");
	else printf("false \n");
    printf("apakah tabel T dan T2 equal : ");
	if(isEqualTable(T, T2)) printf("true \n");
	else printf("false \n");


    inverseTable(&T2);
    printf("inverseTable(T2) : ");
    viewTable(T2); 
	printf("\n");

    // PENGURUTAN
    addXTable(&T2, 'M');
    addXTable(&T2, 'A');
    addXTable(&T2, 'Z');
    printf("Sebelum sortAsc : ");
    viewTable(T2); 
	printf("\n");

    sortAsc(&T2);
    printf("Setelah sortAsc : ");
    viewTable(T2); 
	printf("\n");

    sortDesc(&T2);
    printf("Setelah sortDesc : ");
    viewTable(T2);
	printf("\n");
    return 0;

	

}