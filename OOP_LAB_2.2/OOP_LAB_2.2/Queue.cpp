// Queue.cpp
#include "Queue.h"
#include <sstream>

// Конструктор за умовчанням
Queue::Queue() : head(nullptr), tail(nullptr), count(0) {}

// Конструктор ініціалізації
Queue::Queue(int val) : head(nullptr), tail(nullptr), count(0)
{
    Push(val);
}

// Конструктор копіювання
Queue::Queue(const Queue& other) : head(nullptr), tail(nullptr), count(0)
{
    Elem* current = other.head;
    while (current != nullptr)
    {
        Push(current->data);
        current = current->next;
    }
}

// Деструктор
Queue::~Queue()
{
    while (!IsEmpty())
    {
        Pop();
    }
}

// Метод запису з перевіркою коректності
void Queue::SetCount(int c)
{
    if (c >= 0)
    {
        count = c;
    }
    else
    {
        cout << "Помилка: кількість не може бути від'ємною!" << endl;
    }
}

// Додавання елемента у чергу
void Queue::Push(int val)
{
    Elem* newElem = new Elem(val);
    if (tail == nullptr)
    {
        head = tail = newElem;
    }
    else
    {
        tail->next = newElem;
        tail = newElem;
    }
    count++;
}

// Вилучення елемента з черги
int Queue::Pop()
{
    if (IsEmpty())
    {
        cerr << "Черга порожня! Неможливо вилучити елемент." << endl;
        return 0;
    }
    Elem* temp = head;
    int val = temp->data;
    head = head->next;
    if (head == nullptr)
    {
        tail = nullptr;
    }
    delete temp;
    count--;
    return val;
}

// Операція присвоєння
Queue& Queue::operator=(const Queue& other)
{
    if (this == &other)
        return *this;

    while (!IsEmpty())
    {
        Pop();
    }

    Elem* current = other.head;
    while (current != nullptr)
    {
        Push(current->data);
        current = current->next;
    }

    return *this;
}

// Операція ++ як метод класу (додає елемент через запит з клавіатури)
Queue& Queue::operator++()
{
    int val;
    cout << "Введіть значення для додавання (оператор ++): ";
    cin >> val;
    Push(val);
    return *this;
}

Queue Queue::operator++(int)
{
    Queue temp(*this);
    int val;
    cout << "Введіть значення для додавання (оператор q++): ";
    cin >> val;
    Push(val);
    return temp;
}

// Операція -- як дружня функція (вилучає елемент)
Queue& operator--(Queue& q)
{
    q.Pop();
    return q;
}

Queue operator--(Queue& q, int)
{
    Queue temp(q);
    q.Pop();
    return temp;
}

// Операція ! перевіряє чергу на наявність елементів (true, якщо елементи є)
bool Queue::operator!() const
{
    return !IsEmpty();
}

// Приведення типу до літерного рядка
Queue::operator string() const
{
    stringstream ss;
    ss << "Елементи черги: ";
    Elem* current = head;
    while (current != nullptr)
    {
        ss << current->data << " ";
        current = current->next;
    }
    ss << "(Загальна кількість: " << count << ")";
    return ss.str();
}

// Потокове виведення
ostream& operator<<(ostream& out, const Queue& q)
{
    out << string(q);
    return out;
}

// Потокове введення (повне формування черги: кількість + елементи)
istream& operator>>(istream& in, Queue& q)
{
    while (!q.IsEmpty())
    {
        q.Pop();
    }

    int n;
    cout << "Введіть кількість елементів для додавання в чергу: ";
    in >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Введіть елемент " << i + 1 << ": ";
        in >> val;
        q.Push(val);
    }
    return in;
}