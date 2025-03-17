#include <iostream>
#include <iomanip>
#include <string>
#include <limits> // Untuk validasi input

using namespace std;

const int MAX_DATA = 100;

int main() {
    string namaInput, nimInput;
    int attempts = 0;

    // Login
    while (attempts < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, namaInput);
        cout << "Masukkan NIM: ";
        getline(cin, nimInput);
        if (namaInput == "Fachlevi Muhammad" && nimInput == "059") {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Login gagal! Coba lagi.\n";
            attempts++;
        }
    }

    if (attempts == 3) {
        cout << "Terlalu banyak percobaan. Program berhenti.\n";
        return 0;
    }

    string pilihan;
    int totalDonasi = 0, totalPenerima = 0;
    string namaDonatur[MAX_DATA], penerimaBantuan[MAX_DATA];
    int jumlahDonasi[MAX_DATA];

    do {
        cout << "\n=== Sistem Manajemen Donasi & Bantuan Sosial ===\n";
        cout << "1. Tambah Donasi\n";
        cout << "2. Tampilkan Data Donasi\n";
        cout << "3. Tambah Penerima Bantuan\n";
        cout << "4. Tampilkan Penerima Bantuan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == "1") {
            // Tambah Donasi
            if (totalDonasi < MAX_DATA) {
                cout << "Masukkan Nama Donatur: ";
                cin >> ws;
                getline(cin, namaDonatur[totalDonasi]);

                bool validInput = false;
                while (!validInput) {
                    cout << "Masukkan Jumlah Donasi: ";
                    cin >> jumlahDonasi[totalDonasi];

                    if (cin.fail()) {
                        cout << "Error! Masukkan angka yang valid.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        validInput = true;
                    }
                }

                totalDonasi++;
                cout << "Donasi berhasil ditambahkan!\n";
            } else {
                cout << "Data donasi penuh!\n";
            }

        } else if (pilihan == "2") {
            // Tampilkan Data Donasi
            cout << "\nDaftar Donasi:\n";
            cout << "+----------------------------------+---------------+\n";
            cout << "| Nama Donatur                     | Jumlah Donasi |\n";
            cout << "+----------------------------------+---------------+\n";
            for (int i = 0; i < totalDonasi; i++) {
                cout << "| " << left << setw(32) << namaDonatur[i] << " | " << right << setw(13) << jumlahDonasi[i] << " |\n";
            }
            cout << "+----------------------------------+---------------+\n";

        } else if (pilihan == "3") {
            // Tambah Penerima Bantuan
            if (totalPenerima < MAX_DATA) {
                cout << "Masukkan Nama Penerima Bantuan: ";
                cin >> ws;
                getline(cin, penerimaBantuan[totalPenerima]);
                totalPenerima++;
                cout << "Penerima bantuan berhasil ditambahkan!\n";
            } else {
                cout << "Data penerima bantuan penuh!\n";
            }

        } else if (pilihan == "4") {
            // Tampilkan Penerima Bantuan
            cout << "\nDaftar Penerima Bantuan:\n";
            cout << "+----------------------------------+\n";
            cout << "| Nama Penerima Bantuan            |\n";
            cout << "+----------------------------------+\n";
            for (int i = 0; i < totalPenerima; i++) {
                cout << "| " << left << setw(32) << penerimaBantuan[i] << " |\n";
            }
            cout << "+----------------------------------+\n";

        } else if (pilihan == "5") {
            cout << "Terima kasih telah menggunakan sistem ini!\n";
        } else {
            cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != "5");

    return 0;
}
