#ifndef MAPPER_H
#define MAPPER_H

#include "Map.h"
#include <vector>
#include <string>

class Mapper {
private:
    Map map;  // Haritayý tutan Map nesnesi
    int robotX, robotY;  // Robotun X ve Y koordinatlarý

public:
    // Constructor: Mapper nesnesini oluþtururken grid boyutlarýný ve robotun baþlangýç konumunu ayarlayabiliriz
    Mapper(int gridSizeX, int gridSizeY, int startX = 0, int startY = 0);

    // Lidar verilerini alýr ve haritayý günceller
    void updateMap(const std::vector<std::pair<int, int>>& lidarData);

    // Haritayý dosyaya kaydeder
    void recordMap(const std::string& filename) const;

    // Haritayý ekranda görsel olarak gösterir
    void showMap() const;
};

#endif // MAPPER_H