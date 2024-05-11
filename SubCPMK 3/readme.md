# <h1 align="center">CPMK 2 - SubCPMK 3</h1>
<p align="center">Olivia Intan Puspita</p>


## Soal

### 1.	Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

- Binary Search

Binary Search adalah algoritma pencarian yang efisien digunakan pada data terurut. 

Alur Algoritma:

1. Membagi data menjadi dua bagian.
2. Memeriksa elemen tengah.
3. Jika nilai yang dicari kurang dari elemen tengah, maka cari di setengah kiri.
4. Jika nilai yang dicari lebih besar dari elemen tengah, maka cari di setengah kanan.
5. Ulangi proses di atas sampai nilai yang dicari ditemukan atau tidak ada lagi elemen yang tersisa.

Runtime dari Best Case pada Binary Search adalah O(1), terjadi ketika nilai yang dicari adalah elemen tengah dari data. Sedangkan runtime dari Worst Case nya adalah O(log n), terjadi ketika nilai yang dicari tidak ada dalam data atau berada pada posisi ekstrim di salah satu ujung data.

- Linear Search

Linear Search adalah algoritma pencarian yang sederhana dan bekerja dengan memeriksa setiap elemen dalam data secara berurutan hingga nilai yang dicari ditemukan atau sampai akhir data.

Alur Algoritma:

1. Mulai dari elemen pertama dalam data.
2. Bandingkan nilai yang dicari dengan setiap elemen secara berurutan.
3. Jika nilai yang dicari cocok dengan elemen yang diperiksa, kembalikan indeks elemen tersebut.
4. Jika semua elemen telah diperiksa dan nilai yang dicari tidak ditemukan, kembalikan nilai "tidak ditemukan".

Runtime dari Best Case pada Linear Search adalah O(1), terjadi ketika nilai yang dicari berada pada elemen pertama data. Sedangkan runtime dari Worst Case nya adalah O(n), terjadi ketika nilai yang dicari berada pada elemen terakhir data atau tidak ada dalam data.

### 2.	Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut  

```C++
#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<int>& arr, int target) {

    // Inisialisasi indeks awal dan akhir
    int left = 0;
    int right = arr.size() - 1;

    // Melakukan pencarian biner selama indeks awal tidak melebihi indeks akhir
    while (left <= right) {
        // Menghitung indeks tengah dari subvektor
        int mid = left + (right - left) / 2;

        // Jika nilai tengah sama dengan target, mengembalikan indeks tengah
        if (arr[mid] == target) {
            return mid;
        }
        // Jika nilai tengah lebih besar dari target, geser indeks kanan ke mid - 1
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // Jika nilai tengah lebih kecil dari target, geser indeks kiri ke mid + 1
        else {
            left = mid + 1;
        }
    }

    // Jika target tidak ditemukan dalam vektor, mengembalikan -1
    return -1;
}

int main() {
    // Contoh penggunaan fungsi Binary Search
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target = 14;
    int result = binary_search(arr, target);
    if (result != -1) {
        cout << "Angka " << target << " ditemukan di indeks " << result << "." << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam vektor." << endl;
    }

    return 0;
}
```
Program di atas adalah sebuah program implementasi dari Binary Search. Berikut penjelasan dari program di atas. Untuk yang pertama, terdapat fungsi binary_search. Sesuai dengan namanya, fungsi ini untuk melakukan pencarian biner pada sebuah vektor terurut. Terdapat dua parameter pada fungsi tersebut, yaitu arr: vector<int>, vektor terurut yang akan dicari dan target: int, nilai yang akan dicari dalam vektor. Pencarian Binary Search dilakukan dengan membagi vector menjadi setengah pada setiap iterasi dan membandingkan nilai tengah dengan target. Jika nilai tengah sama dengan target, fungsi mengembalikan indeks nilai tengah. Sebaliknya, jika nilai tengah lebih besar dari target, pencarian dilakukan pada setengah kiri vector. Lalu, jika nilai tengah lebih kecil dari target, pencarian dilakukan pada setengah kanan vector. Proses ini dilakukan hingga indeks awal tidak lagi kurang dari atau sama dengan indeks akhir. Jika target tidak ditemukan dalam vector, fungsi mengembalikan -1. Selanjutnya pada fungsi main(), terdapat contoh penggunaan fungsi Binary Search pada sebuah vector "arr" dengan angka target yang dicari adalah 14. Setelah dilakukan pencarian, program mencetak pesan sesuai yang telah ditentukan.

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/8f2499c6-3513-4ea4-80cc-941008da65f0)


### 3.	Tulislah sebuah fungsi program dengan kondisi sebagai berikut: Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari!
Input: bola, {“Adi”,””,””, “”, “bermain”, “”, “bola”, “”, “”, “sedang”}
Output: 6

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* Fungsi untuk melakukan pencarian biner pada sorted array of strings yang mungkin mengandung string kosong diantaranya.
Parameter:
- arr: vector<string>, array of strings yang sudah terurut
- target: string, kata yang dicari dalam array*/
int binary_search(const vector<string>& arr, const string& target) {

    // Inisialisasi indeks awal dan akhir
    int left = 0;
    int right = arr.size() - 1;

    // Melakukan pencarian biner selama indeks awal tidak melebihi indeks akhir
    while (left <= right) {
        // Menghitung indeks tengah dari subarray
        int mid = left + (right - left) / 2;

        // Mencari indeks non-kosong terdekat di sebelah kiri
        int left_non_empty = mid;
        while (left_non_empty >= left && arr[left_non_empty] == "") {
            left_non_empty--;
        }

        // Jika tidak ada string non-kosong di sebelah kiri
        if (left_non_empty < left) {
            left = mid + 1;
            continue;
        }

        // Memeriksa apakah string di indeks tengah sama dengan target
        if (arr[left_non_empty] == target) {
            return left_non_empty;
        }
        // Jika string di indeks tengah kurang dari target, geser indeks kiri ke mid + 1
        else if (arr[left_non_empty] < target) {
            left = mid + 1;
        }
        // Jika string di indeks tengah lebih besar dari target, geser indeks kanan ke mid - 1
        else {
            right = mid - 1;
        }
    }

    // Jika target tidak ditemukan dalam array, mengembalikan -1
    return -1;
}

int main() {
    // Contoh penggunaan fungsi binary_search sorted array of strings
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    string target = "bola";
    int result = binary_search(arr, target);
    if (result != -1) {
        cout << "Kata \"" << target << "\" ditemukan pada indeks ke-" << result << "." << endl;
    } else {
        cout << "Kata \"" << target << "\" tidak ditemukan dalam array." << endl;
    }

    return 0;
}
```

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/6423b758-653a-41ed-af8f-35f37db12772)
