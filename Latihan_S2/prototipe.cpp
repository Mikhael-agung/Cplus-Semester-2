#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa {
    string nama;
    string npm;
    float nilaiNTS;
    float nilaiNAS;
    float totalAkhir;
    string grade;
    Mahasiswa* next;
};

string hitungGrade(float total) {
    if (total >= 91) return "A+";
    else if (total >= 86) return "A";
    else if (total >= 80) return "A-";
    else if (total >= 76) return "B+";
    else if (total >= 73) return "B";
    else if (total >= 66) return "B-";
    else if (total >= 61) return "C+";
    else if (total >= 51) return "C";
    else if (total >= 41) return "D";
    else return "E";
}

void tambahMahasiswa(Mahasiswa*& head, const string& nama, const string& npm, float nilaiNTS, float nilaiNAS) {
    Mahasiswa* newMahasiswa = new Mahasiswa;
    newMahasiswa->nama = nama;
    newMahasiswa->npm = npm;
    newMahasiswa->nilaiNTS = nilaiNTS;
    newMahasiswa->nilaiNAS = nilaiNAS;
    newMahasiswa->totalAkhir = (newMahasiswa->nilaiNTS + newMahasiswa->nilaiNAS) / 2;
    newMahasiswa->grade = hitungGrade(newMahasiswa->totalAkhir);
    newMahasiswa->next = head;
    head = newMahasiswa;
}

void tampilkanMahasiswa(Mahasiswa* head) {
    cout << left << setw(6) << "No"
         << left << setw(12) << "Nama"
         << left << setw(10) << "NPM"
         << left << setw(8) << "NTS"
         << left << setw(8) << "NAS"
         << left << setw(14) << "Total Akhir"
         << left << setw(8) << "Grade" << endl;

    int no = 1;
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        cout << left << setw(6) << no++
             << left << setw(12) << temp->nama
             << left << setw(10) << temp->npm
             << left << setw(8) << temp->nilaiNTS
             << left << setw(8) << temp->nilaiNAS
             << left << setw(14) << temp->totalAkhir
             << left << setw(8) << temp->grade << endl;
        temp = temp->next;
    }
}

void updateMahasiswa(Mahasiswa* head, const string& npm, const string& nama, float nilaiNTS, float nilaiNAS) {
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        if (temp->npm == npm) {
            temp->nama = nama;
            temp->nilaiNTS = nilaiNTS;
            temp->nilaiNAS = nilaiNAS;
            temp->totalAkhir = (temp->nilaiNTS + temp->nilaiNAS) / 2;
            temp->grade = hitungGrade(temp->totalAkhir);
            return;
        }
        temp = temp->next;
    }
    cout << "Mahasiswa dengan NPM " << npm << " tidak ditemukan." << endl;
}

void hapusMahasiswa(Mahasiswa*& head, const string& nama, const string& npm) {
    Mahasiswa* temp = head;
    Mahasiswa* prev = nullptr;
    while (temp != nullptr && (temp->nama != nama || temp->npm != npm)) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Mahasiswa dengan Nama " << nama << " dan NPM " << npm << " tidak ditemukan." << endl;
        return;
    }
    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Data mahasiswa dengan Nama " << nama << " dan NPM " << npm << " telah dihapus." << endl;
}

void insertionSort(Mahasiswa*& head, bool ascending, bool byName) {
    if (head == nullptr || head->next == nullptr) return;

    Mahasiswa* sorted = nullptr;

    Mahasiswa* current = head;
    while (current != nullptr) {
        Mahasiswa* next = current->next;

        if (sorted == nullptr || 
            (ascending && (byName ? current->nama < sorted->nama : current->npm < sorted->npm)) || 
            (!ascending && (byName ? current->nama > sorted->nama : current->npm > sorted->npm))) {
            current->next = sorted;
            sorted = current;
        } else {
            Mahasiswa* temp = sorted;
            while (temp->next != nullptr && 
                   ((ascending && (byName ? current->nama >= temp->next->nama : current->npm >= temp->next->npm)) ||
                   (!ascending && (byName ? current->nama <= temp->next->nama : current->npm <= temp->next->npm)))) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    head = sorted;
}

void searchMahasiswaByName(Mahasiswa* head, const string& nama) {
    Mahasiswa* temp = head;
    bool found = false;
    cout << left << setw(6) << "No"
         << left << setw(12) << "Nama"
         << left << setw(10) << "NPM"
         << left << setw(8) << "NTS"
         << left << setw(8) << "NAS"
         << left << setw(14) << "Total Akhir"
         << left << setw(8) << "Grade" << endl;

    int no = 1;
    while (temp != nullptr) {
        if (temp->nama == nama) {
            found = true;
            cout << left << setw(6) << no++
                 << left << setw(12) << temp->nama
                 << left << setw(10) << temp->npm
                 << left << setw(8) << temp->nilaiNTS
                 << left << setw(8) << temp->nilaiNAS
                 << left << setw(14) << temp->totalAkhir
                 << left << setw(8) << temp->grade << endl;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Mahasiswa dengan Nama " << nama << " tidak ditemukan." << endl;
    }
}

void searchMahasiswaByNPM(Mahasiswa* head, const string& npm) {
    Mahasiswa* temp = head;
    bool found = false;
    cout << left << setw(6) << "No"
         << left << setw(12) << "Nama"
         << left << setw(10) << "NPM"
         << left << setw(8) << "NTS"
         << left << setw(8) << "NAS"
         << left << setw(14) << "Total Akhir"
         << left << setw(8) << "Grade" << endl;

    int no = 1;
    while (temp != nullptr) {
        if (temp->npm == npm) {
            found = true;
            cout << left << setw(6) << no++
                 << left << setw(12) << temp->nama
                 << left << setw(10) << temp->npm
                 << left << setw(8) << temp->nilaiNTS
                 << left << setw(8) << temp->nilaiNAS
                 << left << setw(14) << temp->totalAkhir
                 << left << setw(8) << temp->grade << endl;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Mahasiswa dengan NPM " << npm << " tidak ditemukan." << endl;
    }
}

void cariMahasiswa(Mahasiswa* head) {
    int pilihan;
    cout << "Cari berdasarkan: 1. Nama, 2. NPM: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            {
                string nama;
                cout << "Masukkan Nama mahasiswa yang ingin dicari: ";
                cin.ignore(); // Untuk mengabaikan newline character dari input sebelumnya
                getline(cin, nama);
                searchMahasiswaByName(head, nama);
            }
            break;
        case 2:
            {
                string npm;
                cout << "Masukkan NPM mahasiswa yang ingin dicari: ";
                cin >> npm;
                searchMahasiswaByNPM(head, npm);
            }
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }
}

void urutkanMahasiswa(Mahasiswa*& head) {
    int pilihan;
    cout << "Urutkan berdasarkan: 1. Nama (Ascending), 2. Nama (Descending), 3. NPM: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            insertionSort(head, true, true);
            break;
        case 2:
            insertionSort(head, false, true);
            break;
        case 3:
            insertionSort(head, true, false);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }
    tampilkanMahasiswa(head);
}

int main() {
    Mahasiswa* head = nullptr;
    int pilihan;
    string nama, npm;
    float nilaiNTS, nilaiNAS;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Update Mahasiswa\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Cari Mahasiswa\n";
        cout << "6. Urutkan Mahasiswa\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin.ignore(); // Untuk mengabaikan newline character dari input sebelumnya
                getline(cin, nama);
                cout << "Masukkan NPM: ";
                cin >> npm;
                cout << "Masukkan Nilai NTS: ";
                cin >> nilaiNTS;
                cout << "Masukkan Nilai NAS: ";
                cin >> nilaiNAS;
                tambahMahasiswa(head, nama, npm, nilaiNTS, nilaiNAS);
                cout << "Data mahasiswa berhasil ditambahkan." << endl;
                break;
            case 2:
                tampilkanMahasiswa(head);
                break;
            case 3:
                cout << "Masukkan NPM mahasiswa yang ingin di-update: ";
                cin >> npm;
                cout << "Masukkan Nama baru: ";
                cin.ignore(); // Untuk mengabaikan newline character dari input sebelumnya
                getline(cin, nama);
                cout << "Masukkan Nilai NTS baru: ";
                cin >> nilaiNTS;
                cout << "Masukkan Nilai NAS baru: ";
                cin >> nilaiNAS;
                updateMahasiswa(head, npm, nama, nilaiNTS, nilaiNAS);
                break;
            case 4:
                cout << "Masukkan Nama mahasiswa yang ingin dihapus: ";
                cin.ignore(); // Untuk mengabaikan newline character dari input sebelumnya
                getline(cin, nama);
                cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
                cin >> npm;
                hapusMahasiswa(head, nama, npm);
                break;
            case 5:
                cariMahasiswa(head);
                break;
            case 6:
                urutkanMahasiswa(head);
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
