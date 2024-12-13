#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include "Encryption.h"

class RobotOperator {
private:
    std::string name;      // Operat�r�n ad�
    std::string surname;   // Operat�r�n soyad�
    unsigned int accessCode; // �ifrelenmi� eri�im kodu
    bool accessState;      // Eri�im durumu (true: eri�im var, false: eri�im yok)

public:
    // Constructor
    RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode);

    // Getter ve Setter metotlar�
    std::string getName() const;
    std::string getSurname() const;
    bool getAccessState() const;

    // Di�er metotlar
    int encryptCode(int code);      // Kod �ifreleme
    int decryptCode(int code);      // Kod ��zme
    bool checkAccessCode(int code); // Girilen kodun do�rulu�unu kontrol eder
    void print() const;             // Operat�r bilgilerini ekrana yazd�r�r
};

#endif // ROBOTOPERATOR_H
