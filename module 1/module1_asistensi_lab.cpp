#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct detailBarang
{
  int harga;
  int stock;
};

struct Barang
{
  string nama;
  struct detailBarang detail;
};

vector<Barang> dataBarang;

void tambahBarang()
{
  Barang barangBaru;

  cout << "Masukan nama barang yang ingin di tambahkan: " << endl;
  getline(cin, barangBaru.nama);
  cout << "Masukan Jumlah Barang: " << endl;
  cin >> barangBaru.detail.stock;
  cout << "Masukan Harga Barang: " << endl;
  cin >> barangBaru.detail.harga;

  dataBarang.push_back(barangBaru);

  if (!dataBarang.empty())
  {
    cout << "barang berhasil di tambahkan!!" << endl;
  }
  else
  {
    cout << "Barang gagal di tambahkan" << endl;
  }
}

void viewDataBarang()
{
  if (dataBarang.empty())
  {
    cout << "Barang masih kosong!!" << endl;
    return;
  }

  cout << "========================" << endl;
  cout << "|| No || Nama Barang || Stock || Harga ||" << endl;
  cout << "========================" << endl;

  for (size_t i = 0; i < dataBarang.size(); i++)
  {
    cout << "|| " << setw(2) << i + 1 << " || " << setw(8) << dataBarang[i].nama << " || " << setw(5) << dataBarang[i].detail.stock << " || " << setw(5) << dataBarang[i].detail.harga << " ||" << endl;
  }
}

void SearchDataBarang()
{
  string namaBarang;

  cout << "Masukan nama Barang yang ingin di cari: ";
  getline(cin, namaBarang);

  bool found = false;
  for (size_t i = 0; i < dataBarang.size(); i++)
  {
    if (dataBarang[i].nama == namaBarang)
    {
      cout << "========================" << endl;
      cout << "|| No || Nama Barang || Stock || Harga ||" << endl;
      cout << "========================" << endl;
      cout << "|| " << setw(2) << i + 1 << " || " << setw(8) << dataBarang[i].nama << " || " << setw(5) << dataBarang[i].detail.stock << " || " << setw(5) << dataBarang[i].detail.harga << " ||" << endl;
      found = true;
      break;
    }
  }

  if (!found)
  {
    cout << "Barang yang anda cari tidak di temukan";
  }
}

int main()
{
  int pilihan

      do
  {
    cout << "|| Program Manajemen Penjualan ||" << endl;
    cout << "1. Menambah Data Barang "
  }
  while ()
    ;

  // tambahBarang();
  // viewDataBarang();
  return 0;
}