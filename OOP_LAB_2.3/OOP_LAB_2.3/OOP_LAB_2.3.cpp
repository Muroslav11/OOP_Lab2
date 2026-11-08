#include <iostream>
#include <string>
#include <Windows.h>
#include "LongLong.h"

using namespace std;

// Структура для перевірки розміру з #pragma pack(1)
#pragma pack(push, 1)
struct PackedLongLong
{
    long highPart;
    long lowPart;
};
#pragma pack(pop)

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "ЛАБОРАТОРНА РОБОТА 2.3" << endl;
    cout << "ВАРІАНТ 10 - КЛАС LongLong" << endl << endl;

    // 1. Конструктор за замовчуванням
    LongLong number1;

    cout << "Конструктор за замовчуванням:" << endl;
    cout << "number1 = " << number1 << endl;

    // 2. Конструктор ініціалізації
    LongLong number2(1234567890LL);
    LongLong number3(9876543210LL);

    cout << endl << "Конструктор ініціалізації:" << endl;
    cout << "number2 = " << number2 << endl;
    cout << "number3 = " << number3 << endl;

    // 3. Конструктор копіювання
    LongLong number4(number2);

    cout << endl << "Конструктор копіювання:" << endl;
    cout << "number4 = " << number4 << endl;

    // 4. Оператор присвоєння
    LongLong number5;
    number5 = number3;

    cout << endl << "Оператор присвоєння:" << endl;
    cout << "number5 = " << number5 << endl;

    // 5. Введення числа з клавіатури
    cout << endl << "Введення числа з клавіатури:" << endl;

    LongLong number6;
    cin >> number6;

    cout << "Введене число: " << number6 << endl;

    // 6. Додавання
    cout << endl << "Операція додавання:" << endl;

    LongLong sum = number2 + number3;

    cout << number2 << " + " << number3
        << " = " << sum << endl;

    // 7. Множення
    cout << endl << "Операція множення:" << endl;

    LongLong product = number2 * LongLong(5);

    cout << number2 << " * 5 = "
        << product << endl;

    // 8. Операції порівняння
    cout << endl << "Операції порівняння:" << endl;

    if (number2 < number3)
        cout << "number2 менше за number3" << endl;

    if (number3 > number2)
        cout << "number3 більше за number2" << endl;

    if (number2 >= number3)
        cout << "number2 не менше за number3" << endl;
    else
        cout << "number2 менше за number3" << endl;

    // 9. Префіксний інкремент
    cout << endl << "Префіксний інкремент (++number2):" << endl;

    cout << "До збільшення: " << number2 << endl;
    cout << "Після збільшення: " << ++number2 << endl;

    // 10. Постфіксний інкремент
    cout << endl << "Постфіксний інкремент (number2++):" << endl;

    cout << "До збільшення: " << number2++ << endl;
    cout << "Після збільшення: " << number2 << endl;

    // 11. Префіксний декремент
    cout << endl << "Префіксний декремент (--number3):" << endl;

    cout << "До зменшення: " << number3 << endl;
    cout << "Після зменшення: " << --number3 << endl;

    // 12. Постфіксний декремент
    cout << endl << "Постфіксний декремент (number3--):" << endl;

    cout << "До зменшення: " << number3-- << endl;
    cout << "Після зменшення: " << number3 << endl;

    // 13. Перетворення об'єкта в рядок
    cout << endl << "Перетворення об'єкта в рядок:" << endl;

    string text = static_cast<string>(number2);

    cout << "Рядок: " << text << endl;

    // 14. Методи отримання значень
    cout << endl << "Методи отримання значень:" << endl;

    cout << "Старша частина: " << number2.GetHighPart() << endl;
    cout << "Молодша частина: " << number2.GetLowPart() << endl;

    // 15. Методи зміни значень
    cout << endl << "Методи зміни значень:" << endl;

    if (number1.SetHighPart(1))
        cout << "Старшу частину успішно змінено" << endl;

    if (number1.SetLowPart(100))
        cout << "Молодшу частину успішно змінено" << endl;

    cout << "number1 = " << number1 << endl;

    // Перевірка неправильного значення
    if (!number1.SetHighPart(3000000000LL))
        cout << "Некоректне значення старшої частини!" << endl;

    // 16. Масив об'єктів
    cout << endl << "Масив об'єктів LongLong:" << endl;

    LongLong numbers[3] =
    {
        LongLong(100),
        LongLong(200),
        LongLong(300)
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "numbers[" << i << "] = "
            << numbers[i] << endl;
    }

    // 17. Розмір класу
    cout << endl << "Розмір класу:" << endl;

    cout << "Розмір класу LongLong без pack(1): "
        << sizeof(LongLong) << " байт" << endl;

    cout << "Розмір структури з #pragma pack(1): "
        << sizeof(PackedLongLong) << " байт" << endl;

    return 0;
}
