#include "Encryption.h"
#include <utility> // std::swap için gerekli

// Þifreleme metodu
int Encryption::encrypt(int code) {
    // Her bir rakamý 7 ekleyip 10'a göre modu alýnýr, ardýndan 1. ve 3., 2. ve 4. rakam yer deðiþtirir
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = (code % 10 + 7) % 10;
        code /= 10;
    }
    // Yer deðiþtirme
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    // Þifrelenmiþ kodu birleþtir
    int encryptedCode = 0;
    for (int i = 0; i < 4; ++i) {
        encryptedCode = encryptedCode * 10 + digits[i];
    }
    return encryptedCode;
}

// Þifre çözme metodu
int Encryption::decrypt(int code) {
    // 1. ve 3., 2. ve 4. rakamý tekrar yer deðiþtir
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = code % 10;
        code /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    // Þifre çözümü: 7 çýkarýp negatifleri pozitif hale getirin
    int decryptedCode = 0;
    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 3) % 10; // 10'dan negatif olmayan bir mod almak için 3 eklenir
        decryptedCode = decryptedCode * 10 + digits[i];
    }
    return decryptedCode;
}
