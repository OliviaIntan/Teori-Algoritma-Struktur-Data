#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Fungsi untuk menggabungkan array B ke dalam array A, dan mengurutkan array A.
    Parameter: 
    A (vector<int>&): Array pertama yang sudah diurutkan dan memiliki cukup indeks untuk menampung array B.
    B (vector<int>&): Array kedua yang sudah diurutkan.
    */
void mergeAndSortArrays(vector<int> &A, vector<int> &B) {
    
    int m = A.size(); // Ukuran array A
    int n = B.size(); // Ukuran array B

    // Perpanjang ukuran array A jika perlu
    A.resize(m + n);

    // Mulai dari index terakhir pada A dan B
    int i = m - 1;
    int j = n - 1;

    // Index untuk menempatkan elemen dari A dan B ke dalam A
    int k = m + n - 1;

    // Masukkan elemen dari B ke dalam A, mulai dari index terakhir
    while (i >= 0 && j >= 0) {
        // Jika elemen terakhir di A lebih besar, masukkan ke posisi k
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        }
        // Jika elemen terakhir di B lebih besar atau sama dengan A, masukkan ke posisi k
        else {
            A[k--] = B[j--];
        }
    }

    // Masukkan sisa elemen dari B ke dalam A jika ada
    while (j >= 0) {
        A[k--] = B[j--];
    }

    // Urutkan array A setelah penggabungan
    sort(A.begin(), A.end());
}

int main() {
    // Contoh penggunaan:
    vector<int> A = {1, 3, 5, 7, 8}; // Array A
    vector<int> B = {2, 4, 6}; // Array B

    // Panggil fungsi mergeAndSortArrays untuk menggabungkan dan mengurutkan array A dan B
    mergeAndSortArrays(A, B);

    // Tampilkan hasil penggabungan dan pengurutan
    cout << "Hasil penggabungan array B ke dalam array A dan pengurutannya:" << endl;
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
