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
}
//  Viewnya di buat langsung ascending dan descending
void viewKendaraan(jumlahParkir& parkir, bool ascending){
    
    // convert linked list ke array
    Transport* kendaraan[50];
    int count = 0;
    Transport* temp = parkir.head;
    while(temp){
        kendaraan[count++] = temp;
        temp = temp-> next;
    }

    auto bandingkan =  ascending ? [](Transport* a, Transport* b) { return a->plat < b->plat; } : [](Transport* a, Transport* b) { return a->plat > b->plat;
    };

    auto tukar = [](Transport* arr[], int low, int hight, auto bandingkan) -> void {
        if(low < high){
            kendaraan* pivot = arr[high];
            int 
        }
    }

}


int main() {
    jumlahParkir parkir;
    int kapasitasMobil, kapasitasSepedah;
    cout << "Masukan kapasitas mobil: ";
    cin >> kapasitasMobil;
    cout << "Masukan Kapasitas sepedah: ";
    cin >> kapasitasSepedah;

    initJumlahParkir(parkir, kapasitasMobil, kapasitasSepedah);



    return 0;
}

