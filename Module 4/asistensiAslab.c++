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

    cout << "Daftar Mahasiswa" << endl;
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

void searchByNama(dataMahasiswa* head, const string& nama){
    dataMahasiswa* temp = head;
    bool found = false;
    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "NPM" << setw(10) << "NTS" << setw(10) << "NAS" << setw(15) << "Total Akhir" << setw(10) << "Grade" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    int no = 1;
    while(temp != nullptr){
        if(temp -> nama == nama){
            cout << left << setw(5) << no++ << setw(20) << temp->nama << setw(15) << temp->NPM << setw(10) << temp->NTS << setw(10) << temp->NAS << setw(15) << temp->totalAkhir << setw(10) << temp->grade << endl;
            found = true;
            break;
        }
        temp = temp -> next;
    }
    if(!found){
        cout << "Mahasiswa dengan Nama "<< nama << " tidak di temukan" << endl;
    }
}

void searchByNPM(dataMahasiswa* head, const string& NPM){
    dataMahasiswa* temp = head;
    bool found = false;
            cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "NPM" << setw(10) << "NTS" << setw(10) << "NAS" << setw(15) << "Total Akhir" << setw(10) << "Grade" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
    int no = 1;
    while(temp != nullptr){
        if(temp -> NPM == NPM){
        cout << left << setw(5) << no++ << setw(20) << temp->nama << setw(15) << temp->NPM << setw(10) << temp->NTS << setw(10) << temp->NAS << setw(15) << temp->totalAkhir << setw(10) << temp->grade << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if(!found){
        cout << "Mahasiswa dengan Nama "<< NPM << " tidak di temukan" << endl;
    }
};


void cariDataMahasiswa(dataMahasiswa* head){
    int pilihan;
    cout << "1. Cari berdasarkan Nama" << endl; 
    cout << "2. Cari berdasarkan NPM" << endl;
    cout << "Masukkan Pilihan: ";
    cin >> pilihan;

    if(pilihan == 1){
        string nama;
        cout << "Masukkan Nama Mahasiswa: ";
        cin.ignore();
        getline(cin, nama);
        searchByNama(head, nama);
    } else if(pilihan == 2){
        string NPM;
        cout << "Masukkan NPM Mahasiswa: ";
        cin >> NPM;
        searchByNPM(head, NPM);
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

// garek fitur utama aseceding dan descending iki seng wangel 🤧🤧
void urutkanDataMahasiswa(dataMahasiswa*& head, bool ascending, bool byNama){
    if(head == nullptr || head->next == nullptr){
        return;
    }

    dataMahasiswa* urutkan = nullptr;

    dataMahasiswa* current = head;
    while(current != nullptr){
        dataMahasiswa* next = current->next;
        
        if(urutkan == nullptr || (ascending && (byNama ? current->nama < urutkan->nama : current->NPM < urutkan->NPM)) || (!ascending && (byNama ? current->nama > urutkan->nama : current->NPM > urutkan-> NPM))){
            current->next = urutkan;
            urutkan = current;
        }else{
            dataMahasiswa* temp = urutkan;
            while (temp->next != nullptr && 
                   ((ascending && (byNama ? current->nama >= temp->next->nama : current->NPM >= temp->next->NPM)) ||
                   (!ascending && (byNama ? current->nama <= temp->next->nama : current->NPM <= temp->next->NPM)))) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = urutkan;
} 

void urutkanDataMahasiswa(dataMahasiswa*& head){
    int pilihan;
    cout << "Urutkan data berdasarkan: " << endl;
    cout << "1. Nama (Ascending)" << endl;
    cout << "2. Nama (Descending)" << endl;
    cout << "3. NPM" << endl;
    cout << "Masukkan Pilihan: ";
    cin >> pilihan;

    switch(pilihan){
        case 1:
            urutkanDataMahasiswa(head, true, true);
            tampilkanDataMahasiswa(head);
            break;
        case 2:
            urutkanDataMahasiswa(head, false, true);
            tampilkanDataMahasiswa(head);
            break;
        case 3:
            urutkanDataMahasiswa(head, true, false);
            tampilkanDataMahasiswa(head);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
    
    };
};


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
        cout << "6. Urutkan Data Mahasiswa" << endl;
        cout << "0. Keluar" << endl;
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
                cariDataMahasiswa(head);
                break;
            case 6:
                urutkanDataMahasiswa(head);
                break;   
            case 0:
                cout << "Program selesai. 🤧🤧" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}
