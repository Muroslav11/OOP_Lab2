// Line.cpp
// файл реалізації — реалізація методів класу
#include "Line.h"
#include <sstream>
#include <cmath>

// Конструктор за умовчанням
Line::Line()
{
    SetFirst(1.0);
    SetSecond(0.0);
}

// Конструктор ініціалізації
Line::Line(double a, double b)
{
    SetFirst(a);
    SetSecond(b);
}

// Конструктор копіювання
Line::Line(const Line& r)
{
    first = r.first;
    second = r.second;
}

Line::~Line()
{}

void Line::SetFirst(double a)
{
    if (a != 0)
    {
        first = a;
    }
    else
    {
        cout << "Error: Coefficient A cannot be zero! Setting A = 1.0 by default." << endl;
        first = 1.0;
    }
}

void Line::SetSecond(double b)
{
    second = b;
}

double Line::GetFirst() const
{
    return first;
}

double Line::GetSecond() const
{
    return second;
}

// Обчислення значення функції y = A*x + B
double Line::function(double x) const
{
    return first * x + second;
}

// Операція присвоєння
Line& Line::operator=(const Line& r)
{
    first = r.first;
    second = r.second;
    return *this;
}

// Перетворення в літерний рядок
Line::operator string() const
{
    stringstream ss;
    ss << "Line equation: y = " << first << " * x + " << second << endl;
    return ss.str();
}

// Префіксні операції (модифікують поле first)
Line& Line::operator++()
{
    first++;
    return *this;
}

Line& Line::operator--()
{
    first--;
    return *this;
}

// Постфіксні операції (модифікують поле second)
Line Line::operator++(int)
{
    Line t(*this);
    second++;
    return t;
}

Line Line::operator--(int)
{
    Line t(*this);
    second--;
    return t;
}

// Операції виводу та вводу
ostream& operator<<(ostream& out, const Line& r)
{
    out << string(r);
    return out;
}

istream& operator>>(istream& in, Line& r)
{
    double a, b;
    cout << "A (first != 0) = "; in >> a;
    cout << "B (second)     = "; in >> b;
    cout << endl;
    r.SetFirst(a);
    r.SetSecond(b);
    return in;
}

// Зовнішня функція MakeLine()
Line MakeLine(double a, double b)
{
    if (a == 0)
    {
        cout << "Error in MakeLine: Coefficient A cannot be 0!" << endl;
        exit(1);
    }
    return Line(a, b);
}