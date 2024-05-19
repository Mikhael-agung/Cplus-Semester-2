#include <iostream>
#include <stack>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Barang_07651
{
    int jumlah_07651;
    string nama_07651;
};

void viewBarang_07651(stack<Barang_07651> s)
{
    if (s.empty())
    {
        cout << "Gudang Barang kosong." << endl;
        return;
    }

    vector<Barang_07651> temp;
    while (!s.empty())
    {
        temp.push_back(s.top());
        s.pop();
    }

    cout << "List Barang Yang ada di gudang." << endl;
    cout << "No. || Nama Barang ||" << endl;
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        cout << (temp.size() - i) << setw(15) << temp[i].nama_07651 << endl;
        s.push(temp[i]);
    }
}

void ambilBarang(stack<Barang_07651>& Gudang) {
    if (!Gudang.empty()) {
        string namaBarang;
    
        cin.ignore(); 
        cout << "Masukkan nama barang yang akan diambil: ";
        getline(cin, namaBarang);

        bool found = false;
        stack<Barang_07651> temp;

        while (!Gudang.empty()) {
            Barang_07651 spec = Gudang.top();
            if (spec.nama_07651 == namaBarang) {
                cout << "Barang " << spec.nama_07651 << " berhasil diambil." << endl;
                found = true;
            } else {
                temp.push(spec);
            }
            Gudang.pop();
        }

        while (!temp.empty()) {
            Gudang.push(temp.top());
            temp.pop();
        }

        if (!found) {
            cout << "Barang dengan nama " << namaBarang << " tidak ditemukan dalam gudang." << endl;
        }
    } else {
        cout << "Gudang kosong. Tidak ada barang yang bisa diambil." << endl;
    }
}

int main()
{
    stack<Barang_07651> Gudang;

    int pilihan;
    do
    {
        cout << "Pengelolahan Barang gudang PT. Gudang Gula" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Nama Barang" << endl;
        cout << "3. Ambil Barang" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukan Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            Barang_07651 spec;
            cin.ignore();
            cout << "Masukan Nama Barang: ";
            getline(cin, spec.nama_07651);
            Gudang.push(spec);
            cout << "Barang berhasil ditambahkan." << endl;
            break;
        }

        case 2:
            viewBarang_07651(Gudang);
            break;

        case 3:
            ambilBarang(Gudang);
            break;

        case 4:
            cout << "Program selesai";
            break;
        default:
            cout << "Pilihan Yang anda pilih tidak ada.";
            break;
        }
    } while (pilihan != 4);

    return 0;
}