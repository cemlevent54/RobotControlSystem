#include "RobotOperator.h"
#include <iostream>

// Constructor
RobotOperator::RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode)
    : name(name), surname(surname), accessState(false) {
    this->accessCode = encryptCode(accessCode); // AccessCode þifrelenmiþ olarak saklanýr
}

// Getter metotlarý
std::string RobotOperator::getName() const {
    return name;
}

std::string RobotOperator::getSurname() const {
    return surname;
}

bool RobotOperator::getAccessState() const {
    return accessState;
}

// Kod þifreleme
int RobotOperator::encryptCode(int code) {
    return Encryption::encrypt(code); // Encryption sýnýfýnýn þifreleme metodu çaðrýlýr
}

// Kod çözme
int RobotOperator::decryptCode(int code) {
    return Encryption::decrypt(code); // Encryption sýnýfýnýn çözme metodu çaðrýlýr
}

// Girilen kodu kontrol et
bool RobotOperator::checkAccessCode(int code) {
    if (encryptCode(code) == accessCode) {
        accessState = true;
    }
    else {
        accessState = false;
    }
    return accessState;
}

// Operatör bilgilerini yazdýr
void RobotOperator::print() const {
    std::cout << "Name: " << name << " " << surname << "\n"
        << "Access State: " << (accessState ? "Granted" : "Denied") << std::endl;
}
