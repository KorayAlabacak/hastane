# 🏥 C Dili ile Randevu Takip Sistemi

Bu proje, C programlama dili kullanılarak geliştirilmiş, konsol tabanlı bir **Hasta Randevu ve Kayıt Yönetim Sistemi**dir. Verilerin kalıcılığını sağlamak amacıyla dosya işlemleri (File I/O) kullanılmıştır.

## 🚀 Özellikler

Bu sistem kullanıcıya aşağıdaki temel CRUD (Create, Read, Update, Delete) işlemlerini sunar:

* **Randevu Oluşturma:** Hasta adı, soyadı, TC, telefon ve bölüm bilgileriyle yeni kayıt oluşturma.
    * *Özellik:* TC Kimlik Numarası için 11 hane kontrolü ve mükerrer kayıt kontrolü (aynı TC ile tekrar kayıt engelleme).
* **Randevu Sorgulama:** TC Kimlik Numarası ile hasta bilgilerini görüntüleme.
* **Randevu Düzenleme:** Mevcut bir randevunun tarih, saat, bölüm veya iletişim bilgilerini güncelleme.
* **Randevu Silme:** Kayıtlı bir randevuyu sistemden ve dosyadan kalıcı olarak silme.
* **Veri Kalıcılığı:** Tüm veriler `randevular.txt` dosyasında saklanır. Program kapatılıp açıldığında veriler korunur.

## 🛠️ Kullanılan Teknolojiler ve Yapılar

Proje geliştirilirken C dilinin şu özellikleri kullanılmıştır:

* **Struct Yapıları:** Hasta bilgilerini (Ad, TC, Bölüm vb.) tek bir çatı altında toplamak için `struct` kullanılmıştır.
* **Dosya İşlemleri (File I/O):** `fopen`, `fprintf`, `fscanf`, `fgets` fonksiyonları ile veriler `.txt` dosyasına yazılır ve okunur.
* **Diziler (Arrays):** Kayıtları bellekte tutmak için Struct dizisi kullanılmıştır (Maksimum 100 kayıt kapasitesi).
* **String Manipülasyonu:** `strcpy`, `strcmp`, `strlen` gibi kütüphane fonksiyonları aktif olarak kullanılmıştır.
* **Algoritmalar:**
    * *Doğrusal Arama (Linear Search):* Kayıt bulma işlemleri için.
    * *Kaydırma Algoritması:* Silme işlemi sonrası dizideki boşluğu doldurmak için.
