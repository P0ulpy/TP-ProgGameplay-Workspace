#pragma once

#include <iostream>
#include <vector>
#include <cmath>

namespace TP1
{
    void swap(int& a, int& b)
    {
        (a ^= b), (b ^= a), (a ^= b);
    }

    struct Vector2
    {
        Vector2() = default;
        Vector2(float x, float y) : x(x), y(y) {}

        float x = 0.0f;
        float y = 0.0f;

        Vector2 operator+(const Vector2& b) const { return {x + b.x,y + b.y}; }
        Vector2 operator-(const Vector2& b) const { return {x - b.x,y - b.y }; }
        //Vector2 operator*(const Vector2& b) const { return Vector2(); }
        Vector2 operator*(const float &mult) const { return { x * mult, y * mult }; }
        Vector2 operator/(const float &devider) const { return { x / devider, y / devider }; }
        std::ostream& operator<<(std::ostream& os) const  { return os << "{ x:" << x << ", y:" << y << "}"; }

        Vector2 normalized() const {
            float _magnitude = magnitude();
            if ((double) _magnitude > 9.99999974737875E-06)
                return *this / _magnitude;
            else
                return Vector2::zero();
        }

        float magnitude() const { return (float) std::sqrt((double) x * (double) x + (double) y * (double) y); }
        static float dot(const Vector2& lhs, const Vector2& rhs) { return (float) ((double) lhs.x * (double) rhs.x + (double) lhs.y * (double) rhs.y); }
        static float crossProduct(const Vector2 & a, const Vector2 & b)
        {
            return (a.x * b.y) - (a.y * b.x);
        }
        static Vector2 zero() { return {0, 0}; }
    };

    int main()
    {
        return 0;
    }
}