/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
/* include tstack+boolean */

int main() 
{	char expr[100];

    printf("Masukkan ekspresi postfix (pisahkan dengan spasi):\n");
    scanf("%s", expr);   // baca input sampai ketemu newline (tanpa fgets)

    float hasil = evaluatePostfix(expr);
    printf("Hasil evaluasi = %.2f\n", hasil);

    return 0;
}
