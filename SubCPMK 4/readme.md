# <h1 align="center">CPMK 2 - SubCPMK 4</h1>
<p align="center">Olivia Intan Puspita</p>


## Soal

### 1.	Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 

Structure atau struct adalah kumpulan dari beberapa variabel dengan beragam tipe data yang dibungkus dalam satu variabel. Ada dua cara untuk mengakses member yang ada di dalam struct. Cara pertama adalah dengan cara mendeklarasikan object-nya terlebih dahulu di dalam struct-nya kemudian untuk mengaksesnya bisa menggunakan object yang telah dideklarasikan tadi. Kemudian cara kedua adalah dengan mendeklarasikan object-nya di dalam 'int main()' dengan cara memanggil nama struct-nya dan diikuti dengan nama object-nya.

Berikut adalah contoh struktur data sederhana untuk merepresentasikan informasi tentang karakteristik tiga penyakit menggunakan struct:

```C++
#include <iostream>
#include <string>
using namespace std;

// Definisi struct untuk merepresentasikan informasi tentang penyakit
struct Penyakit {
    string nama;
    string kategori;
    string gejala;
    string penanganan;
};

int main() {
    // Mendeklarasikan array dari struct Penyakit
    const int JUMLAH_PENYAKIT = 3;
    Penyakit daftar_penyakit[JUMLAH_PENYAKIT];

    // Mengisi data ke dalam array dari struct Penyakit
    daftar_penyakit[0] = {"COVID-19", "Virus", "Demam, Batuk, Sesak Napas", "Karantina, Perawatan Medis"};
    daftar_penyakit[1] = {"DBD (Demam Berdarah Dengue)", "Virus", "Demam Tinggi, Nyeri Sendi, Ruam Kulit", "Pengobatan Simptomatik, Istirahat"};
    daftar_penyakit[2] = {"Hipertensi (Tekanan Darah Tinggi)", "Penyakit Jantung", "Sakit Kepala, Pusing, Penglihatan Kabur", "Pengaturan Diet, Olahraga Teratur, Obat-obatan"};

    // Menampilkan informasi penyakit
    cout << "Karakteristik 3 Penyakit:" << endl;
    for (int i = 0; i < JUMLAH_PENYAKIT; ++i) {
        cout << "Penyakit " << i+1 << ":" << endl;
        cout << "Nama: " << daftar_penyakit[i].nama << endl;
        cout << "Kategori: " << daftar_penyakit[i].kategori << endl;
        cout << "Gejala: " << daftar_penyakit[i].gejala << endl;
        cout << "Penanganan: " << daftar_penyakit[i].penanganan << endl;
        cout << endl;
    }

    return 0;
}
```

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/8c2a8c74-7203-4f4b-9e68-0d894db7f5e6)

Dari output di atas dapat kita ketahui bahwa tiga daftar penyakit yang dimasukkan adalah covid-19, DBD, dan hipertensi. Kemudian dari tiga daftar penyakit tersebut, diberikan data karakteristik masing-masing penykit, seperti nama penyakit, kategori, gejala, dan penanganan. 