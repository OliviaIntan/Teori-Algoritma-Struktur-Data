#include <iostream>
#include <string>
using namespace std;

// Definisi struct untuk merepresentasikan informasi tentang penyakit
struct Penyakit {
    string nama;
    string kategori;
    string gejala;
    string penanganan;
};

int main() {
    // Mendeklarasikan array dari struct Penyakit
    const int JUMLAH_PENYAKIT = 3;
    Penyakit daftar_penyakit[JUMLAH_PENYAKIT];

    // Mengisi data ke dalam array dari struct Penyakit
    daftar_penyakit[0] = {"COVID-19", "Virus", "Demam, Batuk, Sesak Napas", "Karantina, Perawatan Medis"};
    daftar_penyakit[1] = {"DBD (Demam Berdarah Dengue)", "Virus", "Demam Tinggi, Nyeri Sendi, Ruam Kulit", "Pengobatan Simptomatik, Istirahat"};
    daftar_penyakit[2] = {"Hipertensi (Tekanan Darah Tinggi)", "Penyakit Jantung", "Sakit Kepala, Pusing, Penglihatan Kabur", "Pengaturan Diet, Olahraga Teratur, Obat-obatan"};

    // Menampilkan informasi penyakit
    cout << "Karakteristik 3 Penyakit:" << endl;
    for (int i = 0; i < JUMLAH_PENYAKIT; ++i) {
        cout << "Penyakit " << i+1 << ":" << endl;
        cout << "Nama: " << daftar_penyakit[i].nama << endl;
        cout << "Kategori: " << daftar_penyakit[i].kategori << endl;
        cout << "Gejala: " << daftar_penyakit[i].gejala << endl;
        cout << "Penanganan: " << daftar_penyakit[i].penanganan << endl;
        cout << endl;
    }

    return 0;
}
