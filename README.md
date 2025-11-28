# Hayatta Kalma Simulasyonu (C)

## Proje Hakkında
Bu proje, **C dili** kullanılarak geliştirilmiş bir **metin tabanlı Hayatta Kalma Simülasyonu**dur. Oyuncu, konsol üzerinden tek karakterli komutlar ile oyunu kontrol eder ve karakterinin sağlık, enerji, yemek ve sığınak durumunu yönetir.  

---

## Komutlar
| Komut | İşlev |
|-------|-------|
| A     | Avlan (enerji azalır, yemek kazanma veya yaralanma ihtimali mantıksal operatörlerle hesaplanır) |
| S     | Sığınak ara (IF-ELSE ile sığınak bulunup bulunmadığı değerlendirilir) |
| E     | Envanteri görüntüle |
| R     | Dinlen (enerji ve sağlık aritmetik operatörlerle artar) |
| F     | Tehlike dalgası simülasyonu (FOR döngüsü ile) |
| P     | Şifreli geçiş (basit matematik sorusu ile DO-WHILE döngüsü kullanılır, doğru cevap ödül verir) |
| X     | Çıkış |

---

## Kullanılan C Yapıları ve Mantığı
- **Switch-Case:** Oyuncu komutlarını yönetmek için kullanıldı.  
- **If-Else:** Durum kontrolleri ve koşullu sonuçlar için kullanıldı.  
- **Aritmetik Operatörler (+, -):** Enerji, sağlık ve yemek miktarını güncellemek için kullanıldı.  
- **Mantıksal Operatörler (&&, ||):** Koşulların birden fazla durumunu değerlendirmek için kullanıldı.  
- **For Döngüsü:** Tehlike dalgası simülasyonu sırasında kullanıldı.  
- **Do-While Döngüsü:** Şifreli geçiş veya matematik sorusu ile doğru cevap girilene kadar tekrar denemeyi sağlamak için kullanıldı.  

---

## Kurulum ve Çalıştırma
1. Kod `main.c` dosyasında yer almaktadır.  
2. Dosyayı **Dev-C++** veya herhangi bir C derleyici ile açın.  
3. Derleyip çalıştırın; konsolda komutları girerek simülasyonu başlatabilirsiniz.  

---

## Örnek Çalışma
- Oyuncu enerji ve sağlık durumunu **`durum_goster()`** ile görebilir.  
- Avlanma ve tehlike dalgası sonucunda sağlık ve enerji değerleri değişir.  
- Matematik sorusunu doğru çözmek ödül kazandırır (yemek ve enerji artışı).  

---

