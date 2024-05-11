#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<int>& arr, int target) {

    // Inisialisasi indeks awal dan akhir
    int left = 0;
    int right = arr.size() - 1;

    // Melakukan pencarian biner selama indeks awal tidak melebihi indeks akhir
    while (left <= right) {
        // Menghitung indeks tengah dari subvektor
        int mid = left + (right - left) / 2;

        // Jika nilai tengah sama dengan target, mengembalikan indeks tengah
        if (arr[mid] == target) {
            return mid;
        }
        // Jika nilai tengah lebih besar dari target, geser indeks kanan ke mid - 1
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // Jika nilai tengah lebih kecil dari target, geser indeks kiri ke mid + 1
        else {
            left = mid + 1;
        }
    }

    // Jika target tidak ditemukan dalam vektor, mengembalikan -1
    return -1;
}

int main() {
    // Contoh penggunaan fungsi Binary Search
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target = 14;
    int result = binary_search(arr, target);
    if (result != -1) {
        cout << "Angka " << target << " ditemukan di indeks " << result << "." << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam vektor." << endl;
    }

    return 0;
}