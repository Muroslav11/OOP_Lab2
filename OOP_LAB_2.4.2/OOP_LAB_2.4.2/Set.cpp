#include "Set.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

// Очищення множини

void Set::Clear()
{
    count = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        elements[i] = 0;
    }
}

// Конструктор без аргументів

Set::Set()
{
    maxSize = MAX_SIZE;

    Clear();
}

// Конструктор ініціалізації

Set::Set(int size)
{
    if (size >= 1 && size <= MAX_SIZE)
    {
        maxSize = size;
    }
    else
    {
        maxSize = MAX_SIZE;
    }

    Clear();
}

// Конструктор ініціалізації рядком

Set::Set(const std::string& str)
{
    maxSize = MAX_SIZE;

    Clear();

    for (int i = 0; i < static_cast<int>(str.length()); i++)
    {
        Add(str[i]);
    }
}

// Конструктор копіювання

Set::Set(const Set& s)
{
    maxSize = s.maxSize;
    count = s.count;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        elements[i] = s.elements[i];
    }
}

// Деструктор

Set::~Set()
{}

// Методи доступу

int Set::size() const
{
    return maxSize;
}

int Set::getMaxSize() const
{
    return maxSize;
}

int Set::getCount() const
{
    return count;
}

int Set::getElement(int index) const
{
    if (index < 0 || index >= maxSize)
    {
        throw std::out_of_range("Індекс виходить за межі множини!");
    }

    return elements[index];
}

// Зміна максимального розміру множини

void Set::setMaxSize(int value)
{
    if (value < 1 || value > MAX_SIZE)
    {
        throw std::invalid_argument("Неправильний розмір множини!");
    }

    if (value < maxSize)
    {
        for (int i = value; i < maxSize; i++)
        {
            if (elements[i] == 1)
            {
                elements[i] = 0;
                count--;
            }
        }
    }

    maxSize = value;
}

// Зміна значення елемента масиву

void Set::setElement(int index, int value)
{
    if (index < 0 || index >= maxSize)
    {
        throw std::out_of_range("Індекс виходить за межі множини!");
    }

    if (value != 0 && value != 1)
    {
        throw std::invalid_argument("Значення може бути лише 0 або 1!");
    }

    if (elements[index] != value)
    {
        if (value == 1)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    elements[index] = static_cast<unsigned char>(value);
}

// Включення елемента у множину

void Set::Add(char ch)
{
    unsigned char index = static_cast<unsigned char>(ch);

    if (index >= maxSize)
    {
        throw std::out_of_range("Символ виходить за межі множини!");
    }

    setElement(index, 1);
}

// Вилучення елемента з множини

void Set::Remove(char ch)
{
    unsigned char index = static_cast<unsigned char>(ch);

    if (index >= maxSize)
    {
        throw std::out_of_range("Символ виходить за межі множини!");
    }

    setElement(index, 0);
}

// Перевірка наявності елемента

bool Set::Contains(char ch) const
{
    unsigned char index = static_cast<unsigned char>(ch);

    if (index >= maxSize)
    {
        return false;
    }

    return elements[index] == 1;
}

// Перевірка входження множини в іншу

bool Set::IsSubsetOf(const Set& s) const
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (elements[i] == 1 && s.elements[i] == 0)
        {
            return false;
        }
    }

    return true;
}

// Операція індексування

bool Set::operator[](int index) const
{
    if (index < 0 || index >= maxSize)
    {
        throw std::out_of_range("Індекс виходить за межі множини!");
    }

    return elements[index] == 1;
}

// Операція присвоєння

Set& Set::operator=(const Set& s)
{
    if (this == &s)
    {
        return *this;
    }

    maxSize = s.maxSize;
    count = s.count;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        elements[i] = s.elements[i];
    }

    return *this;
}

// Перетворення множини у рядок

Set::operator std::string() const
{
    std::stringstream ss;

    ss << "{ ";

    for (int i = 0; i < maxSize; i++)
    {
        if (elements[i] == 1)
        {
            if (i >= 32 && i <= 126)
            {
                ss << static_cast<char>(i) << " ";
            }
            else
            {
                ss << "\\x"
                    << std::uppercase << std::hex
                    << std::setw(2) << std::setfill('0')
                    << i << std::dec << " ";
            }
        }
    }

    ss << "}";

    return ss.str();
}

// Об'єднання множин

Set operator|(const Set& a, const Set& b)
{
    int maxSize;

    if (a.maxSize > b.maxSize)
    {
        maxSize = a.maxSize;
    }
    else
    {
        maxSize = b.maxSize;
    }

    Set result(maxSize);

    for (int i = 0; i < maxSize; i++)
    {
        if (a.elements[i] == 1 || b.elements[i] == 1)
        {
            result.setElement(i, 1);
        }
    }

    return result;
}

// Перетин множин

Set operator&(const Set& a, const Set& b)
{
    int maxSize;

    if (a.maxSize > b.maxSize)
    {
        maxSize = a.maxSize;
    }
    else
    {
        maxSize = b.maxSize;
    }

    Set result(maxSize);

    for (int i = 0; i < maxSize; i++)
    {
        if (a.elements[i] == 1 && b.elements[i] == 1)
        {
            result.setElement(i, 1);
        }
    }

    return result;
}

// Різниця множин

Set operator-(const Set& a, const Set& b)
{
    Set result(a.maxSize);

    for (int i = 0; i < a.maxSize; i++)
    {
        if (a.elements[i] == 1 && b.elements[i] == 0)
        {
            result.setElement(i, 1);
        }
    }

    return result;
}

// Перевірка входження однієї множини в іншу

bool operator<=(const Set& a, const Set& b)
{
    return a.IsSubsetOf(b);
}

// Порівняння множин

bool operator==(const Set& a, const Set& b)
{
    for (int i = 0; i < Set::MAX_SIZE; i++)
    {
        if (a.elements[i] != b.elements[i])
        {
            return false;
        }
    }

    return true;
}

// Виведення множини

std::ostream& operator<<(std::ostream& out, const Set& s)
{
    out << static_cast<std::string>(s);

    return out;
}

// Введення множини

std::istream& operator>>(std::istream& in, Set& s)
{
    std::string str;

    std::cout << "Введіть символи множини: ";

    std::getline(in >> std::ws, str);

    s.Clear();

    for (int i = 0; i < static_cast<int>(str.length()); i++)
    {
        unsigned char index = static_cast<unsigned char>(str[i]);

        if (index >= s.maxSize)
        {
            in.setstate(std::ios::failbit);
            return in;
        }

        s.Add(str[i]);
    }

    return in;
}