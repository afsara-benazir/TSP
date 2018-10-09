
#include "vector2.hpp"
#include <fstream>      // std::istream & std::ostream
#include <iomanip>      // std::setprecision
#include <utility>      // std::move

// Constructors:
Vector2::Vector2()
:
_x(0.0), _y(0.0)
{
}

Vector2::Vector2(double _x, double _y)
:
_x(_x), _y(_y)
{
}

Vector2::Vector2(const Vector2& other)
:
_x(other._x), _y(other._y)
{
}

Vector2::Vector2(const Vector2&& other) noexcept
:
_x(std::move(other._x)), _y(std::move(other._y))
{
}

// IO:
std::ostream& operator<<(std::ostream& out, const Vector2& vec2)
{
    out << std::fixed << std::setprecision(5) << std::showpos << vec2._x;
    out << ", ";
    out << std::fixed << std::setprecision(5) << std::showpos << vec2._y;

    return out;
}

std::istream& operator>>(std::istream& in, Vector2& vec2)
{
    in >> vec2._x >> vec2._y;

    return in;
}

// Operations:
Vector2& Vector2::operator=(const Vector2& other)
{
    _x = other._x;
    _y = other._y;
    
    return *this;
}

Vector2& Vector2::operator=(const Vector2&& other)
{
    _x = std::move(other._x);
    _y = std::move(other._y);

    return *this;
}

Vector2 operator+(const Vector2& A, const Vector2& B)
{
    double x = A._x + B._x;
    double y = A._y + B._y;

    return Vector2(x, y);
}

Vector2 operator-(const Vector2& A, const Vector2& B)
{
    double x = A._x - B._x;
    double y = A._y - B._y;

    return Vector2(x, y);
}

inline double operator*(const Vector2& A, const Vector2& B)
{
    return A._x * B._x + A._y * B._y;
}

Vector2 operator*(const Vector2& vec2, double lambda)
{
    double x = vec2._x * lambda;
    double y = vec2._y * lambda;

    return Vector2(x, y);
}

Vector2 operator/(const Vector2& vec2, double lambda)
{
    double x = vec2._x / lambda;
    double y = vec2._y / lambda;

    return Vector2(x, y);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
    _x += other._x;
    _y += other._y;
    
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    _x -= other._x;
    _y -= other._y;
    
    return *this;
}

Vector2& Vector2::operator*=(double lambda)
{
    _x *= lambda;
    _y *= lambda;
    
    return *this;
}

Vector2& Vector2::operator/=(double lambda)
{
    _x /= lambda;
    _y /= lambda;
    
    return *this;
}

bool operator< (const Vector2& A, const Vector2& B)
{
    return (A._x < B._x) ||
           (A._x == B._x && A._y < B._y);
}

bool operator> (const Vector2& A, const Vector2& B)
{
    return B < A;
}

bool operator==(const Vector2& A, const Vector2& B)
{
    return !(A < B) && !(B < A);
}

bool operator!=(const Vector2& A, const Vector2& B)
{
    return !(A == B);
}
