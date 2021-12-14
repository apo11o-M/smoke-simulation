#include "Vec2d.hpp"

Vec2d::Vec2d() {
    x = 0;
    y = 0;
}

Vec2d::Vec2d(const Vec2d& vec) {
    x = vec.x;
    y = vec.y;
}

Vec2d::Vec2d(double inputX, double inputY) {
    x = inputX;
    y = inputY;
}

Vec2d::Vec2d(std::vector<double> vec) {
    if (vec.size() == 2) {
        x = vec[0];
        y = vec[1];
    } else {
        std::cerr << "Vector size is not 2, vector size: " << vec.size() << std::endl;
    }
}

Vec2d::Vec2d(std::vector<int> vec) {
    if (vec.size() == 2) {
        x = (double)vec[0];
        y = (double)vec[1];
    } else {
        std::cerr << "Vector size is not 2, vector size: " << vec.size() << std::endl;
    }
}

double Vec2d::length() {
    return std::sqrt(x * x + y * y);
}

double Vec2d::distanceSq(Vec2d& vec) {
    double xLen = vec.x - x;
    double yLen = vec.y - y;
    return (xLen * xLen + yLen * yLen);
}

double Vec2d::dot(Vec2d& vec) {
    return (x * vec.x + y * vec.y);
}

Vec2d Vec2d::normalize() {
    Vec2d result = Vec2d(x, y);
    double length = std::sqrt((x * x) + (y * y));
    return result / length;
}

// TODO: Implement rotation function
Vec2d Vec2d::rotation(double rotX, double rotY) {

}

Vec2d Vec2d::operator+(const Vec2d& vec) {
    Vec2d result = Vec2d(x + vec.x, y + vec.y);
    return result;
}

Vec2d Vec2d::operator-(const Vec2d& vec) {
    Vec2d result = Vec2d(x - vec.x, y - vec.y);
    return result;
}

Vec2d Vec2d::operator*(double val) {
    Vec2d result = Vec2d(x * val, y * val);
    return result;
}

Vec2d Vec2d::operator/(double val) {
    Vec2d result = Vec2d(x * val, y * val);
    return result;
}

void Vec2d::operator=(const Vec2d& vec) {
    x = vec.x;
    y = vec.y;
}

std::ostream& operator<<(std::ostream& os, const Vec2d& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os; 
}