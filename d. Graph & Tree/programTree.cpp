#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // konstruktor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode* masukkanNode(TNode *akar, int nilai) {
    if (akar == NULL) {
        return new TNode(nilai);
    }
    if (nilai < akar->data) {
        akar->left = masukkanNode(akar->left, nilai);
    } else {
        akar->right = masukkanNode(akar->right, nilai);
    }
    return akar;
}

TNode* cariNode(TNode *akar, int nilai) {
    if (akar == NULL || akar->data == nilai) {
        return akar;
    }
    if (nilai < akar->data) {
        return cariNode(akar->left, nilai);
    } else {
        return cariNode(akar->right, nilai);
    }
}

void tampilkanAnak(TNode *node) {
    if (node == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Node " << node->data << " memiliki anak: ";
    if (node->left != NULL) {
        cout << node->left->data << " (kiri) ";
    }
    if (node->right != NULL) {
        cout << node->right->data << " (kanan) ";
    }
    if (node->left == NULL && node->right == NULL) {
        cout << "Tidak ada anak";
    }
    cout << endl;
}

void tampilkanKeturunan(TNode *node) {
    if (node == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Keturunan dari node " << node->data << ": ";
    queue<TNode*> q;
    q.push(node);
    bool pertama = true;
    while (!q.empty()) {
        TNode *saat_ini = q.front();
        q.pop();
        if (saat_ini != node) {
            cout << saat_ini->data << " ";
        }
        if (saat_ini->left != NULL) {
            q.push(saat_ini->left);
        }
        if (saat_ini->right != NULL) {
            q.push(saat_ini->right);
        }
    }
    cout << endl;
}

void tampilkanMenu() {
    cout << "1. Masukkan node" << endl;
    cout << "2. Traversal pre-order" << endl;
    cout << "3. Traversal in-order" << endl;
    cout << "4. Traversal post-order" << endl;
    cout << "5. Tampilkan anak dari node" << endl;
    cout << "6. Tampilkan keturunan dari node" << endl;
    cout << "7. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    TNode *akar = NULL;
    int pilihan, nilai;

    do {
        tampilkanMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai untuk dimasukkan: ";
                cin >> nilai;
                akar = masukkanNode(akar, nilai);
                break;
            case 2:
                cout << "Traversal pre-order: ";
                preOrder(akar);
                cout << endl;
                break;
            case 3:
                cout << "Traversal in-order: ";
                inOrder(akar);
                cout << endl;
                break;
            case 4:
                cout << "Traversal post-order: ";
                postOrder(akar);
                cout << endl;
                break;
            case 5:
                cout << "Masukkan nilai node untuk menampilkan anak-anak: ";
                cin >> nilai;
                tampilkanAnak(cariNode(akar, nilai));
                break;
            case 6:
                cout << "Masukkan nilai node untuk menampilkan keturunan: ";
                cin >> nilai;
                tampilkanKeturunan(cariNode(akar, nilai));
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 7);

    return 0;
}