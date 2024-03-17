# Tugas2-SDA

cara menjalankan program sebagai berikut: </br>
Untuk mengkompilasi program ini,kita mmenggunakan kompiler C dan dapat menjalankan perintah berikut di terminal
gcc -o 2208107010066-Simple_Sorting 2208107010066_Simple_Sorting.c
Setelah berhasil dikompilasi, kita dapat menjalankan program dengan mengetikkan nama file biner yang telah dibuat. seperti
./2208107010066_Simple_Sorting
Program akan mulai menjalankan pengujian dengan mengurutkan array dengan ukuran yang berbeda menggunakan tiga algoritma pengurutan yang berbeda.

Fungsi yang terdapat dalam kode program sebagai berikut
generateRandomIntegers(int *arr, int n): Fungsi ini digunakan untuk menghasilkan bilangan bulat acak dan menyimpannya dalam array arr. Fungsi ini menerima parameter array arr dan panjangnya n, kemudian mengisi array tersebut dengan bilangan bulat acak dari 0 hingga 999999.

bubbleSort(int *arr, int n): Fungsi ini menerapkan algoritma Bubble Sort untuk mengurutkan array arr yang diberikan dengan panjang n. Bubble Sort adalah algoritma pengurutan yang sederhana dan berulang kali membandingkan elemen-elemen berdekatan, menukar mereka jika mereka berada dalam urutan yang salah.

selectionSort(int *arr, int n): Fungsi ini menerapkan algoritma Selection Sort untuk mengurutkan array arr dengan panjang n. Selection Sort adalah algoritma pengurutan sederhana yang secara berulang mencari elemen terkecil dari array yang belum diurutkan dan menukarnya dengan elemen terkecil saat ini.

insertionSort(int *arr, int n): Fungsi ini menerapkan algoritma Insertion Sort untuk mengurutkan array arr dengan panjang n. Insertion Sort adalah algoritma pengurutan yang secara berulang memindahkan satu elemen pada saatnya dari bagian belum diurutkan dari array ke bagian yang sudah diurutkan pada posisi yang tepat.

saveToFile(int *arr, int n, char *filename): Fungsi ini digunakan untuk menyimpan array ke dalam sebuah file. Fungsi ini menerima array arr dengan panjang n dan nama file filename. Ini membuka file dengan nama yang diberikan untuk ditulis, kemudian menyimpan setiap elemen array sebagai baris dalam file tersebut.

main(): Fungsi utama program. Ini adalah tempat di mana eksekusi program dimulai. Di dalamnya, array dialokasikan, diisi dengan bilangan bulat acak, dan kemudian diurutkan menggunakan ketiga algoritma pengurutan yang ada. Waktu yang dibutuhkan untuk pengurutan dicatat, dan hasilnya ditampilkan di layar dan disimpan dalam bentuk file teks.
