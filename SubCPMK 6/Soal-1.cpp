#include <iostream>

using namespace std;

// Ukuran maksimum stack
#define MAX_SIZE 5

// Class untuk stack
class Stack {
private:
    int top;
    int data[MAX_SIZE];

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Fungsi untuk menambahkan elemen ke stack (push)
    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh, tidak bisa menambahkan elemen lagi" << endl;
            return;
        }
        data[++top] = value;
        cout << "Elemen " << value << " berhasil ditambahkan ke stack" << endl;
    }

    // Fungsi untuk menghapus elemen dari stack (pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak ada elemen yang dapat dihapus" << endl;
            return;
        }
        cout << "Elemen " << data[top--] << " berhasil dihapus dari stack" << endl;
    }

    // Fungsi untuk mengecek apakah stack kosong
    bool isEmpty() {
        return (top == -1);
    }

    // Fungsi untuk mengecek apakah stack penuh
    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    // Fungsi untuk mendapatkan elemen teratas dari stack tanpa menghapusnya
    int peek() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak ada elemen yang dapat dilihat" << endl;
            return -1;
        }
        return data[top];
    }

    // Fungsi untuk mendapatkan jumlah elemen dalam stack
    int size() {
        return top + 1;
    }

    // Fungsi untuk menghapus semua elemen dari stack
    void clear() {
        top = -1;
        cout << "Stack berhasil dikosongkan" << endl;
    }

    // Fungsi untuk mencetak isi stack
    void printStack() {
        if (isEmpty()) {
            cout << "Stack kosong" << endl;
            return;
        }
        cout << "Isi stack: ";
        for (int i = 0; i <= top; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(3);
    stack.push(6);
    stack.push(9);
    stack.push(12);
    stack.push(15);
    stack.printStack();

    cout << "Elemen teratas: " << stack.peek() << endl;

    stack.pop();
    stack.printStack();

    cout << "Ukuran stack: " << stack.size() << endl;

    cout << "Apakah stack kosong? " << (stack.isEmpty() ? "Ya" : "Tidak") << endl;

    stack.clear();
    stack.printStack();

    return 0;
}
