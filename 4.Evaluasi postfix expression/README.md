# Tugas Struktur Data - Aplikasi Stack

## 1. Parentheses Checker
**Fungsi:**  
```c
function isValidKurung(kata: string) -> boolean
kata adalah string yang di dalamnya dapat berisi tanda kurung (), {}, ataupun [].
Fungsi ini mengecek apakah pasangan kurung buka dan kurung tutup di dalam kata sesuai.

Return true jika sesuai

Return false jika tidak sesuai

Contoh:

{[(A+B) * (C+D)] – (7*D)} → true

{[(A+B) * (C+D)] – (7*D) → false

{[(A+B) * (C+D]) – (7*D)} → false

{[(A+B) * (C+D)] – (7*D))} → false

Hint:

Jika menemui tanda kurung buka, push ke dalam stack.

Jika menemui karakter selain tanda kurung, lewati.

Jika menemui tanda kurung tutup, lakukan pop lalu bandingkan. Jika tidak cocok, return false.

Jika stack kosong setelah semua karakter dibaca, maka return true.

2. Undo – Redo pada Aplikasi Text Editor
Buat main program menggunakan ADT Stack.
Gunakan dua buah stack:

Stack Undo → menyimpan perintah yang diberikan

Stack Redo → menyimpan perintah yang dibatalkan (undo)

Asumsi: perintah diberikan dalam bentuk string.

Hint:

Jika ada perintah baru → push ke stack Undo, kosongkan stack Redo.

Jika dilakukan undo → pop dari stack Undo, lalu push ke stack Redo.

Jika dilakukan redo → pop dari stack Redo, lalu push kembali ke stack Undo.

3. Konversi Infix ke Postfix
Buat fungsi untuk mengubah infix expression (operator di tengah) menjadi postfix expression (operator di akhir).

Contoh:

Infix Expression	Postfix Expression
3 + ( 4 * 3 ) / 4	3 4 3 * 4 / +
3 * ( 4 + 5 ) / 2	3 4 5 + * 2 /
3 + ( 4 * 5 ) – 2	3 4 5 * + 2 -

Asumsi:

Operand hanya satu digit (0–9)

Ekspresi valid

Tidak ada pembagian dengan 0

Prioritas Operator:

* dan / lebih tinggi dari + dan -

Semua operator left-associative

Hint:

Gunakan stack untuk menampung operator dan tanda kurung buka.

Jika token berupa operand (0–9), tambahkan ke output postfix.

Jika token berupa operator:

pop selama precedence operator di stack ≥ precedence operator saat ini

push operator baru ke stack

Jika token "(" → push ke stack

Jika token ")" → pop semua operator sampai ketemu "("

4. Evaluasi Postfix Expression
Buat fungsi untuk mengevaluasi string postfix expression → menghasilkan bilangan real.

Contoh:

Input: 9 3 4 * 8 + 4 / -

Output: 4

Pengumpulan
Dokumen .pdf berisi:

Notasi algoritmik

Screenshot implementasi program (C)

Screenshot hasil run program

File program dalam Bahasa C

Catatan:
Tugas akan dipresentasikan pada kuliah pertemuan ke-5.