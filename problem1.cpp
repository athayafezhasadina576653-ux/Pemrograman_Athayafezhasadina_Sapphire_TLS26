#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    
    // Input N dan K
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    // Sesuai aturan: Nilai K tidak boleh kurang dari 2
    if (K < 2) {
        K = 2;
    }

    // Inisialisasi daftar astronot [1, 2, ..., N]
    vector<int> astronot;
    for (int i = 1; i <= N; ++i) {
        astronot.push_back(i);
    }

    int current_index = 0;
    int step = 1;

    cout << "\n================ URUTAN ELIMINASI ================\n";

    // Simulasi eliminasi hingga tersisa 1 astronot
    while (astronot.size() > 1) {
        // Cari posisi astronot yang dieliminasi pada hitungan ke-K
        current_index = (current_index + K - 1) % astronot.size();
        
        int astronot_dieliminasi = astronot[current_index];
        
        // Hapus astronot dari lingkaran
        astronot.erase(astronot.begin() + current_index);

        // Aturan perubahan nilai K
        if (astronot_dieliminasi % 2 == 0) {
            K += 2; // Jika astronot genap, K + 2
        } else {
            K -= 1; // Jika astronot ganjil, K - 1
        }

        // Aturan batas minimal K = 2
        if (K < 2) {
            K = 2;
        }

        // Cetak detail eliminasi per tahap
        cout << "Eliminasi ke-" << step << ": Astronot " << astronot_dieliminasi 
             << " | Nilai K selanjutnya: " << K << "\n";

        step++;
    }

    cout << "==================================================\n";
    cout << "Astronot terakhir yang tersisa: Astronot " << astronot[0] << "\n";

    return 0;
}