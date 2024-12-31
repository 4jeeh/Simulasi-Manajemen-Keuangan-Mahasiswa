# Simulasi Manajemen Keuangan Mahasiswa

Tugas UAS Pemrograman Dasar

**Deskripsi**  
Simulasi Manajemen Keuangan Mahasiswa adalah aplikasi berbasis C++ yang membantu mahasiswa dalam mengelola keuangan mereka. Aplikasi ini memungkinkan pengguna untuk mencatat pemasukan dan pengeluaran dalam berbagai kategori, mengelola anggaran bulanan, serta menghasilkan laporan keuangan lengkap. Fitur analisis keuangan yang tersedia akan memberikan wawasan tentang status keuangan mahasiswa, apakah surplus, impas, atau defisit.

## Fitur Utama:
- **Pencatatan Pemasukan & Pengeluaran**  
  Memungkinkan pengguna untuk mencatat pemasukan dan pengeluaran harian dalam kategori yang dapat ditentukan sendiri.
  
- **Perencanaan Anggaran Bulanan**  
  Membantu pengguna merencanakan pengeluaran mereka berdasarkan kategori yang ditentukan, dengan perhitungan persentase terhadap total pengeluaran.

- **Laporan Keuangan**  
  Menampilkan laporan keuangan dalam bentuk tabel yang berisi kategori pengeluaran, jumlah pengeluaran, dan persentase pengeluaran terhadap total.

- **Analisis Keuangan**  
  Memberikan analisis tentang rasio pengeluaran dan sisa pendapatan, serta memberikan rekomendasi sesuai dengan status keuangan (surplus, impas, defisit).

- **Grafik Pengeluaran**  
  Menyajikan grafik ASCII yang menunjukkan proporsi pengeluaran per kategori.

- **Simpan Laporan Keuangan**  
  Menghasilkan laporan keuangan dalam file teks yang dapat disimpan dan dilihat kapan saja.

## Teknologi yang Digunakan:
- **Bahasa Pemrograman:** C++
- **Compiler/IDE:** GCC, Clang, atau Visual Studio
- **File Output:** Laporan disimpan dalam format teks (.txt)

## Instalasi:

### Prasyarat:
Pastikan Anda telah menginstal:
- Compiler C++ (GCC, Clang, atau Visual Studio)

### Langkah-langkah Instalasi:
1. Clone repository ini ke dalam komputer Anda dengan perintah:
    ```bash
    git clone https://github.com/[username]/simulasi-manajemen-keuangan-mahasiswa.git
    ```
2. Masuk ke direktori proyek:
    ```bash
    cd simulasi-manajemen-keuangan-mahasiswa
    ```

3. Kompilasi kode dengan perintah:
    ```bash
    g++ -o keuangan main.cpp
    ```

4. Jalankan aplikasi:
    ```bash
    ./keuangan
    ```

## Contoh Penggunaan:
1. Masukkan pendapatan bulanan Anda.
2. Tentukan kategori pengeluaran yang ingin dicatat (misalnya: Makanan, Transportasi, dll).
3. Masukkan jumlah pengeluaran untuk setiap kategori.
4. Lihat laporan keuangan yang mencakup pengeluaran per kategori, total pengeluaran, dan sisa pendapatan.
5. Lihat grafik pengeluaran dan analisis keuangan yang memberikan wawasan tentang rasio pengeluaran.
6. Simpan laporan keuangan dalam file teks untuk referensi di masa depan.

## Fitur Tambahan:
- **Rekomendasi Keuangan:** Berdasarkan status keuangan Anda (surplus, impas, atau defisit), aplikasi memberikan saran untuk menabung, mengurangi pengeluaran, atau mencari sumber pendapatan tambahan.
