//
// Created by Flo on 22/04/2022.
//

#ifndef TP_PROGGAMEPLAY_WORKSPACE_POINT_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_POINT_HPP

#include <ostream>
#include <complex>

namespace TP8
{
    namespace Maths
    {
        template<typename T>
        struct Point2D
        {
            Point2D() = default;
            Point2D(T x, T y) : x(x), y(y) {}
            T x, y;

            Point2D operator+(const Point2D<T>& b) const { return {x + b.x,y + b.y}; }
            Point2D operator-(const Point2D<T>& b) const { return {x - b.x,y - b.y }; }
            //std::ostream& operator<<(std::ostream& os) const { return os << "{ x:" << x << ", y:" << y << "}"; }
        };

        template<typename T>
        std::ostream& operator<<(std::ostream& os, const Point2D<T>& point)
        {
            os << "(" << point.x << ", " << point.y << ")";
            return os;
        }

        template<typename T>
        struct Vector2D
        {
            Vector2D() = default;

            Vector2D(T x, T y) : x(x), y(y) {}
            T x, y;


            Vector2D operator+(const Vector2D<T>& b) const { return {x + b.x,y + b.y}; }
            Vector2D operator-(const Vector2D<T>& b) const { return {x - b.x,y - b.y }; }
            Vector2D operator*(const Vector2D<T>& b) const { return crossProduct(*this, b); }
            Vector2D operator*(const T &mult) const { return { x * mult, y * mult }; }
            Vector2D operator/(const T &devider) const { return { x / devider, y / devider }; }
            //std::ostream& operator<<(std::ostream& os) const  { return os << "{ x:" << x << ", y:" << y << "}"; }

            Vector2D<T> normalized() const {
                float _magnitude = magnitude();
                if ((double) _magnitude > 9.99999974737875E-06)
                    return *this / _magnitude;
                else
                    return Vector2D<T>::zero();
            }

            T magnitude() const { return (T) std::sqrt((double) x * (double) x + (double) y * (double) y); }

            static float dot(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { return (float) ((double) lhs.x * (double) rhs.x + (double) lhs.y * (double) rhs.y); }
            static float crossProduct(const Vector2D<T> & a, const Vector2D<T> & b)
            {
                return (a.x * b.y) - (a.y * b.x);
            }
            static Vector2D<T> zero() { return {0, 0}; }
        };

        template<typename T>
        std::ostream& operator<<(std::ostream& os, const Vector2D<T>& vec)
        {
            os << "(" << vec.x << ", " << vec.y << ")";
            return os;
        }
    }
}

#endif //TP_PROGGAMEPLAY_WORKSPACE_POINT_HPP
