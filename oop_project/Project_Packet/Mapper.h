#ifndef MAPPER_H
#define MAPPER_H

#include "Map.h"
#include <vector>
#include <string>

class Mapper {
private:
    Map map;  // Haritay� tutan Map nesnesi
    int robotX, robotY;  // Robotun X ve Y koordinatlar�

public:
    // Constructor: Mapper nesnesini olu�tururken grid boyutlar�n� ve robotun ba�lang�� konumunu ayarlayabiliriz
    Mapper(int gridSizeX, int gridSizeY, int startX = 0, int startY = 0);

    // Lidar verilerini al�r ve haritay� g�nceller
    void updateMap(const std::vector<std::pair<int, int>>& lidarData);

    // Haritay� dosyaya kaydeder
    void recordMap(const std::string& filename) const;

    // Haritay� ekranda g�rsel olarak g�sterir
    void showMap() const;
};

#endif // MAPPER_H