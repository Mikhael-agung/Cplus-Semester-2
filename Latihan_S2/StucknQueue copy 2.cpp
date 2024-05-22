#include <iostream>
#include <stack>
#include <string>

using namespace std;


struct Keranjang {
    char Kalimat;  
};

void tampilkanStack(stack<Keranjang>& a) {
    if (a.empty()) {
        cout << "Keranjang masih Kosong" << endl;  
        return;
    }

    stack<Keranjang> tempStack;  
    while (!a.empty()) {
        tempStack.push(a.top());  
        a.pop();
    }

    cout << "Bottom -> ";
    while (!tempStack.empty()) {
        cout << tempStack.top().Kalimat;  
        tempStack.pop();
        if (!tempStack.empty()) {
            cout << endl << "        ";  
        }
    }
    cout << endl << "Top -> " << a.top().Kalimat << endl;  
};

int main() {
    stack<Keranjang> isiKeranjang;  
    string kalimat;

    cout << "Masukkan kalimat yang anda mau: ";
    cin >> kalimat;  

    
    for (char a : kalimat) {
        Keranjang item;
        item.Kalimat = a;  
        isiKeranjang.push(item);  
    }
    cout << "Kalimat berhasil dimasukkan ke stack." << endl;

   
    cout << "Susunan Kalimat" << endl;
    tampilkanStack(isiKeranjang);  
    
    cout << "\nProses POP dimulai:" << endl;
    while (!isiKeranjang.empty()) {
        cout << "Huruf yang di-POP: " << isiKeranjang.top().Kalimat << endl;
        isiKeranjang.pop();

        if (!isiKeranjang.empty()) {
            cout << "Isi keranjang setelah POP:" << endl;
            tampilkanStack(isiKeranjang);  
        } else {
            cout << "Keranjang sekarang kosong." << endl;
        }
        cout << endl;
    }

    return 0;  
}
