/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter untuk konversi infix expression */
/* NIM/Nama  :
Muhammad Akmal Fazli Riyadi 24060124130123
Muhammad Fikri 24060124130069
Khanza Qaila 24060124120011
Nayla Husna 24060124140158
Muhammad Fahri 24060124120037*/
/* Tanggal   : 21 September 2025*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
/* include tstack+boolean */

int main()
{ /* kamus main */
	Tstack A;
	char infix1[] = "3+(4*3)/4";
	char infix2[] = "3*(4+5)/2";
	char infix3[] = "3+(4*5)-2";
	char *result;

	/* algoritma */
	printf("=== PENGUJIAN OPERASI STACK UNTUK KONVERSI INFIX KE POSTFIX ===\n\n");

	printf("1. PENGUJIAN OPERASI DASAR STACK:\n");
	createStack(&A);
	printf("   Stack dibuat. Kosong: %s\n", isEmptyStack(A) ? "Benar" : "Salah");

	push(&A, 'A');
	push(&A, 'B');
	push(&A, '+');
	printf("   Setelah push A, B, +:\n");
	printf("   Isi stack: ");
	viewStack(A);
	printf("   TOP: %c\n", infotop(A));
	printf("   Kosong: %s, Penuh: %s\n",
		   isEmptyStack(A) ? "Benar" : "Salah",
		   isFullStack(A) ? "Benar" : "Salah");

	char popped;
	pop(&A, &popped);
	printf("   Setelah pop: %c\n", popped);
	printf("   Isi stack: ");
	viewStack(A);
	printf("\n");

	// Uji fungsi precedence
	printf("2. PENGUJIAN FUNGSI PRECEDENCE:\n");
	printf("   precedence('*') = %d\n", precedence('*'));
	printf("   precedence('/') = %d\n", precedence('/'));
	printf("   precedence('+') = %d\n", precedence('+'));
	printf("   precedence('-') = %d\n", precedence('-'));
	printf("   precedence('(') = %d\n", precedence('('));
	printf("\n");

	// Uji konversi infix ke postfix
	printf("3. PENGUJIAN KONVERSI INFIX KE POSTFIX:\n");

	printf("   Uji 1:\n");
	printf("   Infix:    %s\n", infix1);
	result = infixToPostfix(infix1);
	printf("   Postfix:  %s\n", result);
	printf("   Harapan:  3 4 3 * 4 / +\n\n");

	printf("   Uji 2:\n");
	printf("   Infix:    %s\n", infix2);
	result = infixToPostfix(infix2);
	printf("   Postfix:  %s\n", result);
	printf("   Harapan:  3 4 5 + * 2 /\n\n");

	printf("   Uji 3:\n");
	printf("   Infix:    %s\n", infix3);
	result = infixToPostfix(infix3);
	printf("   Postfix:  %s\n", result);
	printf("   Harapan:  3 4 5 * + 2 -\n\n");

	printf("=== SEMUA PENGUJIAN SELESAI ===\n");

	return 0;
}