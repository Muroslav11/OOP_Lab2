#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2.1/Line.h" 
#include "../OOP_Lab_2.1/Line.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace LineUnitTest
{
    TEST_CLASS(LineTests)
    {
    public:

        // Тест конструктора за умовчанням та геттерів
        TEST_METHOD(TestDefaultConstructor)
        {
            Line l;
            Assert::AreEqual(1.0, l.GetFirst(), 0.0001);
            Assert::AreEqual(0.0, l.GetSecond(), 0.0001);
        }

        // Тест конструктора ініціалізації та перевірки на A != 0
        TEST_METHOD(TestInitConstructorAndValidation)
        {
            // Спроба передати 0 у перше поле
            Line l(0.0, 5.0);
            // Сеттер повинен запобігти нулю та встановити значення за умовчанням (1.0)
            Assert::AreEqual(1.0, l.GetFirst(), 0.0001);
            Assert::AreEqual(5.0, l.GetSecond(), 0.0001);
        }

        // Тест обчислення значення функції y = A * x + B
        TEST_METHOD(TestFunctionEvaluation)
        {
            // Рівняння: y = 2.5 * x + 3.0
            Line l(2.5, 3.0);
            double x = 4.0;
            // y = 2.5 * 4.0 + 3.0 = 10.0 + 3.0 = 13.0
            double result = l.function(x);
            Assert::AreEqual(13.0, result, 0.0001);
        }

        // Тест префіксного інкременту (модифікує перше поле)
        TEST_METHOD(TestPrefixIncrement)
        {
            Line l(2.0, 5.0);
            ++l; // first стає 3.0
            Assert::AreEqual(3.0, l.GetFirst(), 0.0001);
            Assert::AreEqual(5.0, l.GetSecond(), 0.0001);
        }

        // Тест постфіксного інкременту (модифікує друге поле)
        TEST_METHOD(TestPostfixIncrement)
        {
            Line l(2.0, 5.0);
            l++; // second стає 6.0
            Assert::AreEqual(2.0, l.GetFirst(), 0.0001);
            Assert::AreEqual(6.0, l.GetSecond(), 0.0001);
        }

    };
}