#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isAnagram(string str1, string str2) {
    // Sorting kedua string
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Membandingkan kedua string yang sudah diurutkan
    return str1 == str2;
}

string checkAnagram(string str1, string str2) {
    // Menggunakan fungsi isAnagram untuk mengecek apakah kedua string adalah anagram
    if (isAnagram(str1, str2)) {
        return "Anagram";
    } else {
        return "Tidak Anagram";
    }
}

int main() {
    // Meminta input
    string string1, string2;
    cout << "Masukkan String Pertama: ";
    cin >> string1;
    cout << "Masukkan String Kedua: ";
    cin >> string2;

    // Memanggil fungsi checkAnagram dan menampilkan hasil
    string result = checkAnagram(string1, string2);
    cout << "Output: \"" << result << "\"" << endl;

    return 0;
}
