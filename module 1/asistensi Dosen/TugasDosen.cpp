#include <iostream>

using namespace std;

// Nama: Mikhael Agung Yoga Pratama
// NIK : 06.2023.1.07651

typedef struct Bilangan
{
    int nilai;
} DataBilangan;

DataBilangan *buatBilangan(int nilai)
{
    DataBilangan *bilangan = new DataBilangan;
    bilangan->nilai = nilai;
    return bilangan;
}

int hitungFaktorial(DataBilangan *bilangan)
{
    int hasil = 1;
    while (bilangan->nilai > 1)
    {
        hasil *= bilangan->nilai;
        bilangan->nilai--;
    }
    return hasil;
}

int hitungPangkat(DataBilangan *bilangan, int pangkat)
{
    int hasil = 1;
    for (int i = 0; i < pangkat; i++)
    {
        hasil *= bilangan->nilai;
    }
    return hasil;
}

bool isPrima(DataBilangan *bilangan)
{
    if (bilangan->nilai <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= bilangan->nilai; i++)
    {
        if (bilangan->nilai % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int pilih;

    do
    {
        cout << "Pilih Soal" << endl;
        cout << "1. Menghitung Faktorial" << endl;
        cout << "2. Menghitung Pangkat" << endl;
        cout << "3. Mengetahui Bilangan Prima" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukan Pilihan: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
        {
            int input;
            cout << "Masukkan bilangan: ";
            cin >> input;

            DataBilangan *bilangan = buatBilangan(input);

            int faktorial = hitungFaktorial(bilangan);
            cout << input << "! = " << faktorial << endl;

            delete bilangan;
            break;
        }
        case 2:
        {
            int input, pangkat;
            cout << "Masukkan bilangan: ";
            cin >> input;
            cout << "Masukkan pangkat: ";
            cin >> pangkat;

            DataBilangan *bilangan = buatBilangan(input);

            int hasilPangkat = hitungPangkat(bilangan, pangkat);
            cout << input << "^" << pangkat << " = " << hasilPangkat << endl;

            delete bilangan;
            break;
        }
        case 3:
        {
            int input;
            cout << "Masukkan bilangan: ";
            cin >> input;

            DataBilangan *bilangan = buatBilangan(input);

            bool isPrimaResult = isPrima(bilangan);
            if (isPrimaResult)
            {
                cout << input << " adalah bilangan prima." << endl;
            }
            else
            {
                cout << input << " bukan bilangan prima." << endl;
            }

            delete bilangan;
            break;
        }
        case 4:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 4);

    return 0;
}