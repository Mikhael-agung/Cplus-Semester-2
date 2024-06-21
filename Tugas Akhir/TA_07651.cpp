#include <iostream>
#include <string>

using namespace std;

struct Transport {
    string tipe;
    string plat;
    Transport* next;
};

struct jumlahParkir {
    Transport* head;
    int maxMobil;
    int maxSepedah;
    int currentMobil;
    int currentSepedah;
};

void initJumlahParkir(jumlahParkir& parkir, int slotMobil, int slotSepedah){
    parkir.head = nullptr;
    parkir.maxMobil = slotMobil;
    parkir.maxSepedah = slotSepedah;
    parkir.currentMobil = 0;
    parkir.currentSepedah = 0;
}

bool parkirPenuh(jumlahParkir& parkir, string jenisKendaran){
    if((jenisKendaran == "mobil" || jenisKendaran == "Mobil") && parkir.currentMobil >= parkir.maxMobil){
        return true;
    } else if ((jenisKendaran == "sepedah" || jenisKendaran == "Sepedah") && parkir.currentSepedah >= parkir.maxSepedah){
        return true;
    }

    return false;
}

void tambahKendaraan(jumlahParkir& parkir, string tipe, string plat){
    if(parkirPenuh(parkir, tipe)){
        cout << "Maaf! parkiran untuk " << tipe << " sudah penuh!!" << endl;
        return;
    }
    
    Transport* newKendaraan = new Transport{tipe, plat, nullptr};
    if(!parkir.head){
        parkir.head = newKendaraan;
    } else {
        Transport* temp = parkir.head;
        while(temp->next){
            temp = temp->next;
        }

        temp->next = newKendaraan;
    }

    if(tipe == "mobil" || tipe == "Mobil"){
        cout << "Mobil berhasil ditambahkan" << endl;
        parkir.currentMobil++;
    } else if(tipe == "sepedah" || tipe == "Sepedah"){
        cout << "Sepedah berhasil ditambahkan" << endl;
        parkir.currentSepedah++;
    }
}

void removeKendaraan(jumlahParkir& parkir, string plat) {
    if (!parkir.head) {
        cout << "Tidak ada kendaraan di parkiran.\n";
        return;
    }

    Transport* temp = parkir.head;
    Transport* prev = nullptr;

    while (temp && temp->plat != plat) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Kendaraan dengan plat nomor " << plat << " tidak ditemukan.\n";
        return;
    }

    if (prev) {
        prev->next = temp->next;
    } else {
        parkir.head = temp->next;
    }

    if (temp->tipe == "mobil" || temp->tipe == "Mobil")
        parkir.currentMobil--;
    else if (temp->tipe == "sepedah" || temp->tipe == "Sepedah")
        parkir.currentSepedah--;

    delete temp;
    cout << "Kendaraan dengan plat nomor " << plat << " berhasil dihapus.\n";
}

// Function to sort the array using quicksort
void quickSort(Transport* arr[], int low, int high, bool (*compare)(Transport*, Transport*)) {
    if (low < high) {
        Transport* pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (compare(arr[j], pivot)) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        quickSort(arr, low, i, compare);
        quickSort(arr, i + 2, high, compare);
    }
}

void viewKendaraan(jumlahParkir& parkir, bool ascending) {
    // convert linked list ke array
    Transport* kendaraan[50];
    int count = 0;
    Transport* temp = parkir.head;
    while (temp) {
        kendaraan[count++] = temp;
        temp = temp->next;
    }

    bool (*compare)(Transport*, Transport*);
    compare = ascending ? [](Transport* a, Transport* b) -> bool { return a->plat < b->plat; } : [](Transport* a, Transport* b) -> bool { return a->plat > b->plat; };

    quickSort(kendaraan, 0, count - 1, compare);

    cout << "Kendaraan dalam urutan " << (ascending ? "ascending" : "descending") << ":\n";
    for (int i = 0; i < count; ++i) {
        cout << "Plat: " << kendaraan[i]->plat << ", Tipe: " << kendaraan[i]->tipe << endl;
    }
}

void searchKendaraan(jumlahParkir& parkir, string plat) {
    Transport* temp = parkir.head;
    while (temp) {
        if (temp->plat == plat) {
            cout << "Kendaraan ditemukan: Plat: " << temp->plat << ", Tipe: " << temp->tipe << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kendaraan dengan plat nomor " << plat << " tidak ditemukan.\n";
}

bool login() {
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    if ((username == "admin" || username == "Admin") && password == "admin") {
        return true;
    } else {
        cout << "Login gagal. Username atau password salah.\n";
        return false;
    }
}

int main() {
    if (!login()) {
        return 0;
    }

    jumlahParkir parkir;
    int kapasitasMobil, kapasitasSepedah;
    cout << "Masukkan kapasitas mobil: ";
    cin >> kapasitasMobil;
    cout << "Masukkan kapasitas sepedah: ";
    cin >> kapasitasSepedah;

    initJumlahParkir(parkir, kapasitasMobil, kapasitasSepedah);

    int pilihan;
    do {
        cout << "\nSistem Manajemen Parkir\n";
        cout << "1. Tambah Kendaraan\n";
        cout << "2. Hapus Kendaraan\n";
        cout << "3. Tampilkan Kendaraan (Ascending)\n";
        cout << "4. Tampilkan Kendaraan (Descending)\n";
        cout << "5. Cari Kendaraan\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        string plat, tipe;
        switch (pilihan) {
            case 1:
                cout << "Masukkan plat nomor: ";
                cin >> plat;
                cout << "Masukkan tipe (mobil/sepedah): ";
                cin >> tipe;
                tambahKendaraan(parkir, tipe, plat);
                break;
            case 2:
                cout << "Masukkan plat nomor yang akan dihapus: ";
                cin >> plat;
                removeKendaraan(parkir, plat);
                break;
            case 3:
                viewKendaraan(parkir, true);
                break;
            case 4:
                viewKendaraan(parkir, false);
                break;
            case 5:
                cout << "Masukkan plat nomor yang dicari: ";
                cin >> plat;
                searchKendaraan(parkir, plat);
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 6);

    return 0;
}
