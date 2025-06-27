#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Siswa {
    string nama;
    double nilai1, nilai2, nilai3;
    double rataRata;
};

void hitungRataRata(Siswa& siswa) {
    siswa.rataRata = (siswa.nilai1 + siswa.nilai2 + siswa.nilai3) / 3.0;
}

void inputNilaiSiswa(Siswa siswa[], int& jumlah) {
    cout << "Masukkan jumlah siswa: ";
    cin >> jumlah;
    
    if (jumlah <= 0) {
        cout << "Jumlah siswa harus lebih dari 0!" << endl;
        return;
    }
    
    cout << "\n=== INPUT DATA SISWA ===" << endl;
    
    for (int i = 0; i < jumlah; i++) {
        cout << "\nSiswa " << (i + 1) << ":" << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, siswa[i].nama);
        
        cout << "Nilai Mata Kuliah 1: ";
        cin >> siswa[i].nilai1;
        
        cout << "Nilai Mata Kuliah 2: ";
        cin >> siswa[i].nilai2;
        
        cout << "Nilai Mata Kuliah 3: ";
        cin >> siswa[i].nilai3;
        
        hitungRataRata(siswa[i]);
    }
    
    cout << "\nData siswa berhasil diinput!" << endl;
}

void tampilkanTabelNilaiDanRataRata(Siswa siswa[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data siswa yang diinput!" << endl;
        return;
    }
    
    cout << "\n=== TABEL NILAI DAN RATA-RATA ===" << endl;
    cout << "================================================================" << endl;
    cout << "| No |      Nama      | MK-1 | MK-2 | MK-3 | Rata-rata |" << endl;
    cout << "================================================================" << endl;
    
    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(2) << (i + 1) << " ";
        cout << "| " << setw(14) << siswa[i].nama.substr(0, 14) << " ";
        cout << "| " << setw(4) << fixed << setprecision(1) << siswa[i].nilai1 << " ";
        cout << "| " << setw(4) << siswa[i].nilai2 << " ";
        cout << "| " << setw(4) << siswa[i].nilai3 << " ";
        cout << "| " << setw(9) << setprecision(2) << siswa[i].rataRata << " |" << endl;
    }
    cout << "================================================================" << endl;
}

void sortingAscending(Siswa siswa[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data siswa yang diinput!" << endl;
        return;
    }
    
    // Bubble sort untuk ascending
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (siswa[j].rataRata > siswa[j + 1].rataRata) {
                // Tukar posisi
                Siswa temp = siswa[j];
                siswa[j] = siswa[j + 1];
                siswa[j + 1] = temp;
            }
        }
    }
    
    cout << "\n=== SORTING RATA-RATA (ASCENDING) ===" << endl;
    cout << "Data diurutkan dari nilai terendah ke tertinggi:" << endl;
    tampilkanTabelNilaiDanRataRata(siswa, jumlah);
}

void sortingDescending(Siswa siswa[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data siswa yang diinput!" << endl;
        return;
    }
    
    // Bubble sort untuk descending
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (siswa[j].rataRata < siswa[j + 1].rataRata) {
                // Tukar posisi
                Siswa temp = siswa[j];
                siswa[j] = siswa[j + 1];
                siswa[j + 1] = temp;
            }
        }
    }
    
    cout << "\n=== SORTING RATA-RATA (DESCENDING) ===" << endl;
    cout << "Data diurutkan dari nilai tertinggi ke terendah:" << endl;
    tampilkanTabelNilaiDanRataRata(siswa, jumlah);
}

void tampilkanMenu() {
    cout << "\n====== MENU ======" << endl;
    cout << "1. Input Nilai Siswa" << endl;
    cout << "2. Tampilkan Tabel Nilai dan Rata-rata" << endl;
    cout << "3. Sorting Rata-rata (Ascending)" << endl;
    cout << "4. Sorting Rata-rata (Descending)" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    const int MAX_SISWA = 100;
    Siswa siswa[MAX_SISWA];
    int jumlah = 0;
    int pilihan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                inputNilaiSiswa(siswa, jumlah);
                break;
            case 2:
                tampilkanTabelNilaiDanRataRata(siswa, jumlah);
                break;
            case 3:
                sortingAscending(siswa, jumlah);
                break;
            case 4:
                sortingDescending(siswa, jumlah);
                break;
            case 5:
                cout << "\nTerima kasih telah menggunakan program!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan pilih menu 1-5." << endl;
        }
        
        if (pilihan != 5) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 5);
    
    return 0;
}
