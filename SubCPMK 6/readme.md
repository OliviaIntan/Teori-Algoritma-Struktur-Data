# <h1 align="center">CPMK 2 - SubCPMK 6</h1>
<p align="center">Olivia Intan Puspita</p>


## Soal

#### 1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)!

Berikut adalah sebuah program stack yang terdiri dari 6 operasi, yaitu push untuk menambahkan elemen, pop untuk menghapus elemen dari posisi paling atas, isEmpty untuk memeriksa apakah stack kosong atau tidak, isFull untuk memeriksa apakah stack penuh atau tidak, size untuk mengembalikan jumlah elemen dalam stack, dan yang terakhir clear untuk menghapus semua elemen dari stack.

```C++
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
```

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/019096ee-4c4c-4dbc-9427-ee04659708c2)


#### 2.	Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty. 

Berikut adalah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi atas (top) dari stack tersebut. Program ini melakukan pengurutan stack secara ascending menggunakan metode insertion sort dengan dua stack tambahan (tempStack1 dan tempStack2) untuk menyimpan elemen sementara.

```C++
#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk mengurutkan stack secara ascending
void sortStack(stack<int> &inputStack) {
    stack<int> tempStack1;
    stack<int> tempStack2;

    while (!inputStack.empty()) {
        // Ambil elemen teratas dari input stack
        int temp = inputStack.top();
        inputStack.pop();

        // Selama temporary stack 1 tidak kosong dan elemen teratasnya lebih besar dari temp
        while (!tempStack1.empty() && tempStack1.top() > temp) {
            // Pindahkan dari temporary stack 1 ke temporary stack 2
            tempStack2.push(tempStack1.top());
            tempStack1.pop();
        }

        // Tambahkan temp ke temporary stack 1
        tempStack1.push(temp);

        // Pindahkan elemen dari temporary stack 2 ke temporary stack 1
        while (!tempStack2.empty()) {
            tempStack1.push(tempStack2.top());
            tempStack2.pop();
        }
    }

    // Pindahkan elemen dari temporary stack 1 ke input stack
    while (!tempStack1.empty()) {
        inputStack.push(tempStack1.top());
        tempStack1.pop();
    }
}

// Fungsi untuk mencetak stack
void printStack(stack<int> inputStack) {
    while (!inputStack.empty()) {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;
}

int main() {
    // Contoh penggunaan
    stack<int> inputStack;
    
    // Tambahkan elemen ke input stack
    inputStack.push(52);
    inputStack.push(36);
    inputStack.push(44);
    inputStack.push(98);
    inputStack.push(76);
    inputStack.push(88);

    cout << "Stack sebelum diurutkan: ";
    printStack(inputStack);

    // Urutkan stack
    sortStack(inputStack);

    cout << "Stack setelah diurutkan: ";
    printStack(inputStack);

    return 0;
}
```

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/d1bbf0a2-0ff6-4c9a-bce7-47048e0f267a)

