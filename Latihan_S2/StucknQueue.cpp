#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Keranjang{
    char Kalimat;
};


void createKalimat(stack<Keranjang> a){
    if(a.empty()){
        cout << "Keranjang masih Kosong";
        return;
    };

    cout << "Isi keranjang adalah ";
    string hasil = "";
    while(!a.empty()){
        hasil = a.top().Kalimat +  hasil;
        a.pop();
    };

    cout << hasil << endl;
};

int main () {
    stack<Keranjang> isiKeranjang;
    string kalimat;

    cout << "Masukan kalimat yang anda mau : ";
    
}