#include <iostream>
#include <queue>
#include <string>

using namespace std;

class AnimalShelter {
private:
    int order; // Untuk melacak waktu masuk
    queue<pair<string, int>> dogQueue;
    queue<pair<string, int>> catQueue;

public:
    AnimalShelter() {
        order = 0;
    }

    // Menambahkan hewan ke selter
    void enqueue(string type) {
        if (type == "dog") {
            dogQueue.push(make_pair(type, order++));
        } else if (type == "cat") {
            catQueue.push(make_pair(type, order++));
        } else {
            cout << "Selter hanya menerima kucing dan anjing." << endl;
        }
    }

    // Mengeluarkan hewan tertua dari selter
    string dequeueAny() {
        if (dogQueue.empty() && catQueue.empty()) {
            return "Selter kosong.";
        } else if (dogQueue.empty()) {
            return dequeueCat();
        } else if (catQueue.empty()) {
            return dequeueDog();
        } else {
            if (dogQueue.front().second < catQueue.front().second) {
                return dequeueDog();
            } else {
                return dequeueCat();
            }
        }
    }

    // Mengeluarkan anjing tertua dari selter
    string dequeueDog() {
        if (dogQueue.empty()) {
            return "Tidak ada anjing di selter.";
        }
        string dog = dogQueue.front().first;
        dogQueue.pop();
        return "Adopsi anjing: " + dog;
    }

    // Mengeluarkan kucing tertua dari selter
    string dequeueCat() {
        if (catQueue.empty()) {
            return "Tidak ada kucing di selter.";
        }
        string cat = catQueue.front().first;
        catQueue.pop();
        return "Adopsi kucing: " + cat;
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("dog");
    shelter.enqueue("cat");
    shelter.enqueue("cat");
    shelter.enqueue("dog");

    cout << shelter.dequeueAny() << endl; 
    cout << shelter.dequeueCat() << endl; 
    cout << shelter.dequeueDog() << endl; 
    cout << shelter.dequeueAny() << endl; 

    return 0;
}
