#include <iostream>
#include <fstream>
using namespace std;

struct Parkir {
    string plat;
    string jenis;
    int lama;
    int biaya;
};

Parkir dataParkir[100];
int jumlah = 0;

void tambahData() {

    cout << "\n=== Tambah Data Kendaraan ===\n";

    cout << "Plat Nomor : ";
    cin >> dataParkir[jumlah].plat;

    cout << "Jenis Kendaraan (motor/mobil) : ";
    cin >> dataParkir[jumlah].jenis;

    cout << "Lama Parkir (jam) : ";
    cin >> dataParkir[jumlah].lama;

    // Hitung biaya parkir
    if (dataParkir[jumlah].jenis == "motor") {
        dataParkir[jumlah].biaya = dataParkir[jumlah].lama * 3000;
    }
    else {
        dataParkir[jumlah].biaya = dataParkir[jumlah].lama * 5000;
    }

    jumlah++;

    cout << "\nData berhasil ditambahkan sementara!\n";
    cout << "Silakan simpan data ke file.\n";
}

void simpanFile() {

    ofstream file("parkir.txt");

    for (int i = 0; i < jumlah; i++) {

        file << dataParkir[i].plat << " "
             << dataParkir[i].jenis << " "
             << dataParkir[i].lama << " "
             << dataParkir[i].biaya << endl;
    }

    file.close();

    cout << "\nData berhasil disimpan ke file!\n";
}

void tampilData() {

    ifstream file("parkir.txt");

    string plat, jenis;
    int lama, biaya;

    cout << "\n=== Data Kendaraan ===\n";

    bool kosong = true;

    while (file >> plat >> jenis >> lama >> biaya) {

        kosong = false;

        cout << "\nPlat Nomor : " << plat << endl;
        cout << "Jenis      : " << jenis << endl;
        cout << "Lama Parkir: " << lama << " jam\n";
        cout << "Biaya      : Rp " << biaya << endl;
    }

    if (kosong) {
        cout << "Data masih kosong!\n";
    }

    file.close();
}

void cariData() {

    ifstream file("parkir.txt");

    string cari;
    bool ditemukan = false;

    cout << "\nMasukkan Plat Nomor : ";
    cin >> cari;

    string plat, jenis;
    int lama, biaya;

    while (file >> plat >> jenis >> lama >> biaya) {

        if (plat == cari) {

            cout << "\n=== Data Ditemukan ===\n";

            cout << "Plat Nomor : " << plat << endl;
            cout << "Jenis      : " << jenis << endl;
            cout << "Lama Parkir: " << lama << " jam\n";
            cout << "Biaya      : Rp " << biaya << endl;

            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan!\n";
    }

    file.close();
}

void sortingData() {

    int pilihan;

    cout << "\n=== Sorting Data ===\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Pilih : ";
    cin >> pilihan;

    // Bubble Sort
    for (int i = 0; i < jumlah - 1; i++) {

        for (int j = 0; j < jumlah - i - 1; j++) {

            // Ascending
            if (pilihan == 1) {

                if (dataParkir[j].biaya > dataParkir[j + 1].biaya) {

                    Parkir temp = dataParkir[j];
                    dataParkir[j] = dataParkir[j + 1];
                    dataParkir[j + 1] = temp;
                }
            }

            // Descending
            else if (pilihan == 2) {

                if (dataParkir[j].biaya < dataParkir[j + 1].biaya) {

                    Parkir temp = dataParkir[j];
                    dataParkir[j] = dataParkir[j + 1];
                    dataParkir[j + 1] = temp;
                }
            }
        }
    }

    cout << "\nData berhasil diurutkan!\n";
    cout << "Silakan simpan ulang ke file.\n";
}

void hapusFile() {

    ofstream file("parkir.txt");

    file.close();

    cout << "\nData file berhasil dihapus!\n";
}

int main() {
    system("cls");
    int menu;

    do {

        cout << "\n===== SISTEM PARKIR KENDARAAN =====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Data\n";
        cout << "4. Sorting Data\n";
        cout << "5. Simpan ke File\n";
        cout << "6. Hapus Data File\n";
        cout << "7. Keluar\n";
        cout << "Pilih Menu : ";
        cin >> menu;

        switch(menu) {

            case 1:
                tambahData();
                break;

            case 2:
                tampilData();
                break;

            case 3:
                cariData();
                break;

            case 4:
                sortingData();
                break;

            case 5:
                simpanFile();
                break;

            case 6:
                hapusFile();
                break;

            case 7:
                cout << "\nProgram selesai.\n";
                break;

            default:
                cout << "\nMenu tidak tersedia!\n";
        }

    } while(menu != 7);

    return 0;
}
