#include <iostream>
#include <string>

using namespace std;

struct Nasabah
{
    int nomor;
    string nama;
    int pinjaman;
    Nasabah *prev;
    Nasabah *next;
};

Nasabah *head = nullptr;
Nasabah *tail = nullptr;

void tambahAntrian()
{
    system("cls");
    Nasabah *baru = new Nasabah;
    cout << "Masukkan nomor antrian: ";
    cin >> baru->nomor;
    cin.ignore();
    cout << "Masukkan nama nasabah: ";
    getline(cin, baru->nama);
    baru->pinjaman = 0;
    baru->prev = nullptr;
    baru->next = nullptr;

    if (!head)
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }

    cout << "Nasabah berhasil ditambahkan ke antrian" << endl
         << endl;
}

void tampilkanAntrian()
{
    system("cls");
    if (!head)
    {
        cout << "Antrian kosong" << endl
             << endl;
        return;
    }

    cout << "Daftar Antrian : " << endl;
    Nasabah *curr = head;
    while (curr)
    {
        cout << "Nomor      : " << curr->nomor << endl;
        cout << "Nama       : " << curr->nama << endl;
        cout << "Pinjaman   : " << curr->pinjaman << endl;
        curr = curr->next;
    }
    cout << endl;
}

void layaniNasabah()
{
    system("cls");
    if (!head)
    {
        cout << "Tidak ada nasabah yang bisa dilayani" << endl
             << endl;
        return;
    }

    cout << "Melayani nasabah: " << head->nama << " (Nomor " << head->nomor << ")" << endl;
    cout << "Masukkan jumlah pinjaman: ";
    cin >> head->pinjaman;
    cout << "Pinjaman berhasil dicatat" << endl
         << endl;
}

void hapusAntrian()
{
    system("cls");
    if (!head)
    {
        cout << "Tidak ada nasabah yang bisa dihapus" << endl
             << endl;
        return;
    }

    if (head->pinjaman == 0)
    {
        cout << "Nasabah " << head->nama << " belum mengajukan pinjaman. Tidak bisa dihapus" << endl
             << endl;
        return;
    }

    Nasabah *hapus = head;
    cout << "Menghapus nasabah: " << hapus->nama << " (Nomor " << hapus->nomor << ")" << endl;

    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }

    delete hapus;
    cout << "Nasabah telah dihapus dari antrian" << endl;
}

int main()
{
    system("cls");
    int menu;

    do
    {
        cout << "===== MENU SISTEM PELAYANAN BANK =====" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Tampilkan Antrian" << endl;
        cout << "3. Layani Nasabah" << endl;
        cout << "4. Hapus Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahAntrian();
            break;
        case 2:
            tampilkanAntrian();
            break;
        case 3:
            layaniNasabah();
            break;
        case 4:
            hapusAntrian();
            break;
        case 5:
            cout << "Terima kasih";
            break;
        default:
            cout << "Pilihan tidak valid";
        }
    } while (menu != 5);

    return 0;
}