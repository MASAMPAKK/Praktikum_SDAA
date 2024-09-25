#include <iostream>
#include <string>

using namespace std;

// struct untuk pemilik dompet
struct Dompet {
    string namaPemilik;
    float saldo;
};

// Fungsi untuk menambah dompet baru
void tambahDompet(Dompet* daftarDompet, int& jumlahDompet) {
    cout << "Masukkan nama pemilik dompet: ";
    cin.ignore();
    getline(cin, daftarDompet[jumlahDompet].namaPemilik);

    cout << "Masukkan saldo awal: ";
    cin >> daftarDompet[jumlahDompet].saldo;

    jumlahDompet++;
    cout << "Dompet berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan semua dompet
void tampilkanDompet(const Dompet* daftarDompet, int jumlahDompet) {
    if (jumlahDompet == 0) {
        cout << "Belum ada dompet yang ditambahkan.\n";
        return;
    }

    for (int i = 0; i < jumlahDompet; i++) {
        cout << "Dompet ke-" << i + 1 << endl;
        cout << "Nama Pemilik: " << daftarDompet[i].namaPemilik << endl;
        cout << "Saldo: " << daftarDompet[i].saldo << endl << endl;
    }
}

// Fungsi untuk memperbarui saldo dompet
void perbaruiDompet(Dompet* daftarDompet, int jumlahDompet) {
    if (jumlahDompet == 0) {
        cout << "Belum ada dompet yang ditambahkan.\n";
        return;
    }

    int indeks;
    cout << "Masukkan nomor dompet yang ingin diperbarui: ";
    cin >> indeks;

    if (indeks < 1 || indeks > jumlahDompet) {
        cout << "Dompet tidak ditemukan.\n";
        return;
    }

    cout << "Masukkan saldo baru: ";
    cin >> daftarDompet[indeks - 1].saldo;
    cout << "Saldo berhasil diperbarui.\n";
}

// Fungsi untuk menghapus dompet
void hapusDompet(Dompet* daftarDompet, int& jumlahDompet) {
    if (jumlahDompet == 0) {
        cout << "Belum ada dompet yang ditambahkan.\n";
        return;
    }

    int indeks;
    cout << "Masukkan nomor dompet yang ingin dihapus: ";
    cin >> indeks;

    if (indeks < 1 || indeks > jumlahDompet) {
        cout << "Dompet tidak ditemukan.\n";
        return;
    }

    for (int i = indeks - 1; i < jumlahDompet - 1; i++) {
        daftarDompet[i] = daftarDompet[i + 1];
    }
    jumlahDompet--;
    cout << "Dompet berhasil dihapus.\n";
}

// Fungsi utama
int main() {
    const int MAX_DOMPET = 100;
    Dompet daftarDompet[MAX_DOMPET];
    int jumlahDompet = 0;

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
                tambahDompet(daftarDompet, jumlahDompet);
                break;
            case 2:
                tampilkanDompet(daftarDompet, jumlahDompet);
                break;
            case 3:
                perbaruiDompet(daftarDompet, jumlahDompet);
                break;
            case 4:
                hapusDompet(daftarDompet, jumlahDompet);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
