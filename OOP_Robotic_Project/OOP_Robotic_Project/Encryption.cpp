#include "Encryption.h"
#include <utility> // std::swap i�in gerekli

// �ifreleme metodu
int Encryption::encrypt(int code) {
    // Her bir rakam� 7 ekleyip 10'a g�re modu al�n�r, ard�ndan 1. ve 3., 2. ve 4. rakam yer de�i�tirir
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = (code % 10 + 7) % 10;
        code /= 10;
    }
    // Yer de�i�tirme
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    // �ifrelenmi� kodu birle�tir
    int encryptedCode = 0;
    for (int i = 0; i < 4; ++i) {
        encryptedCode = encryptedCode * 10 + digits[i];
    }
    return encryptedCode;
}

// �ifre ��zme metodu
int Encryption::decrypt(int code) {
    // 1. ve 3., 2. ve 4. rakam� tekrar yer de�i�tir
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = code % 10;
        code /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    // �ifre ��z�m�: 7 ��kar�p negatifleri pozitif hale getirin
    int decryptedCode = 0;
    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 3) % 10; // 10'dan negatif olmayan bir mod almak i�in 3 eklenir
        decryptedCode = decryptedCode * 10 + digits[i];
    }
    return decryptedCode;
}
