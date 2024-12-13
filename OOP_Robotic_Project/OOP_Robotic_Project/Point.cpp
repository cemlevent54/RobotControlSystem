#include "Point.h"

// Varsayýlan constructor
Point::Point() : x(0.0), y(0.0) {}

// Parametreli constructor
Point::Point(double x, double y) : x(x), y(y) {}

// Get metotlarý
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

// Set metotlarý
void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

// getPoint metodu
void Point::getPoint(double& x, double& y) const {
    x = this->x;
    y = this->y;
}

// setPoint metodu
void Point::setPoint(double x, double y) {
    this->x = x;
    this->y = y;
}

// Ýki nokta arasýndaki mesafeyi bulur
double Point::findDistanceTo(const Point& other) const {
    double dx = other.x - this->x;
    double dy = other.y - this->y;
    return std::sqrt(dx * dx + dy * dy);
}

// Ýki nokta arasýndaki açýyý bulur
double Point::findAngleTo(const Point& other) const {
    double dx = other.x - this->x;
    double dy = other.y - this->y;
    return std::atan2(dy, dx); // Açýyý radyan cinsinden döner
}

// operator== metodu
bool Point::operator==(const Point& other) const {
    return (this->x == other.x && this->y == other.y);
}

// operator<< metodu (friend function)
std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}
