#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <string>

class Record {
private:
    std::fstream file;  // Dosya ak���
    std::string fileName;  // Dosya ad�

public:
    // Constructor: Ba�lang��ta dosya a��lmam�� olur
    Record();

    // Destructor: Nesne silindi�inde dosya kapat�l�r
    ~Record();

    // Dosyay� a�ar
    bool openFile(const std::string& filename, std::ios::openmode mode);

    // Dosyay� kapat�r
    void closeFile();

    // Dosya ad�n� ayarlar
    void setFileName(const std::string& filename);

    // Dosyadan bir sat�r okur (referans parametre kullan�m�)
    bool readLine(std::string& line);

    // Dosyaya bir sat�r yaz
    void writeLine(const std::string& line);

    // Dosyaya yazma i�in << operat�r�
    friend std::fstream& operator<<(std::fstream& os, const Record& record);

    // Dosyadan okuma i�in >> operat�r�
    friend std::fstream& operator>>(std::fstream& is, Record& record);
};

#endif // RECORD_H
