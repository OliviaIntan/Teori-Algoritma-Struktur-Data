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
