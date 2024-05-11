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
