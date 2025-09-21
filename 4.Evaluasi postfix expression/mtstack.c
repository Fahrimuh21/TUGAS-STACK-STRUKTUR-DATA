/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 
Muhammad Akmal Fazli Riyadi 24060124130123
Muhammad Fikri 24060124130069
Khanza Qaila 24060124120011
Nayla Husna 24060124140158
Muhammad Fahri 24060124120037*/
/* Tanggal   : 21 September 2025 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
/* include tstack+boolean */

int main() 
{	char expr[100];

    printf("Masukkan ekspresi postfix (pisahkan dengan spasi):\n");
    scanf("%s", expr);  
    float hasil = evaluatePostfix(expr);
    printf("Hasil evaluasi = %.2f\n", hasil);

    return 0;
}
