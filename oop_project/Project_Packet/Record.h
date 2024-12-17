#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <string>

class Record {
private:
    std::fstream file;  // Dosya akýþý
    std::string fileName;  // Dosya adý

public:
    // Constructor: Baþlangýçta dosya açýlmamýþ olur
    Record();

    // Destructor: Nesne silindiðinde dosya kapatýlýr
    ~Record();

    // Dosyayý açar
    bool openFile(const std::string& filename, std::ios::openmode mode);

    // Dosyayý kapatýr
    void closeFile();

    // Dosya adýný ayarlar
    void setFileName(const std::string& filename);

    // Dosyadan bir satýr okur (referans parametre kullanýmý)
    bool readLine(std::string& line);

    // Dosyaya bir satýr yaz
    void writeLine(const std::string& line);

    // Dosyaya yazma için << operatörü
    friend std::fstream& operator<<(std::fstream& os, const Record& record);

    // Dosyadan okuma için >> operatörü
    friend std::fstream& operator>>(std::fstream& is, Record& record);
};

#endif // RECORD_H
