#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct JobDetails
{
    string jobType;
    long double salary;
};

struct Employee
{
    string nip;
    string name;
    JobDetails job;
    string shift;

    double HitungBonusMalam_07651()
    {
        if (shift == "Malam")
        {
            return job.salary * 0.1;
        }
        else
        {
            return 0;
        }
    }

    void display()
    {
        cout << "NIP: " << nip << endl;
        cout << "Nama: " << name << endl;
        cout << "Jenis Pekerjaan: " << job.jobType << endl;
        cout << "Shift: " << shift << endl;
        cout << "Gaji: Rp. " << fixed << setprecision(2) << job.salary << endl;
        cout << "Bonus Shift Malam: Rp. " << HitungBonusMalam_07651() << endl;
    }
};

int main()
{

    Employee employee;

    cout << "Masukkan NIP: ";
    cin >> employee.nip;
    cout << "Masukkan nama: ";
    cin >> employee.name;
    cout << "Masukkan jenis pekerjaan (Kontrak, Paruh Waktu, Magang): ";
    cin >> employee.job.jobType;
    cout << "Masukkan shift (Pagi, Siang, Malam): ";
    cin >> employee.shift;

    if (employee.job.jobType == "Kontrak")
    {
        employee.job.salary = 6000000;
    }
    else if (employee.job.jobType == "Paruh Waktu")
    {
        employee.job.salary = 4000000;
    }
    else if (employee.job.jobType == "Magang")
    {
        employee.job.salary = 2500000;
    }
    else
    {
        cout << "Jenis pekerjaan tidak valid!" << endl;
        return 1;
    }

    employee.display();

    return 0;
}
