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
