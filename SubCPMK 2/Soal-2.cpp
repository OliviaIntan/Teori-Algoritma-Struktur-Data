#include <iostream>
using namespace std;

// Fungsi untuk mengurutkan array menggunakan algoritma Selection Sort.
void selectionSort(int arr[], int n) { 
    // Loop melalui setiap elemen array kecuali elemen terakhir
    for (int i = 0; i < n-1; ++i) {
        // Cari elemen terkecil dari bagian yang belum diurutkan
        int min_index = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        // Tukar elemen terkecil dengan elemen pertama dari bagian yang belum diurutkan
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    // Mendefinisikan array awal
    int arr[] = {55, 33, 44, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Memanggil fungsi selectionSort untuk mengurutkan array
    selectionSort(arr, n);
    
    // Menampilkan hasil pengurutan
    cout << "Array yang sudah diurutkan: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
