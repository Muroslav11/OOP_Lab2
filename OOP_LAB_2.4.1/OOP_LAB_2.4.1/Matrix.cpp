
#include "Matrix.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>

using namespace std;

// Реалізація допоміжного класу Row

Matrix::Row::Row(int* data, int cols)
{
    this->data = data;
    this->cols = cols;
}

int& Matrix::Row::operator [] (int j)
{
    if (j < 0 || j >= cols)
        throw out_of_range("Індекс стовпця за межами матриці!");

    return data[j];
}

// Реалізація допоміжного класу ConstRow

Matrix::ConstRow::ConstRow(const int* data, int cols)
{
    this->data = data;
    this->cols = cols;
}

const int& Matrix::ConstRow::operator [] (int j) const
{
    if (j < 0 || j >= cols)
        throw out_of_range("Індекс стовпця за межами матриці!");

    return data[j];
}

// Конструктор без аргументів

Matrix::Matrix()
{
    rows = 1;
    cols = 1;

    data = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        data[i] = new int[cols];

        for (int j = 0; j < cols; j++)
            data[i][j] = 0;
    }
}

// Конструктор ініціалізації

Matrix::Matrix(int rows, int cols)
{
    if (rows < 1 || rows > MAX_SIZE)
        rows = 1;

    if (cols < 1 || cols > MAX_SIZE)
        cols = 1;

    this->rows = rows;
    this->cols = cols;

    data = new int* [this->rows];

    for (int i = 0; i < this->rows; i++)
    {
        data[i] = new int[this->cols];

        for (int j = 0; j < this->cols; j++)
            data[i][j] = 0;
    }
}

// Конструктор копіювання

Matrix::Matrix(const Matrix& m)
{
    rows = m.rows;
    cols = m.cols;

    data = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        data[i] = new int[cols];

        for (int j = 0; j < cols; j++)
            data[i][j] = m.data[i][j];
    }
}

// Деструктор

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] data[i];

    delete[] data;
}

// Зміна розмірів матриці

void Matrix::Resize(int newRows, int newCols)
{
    if (newRows < 1 || newRows > MAX_SIZE ||
        newCols < 1 || newCols > MAX_SIZE)
    {
        return;
    }

    int** temp = new int* [newRows];

    for (int i = 0; i < newRows; i++)
    {
        temp[i] = new int[newCols];

        for (int j = 0; j < newCols; j++)
            temp[i][j] = 0;
    }

    // Визначення кількості рядків і стовпців,
    // які можна зберегти під час зміни розмірів

    int minRows = rows < newRows ? rows : newRows;
    int minCols = cols < newCols ? cols : newCols;

    // Копіювання старих елементів у нову матрицю

    for (int i = 0; i < minRows; i++)
        for (int j = 0; j < minCols; j++)
            temp[i][j] = data[i][j];

    // Звільнення старої пам'яті

    for (int i = 0; i < rows; i++)
        delete[] data[i];

    delete[] data;

    // Збереження нової матриці

    data = temp;
    rows = newRows;
    cols = newCols;
}

// Методи доступу

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getCols() const
{
    return cols;
}

int Matrix::getElement(int i, int j) const
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw out_of_range("Індекс елемента за межами матриці!");

    return data[i][j];
}

// Методи зміни значень

void Matrix::setRows(int value)
{
    if (value < 1 || value > MAX_SIZE)
    {
        cout << "Помилка: неправильна кількість рядків!" << endl;
        return;
    }

    Resize(value, cols);
}

void Matrix::setCols(int value)
{
    if (value < 1 || value > MAX_SIZE)
    {
        cout << "Помилка: неправильна кількість стовпців!" << endl;
        return;
    }

    Resize(rows, value);
}

void Matrix::setElement(int i, int j, int value)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw out_of_range("Індекс елемента за межами матриці!");

    data[i][j] = value;
}

// Операція присвоєння

Matrix& Matrix::operator = (const Matrix& m)
{
    if (this == &m)
        return *this;

    Resize(m.rows, m.cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = m.data[i][j];

    return *this;
}

// Операція індексування

Matrix::Row Matrix::operator [] (int i)
{
    if (i < 0 || i >= rows)
        throw out_of_range("Індекс рядка за межами матриці!");

    return Row(data[i], cols);
}

Matrix::ConstRow Matrix::operator [] (int i) const
{
    if (i < 0 || i >= rows)
        throw out_of_range("Індекс рядка за межами матриці!");

    return ConstRow(data[i], cols);
}

// Перетворення матриці у літерний рядок

Matrix::operator string () const
{
    stringstream ss;

    ss << "Матриця " << rows << " x " << cols << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            ss << data[i][j] << "\t";

        ss << endl;
    }

    return ss.str();
}

// Обчислення норми матриці

double Matrix::Norm() const
{
    long double sum = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            long double value = data[i][j];
            sum += value * value;
        }

    return sqrt(sum);
}

// Віднімання матриць

Matrix operator - (const Matrix& a, const Matrix& b)
{
    if (a.rows != b.rows || a.cols != b.cols)
        throw invalid_argument("Розміри матриць повинні збігатися!");

    Matrix result(a.rows, a.cols);

    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            result.data[i][j] = a.data[i][j] - b.data[i][j];

    return result;
}

// Порівняння матриць

bool operator == (const Matrix& a, const Matrix& b)
{
    if (a.rows != b.rows || a.cols != b.cols)
        return false;

    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            if (a.data[i][j] != b.data[i][j])
                return false;

    return true;
}

// Операція виведення

ostream& operator << (ostream& out, const Matrix& m)
{
    out << string(m);

    return out;
}

// Операція введення

istream& operator >> (istream& in, Matrix& m)
{
    cout << "Введіть елементи матриці:" << endl;

    for (int i = 0; i < m.rows; i++)
        for (int j = 0; j < m.cols; j++)
        {
            cout << "[" << i << "][" << j << "] = ";
            in >> m.data[i][j];
        }

    return in;
}
