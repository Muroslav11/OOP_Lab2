#pragma once

#include <iostream>
#include <string>

class Set
{
private:
    static const int MAX_SIZE = 256;

    int maxSize;                         // Максимальний розмір множини
    int count;                           // Кількість елементів
    unsigned char elements[MAX_SIZE];    // Масив наявності елементів

    void Clear();                        // Очищення множини

public:
    // Конструктори
    Set();
    Set(int size);
    Set(const std::string& str);
    Set(const Set& s);

    // Деструктор
    ~Set();

    // Методи доступу
    int size() const;
    int getMaxSize() const;
    int getCount() const;
    int getElement(int index) const;

    // Методи зміни значень
    void setMaxSize(int value);
    void setElement(int index, int value);

    // Включення та вилучення елементів
    void Add(char ch);
    void Remove(char ch);

    // Перевірка наявності елемента
    bool Contains(char ch) const;

    // Перевірка входження множини в іншу
    bool IsSubsetOf(const Set& s) const;

    // Операція індексування
    bool operator[](int index) const;

    // Операція присвоєння
    Set& operator=(const Set& s);

    // Перетворення у рядок
    operator std::string() const;

    // Дружні функції
    friend Set operator|(const Set& a, const Set& b);
    friend Set operator&(const Set& a, const Set& b);
    friend Set operator-(const Set& a, const Set& b);

    friend bool operator<=(const Set& a, const Set& b);
    friend bool operator==(const Set& a, const Set& b);

    friend std::ostream& operator<<(std::ostream& out, const Set& s);
    friend std::istream& operator>>(std::istream& in, Set& s);
};

// Звичайна структура без примусового пакування
struct SetNormalInfo
{
    int maxSize;
    int count;
    unsigned char elements[256];
};

// Структура з пакуванням в один байт
#pragma pack(push, 1)

struct SetPackedInfo
{
    int maxSize;
    int count;
    unsigned char elements[256];
};

#pragma pack(pop)