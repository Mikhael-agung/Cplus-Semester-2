#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Barang_07651 {
    string nama_07651;
    int jumlah_07651;
    int id_07651;
    float harga_07651;
    Barang_07651* next;

};

Barang_07651* head_07651 = nullptr;
int currentId_07651 = 1;

void tambahBarang_07651(const string& nama, int jumlah,float harga) {
    Barang_07651* newBarang = new Barang_07651;
    newBarang->id_07651 = currentId_07651++;
    newBarang->nama_07651 = nama;
    newBarang->jumlah_07651 = jumlah;
    newBarang->harga_07651 = harga;
    newBarang->next = head_07651;
    head_07651 = newBarang;
    cout << "Barang berhasil ditambahkan." << endl;
}

void hapusBarang_07651(string nama) {
    Barang_07651* temp = head_07651;
    Barang_07651* prev = nullptr;

    if (temp != nullptr && temp->nama_07651 != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Barang tidak ditemukan." << endl;
        return;
    }

    if (prev == nullptr) {
        head_07651 = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Barang berhasil dihapus." << endl;
};
    
void perbaruiBarang_07651(string nama, string namaBaru, int jumlah, float harga){
    Barang_07651* temp = head_07651;
    while(temp != nullptr) {
        if(temp->nama_07651 == nama) {
            temp->nama_07651 = namaBaru;
            temp->jumlah_07651 = jumlah;
            temp->harga_07651 = harga;
            cout << "Barang berhasil diperbarui." << endl;
            return;
        }
        temp = temp->next;
    };
    cout << "Barang tidak ditemukan." << endl;
};

void tampilkanBarang_07651 () {
    Barang_07651* temp = head_07651;

    cout << "List Barang Yang ada di gudang." << endl;
    cout << "No. || Nama Barang || Jumlah || Harga ||" << endl;
    cout << "----------------------------------------" << endl;

    while(temp != nullptr) {
        cout << temp->id_07651 << setw(15) << temp->nama_07651 << setw(10) << temp->jumlah_07651 << setw(10) << temp->harga_07651 << endl;
        temp = temp->next;

    };
};

void UrutkanShellsort_07651() {
    int n = 0;
    Barang_07651* temp = head_07651;
    while(temp != nullptr) {
        n++;
        temp = temp->next;
    };

    int gap, i, j;
    Barang_07651** array = new Barang_07651*[n];
    temp = head_07651;

    for( i = 0; i < n; i++) {
        array[i] = temp;
        temp = temp->next;
    };

    for(gap = n/2; gap > 0; gap /= 2) {
        for(i = gap; i < n; i++) {
            Barang_07651* temp = array[i];
            for(j = i; j >= gap && array[j - gap]->id_07651 > temp->id_07651; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }

    head_07651 = array[0];
    temp = head_07651;
    for(i = 1; i < n; i++) {
        temp->next = array[i];
        temp = temp->next;
    }
    temp->next = nullptr;
    delete[] array;

}

void sequentialSearch_07651(string nama) {
    Barang_07651* temp = head_07651;
    bool found = false;
    while(temp != nullptr) {
        if(temp->nama_07651 == nama) {
            cout << "Barang ditemukan." << endl;
            cout << "Nama Barang: " << temp->nama_07651 << endl;
            cout << "Jumlah Barang: " << temp->jumlah_07651 << endl;
            cout << "Harga Barang: " << temp->harga_07651 << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if(!found) {
        cout << "Barang tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan, jumlah;
    string nama, namaBaru;
    float harga;

    do
    {
        cout << "Pengelolahan Barang" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Hapus Barang" << endl;
        cout << "3. Tampilkan barang" << endl;
        cout << "4. Perbarui barang" << endl;
        cout << "5. Urutkan Barang" << endl;
        cout << "6. Cari Barang" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1: 
            cout << "Masukan Nama Barang: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukan Jumlah Barang: ";
            cin >> jumlah;
            cout << "Masukan Harga Barang: ";
            cin >> harga;
            tambahBarang_07651(nama, jumlah, harga);
            break;
        case 2 :
            cout << "Masukan Nama Barang yang akan dihapus: ";
            cin.ignore();
            getline(cin, nama);
            hapusBarang_07651(nama);
            break;

        case 3:
            tampilkanBarang_07651();
            break;

        case 4:
            cout << "Masukan Nama Barang yang ingin di perbarui: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukan Nama Baru: ";
            getline(cin, namaBaru);
            cout << "Masukan Jumlah Baru: ";
            cin >> jumlah;
            cout << "Masukan Harga Baru: ";
            cin >> harga;
            perbaruiBarang_07651(nama, namaBaru, jumlah, harga);
            break;

        case 5:
            UrutkanShellsort_07651();
            break;
        
        case 6:
            cout << "Masukan Nama Barang yang ingin di cari: ";
            cin.ignore();
            getline(cin, nama);
            sequentialSearch_07651(nama);
            break;

        case 7:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan yang anda masukan tidak ada." << endl;
            break;
        }
    } while (pilihan != 6);
    
    return 0;
}