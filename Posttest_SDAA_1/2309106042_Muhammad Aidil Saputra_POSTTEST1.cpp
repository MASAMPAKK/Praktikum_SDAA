#include <iostream>
using namespace std;

// Fungsi rekursif
int hitungnilai(int baris, int kolum) {
    if (kolum == 0 || kolum == baris) {
        return 1;
    } else {
        return hitungnilai(baris - 1, kolum - 1) + hitungnilai(baris - 1, kolum);
    }
}

// Fungsi print segitiga siku2
void printsegitiga(int tingkat) {
    for (int baris = 0; baris < tingkat; baris++) {
        for (int kolum = 0; kolum <= baris; kolum++) {
            cout << hitungnilai(baris, kolum) << " ";
        }
        cout << endl;
    }
}

int main() {
    int tingkat = 3; 
    printsegitiga(tingkat);
    return 0;
}
