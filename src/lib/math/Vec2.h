#ifndef VEC2_H
#define VEC2_H

#include <string>

class Vec2 {
public:
    double x;
    double y;
public:
    Vec2();
    Vec2(double x);
    Vec2(double x, double y);

    double length() const;
    Vec2 normalized() const;
    double dot(Vec2 b) const;
    double distance(Vec2 b) const;
    Vec2 reflect(Vec2 normal) const;

    Vec2 copy() const;
    std::string toString() const;
};

Vec2 operator+(const Vec2& a, const Vec2& b);
Vec2 operator-(const Vec2& a, const Vec2& b);
Vec2 operator*(const Vec2& a, const double& b);
Vec2 operator/(const Vec2& a, const double& b);
Vec2 operator*(const double& a, const Vec2& b);
Vec2 operator/(const double& a, const Vec2& b);
void operator+=(Vec2& a, const Vec2& b);
void operator-=(Vec2& a, const Vec2& b);
void operator*=(Vec2& a, const double& b);
void operator/=(Vec2& a, const double& b);
void operator++(Vec2& a);
void operator--(Vec2& a);

#endif
