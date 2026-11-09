
#include <iostream>
#include <string>
#include <stdexcept>
#include <Windows.h>

#include "Matrix.h"

using namespace std;

int main()
{
    // Налаштування кодування консолі

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Створення об'єктів

    cout << "СТВОРЕННЯ ОБ'ЄКТІВ" << endl;

    Matrix a;               // Конструктор без аргументів
    Matrix b(2, 3);         // Конструктор ініціалізації
    Matrix c(2, 3);

    cout << endl << "Введіть матрицю А:" << endl;
    cin >> b;

    cout << endl << "Введіть матрицю Б:" << endl;
    cin >> c;

    // Конструктор копіювання

    cout << endl << "КОНСТРУКТОР КОПІЮВАННЯ" << endl;

    Matrix d = b;

    cout << "Матриця Г (копія матриці А):" << endl;
    cout << d;

    // Операція присвоєння

    cout << endl << "ОПЕРАЦІЯ ПРИСВОЄННЯ" << endl;

    a = c;

    cout << "Матриця А після присвоєння:" << endl;
    cout << a;

    // Операція індексування

    cout << endl << "ОПЕРАЦІЯ ІНДЕКСУВАННЯ" << endl;

    cout << "Елемент матриці А[0][0]: "
        << b[0][0] << endl;

    // Методи доступу

    cout << endl << "МЕТОДИ ДОСТУПУ" << endl;

    cout << "Кількість рядків: " << b.getRows() << endl;
    cout << "Кількість стовпців: " << b.getCols() << endl;

    cout << "Елемент А[0][1]: "
        << b.getElement(0, 1) << endl;

    // Зміна елемента

    cout << endl << "ЗМІНА ЕЛЕМЕНТА" << endl;

    b.setElement(0, 0, 10);

    cout << "Матриця А після зміни елемента:" << endl;
    cout << b;

    // Зміна розмірів матриці

    cout << endl << "ЗМІНА РОЗМІРІВ МАТРИЦІ" << endl;

    Matrix e(2, 2);

    e.setRows(3);
    e.setCols(3);

    cout << "Матриця Е після зміни розмірів:" << endl;
    cout << e;

    // Віднімання матриць

    cout << endl << "ВІДНІМАННЯ МАТРИЦЬ" << endl;

    try
    {
        Matrix result = b - c;

        cout << "Результат віднімання А - Б:" << endl;
        cout << result;
    }
    catch (const invalid_argument& error)
    {
        cout << "Помилка: " << error.what() << endl;
    }

    // Порівняння матриць

    cout << endl << "ПОРІВНЯННЯ МАТРИЦЬ" << endl;

    if (b == c)
        cout << "Матриці однакові!" << endl;
    else
        cout << "Матриці не однакові!" << endl;

    // Обчислення норми матриці

    cout << endl << "ОБЧИСЛЕННЯ НОРМИ МАТРИЦІ" << endl;

    cout << "Норма матриці А: " << b.Norm() << endl;
    cout << "Норма матриці Б: " << c.Norm() << endl;

    // Перетворення матриці у рядок

    cout << endl << "ПЕРЕТВОРЕННЯ МАТРИЦІ У РЯДОК" << endl;

    string text = string(b);

    cout << text;

    // Масив об'єктів

    cout << endl << "МАСИВ ОБ'ЄКТІВ" << endl;

    Matrix arr[3] =
    {
        Matrix(2, 2),
        Matrix(2, 3),
        Matrix(3, 2)
    };

    cout << "Створено масив із трьох матриць:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << endl << "Матриця №" << i + 1 << ":" << endl;
        cout << arr[i];
    }

    // Введення елементів масиву матриць

    cout << endl << "ВВЕДЕННЯ ЕЛЕМЕНТІВ МАСИВУ МАТРИЦЬ" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << endl << "Введення матриці №" << i + 1 << ":" << endl;
        cin >> arr[i];
    }

    // Виведення елементів масиву матриць

    cout << endl << "ВИВЕДЕННЯ ЕЛЕМЕНТІВ МАСИВУ МАТРИЦЬ" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << endl << "Матриця №" << i + 1 << ":" << endl;
        cout << arr[i];
    }

    // Порівняння розмірів структур

    cout << endl << "РОЗМІР СТРУКТУР" << endl;

    cout << "Розмір звичайної структури: "
        << sizeof(MatrixLayout) << " байт" << endl;

    cout << "Розмір упакованої структури (#pragma pack(1)): "
        << sizeof(MatrixPacked) << " байт" << endl;

    cout << "Розмір класу Matrix: "
        << sizeof(Matrix) << " байт" << endl;

    cout << endl << "ПРОГРАМУ ЗАВЕРШЕНО!" << endl;

    return 0;
}
