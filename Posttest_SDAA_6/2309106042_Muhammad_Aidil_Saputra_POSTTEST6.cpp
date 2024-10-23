#include <iostream>
#include <string>
#include <cmath>
#include <vector>

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

// Sorting functions
Dompet* merge(Dompet* left, Dompet* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->saldo <= right->saldo) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Dompet* mergeSort(Dompet* head) {
    if (!head || !head->next) return head;

    Dompet* mid = head;
    Dompet* fast = head->next;

    while (fast && fast->next) {
        mid = mid->next;
        fast = fast->next->next;
    }

    Dompet* left = head;
    Dompet* right = mid->next;
    mid->next = nullptr;

    return merge(mergeSort(left), mergeSort(right));
}

Dompet* partition(Dompet* head, Dompet* end, Dompet** newHead, Dompet** newEnd) {
    Dompet* pivot = end;
    Dompet* prev = nullptr;
    Dompet* curr = head;
    Dompet* tail = pivot;

    while (curr != pivot) {
        if (curr->saldo > pivot->saldo) {
            if ((*newHead) == nullptr) (*newHead) = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) prev->next = curr->next;
            Dompet* temp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if ((*newHead) == nullptr) (*newHead) = pivot;
    (*newEnd) = tail;

    return pivot;
}

Dompet* getTail(Dompet* head) {
    while (head != nullptr && head->next != nullptr) {
        head = head->next;
    }
    return head;
}

Dompet* quickSortRec(Dompet* head, Dompet* end) {
    if (!head || head == end) return head;

    Dompet* newHead = nullptr;
    Dompet* newEnd = nullptr;

    Dompet* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Dompet* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRec(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRec(pivot->next, newEnd);

    return newHead;
}

void quickSort(Dompet*& head) {
    Dompet* tail = getTail(head);
    head = quickSortRec(head, tail);
}

int fibonacciSearch(vector<float>& arr, float x) {
    int n = arr.size();
    int fib2 = 0;
    int fib1 = 1;
    int fibM = fib2 + fib1;

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        } else {
            return i;
        }
    }

    if (fib1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int jumpSearch(vector<float>& arr, float x) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

int boyerMooreSearch(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();

    vector<int> badChar(256, -1);

    for (int i = 0; i < m; i++) {
        badChar[pattern[i]] = i;
    }

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            return s;
        } else {
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    return -1;
}

void copySaldoToArray(Dompet* head, vector<float>& saldoArray) {
    Dompet* temp = head;
    while (temp != nullptr) {
        saldoArray.push_back(temp->saldo);
        temp = temp->next;
    }
}

int main() {
    Dompet* head = nullptr;
    Dompet* stackTop = nullptr;
    Dompet* queueFront = nullptr;
    Dompet* queueRear = nullptr;
    int pilihan;
    do {
        cout << "\n--- Menu Manajemen Dompet ---\n";
        cout << "1. Tambah Dompet\n";
        cout << "2. Tampilkan Dompet\n";
        cout << "3. Perbarui Saldo Dompet\n";
        cout << "4. Hapus Dompet\n";
        cout << "5. Push ke Stack\n";
        cout << "6. Pop dari Stack\n";
        cout << "7. Enqueue ke Queue\n";
        cout << "8. Dequeue dari Queue\n";
        cout << "9. Urutkan dengan Merge Sort\n";
        cout << "10. Urutkan dengan Quick Sort\n";
        cout << "11. Fibonacci Search (Saldo)\n";
        cout << "12. Jump Search (Saldo)\n";
        cout << "13. Boyer-Moore Search (Nama Pemilik)\n";
        cout << "14. Keluar\n";
        cout << "Pilih menu (1-14): ";
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
            case 5: {
                string namaPemilik;
                float saldo;
                cout << "Masukkan nama pemilik dompet: ";
                cin.ignore();
                getline(cin, namaPemilik);
                cout << "Masukkan saldo: ";
                cin >> saldo;
                push(stackTop, namaPemilik, saldo);
                break;
            }
            case 6:
                pop(stackTop);
                break;
            case 7: {
                string namaPemilik;
                float saldo;
                cout << "Masukkan nama pemilik dompet: ";
                cin.ignore();
                getline(cin, namaPemilik);
                cout << "Masukkan saldo: ";
                cin >> saldo;
                enqueue(queueFront, queueRear, namaPemilik, saldo);
                break;
            }
            case 8:
                dequeue(queueFront, queueRear);
                break;
            case 9:
                head = mergeSort(head);
                cout << "Dompet berhasil diurutkan menggunakan Merge Sort.\n";
                break;
            case 10:
                quickSort(head);
                cout << "Dompet berhasil diurutkan menggunakan Quick Sort.\n";
                break;
            case 11: {
                vector<float> saldoArray;
                copySaldoToArray(head, saldoArray);
                if (saldoArray.empty()) {
                    cout << "Data saldo tidak tersedia.\n";
                } else {
                    cout << "Masukkan saldo yang dicari: ";
                    float saldo;
                    cin >> saldo;

                    int index = fibonacciSearch(saldoArray, saldo);

                    if (index != -1) {
                        cout << "Saldo ditemukan pada indeks " << index << ".\n";
                    } else {
                        cout << "Saldo tidak ditemukan.\n";
                    }
                }
                break;
            }
            case 12: {
                vector<float> saldoArray;
                copySaldoToArray(head, saldoArray);
                if (saldoArray.empty()) {
                    cout << "Data saldo tidak tersedia.\n";
                } else {
                    cout << "Masukkan saldo yang dicari: ";
                    float saldo;
                    cin >> saldo;

                    int index = jumpSearch(saldoArray, saldo);

                    if (index != -1) {
                        cout << "Saldo ditemukan pada indeks " << index << ".\n";
                    } else {
                        cout << "Saldo tidak ditemukan.\n";
                    }
                }
                break;
            }
            case 13: {
                cout << "Masukkan nama pemilik yang dicari: ";
                string namaPemilik;
                cin.ignore();
                getline(cin, namaPemilik);

                Dompet* temp = head;
                int posisi = 1;
                bool found = false;

                while (temp != nullptr) {
                    if (boyerMooreSearch(temp->namaPemilik, namaPemilik) != -1) {
                        cout << "Nama pemilik ditemukan di dompet ke-" << posisi << ".\n";
                        found = true;
                        break;
                    }
                    temp = temp->next;
                    posisi++;
                }

                if (!found) {
                    cout << "Nama pemilik tidak ditemukan.\n";
                }
                break;
            }
        }
    } while (pilihan != 14);

    return 0;
}
