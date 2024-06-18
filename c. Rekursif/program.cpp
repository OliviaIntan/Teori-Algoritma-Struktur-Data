#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung dari angka 8 yaitu: ";
    countdown(8);
    cout << endl;
    return 0;
}

