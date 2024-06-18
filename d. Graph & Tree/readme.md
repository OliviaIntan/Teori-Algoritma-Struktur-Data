# <h1 align="center">Graph & Tree</h1>
<p align="center">Nama: Olivia Intan Puspita</p>
<p align="center">NIM: 2311110006</p>
<p align="center">Kelas: S1SD-04-A</p>

## A. Penjelasan Graph 

![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/23e194a9-645a-4bb6-9c8a-45abefed8109)

Struktur data yang terdiri dari berbagai node yang saling terhubung dan node tersebut berperan sebagai simpul yang mana akan ada garis yang menghubungkan setiap simpul tersebut dinamakan dengan graph. Graph sendiri menggambarkan suatu kumpulan objek yang mana pasangan dari objek tersebut terhubung oleh sebuah link. Verteks adalah titik yang menggambarkan objek yang saling terhubung, sedangkan edge adalah link yang menghubungkan verteks [1].

Terdapat tiga jenis graph, yaitu directed graph, undirected graph, dan weighted graph. Garis yang terhubung ke semua simpul disebut dengan directed graph, sedangkan tidak semua simpul yang terhubung dengan garis disebut dengan undirected graph, dan yang terakhir graf yang setiap busurnya memiliki nilai disebut dengan graf berbobot atau weighted graph [1].

Graph memiliki kelebihan dan kekurangan. Graph memeriksa hubungan antar node dengan cepat dan juga cocok digunakan untuk grafik yang tidak banyak mengandung node. Sedangkan kekurangannya, dalam struktur sata graph memerlukan waktu yang lebih lama dalam hal memodifikasi data [1].

### Contoh Program Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[6] = {
    "Andi", "Dimas", "Enggar", "Rahma", "Santi", "Fitri"
};

int busur[6][6] = {
    {0, 4, 3, 0, 0, 0,},
    {4, 0, 0, 15, 0, 9},
    {3, 0, 0, 0, 5, 0},
    {0, 15, 0, 0, 2, 19},
    {0, 0, 5, 2, 0, 14},
    {0, 9, 0, 19, 14, 0},
};

void tampilGraph() {
    for (int baris = 0; baris < 6; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 6; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

### Penjelasan Alur Program Graph

Program di atas merupakan implementasi dari graf. Untuk yang pertama kita mendeklarasikan array ```simpul``` terlebih dahulu. Dalam array ini berisi 6 nama-nama rumah teman-teman saya yang nantinya menjadi simpul dalam graf. Selanjutnya kita mendeklarasikan matriks ```busur```. Dalam matriks ini berisi jarak antar rumah. Pada program di atas nilai pada busur dinyatakan ```busur[6][6]```. Kita misalkan nilai pada ```busur[i][j]```, jika nilai pada busur bukan nol maka berarti ada jalan dari rumah ```simpul[i]``` ke rumah ```simpul[j]``` dengan jarak yang sudah ditentukan oleh nilai di atas. Kemudian terdapat fungsi ```tampilGraph```. Sesuai namanya, fungsi ini digunakan untuk menampilkan graf agar mudah dibaca. Dia mencetak setiap kota yang terhubung beserta dengan jaraknya. Lalu yang terakhir fungsi ```main```. Fungsi utama ini melakukan pemanggilan ```tampilGraph``` untuk mencetak graf. 

### Contoh Output Graph
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/3ceca405-ff38-4832-9f90-30fd7785edc4)

Dari output di atas kita dapat mengetahui jarak antar rumah-rumah:
1. Andi

```Dimas (4) Enggar (3)```

Rumah Andi terhubung ke rumah Dimas dengan jarak 4 dan ke rumah Enggar dengan jarak 3

2. Dimas

```Andi (4) Rahma (15) Fitri (9)```

Rumah Dimas terhubung ke rumah Andi dengan jarak 4, ke rumah Rahma dengan jarak 15, dan ke rumah Fitri dengan jarak 9

3. Enggar

```Andi (3) Santi (5)```

Rumah Enggar terhubung ke rumah Enggar dengan jarak 3 dan ke rumah Santi dengan jarak 5

4. Rahma

```Dimas (15) Santi (2) Fitri (19)```

Rumah Rahma terhubung ke rumah Dimas dengan jarak 15, ke rumah Santi dengan jarak 2, dan ke rumah Fitri dengan jarak 19

5. Santi

```Enggar (5) Rahma (2) Fitri (14)```

Rumah Santi terhubung ke rumah Enggar dengan jarak 5, ke rumah Rahma dengan jarak 2, dan ke rumah Fitri dengan jarak 14

6. Fitri

```Dimas (9) Rahma (19) Santi (14)```

Rumah Fitri terhubung ke rumah Dimas dengan jarak 9, ke rumah Rahma dengan jarak 19, dan ke rumah Santi dengan jarak 14


## B. Penjelasan Tree

Struktur data yang terdiri dari simpul-simpul (nodes) yang saling terhubung (edges) satu sama lain secara hierarkis dinamakan dengan tree atau pohon. Dalam implementasinya, nodes merepresentasikan data, sedangkan edges lintasan yang menghubungkan antara nodes [2]. 

![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/f8b80dac-80e3-4fa4-933e-74733b6c654b)

Gambar di atas merupakan contoh struktur data tree. Dapat kita ketahui akar (root) yaitu A. B dan C sebagai anak (child) dari A, sedangkan D dan E sebagai daun (leaf) dari A. Begitupun dengan F dan G sebagai daun dari C [2].

Pohon yang memiliki simpul sebanyak-banyaknya dua anak disebut dengan pohon biner atau binary tree. Pada pohon biner, dua anak dari tiap simpul disebut dengan anak kiri dan anak kanan. Akan tetapi, pohon biner bisa hanya memiliki salah satu anak saja atau tidak memiliki anak sama sekali (pasa kasus ini, simpul disebut dengan daun) [3].

![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/a137d47c-c564-4dea-b7be-4879057dafed)

Terdapat tiga cara atau metode untuk mengunjungi atau menjelajahi setiap simpul dalam pohon, yaitu metode inOrder, preOrder, dan postOrder. Pada metode ```inOrder```, dia memanggil dirinya untuk menjelajah subpohon kiri dari simpul, mengunjungi simpul, lalu memanggil dirinya untuk menjelajah subpohon kanan dari simpul. Sedangkan pada metode ```preOrder```, dia mengunjungi simpul, memanggil dirinya untuk menjelajah subpohon kiri, memanggil dirinya untuk menjelajah subpohon kanan. Dan pada metode ```postOrder```, dia memanggil dirinya untuk menjelajah subpohon kiri, memanggil dirinya untuk menjelajah subpohon kanan, mengunjungi simpul [3].

Dalam kehidupan, struktur data tree memiliki banyak kegunaan, diantaranya struktur organisasi suatu perusahaan, silsilah keluarga, skema sistem gugur suatu pertandingan, dan ikatan kimia suatu molekul [4].

### Contoh Program Tree

```C++
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // konstruktor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode* masukkanNode(TNode *akar, int nilai) {
    if (akar == NULL) {
        return new TNode(nilai);
    }
    if (nilai < akar->data) {
        akar->left = masukkanNode(akar->left, nilai);
    } else {
        akar->right = masukkanNode(akar->right, nilai);
    }
    return akar;
}

TNode* cariNode(TNode *akar, int nilai) {
    if (akar == NULL || akar->data == nilai) {
        return akar;
    }
    if (nilai < akar->data) {
        return cariNode(akar->left, nilai);
    } else {
        return cariNode(akar->right, nilai);
    }
}

void tampilkanAnak(TNode *node) {
    if (node == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Node " << node->data << " memiliki anak: ";
    if (node->left != NULL) {
        cout << node->left->data << " (kiri) ";
    }
    if (node->right != NULL) {
        cout << node->right->data << " (kanan) ";
    }
    if (node->left == NULL && node->right == NULL) {
        cout << "Tidak ada anak";
    }
    cout << endl;
}

void tampilkanKeturunan(TNode *node) {
    if (node == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Keturunan dari node " << node->data << ": ";
    queue<TNode*> q;
    q.push(node);
    bool pertama = true;
    while (!q.empty()) {
        TNode *saat_ini = q.front();
        q.pop();
        if (saat_ini != node) {
            cout << saat_ini->data << " ";
        }
        if (saat_ini->left != NULL) {
            q.push(saat_ini->left);
        }
        if (saat_ini->right != NULL) {
            q.push(saat_ini->right);
        }
    }
    cout << endl;
}

void tampilkanMenu() {
    cout << "1. Masukkan node" << endl;
    cout << "2. Traversal pre-order" << endl;
    cout << "3. Traversal in-order" << endl;
    cout << "4. Traversal post-order" << endl;
    cout << "5. Tampilkan anak dari node" << endl;
    cout << "6. Tampilkan keturunan dari node" << endl;
    cout << "7. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    TNode *akar = NULL;
    int pilihan, nilai;

    do {
        tampilkanMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai untuk dimasukkan: ";
                cin >> nilai;
                akar = masukkanNode(akar, nilai);
                break;
            case 2:
                cout << "Traversal pre-order: ";
                preOrder(akar);
                cout << endl;
                break;
            case 3:
                cout << "Traversal in-order: ";
                inOrder(akar);
                cout << endl;
                break;
            case 4:
                cout << "Traversal post-order: ";
                postOrder(akar);
                cout << endl;
                break;
            case 5:
                cout << "Masukkan nilai node untuk menampilkan anak-anak: ";
                cin >> nilai;
                tampilkanAnak(cariNode(akar, nilai));
                break;
            case 6:
                cout << "Masukkan nilai node untuk menampilkan keturunan: ";
                cin >> nilai;
                tampilkanKeturunan(cariNode(akar, nilai));
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 7);

    return 0;
}
```

### Penjelasan Alur Program Tree

Program di atas merupakan implementasi dari pohon biner. Dimana pada program ini ditambahkan fungsi untuk menampilkan node child dan descendant dari node yang diinput kan. Program ini juga memiliki 7 menu untuk melakukan beberapa operasi seperti: memasukkan node ke dalam pohon, melakukan traversal pre-order, in-order, dan post-order, menampilkan anak-anak dari node tertentu, menampilkan keturunan dari node tertentu, dan terakhir keluar dari program. Sama seperti sebelumnya untuk yang pertama terdapat struktur ```TNode```, struktur ini mendefinisikan node dalam pohon biner yaitu left (anak kiri), dan right (anak kanan). Kemudian terdapat fungsi Traversal atau penjelajahan. Fungsi ini digunakan untuk melakukan tiga traversal yaitu ```preOrder```, ```inOrder```, dan ```postOrder```. Selanjutnya fungsi Insert dan Find yang digunakan untuk menambahkan node baru ke dalam pohon. Lalu terdapat juga fungsi ```cariNode``` yang digunakan untuk mencari node dengan nilai tertentu. Kemudian terdapat fungsi ```tampilkanAnak``` yang digunakan untuk menampilkan anak-anak dari node tertentu, dan fungsi ```tampilkanKeturunan``` yang digunakan untuk menampilkan seluruh keturunan dari node tertentu.

### Contoh Output Tree
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/5c1f155e-202c-4ade-a60e-56a1eb246090)

![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/7987b8aa-b54b-4dbb-bc97-92d605ca3c6e)

Dari output di atas dapat kita lihat operasi apa saja yang telah dilakukan, yaitu sebagai berikut:

1. Pilih menu 1: Masukkan node

Memasukkan nilai ```63``` untuk ditambahkan ke dalam pohon 

2. Pilih menu 1: Masukkan node

Memasukkan nilai ```27``` untuk ditambahkan ke dalam pohon 

3. Pilih menu 1: Masukkan node

Memasukkan nilai ```99``` untuk ditambahkan ke dalam pohon 

4. Pilih menu 2: Traversal pre-order

Menampilkan node dalam urutan preOrder dimana urutannya adalah akar, kiri, kanan : ```63 27 99```

5. Pilih menu 3: Traversal in-order

Menampilkan node dalam urutan inOrder dimana urutannya adalah kiri, akar, kanan : ```27 63 99```

6. Pilih menu 4: Traversal post-order

Menampilkan node dalam urutan postOrder dimana urutannya adalah kiri, kanan, akar : ```27 99 63```

7. Pilih menu 5: Tampilkan anak dari nood

Menampilkan anak-anak dari node 63: ```Node 63 memiliki anak: 27 (kiri) dan 99 (kanan).

8. Pilih menu 6: Tampilkan keturunan dari node

Menampilkan seluruh keturunan dari node 63: ```Keturunan dari node 63: adalah 27 99```

9. Pilih menu 7: Keluar

Menghentikan program


## Referensi
[1] O. Arifin, S.Kom., M.Cs, dkk, Dasar Pemrograman (Teori & Aplikasi), Jambi: PT. Sonpedia Publishing Indonesia, 2023.

[2] M. Erkamim, S.Kom., M.Kom, dkk, Buku Ajar Algoritma dan Struktur Data, Indonesia: PT. Sonpedia Publishing Indonesia, 2024.

[3] V. Siahaan, Buku Resep Algoritma dan Struktur Data dengan Java, Sumatera Utara: Balige Publishing, 2020.

[4] Amrullah, Aplikasi Graf Pohon dalam Algoritma Huffman, vol. VI, no. 1, pp. 25, Maret 2011.

