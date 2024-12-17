#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <iomanip>

// Point yapýsý, (x, y) koordinatlarýný tutar
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}  // Constructor, x ve y'yi baþlatýr
};

class Map {
private:
    std::vector<std::vector<int>> grid;  // 2D grid matrisi, harita verileri
    int gridSizeX, gridSizeY;            // Grid boyutlarý (X ve Y)

public:
    // Constructor: Grid boyutlarýný alýr ve baþlangýçta tüm hücreleri 0 ile baþlatýr
    Map(int sizeX = 10, int sizeY = 10);

    // Grid üzerinde belirtilen noktayý iþaretle (x, y)
    void clearMap();  // Haritadaki tüm grid hücrelerini sýfýrlar
    void insertPoint(const Point& point);  // Verilen Point'e karþýlýk gelen hücreyi 1 ile iþaretler
    int getGrid(int x, int y) const;  // Belirtilen x ve y koordinatlarýndaki grid deðerini döndürür
    void setGrid(int x, int y, int value);  // Belirtilen x ve y koordinatýndaki grid hücresini verilen deðerle deðiþtirir

    // Grid boyutlarýný almak ve ayarlamak için fonksiyonlar
    int getNumberX() const;  // Grid'in X boyutunu döndürür
    int getNumberY() const;  // Grid'in Y boyutunu döndürür
    void addGridSize(int deltaX, int deltaY);  // Grid boyutlarýný büyütür (deltaX, deltaY kadar artýrýr)
    void setGridSize(int sizeX, int sizeY);  // Grid boyutlarýný belirtilen deðerlere ayarlar

    // Harita bilgilerini yazdýrmak için fonksiyonlar
    void printInfo() const;  // Grid boyutlarýný yazdýrýr
    void showMap() const;  // Grid'i görsel olarak ekrana bastýrýr, boþ hücreler '.' dolu hücreler 'x' ile gösterilir
};

#endif // MAP_H
