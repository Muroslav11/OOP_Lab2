#include <iostream>
#include <windows.h>
#include "Line.h"

using namespace std;

// Структури для перевірки розміру класу з вирівнюванням та без
#pragma pack(push, 1)
class LinePacked
{
    double first;
    double second;
};
#pragma pack(pop)

int main()
{

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Демонстрація створення об'єктів різними конструкторами
    Line l1; // конструктор за умовчанням
    Line l2(2.5, -4.0); // конструктор ініціалізації
    Line l3(l2); // конструктор копіювання

    cout << "l1: " << l1;
    cout << "l2: " << l2;
    cout << "l3: " << l3;

    // Демонстрація виклику функції MakeLine
    Line l4 = MakeLine(3.0, 5.0);
    cout << "l4 (створено за допомогою MakeLine): " << l4;

    // Демонстрація роботи методу function()
    double x = 2.0;
    cout << "Обчислення функції для l2 при x = " << x << ": y = " << l2.function(x) << endl << endl;

    // Демонстрація префіксного інкременту (змінює first)
    cout << "Демонстрація ++l2 (змінює first):" << endl;
    cout << "До: " << l2;
    cout << "Результат ++l2: " << ++l2;
    cout << "Після: " << l2 << endl;

    // Демонстрація постфіксного інкременту (змінює second)
    cout << "Демонстрація l2++ (змінює second):" << endl;
    cout << "До: " << l2;
    cout << "Результат l2++: " << l2++;
    cout << "Після: " << l2 << endl;

    // Демонстрація введення з клавіатури
    Line l5;
    cout << "Введіть коефіцієнти нового рівняння:" << endl;
    cin >> l5;
    cout << "Ви ввели: " << l5;

    // Демонстрація масиву об'єктів
    Line arr[2] = { Line(1.0, 2.0), Line(3.0, 4.0) };
    cout << "Масив об'єктів:" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "arr[" << i << "]: " << arr[i];
    }

    // Виведення розмірів класу з pragma pack і без
    cout << endl << "--- Розміри класу ---" << endl;
    cout << "sizeof(Line) за умовчанням: " << sizeof(Line) << " байт" << endl;
    cout << "sizeof(LinePacked) pack(1): " << sizeof(LinePacked) << " байт" << endl;

    cin.get();
    return 0;
}