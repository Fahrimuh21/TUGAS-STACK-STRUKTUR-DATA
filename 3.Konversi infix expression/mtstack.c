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
	printf("=== TESTING STACK OPERATIONS FOR INFIX TO POSTFIX ===\n\n");

	// Test basic stack operations
	printf("1. TESTING BASIC STACK OPERATIONS:\n");
	createStack(&A);
	printf("   Stack created. IsEmpty: %s\n", isEmptyStack(A) ? "True" : "False");

	push(&A, 'A');
	push(&A, 'B');
	push(&A, '+');
	printf("   After pushing A, B, +:\n");
	printf("   Stack contents: ");
	viewStack(A);
	printf("   Top element: %c\n", infotop(A));
	printf("   IsEmpty: %s, IsFull: %s\n",
		   isEmptyStack(A) ? "True" : "False",
		   isFullStack(A) ? "True" : "False");

	char popped;
	pop(&A, &popped);
	printf("   After popping: %c\n", popped);
	printf("   Stack contents: ");
	viewStack(A);
	printf("\n");

	// Test precedence function
	printf("2. TESTING PRECEDENCE FUNCTION:\n");
	printf("   precedence('*') = %d\n", precedence('*'));
	printf("   precedence('/') = %d\n", precedence('/'));
	printf("   precedence('+') = %d\n", precedence('+'));
	printf("   precedence('-') = %d\n", precedence('-'));
	printf("   precedence('(') = %d\n", precedence('('));
	printf("\n");

	// Test infix to postfix conversion
	printf("3. TESTING INFIX TO POSTFIX CONVERSION:\n");

	printf("   Test 1:\n");
	printf("   Infix:    %s\n", infix1);
	result = infixToPostfix(infix1);
	printf("   Postfix:  %s\n", result);
	printf("   Expected: 3 4 3 * 4 / +\n\n");

	printf("   Test 2:\n");
	printf("   Infix:    %s\n", infix2);
	result = infixToPostfix(infix2);
	printf("   Postfix:  %s\n", result);
	printf("   Expected: 3 4 5 + * 2 /\n\n");

	printf("   Test 3:\n");
	printf("   Infix:    %s\n", infix3);
	result = infixToPostfix(infix3);
	printf("   Postfix:  %s\n", result);
	printf("   Expected: 3 4 5 * + 2 -\n\n");

	printf("=== ALL TESTS COMPLETED ===\n");

	return 0;
}