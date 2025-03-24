#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Donasi {
    string namaPenerima;
    string jenisBantuan;
    int jumlahBantuan;
};

Donasi dataDonasi[100];
int jumlahData = 0;

bool login() {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        cin >> nim;
        cin.ignore();

        if (nama == "Fachlevi Muhammad" && nim == "059") {
            cout << "Login berhasil\n";
            return true;
        } else {
            percobaan++;
            cout << "Login gagal percobaan ke-" << percobaan << " dari 3\n";
        }
    }
    cout << "Anda telah gagal login 3 kali program berhenti\n";
    return false;
}

void tampilkanMenu() {
    cout << "\n=== MENU UTAMA ===\n";
    cout << "1. Tambah Data Donasi\n";
    cout << "2. Tampilkan Data Donasi\n";
    cout << "3. Ubah Data Donasi\n";
    cout << "4. Hapus Data Donasi\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

void tampilkanJenisBantuan() {
    cout << "\n=== JENIS BANTUAN ===\n";
    cout << "1. Makanan\n";
    cout << "2. Pakaian\n";
    cout << "3. Uang Tunai\n";
    cout << "4. Obat-obatan\n";
    cout << "5. Buku\n";
}

void tambahData() {
    if (jumlahData < 100) {
        cin.ignore();
        cout << "Masukkan Nama Penerima: ";
        getline(cin, dataDonasi[jumlahData].namaPenerima);

        int pilihanBantuan;
        tampilkanJenisBantuan();
        cout << "Pilih jenis bantuan (1-5): ";
        while (!(cin >> pilihanBantuan) || pilihanBantuan < 1 || pilihanBantuan > 5) {
            cout << "Input tidak valid, Masukkan angka antara 1 sampai 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihanBantuan) {
            case 1:
                dataDonasi[jumlahData].jenisBantuan = "Makanan";
                break;
            case 2:
                dataDonasi[jumlahData].jenisBantuan = "Pakaian";
                break;
            case 3:
                dataDonasi[jumlahData].jenisBantuan = "Uang Tunai";
                break;
            case 4:
                dataDonasi[jumlahData].jenisBantuan = "Obat obatan";
                break;
            case 5:
                dataDonasi[jumlahData].jenisBantuan = "Buku";
                break;
        }

        cout << "Masukkan Jumlah Bantuan: ";
        while (!(cin >> dataDonasi[jumlahData].jumlahBantuan)) {
            cout << "Input tidak valid, Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        jumlahData++;
        cout << "Data berhasil ditambahkan\n";
    } else {
        cout << "Kapasitas data penuh\n";
    }
}

void tampilkanData() {
    if (jumlahData == 0) {
        cout << "Belum ada data donasi\n";
    } else {
        cout << "\n=== DATA DONASI ===\n";
        for (int i = 0; i < jumlahData; i++) {
            cout << "Data ke-" << i + 1 << ":\n";
            cout << "Nama Penerima: " << dataDonasi[i].namaPenerima << endl;
            cout << "Jenis Bantuan: " << dataDonasi[i].jenisBantuan << endl;
            cout << "Jumlah Bantuan: " << dataDonasi[i].jumlahBantuan << endl;
            cout << "----------------------------\n";
        }
    }
}

void ubahData() {
    int index;
    tampilkanData();
    cout << "Masukkan nomor data yang ingin diubah: ";
    while (!(cin >> index) || index < 1 || index > jumlahData) {
        cout << "Nomor data tidak valid, Masukkan angka antara 1 sampai " << jumlahData << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    cout << "Masukkan Nama Penerima Baru: ";
    getline(cin, dataDonasi[index - 1].namaPenerima);

    int pilihanBantuan;
    tampilkanJenisBantuan();
    cout << "Pilih jenis bantuan (1-5): ";
    while (!(cin >> pilihanBantuan) || pilihanBantuan < 1 || pilihanBantuan > 5) {
        cout << "Input tidak valid, Masukkan angka antara 1 sampai 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (pilihanBantuan) {
        case 1:
            dataDonasi[index - 1].jenisBantuan = "Makanan";
            break;
        case 2:
            dataDonasi[index - 1].jenisBantuan = "Pakaian";
            break;
        case 3:
            dataDonasi[index - 1].jenisBantuan = "Uang Tunai";
            break;
        case 4:
            dataDonasi[index - 1].jenisBantuan = "Obat obatan";
            break;
        case 5:
            dataDonasi[index - 1].jenisBantuan = "Buku";
            break;
    }

    cout << "Masukkan Jumlah Bantuan Baru: ";
    while (!(cin >> dataDonasi[index - 1].jumlahBantuan)) {
        cout << "Input tidak valid, Masukkan angka: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Data berhasil diubah\n";
}

void hapusData() {
    int index;
    tampilkanData();
    cout << "Masukkan nomor data yang ingin dihapus: ";
    while (!(cin >> index) || index < 1 || index > jumlahData) {
        cout << "Nomor data tidak valid, Masukkan angka antara 1 sampai " << jumlahData << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = index - 1; i < jumlahData - 1; i++) {
        dataDonasi[i] = dataDonasi[i + 1];
    }
    jumlahData--;
    cout << "Data berhasil dihapus\n";
}

int main() {
    if (!login()) {
        return 0;
    }

    int pilihan;
    do {
        tampilkanMenu();
        while (!(cin >> pilihan)) {
            cout << "Input tidak valid, Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                ubahData();
                break;
            case 4:
                hapusData();
                break;
            case 5:
                cout << "Terima kasih, Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 5);

    return 0;
}