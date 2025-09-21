/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
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
