#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Randevular {
    char adsoyad[50];
    char tc[12];
    char dogumTarihi[11];
    char telefonNo[16];
    char bolum[50];
    char gun[11];
    char saat[6];
};

struct Randevular randevular[100];
int sayac = 0;
int i;
char dosyaAdi[] = "randevular.txt"; 

void dosyayiKaydet() {
    FILE *fp = fopen(dosyaAdi, "w"); 
    if (fp == NULL) {
        printf("Dosya hatasi!\n");
        return;
    }

    for ( i = 0; i < sayac; i++) {

        fprintf(fp, " tc: %s\n", randevular[i].tc);
        fprintf(fp, "ad soyad: %s\n", randevular[i].adsoyad);
        fprintf(fp, "dogum tarihi: %s\n", randevular[i].dogumTarihi);
        fprintf(fp, "telefon: %s\n", randevular[i].telefonNo);
        fprintf(fp, "bolum: %s\n", randevular[i].bolum);
        fprintf(fp, "gun: %s\n", randevular[i].gun);
        fprintf(fp, "saat: %s\n", randevular[i].saat);
    }
    fclose(fp);
    
}


void dosyayiOku() {
    FILE *fp = fopen(dosyaAdi, "r"); 
    if (fp == NULL) {
        return; 
    }

    sayac = 0; 
    while (sayac < 100) {
        
        if (fscanf(fp, "%s\n", randevular[sayac].tc) == EOF) break;
        
       
        fgets(randevular[sayac].adsoyad, 50, fp);
        randevular[sayac].adsoyad[strcspn(randevular[sayac].adsoyad, "\n")] = 0;

        fscanf(fp, "%s\n", randevular[sayac].dogumTarihi);
        fscanf(fp, "%s\n", randevular[sayac].telefonNo);
        fscanf(fp, "%s\n", randevular[sayac].bolum);
        fscanf(fp, "%s\n", randevular[sayac].gun);
        fscanf(fp, "%s\n", randevular[sayac].saat);

        sayac++;
    }
    fclose(fp);
    printf("--> %d adet kayit dosyadan yuklendi.\n", sayac);
}



void menu() {
    printf("\n-------------------\n");
    printf("A - Randevu olustur\n");
    printf("B - TC ile randevu duzenle\n");
    printf("C - TC ile randevu sorgula\n");
    printf("D - TC ile randevu sil\n");
    printf("Q - Cikis\n");
    printf("Seciminiz: ");
}

void ekle() {
    if (sayac >= 100) {
        printf("Kapasite dolu!\n");
        return;
    }

    char girilentc[12];
    int durum = 1;
    printf("\n--- Randevu Olusturma ---\n");
    printf("Ad Soyad: ");
    getchar();
    fgets(randevular[sayac].adsoyad, 50, stdin);
    randevular[sayac].adsoyad[strcspn(randevular[sayac].adsoyad, "\n")] = 0; 

    while (durum) {
        printf("TC (11 haneli): ");
        scanf("%s", girilentc);
        
        if (strlen(girilentc) == 11) {
        
            int varMi = 0;
            for( i=0; i<sayac; i++) {
                if(strcmp(randevular[i].tc, girilentc) == 0) {
                    varMi = 1; 
                    break;
                }
            }

            if(varMi == 0) {
                strcpy(randevular[sayac].tc, girilentc);
                durum = 0;
            } else {
                printf("Bu TC zaten kayitli!\n");
                return; 
            }
        } else {
            printf("Hata: TC Kimlik numarasi 11 haneli olmalidir.\n");
        }
    }

    printf("Dogum Tarihi (gg/aa/yyyy): ");
    scanf("%s", randevular[sayac].dogumTarihi);

    printf("Telefon No: ");
    scanf("%s", randevular[sayac].telefonNo);

    printf("Bolum: ");
    scanf("%s", randevular[sayac].bolum);

    printf("Randevu Gunu (gg/aa/yyyy): ");
    scanf("%s", randevular[sayac].gun);

    printf("Randevu Saati (ss:dd): ");
    scanf("%s", randevular[sayac].saat);

    sayac++;
    

    dosyayiKaydet();
    
    printf("\nRandevu basariyla olusturuldu ve dosyaya kaydedildi!\n");
}

void tcIleSorgula() {
    char arananTC[12];
    int bulundu = 0;
    int i;
    if (sayac == 0) {
        printf("\nHic randevu yok!\n");
        return;
    }

    printf("\nSorgulanacak TC giriniz: ");
    scanf("%s", arananTC);

    for (i = 0; i < sayac; i++) {
        if (strcmp(randevular[i].tc, arananTC) == 0) {
            printf("\n--- Randevu Bilgileri ---\n");
            printf("Ad Soyad: %s\n", randevular[i].adsoyad);
            printf("TC: %s\n", randevular[i].tc);
            printf("Dogum Tarihi: %s\n", randevular[i].dogumTarihi);
            printf("Telefon: %s\n", randevular[i].telefonNo);
            printf("Bolum: %s\n", randevular[i].bolum);
            printf("Gun: %s\n", randevular[i].gun);
            printf("Saat: %s\n", randevular[i].saat);
            bulundu = 1;
            break;
        }
    }

    if (!bulundu) {
        printf("\nBu TC'ye ait randevu bulunamadi!\n");
    }
}

void tcIleDuzenle() {
    char arananTC[12];
    int bulundu = 0;
    int i;
    if (sayac == 0) {
        printf("\nHic randevu yok!\n");
        return;
    }

    printf("\nDuzenlenecek TC'yi giriniz: ");
    scanf("%s", arananTC);
    for (i = 0; i < sayac; i++) {
        if (strcmp(randevular[i].tc, arananTC) == 0) {
            printf("\n--- Yeni Bilgileri Giriniz ---\n");

            printf("Yeni Telefon No: ");
            scanf("%s", randevular[i].telefonNo);

            printf("Yeni Bolum: ");
            scanf("%s", randevular[i].bolum);

            printf("Yeni Randevu Gunu: ");
            scanf("%s", randevular[i].gun);

            printf("Yeni Randevu Saati: ");
            scanf("%s", randevular[i].saat);


            dosyayiKaydet();

            printf("\nRandevu guncellendi!\n");
            bulundu = 1;
            break;
        }
    }
    if (!bulundu) {
        printf("\nBu TC'ye ait randevu bulunamadi!\n");
    }
}

void tcIleSil() {
    char arananTC[12];
    int bulundu = 0;
    int silinecekIndex = -1;
    int i, j;

    if (sayac == 0) {
        printf("\nHic randevu yok!\n");
        return;
    }

    printf("\nSilinecek TC'yi giriniz: ");
    scanf("%s", arananTC);

    for (i = 0; i < sayac; i++) {
        if (strcmp(randevular[i].tc, arananTC) == 0) {
            silinecekIndex = i;
            bulundu = 1;
            break;
        }
    }

    if (bulundu) {
        for (j = silinecekIndex; j < sayac - 1; j++) {
            randevular[j] = randevular[j + 1];
        }

        sayac--;
        
      
        dosyayiKaydet();
        
        printf("\nRandevu silindi!\n");
    } else {
        printf("\nBu TC'ye ait randevu bulunamadi!\n");
    }
}

int main() {
    char secim;
    

    dosyayiOku();

    while (1) {
        menu();
        scanf(" %c", &secim);

        switch (secim) {
            case 'A': case 'a': ekle(); break;
            case 'B': case 'b': tcIleDuzenle(); break;
            case 'C': case 'c': tcIleSorgula(); break;
            case 'D': case 'd': tcIleSil(); break;
            case 'Q': case 'q':
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Hatali secim!\n");
        }
    }
}
