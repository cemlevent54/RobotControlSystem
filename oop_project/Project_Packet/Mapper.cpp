#include "mapper.h"
#include <fstream>
#include <iostream>
#include <cmath>  // Mesafe ve a�� i�lemleri i�in

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Constructor: Mapper nesnesi olu�turulurken grid boyutlar�n� al�r ve bir Map nesnesi olu�turur
Mapper::Mapper(int gridSizeX, int gridSizeY, int startX, int startY)
    : map(gridSizeX, gridSizeY), robotX(startX), robotY(startY) {
    // Ba�lang��ta harita olu�turulmu� olur ve robotun ba�lang�� konumu belirlenir
}

// Lidar verilerini kullanarak haritay� g�ncelle
void Mapper::updateMap(const std::vector<std::pair<int, int>>& lidarData) {
    for (const auto& data : lidarData) {
        int distance = data.first;  // Mesafe
        int angle = data.second;    // A�� (derece cinsinden)

        // D�nya koordinat sistemine d�n���m: Mesafe ve a��dan x, y koordinatlar�n� hesapla
        // Robotun mevcut konumunu (robotX, robotY) dikkate alarak koordinatlar� hesapl�yoruz
        int x = robotX + distance * cos(angle * M_PI / 180);  // A�� radiana �evrilmeli
        int y = robotY + distance * sin(angle * M_PI / 180);

        // Koordinatlar, harita boyutlar� i�inde ge�erli mi diye kontrol et
        if (x >= 0 && x < map.getNumberX() && y >= 0 && y < map.getNumberY()) {
            map.insertPoint(Point(x, y));  // E�er ge�erliyse, bu noktay� i�aretle
        }
    }
}

// Haritay� dosyaya kaydet
void Mapper::recordMap(const std::string& filename) const {
    std::ofstream outFile(filename);  // Dosyay� a�

    if (outFile.is_open()) {
        // Dosyaya harita bilgilerini yaz�yoruz
        for (int i = 0; i < map.getNumberY(); ++i) {
            for (int j = 0; j < map.getNumberX(); ++j) {
                outFile << map.getGrid(j, i) << " ";  // Grid h�cresindeki de�eri yazd�r
            }
            outFile << "\n";  // Sat�r sonu
        }
        outFile.close();  // Dosyay� kapat
    }
    else {
        std::cerr << "Dosya a��l�rken hata olu�tu!" << std::endl;
    }
}

// Haritay� ekranda g�rsel olarak g�ster
void Mapper::showMap() const {
    // Haritay� ekrana yazd�r
    for (int i = 0; i < map.getNumberY(); ++i) {
        for (int j = 0; j < map.getNumberX(); ++j) {
            // Grid h�cresinde dolu olan� 'x', bo� olan� '.' olarak g�ster
            std::cout << (map.getGrid(j, i) == 1 ? "x" : ".") << " ";
        }
        std::cout << std::endl;
    }
}