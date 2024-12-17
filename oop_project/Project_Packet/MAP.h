#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <iomanip>

// Point yap�s�, (x, y) koordinatlar�n� tutar
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}  // Constructor, x ve y'yi ba�lat�r
};

class Map {
private:
    std::vector<std::vector<int>> grid;  // 2D grid matrisi, harita verileri
    int gridSizeX, gridSizeY;            // Grid boyutlar� (X ve Y)

public:
    // Constructor: Grid boyutlar�n� al�r ve ba�lang��ta t�m h�creleri 0 ile ba�lat�r
    Map(int sizeX = 10, int sizeY = 10);

    // Grid �zerinde belirtilen noktay� i�aretle (x, y)
    void clearMap();  // Haritadaki t�m grid h�crelerini s�f�rlar
    void insertPoint(const Point& point);  // Verilen Point'e kar��l�k gelen h�creyi 1 ile i�aretler
    int getGrid(int x, int y) const;  // Belirtilen x ve y koordinatlar�ndaki grid de�erini d�nd�r�r
    void setGrid(int x, int y, int value);  // Belirtilen x ve y koordinat�ndaki grid h�cresini verilen de�erle de�i�tirir

    // Grid boyutlar�n� almak ve ayarlamak i�in fonksiyonlar
    int getNumberX() const;  // Grid'in X boyutunu d�nd�r�r
    int getNumberY() const;  // Grid'in Y boyutunu d�nd�r�r
    void addGridSize(int deltaX, int deltaY);  // Grid boyutlar�n� b�y�t�r (deltaX, deltaY kadar art�r�r)
    void setGridSize(int sizeX, int sizeY);  // Grid boyutlar�n� belirtilen de�erlere ayarlar

    // Harita bilgilerini yazd�rmak i�in fonksiyonlar
    void printInfo() const;  // Grid boyutlar�n� yazd�r�r
    void showMap() const;  // Grid'i g�rsel olarak ekrana bast�r�r, bo� h�creler '.' dolu h�creler 'x' ile g�sterilir
};

#endif // MAP_H
