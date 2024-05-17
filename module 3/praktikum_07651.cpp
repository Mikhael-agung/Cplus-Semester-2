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
    cout << "No. || Nama Barang || Jumlah Barang" << endl;
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        cout << (temp.size() - i) << setw(20) << temp[i].nama_07651 << setw(10) << temp[i].jumlah_07651 << endl;
        s.push(temp[i]);
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
            cout << "Masukan Jumlah Barang: ";
            cin >> spec.jumlah_07651;
            cin.ignore();
            Gudang.push(spec);
            cout << "Barang berhasil ditambahkan." << endl;
            break;
        }

        case 2:
            viewBarang_07651(Gudang);
            break;

       case 3:
            if (!Gudang.empty()) {
                Barang_07651 spec = Gudang.top();
                Gudang.pop();
                cout << "Barang yaag akan diambil:" << endl;
                cout << "Nama Barang: ";
                cin >> spec.nama_07651;
                cout << "Barang berhasil di ambil";
            } else {
                cout << "Barang yang anda maksud tidak dapat di temukan." << endl;
            }
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