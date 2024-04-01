#include <iostream>
using namespace std;

bool cekDuplikatMaks(int arr[]) {
    int panjangArr = 4;
    for (int i = 1;  i < panjangArr; i++) {
        if (arr[i] == arr[i - 1]) {
            return true;  
        }
    }
    return false; 
}
int main(void) {
    int arrA[] = {2, 1, 3, 4};
    cout << cekDuplikatMaks(arrA);
}