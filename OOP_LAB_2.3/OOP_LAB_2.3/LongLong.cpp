
#include "LongLong.h"
#include <climits>
#include <stdexcept>
#include <sstream>

// Перетворення двох частин у 64-розрядне число
long long LongLong::ToLongLong() const
{
    int32_t high = static_cast<int32_t>(highPart);
    int32_t low = static_cast<int32_t>(lowPart);

    return static_cast<long long>(high) * 4294967296LL
        + static_cast<uint32_t>(low);
}

// Розділення 64-розрядного числа на дві частини
void LongLong::FromLongLong(long long value)
{
    uint64_t bits = static_cast<uint64_t>(value);

    highPart = static_cast<int32_t>(bits >> 32);
    lowPart = static_cast<int32_t>(static_cast<uint32_t>(bits));
}

// Конструктор за замовчуванням
LongLong::LongLong()
{
    highPart = 0;
    lowPart = 0;
}

// Конструктор ініціалізації
LongLong::LongLong(long long value)
{
    FromLongLong(value);
}

// Конструктор копіювання
LongLong::LongLong(const LongLong& other)
{
    highPart = other.highPart;
    lowPart = other.lowPart;
}

// Отримання старшої частини
long LongLong::GetHighPart() const
{
    return highPart;
}

// Отримання молодшої частини
long LongLong::GetLowPart() const
{
    return lowPart;
}

// Зміна старшої частини з перевіркою
bool LongLong::SetHighPart(long value)
{
    if (value >= INT32_MIN && value <= INT32_MAX)
    {
        highPart = value;
        return true;
    }

    return false;
}

// Зміна молодшої частини з перевіркою
bool LongLong::SetLowPart(long value)
{
    if (value >= INT32_MIN && value <= INT32_MAX)
    {
        lowPart = value;
        return true;
    }

    return false;
}

// Оператор присвоєння
LongLong& LongLong::operator=(const LongLong& other)
{
    if (this != &other)
    {
        highPart = other.highPart;
        lowPart = other.lowPart;
    }

    return *this;
}

// Префіксний інкремент
LongLong& LongLong::operator++()
{
    *this = *this + LongLong(1);
    return *this;
}

// Постфіксний інкремент
LongLong LongLong::operator++(int)
{
    LongLong temp(*this);

    ++(*this);

    return temp;
}

// Префіксний декремент
LongLong& LongLong::operator--()
{
    *this = *this + LongLong(-1);
    return *this;
}

// Постфіксний декремент
LongLong LongLong::operator--(int)
{
    LongLong temp(*this);

    --(*this);

    return temp;
}

// Додавання
LongLong operator+(const LongLong& a, const LongLong& b)
{
    long long x = a.ToLongLong();
    long long y = b.ToLongLong();

    if ((y > 0 && x > LLONG_MAX - y) ||
        (y < 0 && x < LLONG_MIN - y))
    {
        throw overflow_error("Переповнення під час додавання!");
    }

    return LongLong(x + y);
}

// Множення
LongLong operator*(const LongLong& a, const LongLong& b)
{
    long long x = a.ToLongLong();
    long long y = b.ToLongLong();

    if (x != 0 && y != 0)
    {
        if ((x == -1 && y == LLONG_MIN) ||
            (y == -1 && x == LLONG_MIN))
        {
            throw overflow_error("Переповнення під час множення!");
        }

        if (x > 0)
        {
            if ((y > 0 && x > LLONG_MAX / y) ||
                (y < 0 && y < LLONG_MIN / x))
            {
                throw overflow_error("Переповнення під час множення!");
            }
        }
        else
        {
            if ((y > 0 && x < LLONG_MIN / y) ||
                (y < 0 && x < LLONG_MAX / y))
            {
                throw overflow_error("Переповнення під час множення!");
            }
        }
    }

    return LongLong(x * y);
}

// Операція менше
bool operator<(const LongLong& a, const LongLong& b)
{
    return a.ToLongLong() < b.ToLongLong();
}

// Операція не менше
bool operator>=(const LongLong& a, const LongLong& b)
{
    return a.ToLongLong() >= b.ToLongLong();
}

// Операція більше
bool operator>(const LongLong& a, const LongLong& b)
{
    return a.ToLongLong() > b.ToLongLong();
}

// Перетворення об'єкта в рядок
LongLong::operator string() const
{
    return to_string(ToLongLong());
}

// Потокове виведення
ostream& operator<<(ostream& out, const LongLong& number)
{
    out << number.ToLongLong();
    return out;
}

// Потокове введення
istream& operator>>(istream& in, LongLong& number)
{
    long long value;

    cout << "Введіть 64-розрядне ціле число: ";

    if (in >> value)
    {
        number.FromLongLong(value);
    }

    return in;
}
