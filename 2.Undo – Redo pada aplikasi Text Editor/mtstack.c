/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
/* include tstack+boolean */

int main() {
    Tstack Undo, Redo ;
    int pilihan;
    char Cmd ;

    createStack(&Undo);
    createStack(&Redo);

    do {
        printf("\nMenu:\n");
        printf("1. Input perintah baru\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Tampilkan isi stack\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

    if (pilihan == 1) {
            printf("Masukkan perintah: ");
            scanf(" %c", &Cmd); 
            addCommand(&Undo, &Redo, Cmd);
        } 
        else if (pilihan == 2) {
            undoCommand(&Undo, &Redo, &Cmd);
            if (Cmd != '\0') { 
                printf("Undo: %c\n", Cmd);
            } else {
                printf("Tidak ada yang bisa di-undo!\n");
            }
        } 
        else if (pilihan == 3) {
            redoCommand(&Undo, &Redo, &Cmd);
            if (Cmd != '\0') {
                printf("Redo: %c\n", Cmd);
            } else {
                printf("Tidak ada yang bisa di-redo!\n");
            }
        } 
        else if (pilihan == 4) {
            tampilkanStack(Undo, Redo);
        } 
        else if (pilihan == 0) {
            printf("Program selesai.\n");
        } 
        else {
            printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);

    return 0;
}
