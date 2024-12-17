#include "mapper.h"
#include <fstream>
#include <iostream>
#include <cmath>  // Mesafe ve açý iþlemleri için

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Constructor: Mapper nesnesi oluþturulurken grid boyutlarýný alýr ve bir Map nesnesi oluþturur
Mapper::Mapper(int gridSizeX, int gridSizeY, int startX, int startY)
    : map(gridSizeX, gridSizeY), robotX(startX), robotY(startY) {
    // Baþlangýçta harita oluþturulmuþ olur ve robotun baþlangýç konumu belirlenir
}

// Lidar verilerini kullanarak haritayý güncelle
void Mapper::updateMap(const std::vector<std::pair<int, int>>& lidarData) {
    for (const auto& data : lidarData) {
        int distance = data.first;  // Mesafe
        int angle = data.second;    // Açý (derece cinsinden)

        // Dünya koordinat sistemine dönüþüm: Mesafe ve açýdan x, y koordinatlarýný hesapla
        // Robotun mevcut konumunu (robotX, robotY) dikkate alarak koordinatlarý hesaplýyoruz
        int x = robotX + distance * cos(angle * M_PI / 180);  // Açý radiana çevrilmeli
        int y = robotY + distance * sin(angle * M_PI / 180);

        // Koordinatlar, harita boyutlarý içinde geçerli mi diye kontrol et
        if (x >= 0 && x < map.getNumberX() && y >= 0 && y < map.getNumberY()) {
            map.insertPoint(Point(x, y));  // Eðer geçerliyse, bu noktayý iþaretle
        }
    }
}

// Haritayý dosyaya kaydet
void Mapper::recordMap(const std::string& filename) const {
    std::ofstream outFile(filename);  // Dosyayý aç

    if (outFile.is_open()) {
        // Dosyaya harita bilgilerini yazýyoruz
        for (int i = 0; i < map.getNumberY(); ++i) {
            for (int j = 0; j < map.getNumberX(); ++j) {
                outFile << map.getGrid(j, i) << " ";  // Grid hücresindeki deðeri yazdýr
            }
            outFile << "\n";  // Satýr sonu
        }
        outFile.close();  // Dosyayý kapat
    }
    else {
        std::cerr << "Dosya açýlýrken hata oluþtu!" << std::endl;
    }
}

// Haritayý ekranda görsel olarak göster
void Mapper::showMap() const {
    // Haritayý ekrana yazdýr
    for (int i = 0; i < map.getNumberY(); ++i) {
        for (int j = 0; j < map.getNumberX(); ++j) {
            // Grid hücresinde dolu olaný 'x', boþ olaný '.' olarak göster
            std::cout << (map.getGrid(j, i) == 1 ? "x" : ".") << " ";
        }
        std::cout << std::endl;
    }
}