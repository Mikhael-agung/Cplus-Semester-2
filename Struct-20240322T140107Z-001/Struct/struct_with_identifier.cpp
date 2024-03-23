#include <iostream>
using namespace std;

struct Data_Mahasiswa{
    char nama[50];
    char npm[20];
    int umur;
    char alamat[50];
    char no_telp[12];
}mahasiswa_umum;

int main(){
    cout<<"Nama : ";
    cin.getline(mahasiswa_umum.nama, 50); //untuk type data char
    // getline(cin, mahasiswa_umum.nama); untuk type data string
    cout<<"NPM : ";
    cin.getline(mahasiswa_umum.npm, 20); //cara ke 1
    // cin.getline(mahasiswa_umum.npm, sizeof(mahasiswa_umum.npm)); //cara ke 2 menggunakan sizeof(elemen yang dituju)
    cout<<"Umur : ";
    cin>>mahasiswa_umum.umur;
    cin.ignore();
    cout<<"Alamat : ";
    cin.getline(mahasiswa_umum.alamat, 50);
    cout<<"No Telepon : ";
    cin.getline(mahasiswa_umum.no_telp, 12);
}