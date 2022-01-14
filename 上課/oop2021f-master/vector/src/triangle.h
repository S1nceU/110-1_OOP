#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "math_vector.h"
class Triangle
{
public:
    // Constructors are also member functions
    Triangle() {}

    Triangle(const MathVector &u, const MathVector &w, const MathVector &v)
    {
        _u = u;
        _w = w;
        _v = v;
    }

    double perimeter() const
    {
        double a, b, c;
        a = (_u - _w).length();
        b = (_w - _v).length();
        c = (_v - _u).length();
        return a + b + c;
    }

    double area() const
    {
        double a, b, c, s;
        a = (_u - _w).length();
        b = (_w - _v).length();
        c = (_v - _u).length();
        s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

private:
    MathVector _u, _w, _v;
};

#endif