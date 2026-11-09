
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Matrix
{
private:
    static const int MAX_SIZE = 100;

    int rows;       // Кількість рядків
    int cols;       // Кількість стовпців
    int** data;     // Динамічний двовимірний масив

    // Допоміжний клас для індексування рядка
    class Row
    {
        int* data;
        int cols;

    public:
        Row(int* data, int cols);

        int& operator [] (int j);
    };

    // Допоміжний клас для константного індексування
    class ConstRow
    {
        const int* data;
        int cols;

    public:
        ConstRow(const int* data, int cols);

        const int& operator [] (int j) const;
    };

    // Допоміжний метод зміни розмірів матриці
    void Resize(int newRows, int newCols);

public:
    // Конструктори
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& m);

    // Деструктор
    ~Matrix();

    // Методи доступу
    int getRows() const;
    int getCols() const;
    int getElement(int i, int j) const;

    // Методи зміни значень
    void setRows(int value);
    void setCols(int value);
    void setElement(int i, int j, int value);

    // Операція присвоєння
    Matrix& operator = (const Matrix& m);

    // Операція індексування
    Row operator [] (int i);
    ConstRow operator [] (int i) const;

    // Перетворення матриці у літерний рядок
    operator string () const;

    // Обчислення норми матриці
    double Norm() const;

    // Дружні функції
    friend Matrix operator - (const Matrix& a, const Matrix& b);
    friend bool operator == (const Matrix& a, const Matrix& b);

    friend ostream& operator << (ostream& out, const Matrix& m);
    friend istream& operator >> (istream& in, Matrix& m);
};

// Звичайна структура для порівняння розмірів
struct MatrixLayout
{
    int rows;
    int cols;
    int** data;
};

// Упакована структура з вирівнюванням в один байт
#pragma pack(push, 1)
struct MatrixPacked
{
    int rows;
    int cols;
    int** data;
};
#pragma pack(pop)
