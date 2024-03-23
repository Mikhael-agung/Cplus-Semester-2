#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct detailBarang {
    int harga;
    int stock;
};

struct Barang {
    string nama;
    detailBarang detail;
};

vector<Barang> dataBarang;

void tambahBarang() {
    Barang barangBaru;

    cout << "Masukan nama barang yang ingin di tambahkan: " << endl;
    cin >> barangBaru.nama;
    cout << "Masukan Jumlah Barang: " << endl;
    cin >> barangBaru.detail.stock;
    cout << "Masukan Harga Barang: " << endl;
    cin >> barangBaru.detail.harga;

    dataBarang.push_back(barangBaru);

    if (!dataBarang.empty())
    {
        cout << "barang berhasil di tambahkan!!" << endl;
    }
    else
    {
        cout << "Barang gagal di tambahkan" << endl;
    }
}

void viewDataBarang(){
    if (dataBarang.empty())
    {
        cout << "Barang masih kosong!!" << endl;
        return;
    }

    cout << "===================" << endl;
    
}

int main()
{
    tambahBarang();
    return 0;
}