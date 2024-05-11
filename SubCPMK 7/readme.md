# <h1 align="center">CPMK 2 - SubCPMK 7</h1>
<p align="center">Olivia Intan Puspita</p>


## Soal

### 1.	Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! 

Berikut adalah sebuah program queue yang memiliki 6 operasi, enqueue untuk menambahkan elemen, dequeue untuk menghapus elemen, isEmpty untuk mengembalikan true jika queue kosong, isFull untuk mengembalikan true jika queue penuh, display untuk menampilkan isi queue, dan yang terakhir peek untuk melihat nilai dari elemen yang berada di depan queue tanpa menghapusnya.

```C++
#include <iostream>

using namespace std;

#define MAX_SIZE 5 // Ukuran maksimum queue

class Queue {
private:
    int front, rear, size;
    int *arr;

public:
    Queue(int size) {
        front = rear = -1;
        this->size = size;
        arr = new int[size];
    }

    ~Queue() {
        delete[] arr;
    }

    // Fungsi untuk menambahkan elemen ke queue (enqueue)
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue penuh, elemen tidak dapat ditambahkan!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = item;
        cout << "Elemen " << item << " berhasil ditambahkan ke queue\n";
    }

    // Fungsi untuk menghapus elemen dari queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong, penghapusan elemen gagal!\n";
            return;
        }
        int removedItem = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        cout << "Elemen " << removedItem << " berhasil dihapus dari queue\n";
    }

    // Fungsi untuk mengecek apakah queue kosong
    bool isEmpty() {
        return front == -1;
    }

    // Fungsi untuk mengecek apakah queue penuh
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Fungsi untuk menampilkan isi queue
    void display() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }
        cout << "Isi queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }

    // Fungsi untuk melihat nilai elemen di depan queue tanpa menghapusnya (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue kosong, tidak ada elemen untuk dilihat!\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue queue(MAX_SIZE);

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);
    queue.enqueue(25);
    queue.enqueue(30); // Akan menampilkan pesan bahwa queue penuh

    queue.display();

    cout << "Nilai elemen di depan queue: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.display();

    cout << "Nilai elemen di depan queue setelah dequeue beberapa elemen: " << queue.peek() << endl;

    return 0;
}
```
### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/41461c93-75da-48d4-beb2-503a9a795fe2)


### 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat.  

Untuk mengimplementasikan struktur data yang memenuhi kondisi tersebut, kita dapat menggunakan dua queue terpisah untuk menyimpan kucing dan anjing yang masuk ke selter, serta menggunakan informasi tambahan untuk melacak waktu masuk masing-masing hewan. Selain itu, kita akan memerlukan tiga operasi dequeue yang berbeda, yaitu dequeueAny untuk mengeluarkan hewan tertua dari kedua jenis, dequeueDog untuk mengeluarkan anjing tertua, dan dequeueCat untuk mengeluarkan kucing tertua.

Dalam contoh ini, setiap hewan yang masuk ke selter akan diberi nomor urut berdasarkan waktu masuk. Saat melakukan dequeueAny, hewan tertua dari kedua jenis akan dipilih berdasarkan nomor urutnya. Saat melakukan dequeueDog atau dequeueCat, hewan tertua dari jenis yang dipilih akan diambil dari antrian yang sesuai.


```C++
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class AnimalShelter {
private:
    int order; // Untuk melacak waktu masuk
    queue<pair<string, int>> dogQueue;
    queue<pair<string, int>> catQueue;

public:
    AnimalShelter() {
        order = 0;
    }

    // Menambahkan hewan ke selter
    void enqueue(string type) {
        if (type == "dog") {
            dogQueue.push(make_pair(type, order++));
        } else if (type == "cat") {
            catQueue.push(make_pair(type, order++));
        } else {
            cout << "Selter hanya menerima kucing dan anjing." << endl;
        }
    }

    // Mengeluarkan hewan tertua dari selter
    string dequeueAny() {
        if (dogQueue.empty() && catQueue.empty()) {
            return "Selter kosong.";
        } else if (dogQueue.empty()) {
            return dequeueCat();
        } else if (catQueue.empty()) {
            return dequeueDog();
        } else {
            if (dogQueue.front().second < catQueue.front().second) {
                return dequeueDog();
            } else {
                return dequeueCat();
            }
        }
    }

    // Mengeluarkan anjing tertua dari selter
    string dequeueDog() {
        if (dogQueue.empty()) {
            return "Tidak ada anjing di selter.";
        }
        string dog = dogQueue.front().first;
        dogQueue.pop();
        return "Adopsi anjing: " + dog;
    }

    // Mengeluarkan kucing tertua dari selter
    string dequeueCat() {
        if (catQueue.empty()) {
            return "Tidak ada kucing di selter.";
        }
        string cat = catQueue.front().first;
        catQueue.pop();
        return "Adopsi kucing: " + cat;
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("dog");
    shelter.enqueue("cat");
    shelter.enqueue("cat");
    shelter.enqueue("dog");

    cout << shelter.dequeueAny() << endl; 
    cout << shelter.dequeueCat() << endl; 
    cout << shelter.dequeueDog() << endl; 
    cout << shelter.dequeueAny() << endl; 

    return 0;
}
```
### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/3cec8f9a-bd6d-43a1-9f37-0dfc08d66c18)
