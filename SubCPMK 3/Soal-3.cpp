#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* Fungsi untuk melakukan pencarian biner pada sorted array of strings yang mungkin mengandung string kosong diantaranya.
Parameter:
- arr: vector<string>, array of strings yang sudah terurut
- target: string, kata yang dicari dalam array*/
int binary_search(const vector<string>& arr, const string& target) {

    // Inisialisasi indeks awal dan akhir
    int left = 0;
    int right = arr.size() - 1;

    // Melakukan pencarian biner selama indeks awal tidak melebihi indeks akhir
    while (left <= right) {
        // Menghitung indeks tengah dari subarray
        int mid = left + (right - left) / 2;

        // Mencari indeks non-kosong terdekat di sebelah kiri
        int left_non_empty = mid;
        while (left_non_empty >= left && arr[left_non_empty] == "") {
            left_non_empty--;
        }

        // Jika tidak ada string non-kosong di sebelah kiri
        if (left_non_empty < left) {
            left = mid + 1;
            continue;
        }

        // Memeriksa apakah string di indeks tengah sama dengan target
        if (arr[left_non_empty] == target) {
            return left_non_empty;
        }
        // Jika string di indeks tengah kurang dari target, geser indeks kiri ke mid + 1
        else if (arr[left_non_empty] < target) {
            left = mid + 1;
        }
        // Jika string di indeks tengah lebih besar dari target, geser indeks kanan ke mid - 1
        else {
            right = mid - 1;
        }
    }

    // Jika target tidak ditemukan dalam array, mengembalikan -1
    return -1;
}

int main() {
    // Contoh penggunaan fungsi binary_search sorted array of strings
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    string target = "bola";
    int result = binary_search(arr, target);
    if (result != -1) {
        cout << "Kata \"" << target << "\" ditemukan pada indeks ke-" << result << "." << endl;
    } else {
        cout << "Kata \"" << target << "\" tidak ditemukan dalam array." << endl;
    }

    return 0;
}
