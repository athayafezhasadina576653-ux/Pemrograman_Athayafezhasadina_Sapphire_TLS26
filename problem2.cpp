#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string pesan;
    
    // Meminta input pesan dari user
    std::cout << "Masukkan pesan (contoh: ALIENS): ";
    std::cin >> pesan;
    
    std::string pesan_sandi = "";
    
    if (!pesan.empty()) {
        // Huruf pertama tidak mengalami perubahan
        pesan_sandi += toupper(pesan[0]);
        
        // Proses untuk huruf kedua dan seterusnya
        for (size_t i = 1; i < pesan.length(); ++i) {
            // Ubah ke huruf kapital untuk memastikan akurasi
            char huruf_sekarang = toupper(pesan[i]);
            char huruf_sebelumnya = toupper(pesan[i - 1]); // Menggunakan huruf asli sebelumnya
            
            // Hitung nilai posisi dalam alfabet (A=1, B=2, ..., Z=26)
            int v_curr = huruf_sekarang - 'A' + 1;
            int v_prev = huruf_sebelumnya - 'A' + 1;
            
            // Aturan pergeseran nilai baru
            int v_new = v_curr + v_prev;
            
            // Jika melebihi Z (26), maka perhitungan berputar kembali dari A
            if (v_new > 26) {
                v_new -= 26;
            }
            
            // Kembalikan nilai angka menjadi karakter huruf kembali
            char huruf_baru = 'A' + (v_new - 1);
            pesan_sandi += huruf_baru;
        }
    }
    
    // Menampilkan hasil enkripsi sandi
    std::cout << "Pesan setelah di-sandi: " << pesan_sandi << "\n";
    
    return 0;
}