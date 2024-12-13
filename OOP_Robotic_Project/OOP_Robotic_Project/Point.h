#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
private:
    double x; // x koordinatý
    double y; // y koordinatý

public:
    // Constructor'lar
    Point(); // Varsayýlan constructor
    Point(double x, double y); // Parametreli constructor

    // Get ve Set metotlarý
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);

    // Diðer metotlar
    void getPoint(double& x, double& y) const;
    void setPoint(double x, double y);
    double findDistanceTo(const Point& other) const;
    double findAngleTo(const Point& other) const;

    // Operatör aþýrý yükleme
    bool operator==(const Point& other) const;
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

#endif // POINT_H
