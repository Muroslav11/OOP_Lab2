#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2.4.1/Matrix.h"
#include "../OOP_Lab_2.4.1/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MatrixUnitTest
{
    TEST_CLASS(MatrixTests)
    {
    public:

        // Тест конструктора за умовчанням та методів доступу (гетерів)
        TEST_METHOD(TestDefaultConstructor)
        {
            Matrix mat;
            Assert::AreEqual(1, mat.getRows());
            Assert::AreEqual(1, mat.getCols());
            Assert::AreEqual(0, mat.getElement(0, 0));
        }

        // Тест конструктора ініціалізації
        TEST_METHOD(TestInitConstructor)
        {
            Matrix mat(2, 3);
            Assert::AreEqual(2, mat.getRows());
            Assert::AreEqual(3, mat.getCols());
            // Перевіряємо занулення елементів
            Assert::AreEqual(0, mat.getElement(0, 0));
            Assert::AreEqual(0, mat.getElement(1, 2));
        }

        // Тест конструктора копіювання та оператора присвоєння
        TEST_METHOD(TestCopyAndAssignment)
        {
            Matrix mat1(2, 2);
            mat1.setElement(0, 0, 5);
            mat1.setElement(1, 1, 10);

            // Конструктор копіювання
            Matrix mat2(mat1);
            Assert::AreEqual(2, mat2.getRows());
            Assert::AreEqual(2, mat2.getCols());
            Assert::AreEqual(5, mat2.getElement(0, 0));
            Assert::AreEqual(10, mat2.getElement(1, 1));

            // Оператор присвоєння
            Matrix mat3;
            mat3 = mat1;
            Assert::AreEqual(2, mat3.getRows());
            Assert::AreEqual(2, mat3.getCols());
            Assert::AreEqual(5, mat3.getElement(0, 0));
            Assert::AreEqual(10, mat3.getElement(1, 1));
        }

        // Тест операції віднімання матриць (-)
        TEST_METHOD(TestSubtraction)
        {
            Matrix mat1(2, 2);
            mat1.setElement(0, 0, 10);
            mat1.setElement(0, 1, 20);
            mat1.setElement(1, 0, 30);
            mat1.setElement(1, 1, 40);

            Matrix mat2(2, 2);
            mat2.setElement(0, 0, 2);
            mat2.setElement(0, 1, 5);
            mat2.setElement(1, 0, 10);
            mat2.setElement(1, 1, 15);

            Matrix result = mat1 - mat2;

            Assert::AreEqual(8, result.getElement(0, 0));
            Assert::AreEqual(15, result.getElement(0, 1));
            Assert::AreEqual(20, result.getElement(1, 0));
            Assert::AreEqual(25, result.getElement(1, 1));
        }

        // Тест операцій порівняння (==)
        TEST_METHOD(TestComparisons)
        {
            Matrix mat1(2, 2);
            mat1.setElement(0, 0, 7);

            Matrix mat2(2, 2);
            mat2.setElement(0, 0, 7);

            Matrix mat3(2, 2);
            mat3.setElement(0, 0, 5);

            Assert::IsTrue(mat1 == mat2);
            Assert::IsFalse(mat1 == mat3);
        }

        // Тест обчислення норми матриці (корінь із суми квадратів елементів)
        TEST_METHOD(TestNorm)
        {
            Matrix mat(1, 2);
            mat.setElement(0, 0, 3); // 3^2 = 9
            mat.setElement(0, 1, 4); // 4^2 = 16
            // Сума = 25, корінь = 5

            double normVal = mat.Norm();
            Assert::AreEqual(5.0, normVal, 0.0001);
        }

        // Тест приведення до літерного рядка (operator string)
        TEST_METHOD(TestStringConversion)
        {
            Matrix mat(1, 1);
            mat.setElement(0, 0, 99);

            string s = string(mat);
            // Перевіряємо, що рядок містить значення елемента
            Assert::IsTrue(s.find("99") != string::npos);
        }

        // Тест операції індексування через каскадні дужки ([][])
        TEST_METHOD(TestIndexing)
        {
            Matrix mat(2, 2);
            mat[0][1] = 42;
            Assert::AreEqual(42, mat[0][1]);
        }

    };
}