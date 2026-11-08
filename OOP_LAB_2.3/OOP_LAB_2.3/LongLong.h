#pragma once
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class LongLong
{
private:
    long highPart;
    long lowPart;

    long long ToLongLong() const;
    void FromLongLong(long long value);

public:
    // Методи доступу
    long GetHighPart() const;
    long GetLowPart() const;

    bool SetHighPart(long value);
    bool SetLowPart(long value);

    // Конструктори
    LongLong();
    LongLong(long long value);
    LongLong(const LongLong& other);

    // Оператор присвоєння
    LongLong& operator=(const LongLong& other);

    // Префіксний та постфіксний інкремент
    LongLong& operator++();
    LongLong operator++(int);

    // Префіксний та постфіксний декремент
    LongLong& operator--();
    LongLong operator--(int);

    // Перетворення в рядок
    operator string() const;

    // Арифметичні операції
    friend LongLong operator+(const LongLong& a, const LongLong& b);
    friend LongLong operator*(const LongLong& a, const LongLong& b);

    // Операції порівняння
    friend bool operator<(const LongLong& a, const LongLong& b);
    friend bool operator>=(const LongLong& a, const LongLong& b);
    friend bool operator>(const LongLong& a, const LongLong& b);

    // Потокове введення та виведення
    friend ostream& operator<<(ostream& out, const LongLong& number);
    friend istream& operator>>(istream& in, LongLong& number);
};