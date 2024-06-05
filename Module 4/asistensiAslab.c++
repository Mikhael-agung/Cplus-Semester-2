#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct dataMahasiswa {
    string nama;
    string NPM;
    int NTS;
    int NAS;
    int totalAkhir;
    string grade;
    dataMahasiswa* next;
};

dataMahasiswa* head = nullptr;

string hitungGrade(int total) {
    if(total >= 91) {
        return "A+";
    } else if(total >= 86){
        return "A";
    } else if(total >= 80){
        return "A-";
    } else if(total >= 76){
        return "B+";
    } else if(total >= 73){
        return "B";
    } else if(total >= 66){
        return "B-";
    } else if(total >= 61){
        return "C+";
    } else if(total >= 51){
        return "C";
    } else if(total >= 41){
        return "D";
    } else {
        return "E";
    }
}

void tambahDataMahasiswa(const string& nama, const string& NPM, int NTS, int NAS) {
    dataMahasiswa* newMahasiswa = new dataMahasiswa;
    newMahasiswa->nama = nama;
    newMahasiswa->NPM = NPM;
    newMahasiswa->NTS = NTS;
    newMahasiswa->NAS = NAS;
    newMahasiswa->totalAkhir = (newMahasiswa->NTS + newMahasiswa->NAS) / 2;
    newMahasiswa->grade = hitungGrade(newMahasiswa->totalAkhir);
    newMahasiswa->next = head;
    head = newMahasiswa;
}

void tampilkanDataMahasiswa(dataMahasiswa* head) {
    dataMahasiswa* temp = head;
    int no = 1;

    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "NPM" << setw(10) << "NTS" << setw(10) << "NAS" << setw(15) << "Total Akhir" << setw(10) << "Grade" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    while (temp != nullptr) {
        cout << left << setw(5) << no++ << setw(20) << temp->nama << setw(15) << temp->NPM << setw(10) << temp->NTS << setw(10) << temp->NAS << setw(15) << temp->totalAkhir << setw(10) << temp->grade << endl;
        temp = temp->next;
    }
}

void hapusDataMahasiswa(dataMahasiswa* head, const string& NPM, const string& nama) {
    dataMahasiswa* temp = head;
    dataMahasiswa* hapus = nullptr;
    while (temp != nullptr && (temp->NPM != NPM || temp->nama != nama)) {
        hapus = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data Mahasiswa tidak ditemukan." << endl;
        return;
    }

    if (hapus == nullptr) {
        head = temp->next;
    } else {
        hapus->next = temp->next;
    }
    delete temp;
    cout << "Data Mahasiswa dengan nama " << nama << " dan NPM " << NPM << " berhasil dihapus." << endl;
};

void updateDataMahasiswa(dataMahasiswa* head, const string& NPM, const string& nama, int NTS, int NAS){
    dataMahasiswa* temp = head;
    while(temp != nullptr){
        if(temp->NPM == NPM){
            temp->nama = nama;
            temp->NTS = NTS;
            temp->NAS = NAS;
            temp->totalAkhir = (temp->NTS + temp->NAS) / 2;
            temp->grade = hitungGrade(temp->totalAkhir);
            return;
        }
        temp = temp->next;
    }
    cout << "Data Mahasiswa dengan NPM " << NPM << " tidak ditemukan." << endl;
};

void cariDataMahasiswa(dataMahasiswa* head, const string& NPM, const string& nama){
    dataMahasiswa* temp = head;
            cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "NPM" << setw(10) << "NTS" << setw(10) << "NAS" << setw(15) << "Total Akhir" << setw(10) << "Grade" << endl;
    int no = 1;
    while(temp != nullptr){
        if((nama.empty() || temp -> nama == nama) && (NPM.empty() || temp -> NPM == NPM)){
        cout << left << setw(5) << no++ << setw(20) << temp->nama << setw(15) << temp->NPM << setw(10) << temp->NTS << setw(10) << temp->NAS << setw(15) << temp->totalAkhir << setw(10) << temp->grade << endl;
        }
        temp = temp->next;
        cout << "Data Mahasiswa tidak ditemukan." << endl;
    };
};

// garek fitur utama aseceding dan descending


int main() {
    string nama, NPM;
    int NTS, NAS, pilihan;

    do {
        cout << "PROGRAM DATA MAHASISWA" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Tampilkan Data Mahasiswa" << endl;
        cout << "3. Hapus Data Mahasiswa" << endl;
        cout << "4. Update Data Mahasiswa" << endl;
        cout << "5. Cari Data Mahasiswa" << endl;
        cout << "7. Keluar" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NPM Mahasiswa: ";
                cin >> NPM;
                cout << "Masukkan Nilai NTS Mahasiswa: ";
                cin >> NTS;
                cout << "Masukkan Nilai NAS Mahasiswa: ";
                cin >> NAS;
                tambahDataMahasiswa(nama, NPM, NTS, NAS);
                cout << "Data Mahasiswa berhasil ditambahkan." << endl;
                break;
            case 2:
                tampilkanDataMahasiswa(head);
                break;
            case 3: 
                cout << "Masukkan NPM Mahasiswa yang akan dihapus: ";
                cin >> NPM;
                hapusDataMahasiswa(head, NPM, nama);
                break;
            case 4:
                cout << "Masukan NPM mahasiswa yang ingin di upadate: ";
                cin.ignore();
                getline(cin, NPM);
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Nilai NTS Mahasiswa: ";
                cin >> NTS;
                cout << "Masukkan Nilai NAS Mahasiswa: ";
                cin >> NAS;
                updateDataMahasiswa(head, NPM, nama, NTS, NAS);
                break;
            case 5:
                cout << "Masukkan NPM Mahasiswa: ";
                cin >> NPM;
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cariDataMahasiswa(head, NPM, nama);
                break;   
            case 7:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 7);

    return 0;
}
