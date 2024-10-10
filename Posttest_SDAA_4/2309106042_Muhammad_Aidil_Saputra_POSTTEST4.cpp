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
        nomorDompet++;
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

void push(Dompet*& top, string namaPemilik, float saldo) {
    Dompet* dompetBaru = new Dompet;
    dompetBaru->namaPemilik = namaPemilik;
    dompetBaru->saldo = saldo;
    dompetBaru->next = top;
    top = dompetBaru;
    cout << "Dompet berhasil ditambahkan ke Stack.\n";
}

void pop(Dompet*& top) {
    if (top == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }
    Dompet* temp = top;
    top = top->next;
    delete temp;
    cout << "Dompet berhasil dihapus dari Stack.\n";
}

void enqueue(Dompet*& front, Dompet*& rear, string namaPemilik, float saldo) {
    Dompet* dompetBaru = new Dompet;
    dompetBaru->namaPemilik = namaPemilik;
    dompetBaru->saldo = saldo;
    dompetBaru->next = nullptr;

    if (rear == nullptr) {
        front = dompetBaru;
        rear = dompetBaru;
    } else {
        rear->next = dompetBaru;
        rear = dompetBaru;
    }
    cout << "Dompet berhasil ditambahkan ke Queue.\n";
}

void dequeue(Dompet*& front, Dompet*& rear) {
    if (front == nullptr) {
        cout << "Queue kosong.\n";
        return;
    }
    Dompet* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    cout << "Dompet berhasil dihapus dari Queue.\n";
}

int main() {
    Dompet* head = nullptr;
    Dompet* stackTop = nullptr;
    Dompet* queueFront = nullptr;
    Dompet* queueRear = nullptr;

    int pilihan;
    do {
        cout << "\n--- Manajemen Dompet Online ---\n";
        cout << "1. Tambah Dompet\n";
        cout << "2. Tampilkan Semua Dompet\n";
        cout << "3. Perbarui Saldo Dompet\n";
        cout << "4. Hapus Dompet\n";
        cout << "5. Tambah Dompet ke Stack\n";
        cout << "6. Hapus Dompet dari Stack (Pop)\n";
        cout << "7. Tambah Dompet ke Queue\n";
        cout << "8. Hapus Dompet dari Queue (Dequeue)\n";
        cout << "9. Keluar\n";
        cout << "Pilih opsi (1-9): ";
        cin >> pilihan;

        string namaPemilik;
        float saldo;

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
                cout << "Masukkan nama pemilik dompet: ";
                cin.ignore();
                getline(cin, namaPemilik);
                cout << "Masukkan saldo: ";
                cin >> saldo;
                push(stackTop, namaPemilik, saldo);
                break;
            case 6:
                pop(stackTop);
                break;
            case 7:
                cout << "Masukkan nama pemilik dompet: ";
                cin.ignore();
                getline(cin, namaPemilik);
                cout << "Masukkan saldo: ";
                cin >> saldo;
                enqueue(queueFront, queueRear, namaPemilik, saldo);
                break;
            case 8:
                dequeue(queueFront, queueRear);
                break;
            case 9:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 9);

    while (head != nullptr) {
        Dompet* temp = head;
        head = head->next;
        delete temp;
    }
    while (stackTop != nullptr) {
        Dompet* temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
    }
    while (queueFront != nullptr) {
        Dompet* temp = queueFront;
        queueFront = queueFront->next;
        delete temp;
    }

    return 0;
}
