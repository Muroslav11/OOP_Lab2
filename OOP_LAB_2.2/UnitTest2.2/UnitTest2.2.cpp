#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2.2/Queue.h" 
#include "../OOP_Lab_2.2/Queue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace QueueUnitTest
{
    TEST_CLASS(QueueTests)
    {
    public:

        // Тест конструктора за умовчанням та початкового стану
        TEST_METHOD(TestDefaultConstructor)
        {
            Queue q;
            Assert::IsTrue(q.IsEmpty());
            Assert::AreEqual(0, q.GetCount());
        }

        // Тест конструктора ініціалізації та методу Push
        TEST_METHOD(TestInitConstructorAndPush)
        {
            Queue q(10);
            Assert::IsFalse(q.IsEmpty());
            Assert::AreEqual(1, q.GetCount());

            q.Push(20);
            q.Push(30);
            Assert::AreEqual(3, q.GetCount());
        }

        // Тест вилучення елементів (Pop / порядок FIFO)
        TEST_METHOD(TestPopAndFIFO)
        {
            Queue q;
            q.Push(100);
            q.Push(200);

            int val1 = q.Pop();
            Assert::AreEqual(100, val1);
            Assert::AreEqual(1, q.GetCount());

            int val2 = q.Pop();
            Assert::AreEqual(200, val2);
            Assert::IsTrue(q.IsEmpty());
        }

        // Тест конструктора копіювання
        TEST_METHOD(TestCopyConstructor)
        {
            Queue q1;
            q1.Push(5);
            q1.Push(15);

            Queue q2(q1); // Копіювання
            Assert::AreEqual(2, q2.GetCount());
            Assert::AreEqual(5, q2.Pop());
            Assert::AreEqual(15, q2.Pop());

            // Перевірка, що оригінальна черга не змінилася
            Assert::AreEqual(2, q1.GetCount());
        }

        // Тест операції присвоєння (=)
        TEST_METHOD(TestAssignmentOperator)
        {
            Queue q1;
            q1.Push(7);

            Queue q2;
            q2 = q1; // Присвоєння
            Assert::AreEqual(1, q2.GetCount());
            Assert::AreEqual(7, q2.Pop());
        }

        // Тест оператора перевірки наявності елементів (!)
        TEST_METHOD(TestNotOperator)
        {
            Queue qEmpty;
            Assert::IsFalse(!qEmpty); // Для порожньої черги !q повертає false

            Queue qFilled(5);
            Assert::IsTrue(!qFilled);  // Для непорожньої черги !q повертає true
        }

        // Тест методу перевірки коректності (SetCount)
        TEST_METHOD(TestSetCountValidation)
        {
            Queue q;
            q.SetCount(5);
            Assert::AreEqual(5, q.GetCount());

            // Перевірка на негативне значення (має спрацювати захист)
            q.SetCount(-3);
            Assert::AreEqual(5, q.GetCount()); // Значення не повинно змінитися
        }

    };
}