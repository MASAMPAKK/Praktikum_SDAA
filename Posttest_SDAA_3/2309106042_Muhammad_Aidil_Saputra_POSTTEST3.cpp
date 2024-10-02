#include <iostream>
#include <string>

using namespace std;


struct Dompet {
    string namaPemilik;
    float saldo;
    Dompet* next;
};

void tambahDompet(Dompet*& head) {
    Dompet* dompetBaru = new Dompet; 
    cout << "Masukkan nama pemilik dompet: ";
    cin.ignore();
    getline(cin, dompetBaru->namaPemilik);

    cout << "Masukkan saldo awal: ";
    cin >> dompetBaru->saldo;
    dompetBaru->next = nullptr;

    if (head == nullptr) {
        head = dompetBaru;
    } else {
        Dompet* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = dompetBaru;
    }
    cout << "Dompet berhasil ditambahkan.\n";
}

void tampilkanDompet(Dompet* head) {
    if (head == nullptr) {
        cout << "Belum ada dompet yang ditambahkan.\n";
        return;
    }

    Dompet* temp = head;
    int nomorDompet = 1;

    while (temp != nullptr) {
        cout << "Dompet ke-" << nomorDompet << endl;
        cout << "Nama Pemilik: " << temp->namaPemilik << endl;
        cout << "Saldo: " << temp->saldo << endl << endl;
        temp = temp->next;
    }
}

void perbaruiDompet(Dompet* head) {
    if (head == nullptr) {
        cout << "Belum ada dompet yang ditambahkan.\n";
        return;
    }

    int nomorDompet;
    cout << "Masukkan nomor dompet yang ingin diperbarui: ";
    cin >> nomorDompet;

    Dompet* temp = head;
    int posisi = 1;

    while (temp != nullptr && posisi < nomorDompet) {
        temp = temp->next;
        posisi++;
    }

    if (temp == nullptr) {
        cout << "Dompet tidak ditemukan.\n";
    } else {
        cout << "Masukkan saldo baru: ";
        cin >> temp->saldo;
        cout << "Saldo berhasil diperbarui.\n";
    }
}

void hapusDompet(Dompet*& head) {
    if (head == nullptr) {
        cout << "Belum ada dompet yang ditambahkan.\n";
        return;
    }

    int nomorDompet;
    cout << "Masukkan nomor dompet yang ingin dihapus: ";
    cin >> nomorDompet;

    Dompet* temp = head;
    Dompet* prev = nullptr;
    int posisi = 1;

    while (temp != nullptr && posisi < nomorDompet) {
        prev = temp;
        temp = temp->next;
        posisi++;
    }

    if (temp == nullptr) {
        cout << "Dompet tidak ditemukan.\n";
    } else {
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Dompet berhasil dihapus.\n";
    }
}

int main() {
    Dompet* head = nullptr; 

    int pilihan;
    do {
        cout << "\n--- Manajemen Dompet Online ---\n";
        cout << "1. Tambah Dompet\n";
        cout << "2. Tampilkan Semua Dompet\n";
        cout << "3. Perbarui Saldo Dompet\n";
        cout << "4. Hapus Dompet\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahDompet(head);
                break;
            case 2:
                tampilkanDompet(head);
                break;
            case 3:
                perbaruiDompet(head);
                break;
            case 4:
                hapusDompet(head);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    Dompet* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
