#include "Map.h"

// Constructor: Verilen boyutlarda bir grid oluþturur ve tüm hücreleri 0 ile baþlatýr
Map::Map(int sizeX, int sizeY) : gridSizeX(sizeX), gridSizeY(sizeY) {
    // Grid boyutlarýna göre 2D matris oluþturuyoruz ve her hücreyi baþlangýçta 0 yapýyoruz
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));
}

// Tüm grid hücrelerini sýfýrla
void Map::clearMap() {
    // Grid'in her bir satýrýný dolaþarak tüm hücreleri sýfýrlýyoruz
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

// Verilen Point nesnesinin karþýlýk geldiði grid hücresini 1 ile iþaretle
void Map::insertPoint(const Point& point) {
    // Eðer verilen nokta geçerli bir grid hücresine denk geliyorsa
    if (point.x >= 0 && point.x < gridSizeX && point.y >= 0 && point.y < gridSizeY) {
        grid[point.y][point.x] = 1;  // Noktayý grid üzerinde iþaretle
    }
}

// Belirtilen (x, y) koordinatýndaki grid deðerini döndür
int Map::getGrid(int x, int y) const {
    // Geçerli bir koordinat olup olmadýðýný kontrol ediyoruz
    if (x >= 0 && x < gridSizeX && y >= 0 && y < gridSizeY) {
        return grid[y][x];  // Eðer geçerli ise, grid deðerini döndürüyoruz
    }
    return -1;  // Geçersiz koordinat ise -1 döndür
}

// Belirtilen (x, y) koordinatýndaki grid hücresine yeni bir deðer ata
void Map::setGrid(int x, int y, int value) {
    // Eðer verilen (x, y) koordinatý geçerliyse
    if (x >= 0 && x < gridSizeX && y >= 0 && y < gridSizeY) {
        grid[y][x] = value;  // Deðeri grid hücresine atýyoruz
    }
}

// Grid'in X boyutunu (yani sütun sayýsýný) döndür
int Map::getNumberX() const {
    return gridSizeX;
}

// Grid'in Y boyutunu (yani satýr sayýsýný) döndür
int Map::getNumberY() const {
    return gridSizeY;
}

// Grid boyutlarýný artýr (deltaX, deltaY kadar ekleme yap)
void Map::addGridSize(int deltaX, int deltaY) {
    // Yeni boyutlarý hesaplayarak grid boyutlarýný büyütüyoruz
    gridSizeX += deltaX;
    gridSizeY += deltaY;

    // Yeni satýrlarý ekle
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));

    // Mevcut satýrlarý geniþlet
    for (auto& row : grid) {
        row.resize(gridSizeX, 0);
    }
}

// Grid boyutlarýný belirli bir (sizeX, sizeY) boyutuna ayarla
void Map::setGridSize(int sizeX, int sizeY) {
    gridSizeX = sizeX;
    gridSizeY = sizeY;
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));  // Yeni boyutlarda grid oluþtur
}

// Harita bilgilerini (grid boyutlarýný) yazdýr
void Map::printInfo() const {
    std::cout << "Grid Boyutlarý: " << gridSizeX << "x" << gridSizeY << std::endl;
}

// Grid içeriðini görsel olarak ekrana yazdýr
void Map::showMap() const {
    // Grid'in her bir satýrýný ve hücresini kontrol ederek yazdýrýyoruz
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell == 0 ? '.' : 'x') << " ";  // Boþ hücre '.' dolu hücre 'x'
        }
        std::cout << std::endl;
    }
}