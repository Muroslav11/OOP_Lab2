// Line.h
// заголовний файл — визначення класу
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Line
{
private:
    double first;  // коефіцієнт A (A != 0)
    double second; // коефіцієнт B

public:
    // Конструктори
    Line();
    Line(double, double);
    Line(const Line&);
    ~Line();

    // Методи доступу (сеттери та геттери)
    void SetFirst(double);
    void SetSecond(double);
    double GetFirst() const;
    double GetSecond() const;

    // Спеціальний метод завдання
    double function(double x) const;

    // Перевантаження операцій
    Line& operator=(const Line&);
    operator string() const;

    // Префіксні та постфіксні інкременти/декременти
    Line& operator++();    // префіксний ++ (змінює first)
    Line& operator--();    // префіксний -- (змінює first)
    Line operator++(int);  // постфіксний ++ (змінює second)
    Line operator--(int);  // постфіксний -- (змінює second)

    // Дружні операції введення/виведення
    friend ostream& operator<<(ostream&, const Line&);
    friend istream& operator>>(istream&, Line&);
};

// Функція-фабрика створення об'єкта
Line MakeLine(double a, double b);