#include <iostream>
using namespace std;

struct Data_Mahasiswa{
    char nama[50];
    char npm[20];
};

int main(){
    Data_Mahasiswa mhs;

    cout<<"Nama : ";
    cin.getline(mhs.nama, 50);
    cout<<"NPM : ";
    cin.getline(mhs.npm, 20);
}