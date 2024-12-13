#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include "Encryption.h"

class RobotOperator {
private:
    std::string name;      // Operatörün adý
    std::string surname;   // Operatörün soyadý
    unsigned int accessCode; // Þifrelenmiþ eriþim kodu
    bool accessState;      // Eriþim durumu (true: eriþim var, false: eriþim yok)

public:
    // Constructor
    RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode);

    // Getter ve Setter metotlarý
    std::string getName() const;
    std::string getSurname() const;
    bool getAccessState() const;

    // Diðer metotlar
    int encryptCode(int code);      // Kod þifreleme
    int decryptCode(int code);      // Kod çözme
    bool checkAccessCode(int code); // Girilen kodun doðruluðunu kontrol eder
    void print() const;             // Operatör bilgilerini ekrana yazdýrýr
};

#endif // ROBOTOPERATOR_H
