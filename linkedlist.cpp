#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int pil;
void pilih();
void buat_baru();
void tambah_depan();
void hapus_tengah();
void tampil();
void print();
void cari();
struct node
{
  char nama[20];
  int nim;
  node *next;
  node *prev;
};
node *baru,  *head = NULL,  *tail = NULL,  *hapus,  *bantu,  *bantu2;
int main()
{
  do
  {
    system("cls");
    cout << "INPUT DATA MAHASISWA " << endl;
    cout << "=========================\n";
    cout << "1. Tambah Depan" << endl;
    cout << "2. Hapus tengah" << endl;
    cout << "3. Centak Mundur" << endl;
    cout << "4. Cari Mahasiswa" << endl;
    cout << "5. Exit" << endl;
    cout << "Pilihan : ";
    cin >> pil;
    pilih();
  }
  while (pil != 4);
}

void pilih()
{
  if (pil == 1)
    tambah_depan();
  else if (pil == 2)
    hapus_tengah();
  else if (pil == 3)
    print();
  else if (pil == 4)
    cari();
  else
    cout << "selesai";
}

void buat_baru()
{
  baru = new(node);
  cout << "Nama \t: ";
  cin >> baru->nama;
  cout << "Nim \t: ";
  cin >> baru->nim;
  baru->next = NULL;
  baru->prev = NULL;
}

void tambah_depan()
{
  buat_baru();
  if (head == NULL)
  {
    head = baru;
    tail = baru;
  }
  else
  {
    baru->next = head;
    baru->prev = NULL;
    head->prev = baru;
    head = baru;
  }
  cout << endl << endl;
  tampil();
}


void hapus_tengah()
{
  int sisip;
  cout << "Masukan Posisi Sisip yg anda ingin hapus Anda : ";
  cin >> sisip;
  bantu = head;

  for (int i = 1; i < sisip - 1; i++)
  {
    bantu = bantu->next;
  }
  hapus = bantu->next;
  bantu2 = hapus->next;
  bantu->next = hapus->next;
  delete hapus;
  cout << endl;
  tampil();

}

void cari()
{
  baru = new struct node;
  cout << "Masukan NIM yang dicari";
  cin >> baru->nim;

  bantu = head;
  while (bantu != NULL)
  {
    if (bantu->nim == baru->nim)
    {
      cout << "\nNama\t :" << bantu->nama << endl;
      cout << "NIM\t" << bantu->nim << endl;
      system("pause");

      break;
    } bantu = bantu->next;
  }
  if (bantu == NULL)
    cout << "\nTidak ada, Coba cek lagi datanya" << endl;
}

void tampil()
{
	if (head == NULL)
	{
		cout<<"Kosong\n";
	}

  else
  {
    bantu = head;
    cout<<"==============================================="<<endl;
    cout<<"Belum Dicetak Mundur"<<endl;
    cout<<"==============================================="<<endl;
    cout << " No \t | Nama \t | NIM \t         |" << endl;
    int no = 0;
    while (bantu != NULL)
    {
      no++;
      cout << " " << no << "    \t | ";
      cout << " " << bantu->nama << "      \t | ";
      cout << " " << bantu->nim << "            | " << endl;
      bantu = bantu->next;
    }
  }
  system("pause");
}

void print()
{
	if (tail == NULL)
	{
		cout<<"Kosong\n";
	}

  else
  {
  	bantu = tail;
    cout << " No \t | Nama \t | NIM \t         |" << endl;
    int no = 0;
    while (bantu!= NULL)
    {
      no++;
      cout << " " << no << "    \t | ";
      cout << " " << bantu->nama << "      \t | ";
      cout << " " << bantu->nim << "            | " << endl;
      bantu = bantu->prev;
    }
  }
  system("pause");
}
