# Aplikasi Pencatat Keuangan Pribadi (Personal Expense Tracker)

Aplikasi pencatat keuangan pribadi berbasis bahasa C yang mendukung penyimpanan data secara permanen menggunakan berkas biner (`.bin`) serta fitur ekspor laporan ke format CSV (`.csv`).

## Anggota Team:
1. Zian Hafiz
2. M. Farhan Alfarisi
3. Jessica Nabila Dalimunte
4. Inaya Dzil Izzati
5. Niswatus Syaqila Zainal

## Struktur Direktori

Pastikan susunan folder proyek tetap terjaga seperti berikut agar jalur pembacaan dan penyimpanan berkas berjalan dengan benar:

```text
├── data/
│   ├── keuangan.bin          # Basis data utama (otomatis dibuat saat menambah data)
│   └── laporan_bulanan.csv   # Hasil ekspor laporan keuangan
├── include/
│   └── fungsi.h              # Deklarasi struct dan prototipe fungsi
└── src/
    ├── main.c                # Program utama (Menu Interaktif & CLI)
    └── fungsi.c              # Implementasi seluruh fungsi aplikasi
```

## Cara Kompilasi

1. Buka terminal dan arahkan direktori kerja ke dalam folder `src/`:
   ```bash
   cd src
   ```

2. Kompilasi kode sumber menggunakan `gcc`:
   ```bash
   gcc main.c fungsi.c -o program
   ```

## Cara Menjalankan Program

> **Catatan Penting:** Selalu jalankan perintah dari dalam folder `src/` karena aplikasi menggunakan jalur relatif (`../data/`) untuk mengakses berkas penyimpanan dan laporan. Pastikan folder `data/` sudah tersedia.

### 1. Mode Menu Interaktif

Jalankan program tanpa argumen tambahan untuk masuk ke tampilan menu utama:
```bash
./program
```

Daftar fitur yang tersedia pada menu:
* **1. Tambah Catatan:** Mencatat transaksi baru (`Pemasukan` atau `Pengeluaran`), kategori, dan nominal (`> 0`). Tanggal tercatat otomatis sesuai tanggal sistem.
* **2. Tampilkan Catatan:** Menampilkan seluruh daftar transaksi yang tersimpan dalam bentuk tabel.
* **3. Ubah Nominal Catatan:** Memperbarui nominal transaksi berdasarkan nomor `ID`.
* **4. Hapus Catatan:** Menghapus transaksi tertentu berdasarkan nomor `ID`.
* **5. Lihat Ringkasan Keuangan:** Menampilkan total pemasukan, total pengeluaran, dan saldo akhir.
* **6. Ekspor Laporan CSV:** Menyimpan seluruh tabel transaksi beserta ringkasan saldo ke `../data/laporan_bulanan.csv`.
* **0. Keluar:** Menutup aplikasi.

### 2. Mode Perintah Langsung (CLI)

Kamu juga dapat menjalankan fitur tertentu secara langsung lewat argumen terminal:

* **Menampilkan Panduan Bantuan:**
  ```bash
  ./program --help
  ```

* **Menambah Catatan Baru:**
  Format: `./program --tambah <Pemasukan|Pengeluaran> <Kategori> <Nominal>`
  ```bash
  ./program --tambah Pengeluaran Makan 25000
  ./program --tambah pemasukan Bonus 50000
  ```

* **Mengekspor Laporan ke CSV:**
  ```bash
  ./program --laporan
  ```

## Pembagian Modul

* **Program Utama, Menu Interaktif, Validasi & Integrasi CLI (`main.c`):** Zian Hafiz
* **Manajemen Data (CRUD):** M. Farhan Alfarisi
* **Ringkasan & Ekspor CSV:** Jessica Nabila Dalimunte
* **Panduan Bantuan (CLI):** Inaya Dzil Izzati
* **Penyimpanan Berkas Biner:** Niswatus Syaqila Zainal
