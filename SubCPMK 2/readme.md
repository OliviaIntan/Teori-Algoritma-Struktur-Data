# <h1 align="center">CPMK 2 - SubCPMK 2</h1>
<p align="center">Olivia Intan Puspita</p>


## Soal

### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

- Bubble Sort

Bubble Sort adalah algoritma sorting sederhana yang berulang kali membandingkan setiap pasangan elemen yang bersebelahan dalam suatu array dan menukar elemen jika mereka berada dalam urutan yang salah. Algoritma ini akan terus berulang hingga tidak ada lagi pertukaran yang diperlukan.

Alur Algoritma:

1. Bandingkan dua elemen bersebelahan.
2. Jika elemen pertama lebih besar dari elemen kedua, tukar posisi mereka.
3. Ulangi langkah 1 dan 2 untuk setiap pasangan elemen dalam array.
4. Ulangi proses di atas sampai tidak ada lagi pertukaran yang dilakukan.

Runtime dari Best Case pada Bubble Sort adalah O(n), terjadi ketika array sudah terurut secara ascending, dan tidak ada pertukaran yang diperlukan. Sedangkan runtime dari Worst Case nya adalah O(n^2), terjadi ketika array terurut secara descending, sehingga setiap elemen harus ditukar dengan setiap elemen lainnya.

- Selection Sort

Selection Sort adalah algoritma sorting sederhana yang membagi array menjadi dua bagian, bagian yang sudah diurutkan dan bagian yang belum diurutkan. Algoritma ini mencari elemen terkecil dari bagian yang belum diurutkan dan memindahkannya ke bagian yang sudah diurutkan.

Alur Algoritma:

1. Temukan elemen terkecil dalam array.
2. Tukar elemen terkecil dengan elemen pertama dalam array (jika belum berada di posisi pertama).
3. Tandai elemen pertama sebagai bagian yang sudah diurutkan.
4. Ulangi proses untuk sisa array, yaitu bagian yang belum diurutkan.

Runtime dari Best Case Selection Sort adalah O(n^2), terjadi ketika setiap elemen harus ditukar dengan elemen lainnya. Sedangkan runtime dari Worst Case nya adalah O(n^2), sama seperti best case karena algoritma ini tidak memperhitungkan apakah array sudah terurut atau tidak.

- Merge Sort

Merge Sort adalah algoritma sorting yang berdasarkan prinsip "divide and conquer". Algoritma ini membagi array menjadi dua bagian, mengurutkan masing-masing bagian secara rekursif, dan kemudian menggabungkan kembali bagian-bagian yang sudah diurutkan menjadi satu array.

Alur Algoritma:

1. Bagi array menjadi dua bagian secara setengah.
2. Urutkan masing-masing bagian secara rekursif dengan menggunakan Merge Sort.
3. Gabungkan kembali bagian-bagian yang sudah diurutkan menjadi satu array.

Runtime dari Best Case pada Merge Sort adalah O(n log n), terjadi ketika setiap pembagian array menghasilkan dua bagian yang memiliki ukuran yang sama. Sedangkan runtime dari Worst Case nya adalah O(n log n), sama seperti best case karena algoritma ini memiliki kompleksitas waktu yang tetap, tidak peduli dengan kondisi awal array.

### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 

```C++
#include <iostream>
using namespace std;

// Fungsi untuk mengurutkan array menggunakan algoritma Selection Sort.
void selectionSort(int arr[], int n) { 
    // Loop melalui setiap elemen array kecuali elemen terakhir
    for (int i = 0; i < n-1; ++i) {
        // Cari elemen terkecil dari bagian yang belum diurutkan
        int min_index = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        // Tukar elemen terkecil dengan elemen pertama dari bagian yang belum diurutkan
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    // Mendefinisikan array awal
    int arr[] = {55, 33, 44, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Memanggil fungsi selectionSort untuk mengurutkan array
    selectionSort(arr, n);
    
    // Menampilkan hasil pengurutan
    cout << "Array yang sudah diurutkan: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```
Program di atas adalah sebuah program implementasi dari Selection Sort. Program ini untuk mengurutkan array bilangan bulat. Berikut penjelasan dari program di atas. Sesuai namanya, fungsi selectionSort adalah fungsi untuk mengurutkan array menggunakan algoritma selection sort. Fungsi ini mengambil dua parameter, yaitu "arr" adalah array yang akan diurutkan dan "n" adalah jumlah elemen dalam array tersebut. Selanjutnya terdapat loop pertama "for (int i = 0; i < n-1; ++i)", loop ini berjalan dari indeks 0 hingga "n-2", hal ini karena elemen terakhir sudah pasti terurut saat semua elemen sebelumnya sudah terurut. Di dalam loop pertama ini, kita mencari elemen terkecil dari bagian array yang belum diurutkan. Kemudian loop kedua "for (int j = i+1; j < n; ++j)", loop ini mencari elemen terkecil dari bagian array yang belum diurutkan, dimulai dari indeks setelah "i". Setelah menemukan elemen terkecil, lanjut dilakukan pertukaran elemen terkecil tersebut dengan elemen pertama dari bagian yang belum diurutkan. Proses ini terus diulangi hingga seluruh array terurut. Kemudian yang terakhir fungsi main. Pada fungsi ini kita mendefinisikan array awal, lalu memanggil fungsi selectionSort untuk mengurutkan array tersebut, dan kemudian menampilkan hasil pengurutan dengan pesan yang sudah ditentukan.

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/02c8ab93-4aab-46a5-8283-0bdf46e2fefd)


### 3.	Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram”

```C++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isAnagram(string str1, string str2) {
    // Sorting kedua string
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Membandingkan kedua string yang sudah diurutkan
    return str1 == str2;
}

string checkAnagram(string str1, string str2) {
    // Menggunakan fungsi isAnagram untuk mengecek apakah kedua string adalah anagram
    if (isAnagram(str1, str2)) {
        return "Anagram";
    } else {
        return "Tidak Anagram";
    }
}

int main() {
    // Meminta input
    string string1, string2;
    cout << "Masukkan String Pertama: ";
    cin >> string1;
    cout << "Masukkan String Kedua: ";
    cin >> string2;

    // Memanggil fungsi checkAnagram dan menampilkan hasil
    string result = checkAnagram(string1, string2);
    cout << "Output: \"" << result << "\"" << endl;

    return 0;
}
```

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/53f26264-34bf-42a9-8af3-86c0eb9bcb13)


### 4.	Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! 

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Fungsi untuk menggabungkan array B ke dalam array A, dan mengurutkan array A.
    Parameter: 
    A (vector<int>&): Array pertama yang sudah diurutkan dan memiliki cukup indeks untuk menampung array B.
    B (vector<int>&): Array kedua yang sudah diurutkan.
    */
void mergeAndSortArrays(vector<int> &A, vector<int> &B) {
    
    int m = A.size(); // Ukuran array A
    int n = B.size(); // Ukuran array B

    // Perpanjang ukuran array A jika perlu
    A.resize(m + n);

    // Mulai dari index terakhir pada A dan B
    int i = m - 1;
    int j = n - 1;

    // Index untuk menempatkan elemen dari A dan B ke dalam A
    int k = m + n - 1;

    // Masukkan elemen dari B ke dalam A, mulai dari index terakhir
    while (i >= 0 && j >= 0) {
        // Jika elemen terakhir di A lebih besar, masukkan ke posisi k
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        }
        // Jika elemen terakhir di B lebih besar atau sama dengan A, masukkan ke posisi k
        else {
            A[k--] = B[j--];
        }
    }

    // Masukkan sisa elemen dari B ke dalam A jika ada
    while (j >= 0) {
        A[k--] = B[j--];
    }

    // Urutkan array A setelah penggabungan
    sort(A.begin(), A.end());
}

int main() {
    // Contoh penggunaan:
    vector<int> A = {1, 3, 5, 7, 8}; // Array A
    vector<int> B = {2, 4, 6}; // Array B

    // Panggil fungsi mergeAndSortArrays untuk menggabungkan dan mengurutkan array A dan B
    mergeAndSortArrays(A, B);

    // Tampilkan hasil penggabungan dan pengurutan
    cout << "Hasil penggabungan array B ke dalam array A dan pengurutannya:" << endl;
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/31043b25-f718-428c-9b16-c5545a66d076)