#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_MAHASISWA = 100; 
const int MAX_MATAKULIAH = 2;  

void tampilkanMenu() {
    cout << "\nMenu :\n";
    cout << "1. Tambahkan Data Mahasiswa\n";
    cout << "2. Tampilkan Data Mahasiswa\n";
    cout << "0. Keluar\n";
    cout << "Pilih Menu : ";
}

void tambahDataMahasiswa(string nama[], string nim[], int nilai[][MAX_MATAKULIAH], int &jumlahMahasiswa) {
    int banyakSiswa;
    cout << "\nBerapa Banyak Siswa yang Ingin di Tambahkan : ";
    cin >> banyakSiswa;
    cout << endl;

    if (banyakSiswa <= 0) {
        cout << "Jumlah mahasiswa tidak valid.\n";
        return;
    }

    // Pastikan tidak melebihi kapasitas
    if (jumlahMahasiswa + banyakSiswa > MAX_MAHASISWA) {
        cout << "Tidak dapat menambahkan data, melebihi kapasitas.\n";
        return;
    }

    for (int i = 0; i < banyakSiswa; i++) {
        cout << "\nMasukkan Nama Mahasiswa ke-" << (jumlahMahasiswa + 1) << "\t: ";
        cin.ignore();  // Membersihkan newline dari buffer

        getline(cin, nama[jumlahMahasiswa]);

        cout << "Masukkan NIM Mahasiswa ke-" << (jumlahMahasiswa + 1) << "\t: ";
        getline(cin, nim[jumlahMahasiswa]);

        for (int j = 0; j < MAX_MATAKULIAH; j++) {
            string matkul = (j == 0) ? "Algoritma" : "Basis Data";
            while (true) {
                cout << "Masukkan Nilai Untuk " << matkul << "\t: ";
                cin >> nilai[jumlahMahasiswa][j];
                if (nilai[jumlahMahasiswa][j] >= 0 && nilai[jumlahMahasiswa][j] <= 100) { 
                break; 
                } else {
                    cout << "Nilai Harus Diantara 0 sampai 100\n";
                }
            }
        }
        jumlahMahasiswa++;
    }
}

void tampilkanDataMahasiswa(string nama[], string nim[], int nilai[][MAX_MATAKULIAH], int jumlahMahasiswa) {
    if (jumlahMahasiswa == 0) {
        cout << "Belum ada data mahasiswa.\n";
        return;
    }
    cout << "\nData Nilai Mahasiswa :\n";
    cout << setfill('=') << setw(65) << "=" << endl;
    cout << setfill(' ') 
         << left << setw(15) << "NIM" 
         << setw(25) << "Nama Mahasiswa" 
         << setw(15) << "Algoritma" 
         << setw(10) << "Basis Data" 
         << endl;
    cout << setfill('=') << setw(65) << "=" << endl;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << setfill(' ') 
             << left << setw(15) << nim[i] 
             << setw(25) << nama[i] 
             << setw(15) << nilai[i][0] 
             << setw(10) << nilai[i][1] 
             << endl;
    }
    cout << setfill('=') << setw(65) << "=" << endl;
}

int main() {
    string nama[MAX_MAHASISWA], nim[MAX_MAHASISWA];
    int nilai[MAX_MAHASISWA][MAX_MATAKULIAH]; 
    int jumlahMahasiswa = 0; 

    int pilihan;
    char ulang;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                tambahDataMahasiswa(nama, nim, nilai, jumlahMahasiswa);
                break;
            }
            case 2: {
                tampilkanDataMahasiswa(nama, nim, nilai, jumlahMahasiswa);
                break;
            }
            case 0: {
                cout << "Keluar dari Program.\n";
                break;
            }
            default:
                cout << "Pilihan Tidak Valid. Silahkan Coba Lagi\n";
                break;
        }

        if (pilihan != 0) {
            cout << "Kembali ke Menu Utama (y/n) : ";
            cin >> ulang;
        } else {
            ulang = 'n'; // Keluar dari program
        }

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
