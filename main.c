/* Basit Hayatta Kalma Simulasyonu (C)
   Komutlar: 
   A = Avlan, S = Siginak ara, E = Envanter, R = Dinlen, F = Tehlike, P = Sifre, X = Cikis
   Not: Deðiþken isimleri Türkçe, ASCII karakter kullanýldý
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int saglik = 80;      // 0-100
int enerji = 80;      // 0-100
int yemek = 1;        // adet
int siginak = 0;      // 0 = yok, 1 = var

// 0-100 arasýnda sýnýrla
int sinirla100(int v) {
    if (v < 0) return 0;
    if (v > 100) return 100;
    return v;
}

// Oyuncu durumunu göster
void durum_goster() {
    printf("\n--- DURUM ---\n");
    printf("Saglik: %d\n", saglik);
    printf("Enerji : %d\n", enerji);
    printf("Yemek  : %d\n", yemek);
    printf("Siginak: %s\n", siginak ? "VAR" : "YOK");
    printf("-------------\n");
}

// A - Avlan
void komut_avlan() {
    printf("\nAvlanma denemesi...\n");
    int maliyet = 15;
    enerji = sinirla100(enerji - maliyet);
    printf("Enerji -%d\n", maliyet);

    int z = rand() % 100;
    if ((enerji > 50 && siginak == 0) || (z < 30)) {
        yemek += 1;
        printf("Basarili: Yemek +1\n");
    } else if ((z >= 30 && z < 55) || (enerji < 20 && saglik > 10)) {
        int zarar = 10 + rand() % 11;
        saglik = sinirla100(saglik - zarar);
        printf("Yaralandin: -%d saglik\n", zarar);
        if (z % 2 == 0) { 
            yemek += 1; 
            printf("Ayni zamanda yemek +1\n"); 
        }
    } else {
        printf("Av basarisiz.\n");
    }
}

// S - Siginak ara
void komut_siginak() {
    printf("\nSiginak aranýyor...\n");

    if (siginak == 1) { 
        printf("Zaten siginak var.\n"); 
        return; 
    }

    int z = rand() % 100;

    if (enerji > 60 && yemek > 0) {
        if (z < 70) { 
            siginak = 1; 
            printf("Siginak bulundu!\n"); 
        } else { 
            printf("Bulunamadi ama yaklastin.\n"); 
        }
    } 
    else if (enerji > 30 || yemek > 0) {
        if (z < 40) { 
            siginak = 1; 
            printf("Siginak bulundu (zor sart).\n"); 
        } else { 
            printf("Siginak yok.\n"); 
        }
    } 
    else {
        if (z < 15) { 
            siginak = 1; 
            printf("Sansliysan siginak buldun!\n"); 
        } else { 
            printf("Enerjin cok dusuk, bulunamadi.\n"); 
        }
    }
}

// E - Envanter
void komut_envanter() {
    printf("\nEnvanter:\nYemek: %d\nSiginak: %s\n", yemek, siginak ? "VAR" : "YOK");
}

// R - Dinlen
void komut_dinlen() {
    printf("\nDinleniyorsun...\n");
    int e_artis = 20;
    int s_artis = 10;
    if (siginak) { e_artis += 10; s_artis += 5; }
    enerji = sinirla100(enerji + e_artis);
    saglik = sinirla100(saglik + s_artis);
    printf("Enerji +%d, Saglik +%d\n", e_artis, s_artis);
}

// F - Tehlike dalgasi
void komut_tehlike() {
    printf("\nTehlike dalgasi!\n");
    int dalga = 3 + rand() % 4; // 3-6
    int i;
    for (i = 1; i <= dalga; i++) {
        printf(" Dalga %d/%d: ", i, dalga);
        int r = rand() % 100;
        if ((enerji > 50 && saglik > 40) || siginak) {
            if (r < 60) { 
                printf("Kacinabildin.\n"); 
                continue; 
            }
        }
        if (r < 40) {
            int d = 5 + rand() % 6;
            saglik = sinirla100(saglik - d);
            printf("Hasar -%d\n", d);
        } else if (r < 75) {
            int e = 5 + rand() % 11;
            enerji = sinirla100(enerji - e);
            printf("Enerji -%d\n", e);
        } else {
            printf("Kactin.\n");
        }
        if (saglik == 0) { 
            printf("Saglik 0 - oyun bitti.\n"); 
            break; 
        }
    }
}

// P - Sifreli gecis (matematik sorusu)
void komut_sifre() {
    int a = rand() % 10 + 1; // 1-10 arasý sayý
    int b = rand() % 10 + 1; // 1-10 arasý sayý
    int dogru = a + b;
    int cevap;
    int deneme = 0;

    printf("\nSifreli gecise calisiyorsun. Dogru sonucu bulmalisin!\n");
    printf("Matematik sorusu: %d + %d = ?\n", a, b);

    do {
        printf("Cevap gir: ");
        if (scanf("%d", &cevap) != 1) { 
            while(getchar() != '\n'); 
            continue; 
        }
        deneme++;
        if (cevap == dogru) {
            printf("Dogru cevap (deneme %d). Odul: Yemek +1, Enerji +10\n", deneme);
            yemek += 1;
            enerji = sinirla100(enerji + 10);
            break;
        } else {
            printf("Yanlis cevap. Tekrar deneyin.\n");
        }
    } while (cevap != dogru);
}

int main() {
    srand((unsigned)time(NULL));
    printf("=== HAYATTA KALMA SIMULASYONU ===\n");
    printf("Komut: A,S,E,R,F,P,X\n");

    char komut;
    do {
        durum_goster();
        printf("\nKomut gir (A/S/E/R/F/P/X): ");
        scanf(" %c", &komut);
        while(getchar() != '\n');
        komut = toupper(komut);

        switch (komut) {
            case 'A': komut_avlan(); break;
            case 'S': komut_siginak(); break;
            case 'E': komut_envanter(); break;
            case 'R': komut_dinlen(); break;
            case 'F': komut_tehlike(); break;
            case 'P': komut_sifre(); break;
            case 'X': printf("Cikis...\n"); break;
            default: printf("Gecersiz komut.\n"); break;
        }

        if (saglik <= 0) { 
            printf("Saglik tukenmis. Simulasyon sonlandi.\n"); 
            break; 
        }

    } while (komut != 'X');

    printf("\nFinal durum:\n");
    durum_goster();
    return 0;
}

