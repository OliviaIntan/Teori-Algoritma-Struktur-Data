#include <iostream>
#include <iomanip>

using namespace std;

string simpul[6] = {
    "Andi", "Dimas", "Enggar", "Rahma", "Santi", "Fitri"
};

int busur[6][6] = {
    {0, 4, 3, 0, 0, 0,},
    {4, 0, 0, 15, 0, 9},
    {3, 0, 0, 0, 5, 0},
    {0, 15, 0, 0, 2, 19},
    {0, 0, 5, 2, 0, 14},
    {0, 9, 0, 19, 14, 0},
};

void tampilGraph() {
    for (int baris = 0; baris < 6; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 6; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
