#include "record.h"
#include <iostream>

// Constructor: Dosya adý boþ, dosya açýlmamýþ olarak baþlar
Record::Record() : fileName("") {}

// Destructor: Eðer dosya açýksa, kapatýlýr
Record::~Record() {
    if (file.is_open()) {
        file.close();
    }
}

// Dosyayý açar
bool Record::openFile(const std::string& filename, std::ios::openmode mode) {
    fileName = filename;  // Dosya adýný kaydediyoruz
    file.open(fileName, mode);  // Dosyayý açýyoruz
    return file.is_open();      // Eðer dosya baþarýyla açýldýysa true döndürür
}

// Dosyayý kapatýr
void Record::closeFile() {
    if (file.is_open()) {
        file.close();
    }
}

// Dosya adýný ayarlar
void Record::setFileName(const std::string& filename) {
    fileName = filename;
}

// Dosyadan bir satýr okur
bool Record::readLine(std::string& line) {
    if (file.is_open() && std::getline(file, line)) {
        return true;  // Satýr baþarýyla okundu
    }
    else {
        std::cerr << "Dosya açýlamadý veya okuma iþlemi baþarýsýz!" << std::endl;
        return false;
    }
}

// Dosyaya bir satýr yaz
void Record::writeLine(const std::string& line) {
    if (file.is_open()) {
        file << line << std::endl;  // Satýrý dosyaya yazar
    }
    else {
        std::cerr << "Dosya açýlamadý, yazma iþlemi yapýlamadý!" << std::endl;
    }
}

// Dosyaya yazma için << operatörü
std::fstream& operator<<(std::fstream& os, const Record& record) {
    if (record.file.is_open()) {
        os << record.file.rdbuf();  // Dosyanýn içeriðini akýþa yazar
    }
    return os;
}

// Dosyadan okuma için >> operatörü
std::fstream& operator>>(std::fstream& is, Record& record) {
    if (record.file.is_open()) {
        std::string line;
        if (record.readLine(line)) {
            // Eðer satýr baþarýyla okunduysa iþlem yapýlabilir
        }
    }
    return is;
}