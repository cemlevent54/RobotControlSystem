#include "RobotOperator.h"
#include <iostream>

// Constructor
RobotOperator::RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode)
    : name(name), surname(surname), accessState(false) {
    this->accessCode = encryptCode(accessCode); // AccessCode �ifrelenmi� olarak saklan�r
}

// Getter metotlar�
std::string RobotOperator::getName() const {
    return name;
}

std::string RobotOperator::getSurname() const {
    return surname;
}

bool RobotOperator::getAccessState() const {
    return accessState;
}

// Kod �ifreleme
int RobotOperator::encryptCode(int code) {
    return Encryption::encrypt(code); // Encryption s�n�f�n�n �ifreleme metodu �a�r�l�r
}

// Kod ��zme
int RobotOperator::decryptCode(int code) {
    return Encryption::decrypt(code); // Encryption s�n�f�n�n ��zme metodu �a�r�l�r
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

// Operat�r bilgilerini yazd�r
void RobotOperator::print() const {
    std::cout << "Name: " << name << " " << surname << "\n"
        << "Access State: " << (accessState ? "Granted" : "Denied") << std::endl;
}
