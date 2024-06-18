# <h1 align="center">Rekursif</h1>
<p align="center">Nama: Olivia Intan Puspita</p>
<p align="center">NIM: 2311110006</p>
<p align="center">Kelas: S1SD-04-A</p>

## Penjelasan Rekursif

Dalam bentuk rekursif, semua algoritma dapat dituliskan. Hal ini karena dengan menuliskan algoritma dalam bentuk rekursif memudahkan dalam menerjemahkan ke dalam bahasa pemrograman yang menjadikan program lebih ringkas. Dengan membuat algoritma menjadi bentuk rekursif juga menjadikan lebih mudah untuk membuktikan kebenarannya jika dibandingkan dengan algoritma yang berbentuk iteratif. Suatu algoritma yang memanggil dirinya sendiri dengan input yang semakin mengecil dan berhenti pada suatu kondisi tertentu dinamakan dengan algoritma rekursif. Algoritma rekursif ditulis dalam sebuah fungsi yang terdiri dari kasus basis/pemberhentian. Untuk memudahkan, dapat dilihat pada gambar di bawah ini[1]. 

![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/00d638c1-f9b7-4a6e-a5d8-b345093b0593)

Terdapat dua jenis dalam algoritma rekursif, yaitu rekursif langsung dan rekursif tidak langsung. 
1. Rekursif Langsung: Fungsi rekursif yang memanggil dirinya sendiri.

2. Rekursif Tidak Langsung: Fungsi rekursif tidak langsung terjadi ketika suatu fungsi dipanggil bukan oleh dirinya sendiri melainkan oleh fungsi lain [2].

Terdapat dua bagian utama dalam fungsi rekursif, yaitu basis dan rekurens. Bagian yang berisi nilai secara eksplisit dan berfungsi menghentikan perulangan yang dilakukan rekurens disebut dengan basis. Sedangkan bagian dari objek yang mendefinisikan fungsi itu sendiri disebut dengan rekurens. Rekurens akan berhenti ketika bertemu dengan basis. Namun, jika tidak ada pertemuan maka yang terjadi adalah perulangan tak terhingga di dalam fungsi tersebut. Oleh karena itu, suatu rekurens harus mengarah ke basis [3].

Sama seperti algoritma yang lain, algoritma rekursif juga memiliki kelebihan dan kekurangan. Fungsi rekursif mudah untuk melakukan perulangan dengan batasan yang luas atau dalam skala besar. Selain itu, fungsi rekursif juga dapat melakukan perulangan dengan batasan fungsi. Namun dibalik kelebihannya tersebut, fungsi rekursif tidak bisa melakukan looping bersarang. Fungsi ini biasanya membuat fungsi yang sulit untuk dipahami dan hanya cocok untuk persoalan tertentu saja. Tak hanya itu, fungsi rekursif juga memungkingkan area memori tidak bisa lagi menangani permintaan pemanggilan fungsi karena terjadinya overflow [3].

## Contoh Program

```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung dari angka 8 yaitu: ";
    countdown(8);
    cout << endl;
    return 0;
}
```

## Penjelasan Alur Program

Program di atas merupakan salah satu implementasi sederhana dari rekursif langsung. Terdapat fungsi ```countdown(int n)``` pada program di atas, fungsi ini menerima bilangan bulat ```n```. Jika ```n``` sama dengan 0, fungsi langsung mengembalikan nilai. Namun jika tidak, maka nilai ```n``` akan dicetak dan diikuti dengan spasi ```cout << n << " "```. Lalu, fungsi juga akan memanggil dirinya sendiri dengan nilai ```n - 1```. Selanjutnya terdapat fungsi ```main()```, fungsi inilah yang akan dieksekusi nantinya. Pada fungsi ```main()``` mencetak pesan ```"Rekursif Langsung dari angka 8 yaitu: "```. Kemudian fungsi ini memanggil fungsi ```countdown``` dimana pada program di atas memiliki nilai ```8```. Setelah itu fungsi mengembalikan nilai 0 ```return 0``` dimana itu menandakan bahwa program telah selesai.

## Contoh Output
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/cfeecd44-68f6-406a-86c1-3f48bc5c7a53)

Sesuai dengan perintah yang terdapat pada fungsi ```main()```, program mencetak pesan ```Rekursif Langsung dari angka 8 yaitu: ``` terlebih dahulu. Kemudian program melakukan hitung mundur nilai dari ```n``` yaitu 8. Penjelasan detailnya seperti ini:

1. Panggilan pertama ```countdown(8)```. Ini berarti ```n``` adalah 8 dan program mencetak ```8```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n - 1``` berarti 8-1 = 7

2. Panggilan kedua ```countdown(7)```. Ini berarti ```n``` adalah 7 dan program mencetak ```7```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 7-1 = 6

3. Panggilan ketiga ```countdown(6)```. Ini berarti ```n``` adalah 6 dan program mencetak ```6```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 6-1 = 5

4. Panggilan keempat ```countdown(5)```. Ini berarti ```n``` adalah 5 dan program mencetak ```5```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 5-1 = 4

5. Panggilan kelima ```countdown(4)```. Ini berarti ```n``` adalah 4 dan program mencetak ```4```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 4-1 = 3

6. Panggilan keenam ```countdown(3)```. Ini berarti ```n``` adalah 3 dan program mencetak ```3```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 3-1 = 2

7. Panggilan ketujuh ```countdown(2)```. Ini berarti ```n``` adalah 2 dan program mencetak ```2```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 2-1 = 1

8. Panggilan kedelapan ```countdown(1)```. Ini berarti ```n``` adalah 1 dan program mencetak ```1```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 1-1 = 0

9. Panggilan kesembilan ```countdown(0)```. Disini ```n``` adalah 0 yang berarti basis rekursif sudah tercapai ```if (n == 0)```, maka fungsi langsung mengembalikan nilai tanpa mencetak apapun. 

Sehingga, didapatkan hasil "Rekursif Langsung dari angka 8 yaitu: 8, 7, 6, 5, 4, 3, 2, 1".

## Referensi
[1] Dr.P.H. Gunawan, Logika Matematika untuk Analisis Algoritma, Yogyakarta: Penerbit Andi, 2022.

[2] I. Irmawati, dkk, Buku Ajar Pemrograman, Jambi: PT. Sonpedia Publishing Indonesia, 2023.

[3] I.K.S. Buana, H. Setiawan, P.A.W. Putro, Pemrograman terstruktur, Aceh: Syiah Kuala Universitiy Press, 2021.
