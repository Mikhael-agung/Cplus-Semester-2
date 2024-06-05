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
    if (total >= 91) return "A";
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

void hapusMahasiswa(Mahasiswa*& head, const string& npm) {
    Mahasiswa* temp = head;
    Mahasiswa* prev = nullptr;
    while (temp != nullptr && temp->npm != npm) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Mahasiswa dengan NPM " << npm << " tidak ditemukan." << endl;
        return;
    }
    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Data mahasiswa dengan NPM " << npm << " telah dihapus." << endl;
}

void cariMahasiswa(Mahasiswa* head, const string& nama, const string& npm) {
    Mahasiswa* temp = head;
    cout << left << setw(6) << "No"
         << left << setw(12) << "Nama"
         << left << setw(10) << "NPM"
         << left << setw(8) << "NTS"
         << left << setw(8) << "NAS"
         << left << setw(14) << "Total Akhir"
         << left << setw(8) << "Grade" << endl;

    int no = 1;
    while (temp != nullptr) {
        if ((nama.empty() || temp->nama == nama) && (npm.empty() || temp->npm == npm)) {
            cout << left << setw(6) << no++
                 << left << setw(12) << temp->nama
                 << left << setw(10) << temp->npm
                 << left << setw(8) << temp->nilaiNTS
                 << left << setw(8) << temp->nilaiNAS
                 << left << setw(14) << temp->totalAkhir
                 << left << setw(8) << temp->grade << endl;
        }
        temp = temp->next;
        cout << "Data mahasiswa tidak ditemukan." << endl;
    }
}

void sortMahasiswaByName(Mahasiswa*& head, bool ascending) {
    if (head == nullptr) return;
    bool swapped;
    Mahasiswa* ptr1;
    Mahasiswa* lptr = nullptr;
    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if ((ascending && ptr1->nama > ptr1->next->nama) || (!ascending && ptr1->nama < ptr1->next->nama)) {
                swap(ptr1->nama, ptr1->next->nama);
                swap(ptr1->npm, ptr1->next->npm);
                swap(ptr1->nilaiNTS, ptr1->next->nilaiNTS);
                swap(ptr1->nilaiNAS, ptr1->next->nilaiNAS);
                swap(ptr1->totalAkhir, ptr1->next->totalAkhir);
                swap(ptr1->grade, ptr1->next->grade);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Mahasiswa* head = nullptr;
    int pilihan;
    string nama, npm;
    float nilaiNTS, nilaiNAS;
    bool ascending;

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
                cin >> nama;
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
                cin >> nama;
                cout << "Masukkan Nilai NTS baru: ";
                cin >> nilaiNTS;
                cout << "Masukkan Nilai NAS baru: ";
                cin >> nilaiNAS;
                updateMahasiswa(head, npm, nama, nilaiNTS, nilaiNAS);
                break;
            case 4:
                cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
                cin >> npm;
                hapusMahasiswa(head, npm);
                break;
            case 5:
                cout << "Cari berdasarkan: 1. Nama, 2. NPM, 3. Nama dan NPM: ";
                cin >> pilihan;
                if (pilihan == 1) {
                    cout << "Masukkan Nama mahasiswa yang ingin dicari: ";
                    cin >> nama;
                    cariMahasiswa(head, nama, "");
                } else if (pilihan == 2) {
                    cout << "Masukkan NPM mahasiswa yang ingin dicari: ";
                    cin >> npm;
                    cariMahasiswa(head, "", npm);
                } else if (pilihan == 3) {
                    cout << "Masukkan Nama mahasiswa yang ingin dicari: ";
                    cin >> nama;
                    cout << "Masukkan NPM mahasiswa yang ingin dicari: ";
                    cin >> npm;
                    cariMahasiswa(head, nama, npm);
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 6:
                cout << "Urutkan berdasarkan Nama (1. Ascending, 2. Descending): ";
                cin >> pilihan;
                ascending = (pilihan == 1);
                sortMahasiswaByName(head, ascending);
                tampilkanMahasiswa(head);
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
