#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Keranjang
{
    char Kalimat;
};

void lihatKalimat(stack<Keranjang> a)
{
    if (a.empty())
    {
        cout << "Keranjang masih Kosong";
        return;
    };

    cout << "Isi keranjang adalah ";
    string hasil = "";
    while (!a.empty())
    {
        hasil = a.top().Kalimat + hasil;
        a.pop();
    };

    cout << hasil << endl;
};

int main()
{
    stack<Keranjang> isiKeranjang;
    string kalimat;
    int pilihan;

    cout << "Masukan kalimat yang anda mau : ";
    cin >> kalimat;
    for (char a : kalimat)
    {
        Keranjang item;
        item.Kalimat = a;
        isiKeranjang.push(item);
    };
    cout << "Kalimat berhasil di masukan\n";

    do
    {
        cout << "Pilih Proses" << endl;
        cout << "1. Push tambahan" << endl;
        cout << "2. Tampilkan hasil " << endl;
        cout << "3. Lakukan POP" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukan pilihan anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:

            cout << "Tambahkan hal baru : ";
            cin >> kalimat;
            for (char a : kalimat)
            {
                Keranjang item;
                item.Kalimat = a;
                isiKeranjang.push(item);
            };
            cout << "Kalimat berhasil di masukan\n";
            break;

        case 2:
            cout << "Susunan Kalimat" << endl;
            lihatKalimat(isiKeranjang);
            break;

        case 3:
            if (!isiKeranjang.empty())
            {
                isiKeranjang.pop();
                cout << "Huruf Paling atas sudah di hapus";
            }
            else
            {
                cout << "Keranjang Kalimat Kosong" << endl;
            };
            break;

        case 4:
            cout << "Program selesai";
            break;

        default:
            cout << "pilihan tidak valid";
            break;
        }
    } while (pilihan != 4);

    return 0;
}