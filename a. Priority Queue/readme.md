# <h1 align="center">Priority Queue</h1>
<p align="center">Nama: Olivia Intan Puspita</p>
<p align="center">NIM: 2311110006</p>
<p align="center">Kelas: S1SD-04-A</p>

## Penjelasan Priority Queue

Tipe data yang mirip seperti struktur data queue, tetapi setiap elemen memiliki prioritas yang telah ditetapkan disebut dengan priority queue [1]. Kompleksitas waktu dari struktur data priority queue yaitu 0(1) pada proses insert dan 0(log n) pada proses delete [2]. Berdasarkan aturan elemennya, priority queue memproses elemen dengan prioritas yang lebih tinggi dahulu daripada dengan elemen yang prioritasnya lebih rendah. Sedangkan dua elemen dengan prioritas yang sama diproses sesuai dengan urutan mereka sewaktu dimasukkan ke dalam priority queue [3].

Priority queue dapat diimplementasikan menggunakan struktur data Array, Linked List, Heap data structure, dan Binary search tree.

Struktur data yang merupakan implementasi dari priority queue yang memenuhi kriteria heap disebut dengan heap. Terdapat dua jenis heap, yaitu max heap dan min heap. Nilai parent selalu lebih besar dari nilai anak disebut dengan max heap, sedangkan nilai parent selalu lebih kecil dari nilai anak disebut dengan min heap. Selain untuk mengimplementasikan priority queue, heap juga dapat digunakan untuk melakukan sorting [4].

![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/0fcd1b18-7eae-49fa-9204-181ea71e152b)

Gambar di atas adalah contoh implementasi priority queue dalam heap.

Terdapat beberapa operasi dalam heap, yaitu ```insert``` untuk menyisipkan elemen baru, ```ekstrakMax``` untuk mengekstrak elemen dengan prioritas maksimum, ```remove``` untuk menghapus elemen, ```getMax``` untuk mengembalikan elemen dengan prioritas maksimum, dan ```changePriority``` untuk mengubah prioritas elemen.

## Contoh Program

```C++
#include <iostream>
#include <algorithm>

int H[25];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i =parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize -1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(15);
    insert(20);
    insert(11);
    insert(9);
    insert(23);
    insert(8);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " " ;
    }
    std::cout << "\n";

    std:: cout << "Node with maximum priority :" << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0;i <= heapSize; ++ i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 17);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```

## Penjelasan Alur Program
Program di atas merupakan implementasi sebuah Priority Queue dan Heap yang menggunakan array. Pada program di atas heap yang digunakan adalah Max-Heap.

Untuk yang pertama dapat kita ketahui bahwa program di atas menggunakan Array ```H[25]``` yang berarti ukuran maksimal elemen heap adalah 25. Kemudian terdapat variabel ```heapSize``` yang digunakan untuk menyimpan jumlah elemen dalam heap. -1 pada variabel ini digunakan untuk menunjukkan heap kosong.

Selanjutnya terdapat beberapa fungsi pada program di atas. Untuk yang pertama adalah fungsi yang digunakan untuk mengetahui indeks orang tua dan anak. ```int parent(int i)``` untuk mengembalikan indeks orang tua dari elemen pada indeks i, ```int leftChild(int i)``` untuk mengembalikan indeks anak kiri, dan ```int rightChild(int i)``` untuk mengembalikan indeks anak kanan. Lalu yang kedua adalah fungsi yang digunakan untuk memperbaiki heap. ```void shiftUp(int i)``` untuk mengembalikan elemen pada indeks i ke atas hingga property heap terpenuhi (yaitu orang tua selalu lebih besar dari anak), dan ```void shiftDown(int i)``` digunakan untuk menurunkan elemen. Kemudian yang ketiga ada fungsi yang digunakan untuk mengelola heap. ```void insert(int p)``` untuk menambahkan elemen p ke dalam heap, ```int extractMax()``` untuk mengambil dan menghapus elemen terbesar dari heap, ```void changePriority(int i, int p)``` untuk mengubah prioritas elemen pada indeks i ke nilai p dan menyesuaikan posisi elemen tersebut, ```int getMax()``` untuk mengembalikan elemen terbesar di heap tanpa menghapusnya, dan ```void remove(int i)``` untuk menghapus elemen dari heap. Cara kerjanya elemen yang akan dihapus akan dengan dijadikan elemen terbesar terlebih dahulu, lalu setelah menjadi nilai maks maka akan dilakukan ekstrak maks atau pengambilan nilai maksimum, dan setelah itu elemen yang dipilih tadi berhasil dihapus. Lalu yang keempat dan terakhir yaitu fungsi ```main()```. Dari fungsi main dapat kita lihat fungsi utama program di atas. Pada program di atas kita menambahkan elemen ke dalam heap, setelah itu mencetak heap, mengambil elemen terbesar, mencetak heap kembali, kemudian mengubah prioritas, dan terakhir menghapus elemen.

## Contoh Output
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/b898847c-2387-44a2-b015-6da306be7108)

Output yang keluar pada gambar di atas sesuai dengan perintah yang kita buat pada fungsi main. Dimana dapat kita ketahui bahwa:

1. Output pertama

```Priority Queue : 23 20 11 9 15 8```

Ini kita dapat dari memasukkan elemen ke dalam heap dengan urutan 15, 20, 11, 9, 23, 8, di mana setiap elemen induk lebih besar atau sama dengan elemen anak-anaknya.

2. Output kedua

```Node with maximum priority :23```

Disini elemen terbesar (23) diambil.

3. Output ketiga

```Priority queue after extracting maximum : 20 15 11 9 8```

Setelah 23 diambil, heap disusun kembali. Kemudian elemen terakhir (8) dipindahkan ke posisi root dan kemudian dilakukan ```shiftDown``` untuk mempertahankan properti heap.

4. Output keempat

```Priority queue after priority change: 20 15 17 9 8```

Disini kita melakukan perubahan pada indeks ke-2 yaitu 11 yang diubah menjadi 17. 

5. Output kelima

```Priority queue after removing the element: 20 15 17 8```

Disini dilakukan penghapusan pada indeks ke-3 yaitu 9 dengan cara mengganti denga nilai yang lebih besar dari nilai terbesar, baru setelah itu elemen dihapus.

## Referensi
[1] I. Sholeh, Penerapan Decrease and Conquer untuk Manajemen Tugas Kuliah Informatika, Jurnal Teknik Informatika dan Sistem Informasi, vol. 1, no. 2, pp. 4, Desember 2021.

[2] I.G.N.L. Wijayakusuma, S.C. Yowani, Penanggulangan Kasus DPT Ganda dengan Menggunakan Algoritma Quiksort dan Priority Queue, Jurnal Matematika, vol. 9, no. 2, pp. 102, Desember 2019.

[3] J.A.Aryadi, dkk., Implementasi Algoritma Queue untuk Menentukan Prioritas Pelayanan Umum di Rumah Sakit", Jurnal Informatika dan Komputer, vol. 7, no.2, hal. 219, September 2023.

[4] K. Prayogo, Algoritma dan Struktur Data menggunakan Golang, Bonus: Intro Pemrograman Web. Indonesia: Kiswono Prayogo, 2014.

