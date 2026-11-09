
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <clocale>
#include <Windows.h>
#include "Set.h"

using namespace std;

int main()
{
    // Налаштування кодування консолі

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Створення об'єктів

    cout << "СТВОРЕННЯ ОБ'ЄКТІВ" << endl;

    Set a;
    Set b(256);
    Set c("ABCDE");

    cout << endl << "Множина А: " << a << endl;
    cout << "Множина Б: " << b << endl;
    cout << "Множина В: " << c << endl;

    // Введення множин

    cout << endl << "ВВЕДЕННЯ МНОЖИН" << endl;

    cout << "Введіть множину А:" << endl;
    cin >> a;

    cout << "Введіть множину Б:" << endl;
    cin >> b;

    // Виведення множин

    cout << endl << "ВИВЕДЕННЯ МНОЖИН" << endl;

    cout << "Множина А: " << a << endl;
    cout << "Множина Б: " << b << endl;

    // Конструктор копіювання

    cout << endl << "КОНСТРУКТОР КОПІЮВАННЯ" << endl;

    Set d(a);

    cout << "Множина Г (копія множини А): " << d << endl;

    // Операція присвоєння

    cout << endl << "ОПЕРАЦІЯ ПРИСВОЄННЯ" << endl;

    Set e;

    e = b;

    cout << "Множина Е після присвоєння: " << e << endl;

    // Методи доступу

    cout << endl << "МЕТОДИ ДОСТУПУ" << endl;

    cout << "Максимальний розмір множини: "
        << a.getMaxSize() << endl;

    cout << "Розмір множини: "
        << a.size() << endl;

    cout << "Кількість елементів у множині А: "
        << a.getCount() << endl;

    // Перевірка значення елемента масиву

    cout << "Значення елемента масиву з індексом 65: "
        << a.getElement(65) << endl;

    // Зміна значення елемента масиву

    cout << endl << "ЗМІНА ЕЛЕМЕНТІВ МАСИВУ" << endl;

    a.setElement(65, 1);

    cout << "Множина А після зміни елемента: " << a << endl;

    // Перевірка операції індексування

    cout << endl << "ОПЕРАЦІЯ ІНДЕКСУВАННЯ" << endl;

    if (a[65])
    {
        cout << "Елемент з кодом 65 присутній у множині А." << endl;
    }
    else
    {
        cout << "Елемент з кодом 65 відсутній у множині А." << endl;
    }

    // Включення елемента у множину

    cout << endl << "ВКЛЮЧЕННЯ ЕЛЕМЕНТА" << endl;

    a.Add('X');

    cout << "Множина А після додавання символу X: "
        << a << endl;

    // Повторне включення того самого елемента

    a.Add('X');

    cout << "Кількість елементів після повторного додавання X: "
        << a.getCount() << endl;

    // Вилучення елемента з множини

    cout << endl << "ВИЛУЧЕННЯ ЕЛЕМЕНТА" << endl;

    a.Remove('X');

    cout << "Множина А після вилучення символу X: "
        << a << endl;

    // Перевірка наявності елемента

    cout << endl << "ПЕРЕВІРКА НАЯВНОСТІ ЕЛЕМЕНТА" << endl;

    if (a.Contains('A'))
    {
        cout << "Символ A присутній у множині." << endl;
    }
    else
    {
        cout << "Символ A відсутній у множині." << endl;
    }

    // Об'єднання множин

    cout << endl << "ОБ'ЄДНАННЯ МНОЖИН" << endl;

    Set unionSet = a | b;

    cout << "Результат об'єднання А | Б: "
        << unionSet << endl;

    // Перетин множин

    cout << endl << "ПЕРЕТИН МНОЖИН" << endl;

    Set intersectionSet = a & b;

    cout << "Результат перетину А & Б: "
        << intersectionSet << endl;

    // Різниця множин

    cout << endl << "РІЗНИЦЯ МНОЖИН" << endl;

    Set differenceSet = a - b;

    cout << "Результат різниці А - Б: "
        << differenceSet << endl;

    // Перевірка входження однієї множини в іншу

    cout << endl << "ПЕРЕВІРКА ВХОДЖЕННЯ МНОЖИН" << endl;

    if (a <= unionSet)
    {
        cout << "Множина А входить у множину об'єднання." << endl;
    }
    else
    {
        cout << "Множина А не входить у множину об'єднання." << endl;
    }

    if (a.IsSubsetOf(unionSet))
    {
        cout << "Метод IsSubsetOf підтвердив входження множини А."
            << endl;
    }

    // Порівняння множин

    cout << endl << "ПОРІВНЯННЯ МНОЖИН" << endl;

    if (a == d)
    {
        cout << "Множини А і Г однакові." << endl;
    }
    else
    {
        cout << "Множини А і Г різні." << endl;
    }

    // Перетворення множини у рядок

    cout << endl << "ПЕРЕТВОРЕННЯ У РЯДОК" << endl;

    string text = static_cast<string>(a);

    cout << "Множина А у вигляді рядка: "
        << text << endl;

    // Зміна максимального розміру множини

    cout << endl << "ЗМІНА РОЗМІРУ МНОЖИНИ" << endl;

    Set f;

    f.Add('A');
    f.Add('B');
    f.Add('C');
    f.Add('D');

    cout << "Множина Ф до зміни розміру: " << f << endl;

    f.setMaxSize(100);

    cout << "Новий максимальний розмір: "
        << f.getMaxSize() << endl;

    cout << "Множина Ф після зміни розміру: " << f << endl;

    // Масив об'єктів

    cout << endl << "МАСИВ ОБ'ЄКТІВ" << endl;

    Set arr[3] =
    {
        Set("ABC"),
        Set("BCD"),
        Set("CDE")
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "Множина №" << i + 1 << ": "
            << arr[i] << endl;
    }

    // Введення елементів масиву об'єктів

    cout << endl << "ВВЕДЕННЯ ЕЛЕМЕНТІВ МАСИВУ" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Введіть множину №" << i + 1 << ":" << endl;
        cin >> arr[i];
    }

    // Виведення елементів масиву об'єктів

    cout << endl << "ВИВЕДЕННЯ ЕЛЕМЕНТІВ МАСИВУ" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Множина №" << i + 1 << ": "
            << arr[i] << endl;
    }

    // Розмір класу та структур

    cout << endl << "--- РОЗМІР ОБ'ЄКТІВ ---" << endl;

    cout << "Розмір об'єкта Set: "
        << sizeof(a) << " байт" << endl;

    cout << "Розмір звичайної структури: "
        << sizeof(SetNormalInfo) << " байт" << endl;

    cout << "Розмір упакованої структури: "
        << sizeof(SetPackedInfo) << " байт" << endl;

    cout << endl << "ПРОГРАМУ ЗАВЕРШЕНО!" << endl;

    return 0;
}
