#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFraction
{
    TEST_CLASS(FractionTests)
    {
    public:
        TEST_METHOD(test1)
        {
            Fraction f1(1, 2);
            Fraction f2(1, 3);

            Fraction result = Fraction::addFractions(f1, f2);

            Assert::AreEqual(5, result.numerator);
            Assert::AreEqual(6, result.denominator);
        }

        TEST_METHOD(test2)
        {
            Fraction f1(2, 3);
            Fraction f2(3, 4);
            Fraction result = Fraction::multiplyFractions(f1, f2);
            Assert::AreEqual(1, result.numerator);
            Assert::AreEqual(2, result.denominator);
        }
        TEST_METHOD(test3)
        {
            auto test3 = []() {
                Fraction f(5, 0);
                };

            Assert::ExpectException<std::invalid_argument>(test3);
        }
        TEST_METHOD(test4)
        {
            auto test4 = []() {
                Fraction f(1, 0);
                };

            Assert::ExpectException<std::invalid_argument>(test4);
        }
    };
}