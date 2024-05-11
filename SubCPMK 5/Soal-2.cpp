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
