#include <iostream>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct angka
{
    int angka1;
    int angka2;
    int total;
    int kartu_tambahan;
};

struct dataAkun
{
    int ID;
    char username[25];
    char noHP[25];
    char email[25];
    int saldo;
    int newSaldo;

    fstream file, file1;
};

int search;

void buatAkun(void);  // declaration of create account function
void depoSaldo(void); // declaration of depoSaldo function
void mainJudi(void);  // declaration of mainJudi function
void infoAkun(void);  // declaration of infoAkun function

void kartu1(int angka1, int angka2, int angka3, int total);
void kartu2(int angka1, int angka2, int total);
bool mainlagi(char ulang, int saldo);
int menang(int kartu_bandar, int kartu_player);
int penentuan(int pemenang, int pilihan, int taruhan);

int main()
{
    system("Color 2F"); // CLI color changer
    srand(time(NULL));  // random number initialization

    char choice;

    cout << "\n\n\n\t\t.......::: BACCARAT GAME :::.......";
    cout << "\n\t\t:: Tekan 1 untuk Login Akun  :: ";
    cout << "\n\t\t:: Tekan 2 untuk Buat Akun ::";
    cout << "\n\t\t:: Tekan 0 untuk Keluar           ::";
    cout << "\n\t\t:: ......................... ::\n\t\t\t\t";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cout << "Masukkan ID Akun kamu :: ";
        cin >> search;
        while (1)
        {

            cout << "\n\n\n\t\t.......::: BACCARAT GAME :::.......";
            cout << "\n\t\t:: Tekan 1 untuk Mulai Bermain  :: ";
            cout << "\n\t\t:: Tekan 2 untuk Deposit Saldo :: ";
            cout << "\n\t\t:: Tekan 3 untuk Cek Info Akun     :: ";
            cout << "\n\t\t:: Tekan 0 untuk Keluar Menu       :: ";
            cout << "\n\t\t:: .......................... ::\n\t\t\t\t";
            cin >> choice;

            switch (choice)
            {
            case '1':
                mainJudi();
                break;
            case '2':
                depoSaldo();
                break;
            case '3':
                infoAkun();
                break;
            case '0':
                return 0;
                break;
            default:
                cout << "Pilihan salah...!";
                break;
            }
            system("pause");
            system("cls");
        }
        break;

    case '2':
        buatAkun();
        break;
    case '0':
        system("exit");
    default:
        cout << "\n Pilihan salah...!";
        break;
    }
    return 0;
}

void kartu1(int angka1, int angka2, int angka3, int total)
{

    cout << "===============================" << endl;
    cout << "Kartu ke - 1 = " << angka1 << endl;
    cout << "Kartu ke - 2 = " << angka2 << endl;
    cout << "Kartu ke - 3 = " << angka3 << endl;
    cout << "===============================" << endl;
    cout << "TOTAL KARTU ADALAH = " << total << endl;
    cout << "===============================" << endl;
}

void kartu2(int angka1, int angka2, int total)
{

    cout << "===============================" << endl;
    cout << "Kartu ke - 1 = " << angka1 << endl;
    cout << "Kartu ke - 2 = " << angka2 << endl;
    cout << "===============================" << endl;
    cout << "TOTAL KARTU  ADALAH = " << total << endl;
    cout << "===============================" << endl;
}

bool mainlagi(char ulang, int saldo)
{
    if (saldo > 0)
    {

        if (ulang == 'Y' || ulang == 'y')
        {

            return true;
        }
        else if (ulang == 'N' || ulang == 'n')
        {

            cout << "THANK YOU FOR PLAYING!";
            return false;
        }
        else
        {

            cout << "SALDO TIDAK MENCUKUPI";
            return false;
        }
    }
}

int menang(int kartu_bandar, int kartu_player)
{
    cout << "=====================================" << endl;
    if (kartu_bandar > kartu_player)
    {

        cout << "\nBANDAR MENANG ";
        return 1;
    }
    else if (kartu_bandar < kartu_player)
    {

        cout << "\nPLAYER MENANG ";
        return 2;
    }
    else if (kartu_bandar == kartu_player)
    {

        cout << "\nDRAW ";
        return 3;
    }
}

int penentuan(int pemenang, int pilihan, int taruhan)
{
    if (pemenang == 2)
    {

        // win pays the bet
        std::cout << "KAMU MENANG\n";
        return taruhan;
    }
    if (pemenang == 3)
    {

        // draw
        std::cout << "DRAW" << std::endl;
        return 0;
    }
    else
    {

        std::cout << "KAMU KALAH LAGII\n";
        taruhan *= -1;
        return taruhan;
    }
}

// Defination of create account function
void buatAkun()
{
    dataAkun acc;
    fstream file;

    srand(time(0));
    acc.ID = rand() * rand() + rand() * rand();

    cout << "Masukkan username :: ";
    cin >> acc.username;

    cout << "Masukkan nomor Handphone :: ";
    cin >> acc.noHP;

    cout << "Masukkan alamat email :: ";
    cin >> acc.email;

    acc.saldo = 10000;

    cout << "Saldo awal :" << acc.saldo << endl;
    cout << " ID Akun kamu :: " << acc.ID;
    cout << "Please save it";

    acc.file.open("data.txt", ios::out | ios::app);
    acc.file << acc.ID << "\t" << acc.username << "\t" << acc.noHP << "\t" << acc.email << "\t" << acc.saldo << endl;
    acc.file.close();
}

// Defination of deposit saldo function
void depoSaldo()
{
    dataAkun acc;
    fstream file, file1;

    cout << "Masukkan jumlah deposit anda :: ";
    cin >> acc.newSaldo;

    file.open("data.txt", ios::in);
    file1.open("data1.txt", ios::out | ios::app);
    file >> acc.ID >> acc.username >> acc.noHP >> acc.email >> acc.saldo;

    while (!file.eof())
    {
        if (acc.ID == search)
        {
            cout << "\nSaldo sebelumnya :: " << acc.saldo;
            acc.saldo = acc.saldo + acc.newSaldo;
            cout << "\nSaldo sekarang :: " << acc.saldo;
            file1 << acc.ID << acc.username << "\t" << acc.noHP << "\t" << acc.email << "\t" << acc.saldo << endl;
        }
        else
        {
            file1 << acc.ID << acc.username << "\t" << acc.noHP << "\t" << acc.email << "\t" << acc.saldo << endl;
        }
        file >> acc.ID >> acc.username >> acc.noHP >> acc.email >> acc.saldo;
    }

    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt", "data.txt");
}

// Defination of wihtdraw saldo function
void mainJudi()
{
    dataAkun acc;
    fstream file, file1;

    int taruhan, pemenang, pilihan, hadiah;
    char ulang;
    bool permainan = true;

    file.open("data.txt", ios::in);
    file1.open("data1.txt", ios::out | ios::app);
    file >> acc.ID >> acc.username >> acc.noHP >> acc.email >> acc.saldo;

    while (!file.eof())
    {
        if (acc.ID == search)
        {
            cout << "\t=========================================" << endl;
            cout << "\t  SELAMAT DATANG DI BACCARAT GAME        " << endl;
            cout << "\t=========================================" << endl;

            // login

            do
            {
                do
                {
                    cout << "PASANG TARUHANMU, RP: ";
                    cin >> taruhan;
                } while (taruhan > acc.saldo);

                char pilihan1;
                angka player;
                player.angka1 = rand() % 10 + 1;
                player.angka2 = rand() % 10 + 1;
                player.total = player.angka1 + player.angka2;
                player.total = player.total % 10;

                // total kartu = 9 (menang)
                if (player.total != 9)
                {
                    cout << "KARTU KE - 1 = " << player.angka1 << endl;
                    cout << "KARTU KE - 2 = " << player.angka2 << endl;
                    cout << "INGIN MENAMBAH KARTU? " << endl;
                    cout << "KETIK 'Y' untuk iya, Ketik 'N' untuk tidak" << endl;
                    cin >> pilihan1;
                    if (pilihan1 == 'Y' || pilihan1 == 'y')
                    {
                        player.kartu_tambahan = rand() % 10 + 1;
                        player.total += player.kartu_tambahan;
                        player.total = player.total % 10;
                        kartu1(player.angka1, player.angka2, player.kartu_tambahan, player.total);
                    }
                    else if (pilihan1 == 'N' || pilihan1 == 'n')
                    {
                        kartu2(player.angka1, player.angka2, player.total);
                    }
                }
                else
                {
                    kartu2(player.angka1, player.angka2, player.total);
                }

                angka bandar;
                bandar.angka1 = rand() % 10 + 1;
                bandar.angka2 = rand() % 10 + 1;
                bandar.total = bandar.angka1 + bandar.angka2;
                bandar.total = bandar.total % 10;

                if (bandar.total != 9)
                {
                    bandar.kartu_tambahan = rand() % 10 + 1;
                    bandar.total += bandar.kartu_tambahan;
                    bandar.total = bandar.total % 10;
                    kartu1(bandar.angka1, bandar.angka2, bandar.kartu_tambahan, bandar.total);
                }
                else
                {
                    kartu2(bandar.angka1, bandar.angka2, bandar.total);
                }

                pemenang = menang(bandar.total, player.total);

                hadiah = penentuan(taruhan, pemenang, pilihan);
                cout << "SELAMAT ANDA MENANG " << hadiah << endl;
                acc.saldo += hadiah;
                cout << "SALDO ANDA MENJADI " << acc.saldo << "\n\n";

                cout << "MAIN LAGI ? (Y/N) " << endl;
                cin >> ulang;
                permainan = mainlagi(ulang, acc.saldo);
            } while (permainan != false);
            cout << "\nSaldo kamu sekarang :: " << acc.saldo;
            file1 << acc.ID << "\t" << acc.username << "\t" << acc.noHP << "\t" << acc.email << "\t" << acc.saldo << endl;
        }
        else
        {
            file1 << acc.ID << "\t" << acc.username << "\t" << acc.noHP << "\t" << acc.email << "\t" << acc.saldo << endl;
        }
        file >> acc.ID >> acc.username >> acc.noHP >> acc.email >> acc.saldo;
    }

    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt", "data.txt");
}

// Defination of check info function
void infoAkun()
{
    dataAkun acc;
    fstream file;

    file.open("data.txt", ios::in);
    if (!file)
    {
        cout << "File opening error !";
    }
    file >> acc.ID >> acc.username >> acc.noHP >> acc.email >> acc.saldo;
    while (!file.eof())
    {
        if (acc.ID == search)
        {
            cout << "\n-------------------\n";
            cout << "\t::: ID Akun ::: ";
            cout << "\t   " << acc.ID << endl;
            cout << "\t::: User Name      ::: ";
            cout << "\t   " << acc.username << "\n";
            cout << "\t::: Nomor Handphone    ::: ";
            cout << "\t   " << acc.noHP << "\n";
            cout << "\t::: Alamat Email  ::: ";
            cout << "\t   " << acc.email << "\n";
            cout << "\t::: Saldo Tersisa ::: ";
            cout << "\t   " << acc.saldo << endl;
            cout << "\n-------------------\n\n";
        }
        file >> acc.ID >> acc.username >> acc.noHP >> acc.email >> acc.saldo;
    }

    file.close();
}
