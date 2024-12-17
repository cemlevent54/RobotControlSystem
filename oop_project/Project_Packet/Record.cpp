#include "record.h"
#include <iostream>

// Constructor: Dosya ad� bo�, dosya a��lmam�� olarak ba�lar
Record::Record() : fileName("") {}

// Destructor: E�er dosya a��ksa, kapat�l�r
Record::~Record() {
    if (file.is_open()) {
        file.close();
    }
}

// Dosyay� a�ar
bool Record::openFile(const std::string& filename, std::ios::openmode mode) {
    fileName = filename;  // Dosya ad�n� kaydediyoruz
    file.open(fileName, mode);  // Dosyay� a��yoruz
    return file.is_open();      // E�er dosya ba�ar�yla a��ld�ysa true d�nd�r�r
}

// Dosyay� kapat�r
void Record::closeFile() {
    if (file.is_open()) {
        file.close();
    }
}

// Dosya ad�n� ayarlar
void Record::setFileName(const std::string& filename) {
    fileName = filename;
}

// Dosyadan bir sat�r okur
bool Record::readLine(std::string& line) {
    if (file.is_open() && std::getline(file, line)) {
        return true;  // Sat�r ba�ar�yla okundu
    }
    else {
        std::cerr << "Dosya a��lamad� veya okuma i�lemi ba�ar�s�z!" << std::endl;
        return false;
    }
}

// Dosyaya bir sat�r yaz
void Record::writeLine(const std::string& line) {
    if (file.is_open()) {
        file << line << std::endl;  // Sat�r� dosyaya yazar
    }
    else {
        std::cerr << "Dosya a��lamad�, yazma i�lemi yap�lamad�!" << std::endl;
    }
}

// Dosyaya yazma i�in << operat�r�
std::fstream& operator<<(std::fstream& os, const Record& record) {
    if (record.file.is_open()) {
        os << record.file.rdbuf();  // Dosyan�n i�eri�ini ak��a yazar
    }
    return os;
}

// Dosyadan okuma i�in >> operat�r�
std::fstream& operator>>(std::fstream& is, Record& record) {
    if (record.file.is_open()) {
        std::string line;
        if (record.readLine(line)) {
            // E�er sat�r ba�ar�yla okunduysa i�lem yap�labilir
        }
    }
    return is;
}