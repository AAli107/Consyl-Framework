#include "Vec2.h"

#include <sstream>
#include <cmath>

Vec2::Vec2() : x(0), y(0) {}

Vec2::Vec2(double x) : x(x), y(x) {}

Vec2::Vec2(double x, double y) : x(x), y(y) {}

double Vec2::length() const { return std::sqrt(x * x + y * y); }

Vec2 Vec2::normalized() const { double len = length(); return len == 0 ? Vec2() : Vec2(x / len, y / len); }

double Vec2::dot(Vec2 b) const { return x * b.x + y * b.y; }

double Vec2::distance(Vec2 b) const { return (*this - b).length(); }

Vec2 Vec2::reflect(Vec2 normal) const { return Vec2(*this - (normal * dot(normal) * 2)); }

Vec2 Vec2::copy() const { return Vec2(x, y); }

std::string Vec2::toString() const
{
    std::ostringstream oss;
    oss << "<" << x << ", " << y << ">";
    return oss.str();
}

Vec2 operator+(const Vec2 &a, const Vec2 &b) { return Vec2(a.x + b.x, a.y + b.y); }

Vec2 operator-(const Vec2 &a, const Vec2 &b) { return Vec2(a.x - b.x, a.y - b.y); }

Vec2 operator*(const Vec2 &a, const double &b) { return Vec2(a.x * b, a.y * b); }

Vec2 operator/(const Vec2 &a, const double &b) { return Vec2(a.x / b, a.y / b); }

Vec2 operator*(const double &a, const Vec2 &b) { return Vec2(a * b.x, a * b.y); }

Vec2 operator/(const double &a, const Vec2 &b) { return Vec2(a / b.x, a / b.y); }

void operator+=(Vec2 &a, const Vec2 &b) { a = Vec2(a.x + b.x, a.y + b.y); }

void operator-=(Vec2 &a, const Vec2 &b) { a = Vec2(a.x - b.x, a.y - b.y); }

void operator*=(Vec2 &a, const double &b) { a = Vec2(a.x * b, a.y * b); }

void operator/=(Vec2 &a, const double &b) { a = Vec2(a.x / b, a.y / b); }

void operator++(Vec2 &a) { a = Vec2(a.x+1, a.y+1); }

void operator--(Vec2 &a) { a = Vec2(a.x-1, a.y-1); }
