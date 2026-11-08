#pragma once
#include <iostream>
#include <string>

using namespace std;

class Queue
{
private:
    struct Elem
    {
        int data;
        Elem* next;
        Elem(int d, Elem* n = nullptr) : data(d), next(n) {}
    };

    Elem* head; // Вказівник на початок черги
    Elem* tail; // Вказівник на кінець черги
    int count;  // Кількість елементів у черзі

public:
    // Конструктори та деструктор
    Queue();
    Queue(int val);
    Queue(const Queue& other);
    ~Queue();

    // Методи доступу (гетери та сетери) з контролем коректності
    int GetCount() const { return count; }
    bool IsEmpty() const { return head == nullptr; }

    void SetCount(int c); // Контролює, щоб count не було < 0

    // Методи додавання та вилучення
    void Push(int val);
    int Pop();

    // Перевантаження операцій (варіант 10)
    Queue& operator++();    // Префіксний ++ (додає елемент через введення)
    Queue operator++(int);  // Постфіксний ++
    bool operator!() const; // Перевірка на наявність елементів

    // Операція присвоєння (обов'язково метод класу)
    Queue& operator=(const Queue& other);

    // Приведення типу до літерного рядка
    operator string() const;

    // Дружні функції
    friend Queue& operator--(Queue& q);     // Префіксний -- (вилучає елемент)
    friend Queue operator--(Queue& q, int); // Постфіксний --

    friend ostream& operator<<(ostream& out, const Queue& q);
    friend istream& operator>>(istream& in, Queue& q);
};