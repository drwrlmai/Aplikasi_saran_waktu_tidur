#include <stdio.h>

// ini fungsi untuk tampilkan saran waktu tidur
void tampilkanSaranWaktuTidur(int jamBangun, int menitBangun) {
    int durasiTidur = 8; // durasi tidur tetap 8 jam
    int waktuBangunMenit = jamBangun * 60 + menitBangun;
    int totalMenitTidur = durasiTidur * 60; // konversi durasi tidur ke menit
    int waktuTidurMenit = waktuBangunMenit - totalMenitTidur;

    if (waktuTidurMenit < 0) {
        waktuTidurMenit += 1440; // menyesuaikan waktu ke hari sebelumnya
    }

    printf("\n=== Saran Waktu Tidur Ideal ===\n");
    printf("Jika Kamu ingin bangun jam %02d:%02d, sebaiknya tidur pada jam %02d:%02d.\n", 
           jamBangun, menitBangun, waktuTidurMenit / 60, waktuTidurMenit % 60);
    printf("Durasi tidur Kamu akan menjadi %d jam.\n", durasiTidur);
    printf("\nSelamat mencoba tidur yang cukup dan berkualitas!\n");
}

int main() {
    int jamBangun, menitBangun;
    char pilihan;

    do {
        // Tampilkan judul program
        printf("=== Aplikasi Saran Waktu Tidur ===\n");
        printf("Masukkan jam berapa Kamu ingin bangun (0-23): ");

        if (scanf("%d", &jamBangun) != 1) {
            while (getchar() != '\n') {}
            printf("Input tidak valid! Coba masukkan angka antara 0 dan 23.\n\n");
            continue;
        }

        if (jamBangun < 0 || jamBangun > 23) {
            printf("Jam tidak valid. Coba masukkan jam antara 0 dan 23.\n\n");
            continue;
        }

        printf("Masukkan menit berapa Kamu ingin bangun (0-59): ");
        if (scanf("%d", &menitBangun) != 1) {
            while (getchar() != '\n') {}
            printf("Input tidak valid! Coba masukkan angka antara 0 dan 59.\n\n");
            continue;
        }
        if (menitBangun < 0 || menitBangun > 59) {
            printf("Menit tidak valid. Coba masukkan menit antara 0 dan 59.\n\n");
            continue;
        }

        // Menampilkan saran waktu tidur dengan durasi tidur 8 jam
        tampilkanSaranWaktuTidur(jamBangun, menitBangun);

        // Menanyakan pengguna apakah mau coba lagi atau tidak
        printf("Apakah Anda ingin mencoba lagi? (y/n): ");
        while (getchar() != '\n') {} // membersihkan buffer input
        pilihan = getchar();

        // Membuang karakter lain sampai newline
        while (getchar() != '\n') {}

        printf("\n");

    } while (pilihan == 'y' || pilihan == 'Y');

    printf("Terima kasih sudah menggunakan aplikasi saran waktu tidur. Selamat beristirahat semoga harimu menyenangkan!\n");

    return 0;
}