#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Donasi {
    string namaPenerima;
    string jenisBantuan;
    int jumlahBantuan;
};

void tampilkanJenisBantuan() {
    cout << "\n=== JENIS BANTUAN ===\n";
    cout << "1. Makanan\n";
    cout << "2. Pakaian\n";
    cout << "3. Uang Tunai\n";
    cout << "4. Obat-obatan\n";
    cout << "5. Buku\n";
}

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
    cout << "6. Hitung Total Bantuan\n";
    cout << "Pilih menu: ";
}

void cetakData(const Donasi &data) {
    cout << "Nama Penerima : " << data.namaPenerima << endl;
    cout << "Jenis Bantuan : " << data.jenisBantuan << endl;
    cout << "Jumlah Bantuan: " << data.jumlahBantuan << endl;
    cout << "----------------------------\n";
}

void cetakData(const string &nama) {
    cout << "Data donasi atas nama: " << nama << endl;
}

int hitungTotalBantuan(const Donasi dataDonasi[], int index) {
    if (index == 0) return 0;
    return dataDonasi[index - 1].jumlahBantuan + hitungTotalBantuan(dataDonasi, index - 1);
}

void tambahData(Donasi dataDonasi[], int *jumlahData) {
    if (*jumlahData < 100) {
        cin.ignore();
        cout << "Masukkan Nama Penerima: ";
        getline(cin, dataDonasi[*jumlahData].namaPenerima);

        int pilihanBantuan;
        tampilkanJenisBantuan();
        cout << "Pilih jenis bantuan (1-5): ";
        while (!(cin >> pilihanBantuan) || pilihanBantuan < 1 || pilihanBantuan > 5) {
            cout << "Input tidak valid, Masukkan angka antara 1 sampai 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihanBantuan) {
            case 1: dataDonasi[*jumlahData].jenisBantuan = "Makanan"; break;
            case 2: dataDonasi[*jumlahData].jenisBantuan = "Pakaian"; break;
            case 3: dataDonasi[*jumlahData].jenisBantuan = "Uang Tunai"; break;
            case 4: dataDonasi[*jumlahData].jenisBantuan = "Obat obatan"; break;
            case 5: dataDonasi[*jumlahData].jenisBantuan = "Buku"; break;
        }

        cout << "Masukkan Jumlah Bantuan: ";
        while (!(cin >> dataDonasi[*jumlahData].jumlahBantuan)) {
            cout << "Input tidak valid, Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        (*jumlahData)++;
        cout << "Data berhasil ditambahkan\n";
    } else {
        cout << "Kapasitas data penuh\n";
    }
}

void tampilkanData(const Donasi dataDonasi[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Belum ada data donasi\n";
    } else {
        cout << "\n=== DATA DONASI ===\n";
        for (int i = 0; i < jumlahData; i++) {
            cout << "Data ke-" << i + 1 << ":\n";
            cetakData(dataDonasi[i]);
        }
    }
}

void ubahData(Donasi dataDonasi[], int *jumlahData) {
    int index;
    tampilkanData(dataDonasi, *jumlahData);
    cout << "Masukkan nomor data yang ingin diubah: ";
    while (!(cin >> index) || index < 1 || index > *jumlahData) {
        cout << "Nomor data tidak valid, Masukkan angka antara 1 sampai " << *jumlahData << ": ";
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
        case 1: dataDonasi[index - 1].jenisBantuan = "Makanan"; break;
        case 2: dataDonasi[index - 1].jenisBantuan = "Pakaian"; break;
        case 3: dataDonasi[index - 1].jenisBantuan = "Uang Tunai"; break;
        case 4: dataDonasi[index - 1].jenisBantuan = "Obat obatan"; break;
        case 5: dataDonasi[index - 1].jenisBantuan = "Buku"; break;
    }

    cout << "Masukkan Jumlah Bantuan Baru: ";
    while (!(cin >> dataDonasi[index - 1].jumlahBantuan)) {
        cout << "Input tidak valid, Masukkan angka: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Data berhasil diubah\n";
}

void hapusData(Donasi dataDonasi[], int *jumlahData) {
    int index;
    tampilkanData(dataDonasi, *jumlahData);
    cout << "Masukkan nomor data yang ingin dihapus: ";
    while (!(cin >> index) || index < 1 || index > *jumlahData) {
        cout << "Nomor data tidak valid, Masukkan angka antara 1 sampai " << *jumlahData << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = index - 1; i < *jumlahData - 1; i++) {
        dataDonasi[i] = dataDonasi[i + 1];
    }
    (*jumlahData)--;
    cout << "Data berhasil dihapus\n";
}

int main() {
    Donasi dataDonasi[100];
    int jumlahData = 0;

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
                tambahData(dataDonasi, &jumlahData);
                break;
            case 2:
                tampilkanData(dataDonasi, jumlahData);
                break;
            case 3:
                ubahData(dataDonasi, &jumlahData);
                break;
            case 4:
                hapusData(dataDonasi, &jumlahData);
                break;
            case 5:
                cout << "Terima kasih, Program selesai\n";
                break;
            case 6:
                cout << "Total semua bantuan: " << hitungTotalBantuan(dataDonasi, jumlahData) << endl;
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 5);

    return 0;
}
