#ifndef VEC3_H
#define VEC3_H

#include <string>

class Vec3 {
public:
    double x;
    double y;
    double z;
public:
    Vec3();
    Vec3(double x);
    Vec3(double x, double y);
    Vec3(double x, double y, double z);

    double length() const;
    Vec3 normalized() const;
    double dot(Vec3 b) const;
    double distance(Vec3 b) const;
    Vec3 reflect(Vec3 normal) const;

    Vec3 copy() const;
    std::string toString() const;
};

Vec3 operator+(const Vec3& a, const Vec3& b);
Vec3 operator-(const Vec3& a, const Vec3& b);
Vec3 operator*(const Vec3& a, const double& b);
Vec3 operator/(const Vec3& a, const double& b);
Vec3 operator*(const double& a, const Vec3& b);
Vec3 operator/(const double& a, const Vec3& b);
void operator+=(Vec3& a, const Vec3& b);
void operator-=(Vec3& a, const Vec3& b);
void operator*=(Vec3& a, const double& b);
void operator/=(Vec3& a, const double& b);
void operator++(Vec3& a);
void operator--(Vec3& a);

#endif
