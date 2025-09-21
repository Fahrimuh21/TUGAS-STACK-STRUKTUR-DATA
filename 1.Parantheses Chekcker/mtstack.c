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
#include "boolean.h"

/* include tstack+boolean */

int main() 
{	/* kamus main */
	char prefix[100];
	printf("masukan ekspresi: ");
	scanf("%s \n", &prefix);
	/* algoritma */
	 if (isValidKurung(prefix)) {
        printf("Ekspresi VALID (kurung seimbang)\n");
    } else {
        printf("Ekspresi TIDAK VALID (kurung tidak seimbang)\n");
    }


	
	return 0;
}
