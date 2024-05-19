#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Keranjang{
    char Kalimat;
};


void lihatKalimat(stack<Keranjang> a){
    if(a.empty()){
        cout << "Keranjang masih Kosong";
        return;
    };

    cout << "Isi keranjang adalah ";
    string hasil = "";
    while(!a.empty()){
        hasil = a.top().Kalimat + hasil;
        a.pop();
    };

    cout << hasil << endl;
};

int main () {
    stack<Keranjang> isiKeranjang;
    string kalimat;
    int pilihan;

    cout << "Masukan kalimat yang anda mau : ";
    cin >> kalimat;

    do
    {
        cout << "Pilih Proses" << endl;
        cout << "1. Push" << endl;
        cout << "2. Tampilkan hasil " << endl;
        cout << "3. POP" << endl;
        cout << "4. Keluar" << endl;
        cin >> pilihan ;

        switch (pilihan)
        {
        case 1:
            for(char a : kalimat){
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
            
            break;

        default:
            cout << "pilihan tidak valid";
            break;
        }
    } while (pilihan != 4);


}