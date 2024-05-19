#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Keranjang {
    char karakter;  // Struct untuk menyimpan karakter
};

// Fungsi untuk menampilkan isi stack
void createKalimat(stack<Keranjang> a) {
    if (a.empty()) {
        cout << "Keranjang masih kosong." << endl;
        return;
    }

    cout << "Isi keranjang adalah: ";
    string output = "";
    while (!a.empty()) {
        output = a.top().karakter + output;
        a.pop();
    }
    cout << output << endl;
}

int main() {
    stack<Keranjang> stackMahasiswa;
    string kalimat = "INSTITUT";

    // PUSH: Masukkan setiap karakter dari "INSTITUT" ke stack
    for (char c : kalimat) {
        Keranjang item;
        item.karakter = c;
        stackMahasiswa.push(item);
    }

    // Tampilkan isi stack setelah operasi PUSH
    cout << "Setelah PUSH:" << endl;
    createKalimat(stackMahasiswa);

    // POP: Hapus beberapa elemen dari stack (misalnya 3 elemen)
    for (int i = 0; i < 3; ++i) {
        if (!stackMahasiswa.empty()) {
            stackMahasiswa.pop();
        }
    }

    // Tampilkan isi stack setelah operasi POP
    cout << "Setelah POP 3 elemen:" << endl;
    createKalimat(stackMahasiswa);

    return 0;
}
