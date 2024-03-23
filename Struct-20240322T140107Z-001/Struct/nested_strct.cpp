#include <iostream>
using namespace std;

struct Identitas {
    char depan[15];
    char tengah[15];
    char belakang[15];
};

struct NPM {
    int kode_jurusan;
    int tahun_masuk;
    int strata;
    int id;
};

struct DataPraktikum {
    struct Identitas nama_praktikum;
    struct NPM npm;
}praktikan;

void inputData() {
    cout<<"Nama Depan: ";
    cin.getline(praktikan.nama_praktikum.depan, 15);
    cout<<"Nama Tengah: ";
    cin.getline(praktikan.nama_praktikum.tengah, 15);
    cout<<"Nama Belakang: ";
    cin.getline(praktikan.nama_praktikum.belakang, 15);
    cout<<"ID : ";
    cin>>praktikan.npm.id;
    cout<<"Kode Jurusan : ";
    cin>>praktikan.npm.kode_jurusan;
    cout<<"Tahun Masuk : ";
    cin>>praktikan.npm.tahun_masuk;
    cout<<"Strata : ";
    cin>>praktikan.npm.strata;
}


void displayMahasiswa() {
    cout<<"=================================================\n";
    cout<<"ID : "<<praktikan.npm.id<<endl;
    cout<<"Tahun Masuk : "<<praktikan.npm.tahun_masuk<<endl;
    cout<<"Kode Jurusan: "<<praktikan.npm.kode_jurusan << endl;
    cout<<"Starata : "<<praktikan.npm.strata<<endl;
    cout<<"=================================================\n";
    cout<<"Nama Depan : "<<praktikan.nama_praktikum.depan<<endl;
    cout<<"Nama Tengah : "<<praktikan.nama_praktikum.tengah<<endl;
    cout<<"Nama Belakang : "<<praktikan.nama_praktikum.belakang<<endl;
    cout<<"=================================================\n";
}

int main() {
    inputData();
    displayMahasiswa();
    return 0;
}
