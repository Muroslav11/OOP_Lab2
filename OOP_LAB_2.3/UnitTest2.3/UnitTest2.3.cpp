#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2.3/LongLong.h"
#include "../OOP_Lab_2.3/LongLong.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace LongLongUnitTest
{
    TEST_CLASS(LongLongTests)
    {
    public:

        // Тест конструктора за умовчанням та гетерів
        TEST_METHOD(TestDefaultConstructor)
        {
            LongLong num;
            Assert::AreEqual(0L, num.GetHighPart());
            Assert::AreEqual(0L, num.GetLowPart());
        }

        // Тест конструктора ініціалізації
        TEST_METHOD(TestInitConstructor)
        {
            LongLong num(5000000000LL); // 5 мільярдів (> INT32_MAX, розіб'ється на частини)
            // Перевіряємо через приведення до рядка або оператор виведення
            string s = static_cast<string>(num);
            Assert::AreEqual(string("5000000000"), s);
        }

        // Тест конструктора копіювання та оператора присвоєння
        TEST_METHOD(TestCopyAndAssignment)
        {
            LongLong num1(123456LL);
            LongLong num2(num1); // Конструктор копіювання
            Assert::AreEqual(string("123456"), static_cast<string>(num2));

            LongLong num3;
            num3 = num1; // Оператор присвоєння
            Assert::AreEqual(string("123456"), static_cast<string>(num3));
        }

        // Тест арифметичної операції додавання (+)
        TEST_METHOD(TestAddition)
        {
            LongLong num1(1000LL);
            LongLong num2(2000LL);
            LongLong sum = num1 + num2;
            Assert::AreEqual(string("3000"), static_cast<string>(sum));
        }

        // Тест арифметичної операції множення (*)
        TEST_METHOD(TestMultiplication)
        {
            LongLong num1(150LL);
            LongLong num2(4LL);
            LongLong prod = num1 * num2;
            Assert::AreEqual(string("600"), static_cast<string>(prod));
        }

        // Тест операцій порівняння (<, >, >=)
        TEST_METHOD(TestComparisons)
        {
            LongLong num1(100LL);
            LongLong num2(200LL);

            Assert::IsTrue(num1 < num2);
            Assert::IsTrue(num2 > num1);
            Assert::IsTrue(num2 >= num1);
            Assert::IsFalse(num1 >= num2);
        }

        // Тест інкременту та декременту
        TEST_METHOD(TestIncrementAndDecrement)
        {
            LongLong num(10LL);

            // Префіксний інкремент
            Assert::AreEqual(string("11"), static_cast<string>(++num));

            // Постфіксний інкремент
            Assert::AreEqual(string("11"), static_cast<string>(num++));
            Assert::AreEqual(string("12"), static_cast<string>(num));

            // Декременти
            Assert::AreEqual(string("11"), static_cast<string>(--num));
            Assert::AreEqual(string("11"), static_cast<string>(num--));
            Assert::AreEqual(string("10"), static_cast<string>(num));
        }

    };
}