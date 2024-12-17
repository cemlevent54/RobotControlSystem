#include "Map.h"

// Constructor: Verilen boyutlarda bir grid olu�turur ve t�m h�creleri 0 ile ba�lat�r
Map::Map(int sizeX, int sizeY) : gridSizeX(sizeX), gridSizeY(sizeY) {
    // Grid boyutlar�na g�re 2D matris olu�turuyoruz ve her h�creyi ba�lang��ta 0 yap�yoruz
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));
}

// T�m grid h�crelerini s�f�rla
void Map::clearMap() {
    // Grid'in her bir sat�r�n� dola�arak t�m h�creleri s�f�rl�yoruz
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

// Verilen Point nesnesinin kar��l�k geldi�i grid h�cresini 1 ile i�aretle
void Map::insertPoint(const Point& point) {
    // E�er verilen nokta ge�erli bir grid h�cresine denk geliyorsa
    if (point.x >= 0 && point.x < gridSizeX && point.y >= 0 && point.y < gridSizeY) {
        grid[point.y][point.x] = 1;  // Noktay� grid �zerinde i�aretle
    }
}

// Belirtilen (x, y) koordinat�ndaki grid de�erini d�nd�r
int Map::getGrid(int x, int y) const {
    // Ge�erli bir koordinat olup olmad���n� kontrol ediyoruz
    if (x >= 0 && x < gridSizeX && y >= 0 && y < gridSizeY) {
        return grid[y][x];  // E�er ge�erli ise, grid de�erini d�nd�r�yoruz
    }
    return -1;  // Ge�ersiz koordinat ise -1 d�nd�r
}

// Belirtilen (x, y) koordinat�ndaki grid h�cresine yeni bir de�er ata
void Map::setGrid(int x, int y, int value) {
    // E�er verilen (x, y) koordinat� ge�erliyse
    if (x >= 0 && x < gridSizeX && y >= 0 && y < gridSizeY) {
        grid[y][x] = value;  // De�eri grid h�cresine at�yoruz
    }
}

// Grid'in X boyutunu (yani s�tun say�s�n�) d�nd�r
int Map::getNumberX() const {
    return gridSizeX;
}

// Grid'in Y boyutunu (yani sat�r say�s�n�) d�nd�r
int Map::getNumberY() const {
    return gridSizeY;
}

// Grid boyutlar�n� art�r (deltaX, deltaY kadar ekleme yap)
void Map::addGridSize(int deltaX, int deltaY) {
    // Yeni boyutlar� hesaplayarak grid boyutlar�n� b�y�t�yoruz
    gridSizeX += deltaX;
    gridSizeY += deltaY;

    // Yeni sat�rlar� ekle
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));

    // Mevcut sat�rlar� geni�let
    for (auto& row : grid) {
        row.resize(gridSizeX, 0);
    }
}

// Grid boyutlar�n� belirli bir (sizeX, sizeY) boyutuna ayarla
void Map::setGridSize(int sizeX, int sizeY) {
    gridSizeX = sizeX;
    gridSizeY = sizeY;
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));  // Yeni boyutlarda grid olu�tur
}

// Harita bilgilerini (grid boyutlar�n�) yazd�r
void Map::printInfo() const {
    std::cout << "Grid Boyutlar�: " << gridSizeX << "x" << gridSizeY << std::endl;
}

// Grid i�eri�ini g�rsel olarak ekrana yazd�r
void Map::showMap() const {
    // Grid'in her bir sat�r�n� ve h�cresini kontrol ederek yazd�r�yoruz
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell == 0 ? '.' : 'x') << " ";  // Bo� h�cre '.' dolu h�cre 'x'
        }
        std::cout << std::endl;
    }
}