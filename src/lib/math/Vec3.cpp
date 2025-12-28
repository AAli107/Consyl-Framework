#include "Vec3.h"

#include <sstream>
#include <cmath>

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(double x) : x(x), y(x), z(x) {}

Vec3::Vec3(double x, double y) : x(x), y(y), z(0) {}

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

Vec3::Vec3(Vec2 v) : x(v.x), y(v.y), z(0)  {}

Vec3::Vec3(Vec2 v, double z) : x(v.x), y(v.y), z(z)  {}

double Vec3::length() const { return std::sqrt(x * x + y * y + z * z); }

Vec3 Vec3::normalized() const { double len = length(); return len == 0 ? Vec3() : Vec3(x / len, y / len, z / len); }

double Vec3::dot(Vec3 b) const { return x * b.x + y * b.y + z * b.z; }

double Vec3::distance(Vec3 b) const { return (*this - b).length(); }

Vec3 Vec3::reflect(Vec3 normal) const { return Vec3(*this - (normal * dot(normal) * 2)); }

Vec3 Vec3::cross(const Vec3 &b)
{ return Vec3( y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x ); }

Vec3 Vec3::copy() const { return Vec3(x, y, z); }

std::string Vec3::toString() const
{
    std::ostringstream oss;
    oss << "<" << x << ", " << y  << ", " << z << ">";
    return oss.str();
}

Vec3::operator Vec2() { return Vec2(x, y); }

Vec3 operator+(const Vec3 &a, const Vec3 &b) { return Vec3(a.x + b.x, a.y + b.y, a.z + b.z); }

Vec3 operator-(const Vec3 &a, const Vec3 &b) { return Vec3(a.x - b.x, a.y - b.y, a.z - b.z); }

Vec3 operator*(const Vec3 &a, const double &b) { return Vec3(a.x * b, a.y * b, a.z * b); }

Vec3 operator/(const Vec3 &a, const double &b) { return Vec3(a.x / b, a.y / b, a.z / b); }

Vec3 operator*(const double &a, const Vec3 &b) { return Vec3(a * b.x, a * b.y, a * b.z); }

Vec3 operator/(const double &a, const Vec3 &b) { return Vec3(a / b.x, a / b.y, a / b.z); }

void operator+=(Vec3 &a, const Vec3 &b) { a = Vec3(a.x + b.x, a.y + b.y, a.z + b.z); }

void operator-=(Vec3 &a, const Vec3 &b) { a = Vec3(a.x - b.x, a.y - b.y, a.z - b.z); }

void operator*=(Vec3 &a, const double &b) { a = Vec3(a.x * b, a.y * b, a.z * b); }

void operator/=(Vec3 &a, const double &b) { a = Vec3(a.x / b, a.y / b, a.z / b); }

void operator++(Vec3 &a) { a = Vec3(a.x+1, a.y+1, a.z+1); }

void operator--(Vec3 &a) { a = Vec3(a.x-1, a.y-1, a.z-1); }
