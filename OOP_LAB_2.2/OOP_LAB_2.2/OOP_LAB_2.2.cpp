// Source.cpp
#include <iostream>
#include <string>
#include <Windows.h>
#include "Queue.h"

using namespace std;

// Допоміжний клас для порівняння розміру з #pragma pack(1) і без нього
class QueueForPacking {
    void* head;
    void* tail;
    int count;
};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== ЛАБОРАТОРНА РОБОТА 2.2 (ВАРІАНТ 10) ===" << endl << endl;

    // 1. Створення об'єктів різними конструкторами
    Queue q1;                 // Конструктор за умовчанням
    Queue q2(5);              // Конструктор ініціалізації

    cout << "Черга q2 (ініціалізована значенням 5):\n" << q2 << endl;

    // 2. Конструктор копіювання
    Queue q3(q2);
    cout << "Черга q3 (скопійована з q2):\n" << q3 << endl;

    // 3. Операція присвоєння
    Queue q4;
    q4 = q3;
    cout << "Черга q4 (присвоєна з q3):\n" << q4 << endl;

    // 4. Демонстрація операції ++ (додавання через введення)
    cout << "\n--- Тестування префіксного оператора ++ ---" << endl;
    ++q1;
    cout << q1 << endl;

    // 5. Демонстрація операції -- (вилучення)
    cout << "\n--- Тестування префіксного оператора -- ---" << endl;
    --q2;
    cout << "Черга q2 після виконання --q2:\n" << q2 << endl;

    // 6. Операція ! (перевірка на наявність елементів)
    if (!q1)
    {
        cout << "Черга q1 містить елементи (!q1 повертає true)." << endl;
    }

    // 7. Потокове введення (зчитування кількості та елементів)
    cout << "\n--- Тестування потокового введення (operator >>) ---" << endl;
    Queue q5;
    cin >> q5;
    cout << "Отримана черга q5:\n" << q5 << endl;

    // 8. Масиви об'єктів
    cout << "\n--- Тестування масиву об'єктів ---" << endl;
    Queue qArray[2]; // Створення масиву через конструктор за умовчанням
    for (int i = 0; i < 2; i++)
    {
        cout << "\nНалаштування елемента масиву " << i + 1 << ":" << endl;
        cin >> qArray[i];
    }

    cout << "\nVиведення елементів масиву:" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "qArray[" << i << "] -> " << qArray[i] << endl;
    }

    // 9. Виведення розміру класу в режимі #pragma pack(1) і без нього
    cout << "\n--- Демонстрація розміру класу ---" << endl;
    cout << "Розмір класу Queue без #pragma pack(1): " << sizeof(Queue) << " байт" << endl;

#pragma pack(push, 1)
    class QueuePacked {
        void* head;
        void* tail;
        int count;
    };
#pragma pack(pop)

    cout << "Розмір класу Queue з #pragma pack(1):    " << sizeof(QueuePacked) << " байт" << endl;

    return 0;
}