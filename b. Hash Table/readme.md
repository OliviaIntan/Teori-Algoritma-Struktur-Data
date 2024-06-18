# <h1 align="center">Hash Table</h1>
<p align="center">Nama: Olivia Intan Puspita</p>
<p align="center">NIM: 2311110006</p>
<p align="center">Kelas: S1SD-04-A</p>

## Penjelasan Hash Table

Algoritma hash adalah suatu algoritma dalam waktu yang konstan yaitu o(1) yang dapat melakukan proses tambah, hapus, dan pencarian. Metode yang secara langsung mengakses data record dalam suatu tabel dengan melakukan perhitungan pada key yang menjadi alamat record pada tabel disebut dengan teknik hash. Key sendiri adalah data unik yang dapat berupa nomor atau karakter [1]. 

Proses Hash terdiri dari dua langkah, untuk yang pertama adalah menghitung fungsi Hash. Fungsi Hash berfungsi mengubah key menjadi alamat dalam tabel dengan memetakan key tersebut ke alamat dalam tabel. Lalu yang kedua resolusi terhadap tabrakan (collision resolution). Resolusi terhadap tabrakan ini adalah proses untuk menangani kejadian dua atau lebih key yang dipetakan ke alamat yang sama pada tabel. Mencari lokasi yang kosong dalam tabel Hash secara terurut atau juga dengan menggunakan fungsi Hash yang lain untuk mencari lokasi yang kosong merupakan cara untuk menangani kejadian tersebut [1].

Salah satu struktur data yang merupakan array, yang dapat berisi data atau key yang memiliki kesamaan dengan data, dengan sel ukurannya telah ditentukan disebut dengan hash table [2]. Cara kerja hash table dengan menggunakan fungsi hash yang mengubah kunci menjadi indeks dalam tabel [3].

![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/a356086c-f983-4566-b0df-a4e35810577e)

Gambar di atas merupakan struktur data jenis hash table [4].

Terdapat 3 operasi utama yang digunakan dalam hash table, yaitu ```Search``` untuk mencari data, ```Insert``` untuk menyisipkan data, ```Delete``` untuk menghapus data [4].

Hash table memiliki kelebihan dan kekurangan. Untuk kelebihannya, dalam melakukan proses sinkronisasi hash table lebih mudah jika dibandingkan dengan jenis struktur data lainnya. Selain itu, dalam hal pencarian data hash table lebih efisien sehingga sering digunakan untuk pengindeksan database. Kemudian untuk kekurangannya, hash table menjadi tidak efisien karena terdapat bentrokan data (collision) [4].

## Contoh Program

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Olivia Intan", "58160");
    employee_map.insert("Roihan Arofa", "38934");
    employee_map.insert("Nadia Anggun", "91011");

    cout << "Nomer Hp Olivia Intan : " << employee_map.searchByName("Olivia Intan") << endl;
    cout << "Phone Hp Roihan Arofa : " << employee_map.searchByName("Roihan Arofa") << endl;

    employee_map.remove("Nadia Anggun");

    cout << "Nomer Hp Nadia Anggun setelah dihapus : " << employee_map.searchByName("Nadia Anggun") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```

## Penjelasan Alur Program

Program di atas adalah salah satu implementasi dari hash table untuk menyimpan dan mengelola data nama dan nomor telepon. Untuk yang pertama kita buat konstanta yang mendefinisikan ukuran hash table yaitu ```TABLE_SIZE``` dan dengan ukuran ```11```. Pada program ini terdapat dua kelas, untuk kelas yang pertama yaitu ```class HashNode```. Kelas ini digunakan untuk menyimpan nama ```name``` dan nomor telepon ```phone_number```. Selanjutnya kelas kedua yaitu ```class HashMap```. Kelas ```HashMap``` ini mendefinisikan hash table menggunakan array dari vektor ```table[TABLE_SIZE]``` yang menyimpan pointer ke ```HashNode```. Terdapat beberapa fungsi di dalam ```class HashNode```. Pertama, fungsi ```hashFunc``` yang digunakan untuk menghitung nilai hash dari nama yang diberikan dengan menjumlahkan nilai ASCII dari setiap nama karyawan dan mengambil modulus dengan TABLE_SIZE untuk menentukan letak indeksnya. Kedua, fungsi ```insert``` yang digunakan untuk menambahkan nama dan nomor telepon karyawan ke dalam hash table. Jika sudah ada data yang sama, maka fungsi akan memperbarui nomor teleponnya. Ketiga, fungsi ```remove``` yang digunakan untuk menghapus data dari hash table. Keempat, fungsi ```searchByName``` yang digunakan untuk mencari nomor telepon berdasarkan nama. Kelima, fungsi ```print``` yang digunakan untuk mencetak seluruh data hash table. Kemudian fungsi ```main```. Pada fungsi ```main``` pertama kita membuat objek ```employee_map``` dari kelas ```HashMap```. Setelah itu kita melakukan beberapa operasi, diantaranya menambahkan tiga data ke dalam hash table ```employee.map.insert("Olivia Intan", "58160")```, ```employee_map.insert("Roihan Arofa", "38934")```, ```employee_map.insert("Nadia Anggun", "91011")```, mencari dan mencetak nomor telepon Olivia Intan ```employee_map.searchByName("Olivia Intan")``` dan Roihan Arofa ```employee_map.searchByName("Roihan Arofa")```, menghapus data Nadia Anggun ```employee_map.remove("Nadia Anggun")```, mencari kembali data Nadia Anggun ```employee_map.searchByName("Nadia Anggun")```, dan terakhir mencetak seluruh hash table ```employee_map.print()```.

## Contoh Output
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/9fe8c8cf-7112-4f33-9073-cd7118eeca23)

Dapat kita lihat hasil output: 

```Nomer Hp Olivia Intan : 58160```

```Nomer Hp Roihan Arofa : 38934```

Pertama kita melakukan pencarian nomor hp Olivia Intan dan Roihan Arofa. Karena nama yang dicari termasuk pada data nama karyawan yang telah dimasukkan sebelumnya, sehingga nomor hp mereka ditemukan.

Kemudian kita menghapus data Nadia Anggun pada hash table

Setelah itu kita melakukan pencarian nomor hp Nadia Anggun kembali:

```Nomer Hp Nadia Anggun setelah dihapus :  ```

Karena data Nadia Angggun sudah kita hapus, itu berarti nomor serta nama Nadia Anggun sudah hilang dari daftar hash table, sehingga output kosong.

Terakhir kita mencetak seluruh hash table beserta nomor indeksnya

```6: [Olivia Intan, 58160]```

```8: [Roihan Arofa, 38934]```

Dapat kita lihat bahwa data Olvia Intan berada di indeks ke-6 sedangkan data Roihan Arofa berada di indeks ke-8. 

## Referensi
[1] V. Mutiawani, HashTable sebagai Alternatif dari Algoritma Pencarian Biner pada Aplikasi E-Acesia, vol. 8, no. 2, pp. 943-944, Juli 2014.

[2] M. Syahrir, Fatimatuzzahra, Integrasi Pendekatan Metode Custom Hashingdan Data Partitioninguntuk Mempercepat Proses Pencarian Frekuensi Item-setpada Algoritma Apriori, vol. 20, no. 1, pp. 152, November 2020.

[3] S. S. Wanda, A.MI., S.Pd., M.M., M.Kom, dkk, Pengantar Ilmu Komputer (Pandungan Komprehensif bagi Pemula), Jambi: PT. Sonpedia Publishing Indonesia, 2023.

[4] O. Arifin, S.Kom., M.Cs, dkk, Dasar Pemrograman (Teori & Aplikasi), Jambi: PT. Sonpedia Publishing Indonesia, 2023
