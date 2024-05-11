# <h1 align="center">CPMK 2 - SubCPMK 5</h1>
<p align="center">Olivia Intan Puspita</p>


## Soal

### 1.	Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) 

Berikut adalah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted double linked list:

```C++
#include <iostream>
#include <unordered_set>

using namespace std;

// Node untuk linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Fungsi untuk menghapus duplikasi dari linked list
void removeDuplicates(Node* head) {
    if (head == nullptr)
        return;

    unordered_set<int> seen;
    Node* curr = head;
    Node* nextNode;

    while (curr != nullptr) {
        nextNode = curr->next;

        if (seen.find(curr->data) != seen.end()) {
            // Jika elemen sudah ada, hapus node
            curr->prev->next = curr->next;
            if (curr->next != nullptr)
                curr->next->prev = curr->prev;
            delete curr;
        } else {
            // Jika elemen belum ada, tambahkan ke set dan lanjutkan
            seen.insert(curr->data);
        }

        curr = nextNode;
    }
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi untuk menambahkan node baru ke linked list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    if (*head_ref != nullptr)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

int main() {
    Node* head = nullptr;

    // Menambahkan elemen ke linked list
    push(&head, 3);
    push(&head, 1);
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 9);

    cout << "Linked list sebelum menghapus duplikasi: ";
    printList(head);

    // Menghapus duplikasi
    removeDuplicates(head);

    cout << "Linked list setelah menghapus duplikasi: ";
    printList(head);

    return 0;
}
```

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/aa812099-b5f3-4b0b-992e-1731c294db25)


### 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list!  

Algoritma:

1. Hitung panjang linked list.
2. Tentukan indeks node tengah (misalnya, panjang list dibagi 2).
3. Iterasi sampai ke node sebelum node tengah.
4. Simpan pointer ke node tengah.
5. Perbarui pointer next dari node sebelum node tengah untuk mengarahkan ke node setelah node tengah.
6. Hapus node yang ditunjuk oleh pointer yang disimpan pada langkah keempat.

```C++
#include <iostream>

using namespace std;

// Node untuk linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk menambahkan node baru ke linked list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi untuk menghapus node di tengah linked list
void deleteMiddleNode(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    // Hitung panjang linked list
    int length = 0;
    Node* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }

    // Tentukan indeks node tengah
    int mid = length / 2;

    // Iterasi sampai ke node sebelum node tengah
    curr = head;
    for (int i = 0; i < mid - 1; i++) {
        curr = curr->next;
    }

    // Simpan pointer ke node tengah
    Node* middle = curr->next;

    // Perbarui pointer next dari node sebelum node tengah
    curr->next = middle->next;

    // Hapus node tengah
    delete middle;
}

int main() {
    Node* head = nullptr;

    // Menambahkan elemen ke linked list
    push(&head, 3);
    push(&head, 11);
    push(&head, 5);
    push(&head, 7);
    push(&head, 1);
    push(&head, 9);
    push(&head, 13);

    cout << "Linked list sebelum menghapus node di tengah: ";
    printList(head);

    // Menghapus node di tengah
    deleteMiddleNode(head);

    cout << "Linked list setelah menghapus node di tengah: ";
    printList(head);

    return 0;
}
```
### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/5d5e5395-be8d-4866-aaf9-6f7b661dda37)

### 3.	Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

```C++
#include <iostream>
#include <stack>

using namespace std;

// Node untuk linked list
struct Node {
    char data;
    Node* next;

    Node(char val) : data(val), next(nullptr) {}
};

// Fungsi untuk menambahkan node baru ke linked list
void push(Node** head_ref, char new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi untuk mengecek apakah linked list adalah palindrom
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    stack<char> charStack;
    Node* slow = head;
    Node* fast = head;

    // Push setengah pertama karakter ke stack
    while (fast != nullptr && fast->next != nullptr) {
        charStack.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // Jika jumlah node ganjil, lewati node tengah
    if (fast != nullptr)
        slow = slow->next;

    // Bandingkan karakter dengan karakter yang ada di stack
    while (slow != nullptr) {
        if (charStack.top() != slow->data)
            return false;
        charStack.pop();
        slow = slow->next;
    }

    return true;
}

int main() {
    Node* head = nullptr;

    // Menambahkan elemen ke linked list
    push(&head, 'l');
    push(&head, 'e');
    push(&head, 'v');
    push(&head, 'e');
    push(&head, 'l');

    cout << "Linked list: ";
    printList(head);

    if (isPalindrome(head))
        cout << "Linked list adalah sebuah palindrom." << endl;
    else
        cout << "Linked list bukan sebuah palindrom." << endl;

    return 0;
}
```

### Full output Screenshot
![image](https://github.com/OliviaIntan/Teori-Algoritma-Struktur-Data/assets/162260430/20e1b2fc-d560-4964-a5cb-32692770512c)
