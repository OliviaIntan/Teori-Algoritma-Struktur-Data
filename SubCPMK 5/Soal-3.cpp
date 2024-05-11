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
