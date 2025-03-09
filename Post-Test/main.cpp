#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int pin = 2025;
    int inputPin, attempts = 0;
    long long saldo = 1000000;
    int pilihan;
    
    while (attempts < 3) {
        cout << "Masukkan PIN: ";
        cin >> inputPin;
        
        if (inputPin == pin) {
            cout << "login berhasil!\n";
            break;
        } else {
            cout << "PIN salah Coba lagi\n";
            attempts++;
        }
    }
    
    if (attempts == 3) {
        cout << "Terlalu banyak percobaan. Akun diblokir\n";
        return 0;
    }
    
    do {
        cout << "\nMENU ATM\n";
        cout << "1.Setor Tunai\n";
        cout << "2.Cek saldo\n";
        cout << "3.Tarik Tunai\n";
        cout << "4.Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                long long setor;
                cout << "Masukkan jumlah setor tunai: ";
                cin >> setor;
                saldo += setor;
                cout << "Setor tunai berhasil! Saldo sekarang: Rp " << saldo << "\n";
                break;
            }
            case 2:
                cout << "Saldo Anda saat ini: rp " << saldo << "\n";
                break;
            case 3: {
                long long tarik;
                cout << "Masukkan jumlah tarik tunai: ";
                cin >> tarik;
                
                if (tarik > saldo) {
                    cout << "Saldo tidak mencukupi\n";
                } else {
                    saldo -= tarik;
                    cout << "Tarik tunai berhasil Saldo sekarang: rp " << saldo << "\n";
                }
                break;
            }
            case 4:
                cout << "Terima kasih telah menggunakan ATM ini :]\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 4);
    
    return 0;
}
