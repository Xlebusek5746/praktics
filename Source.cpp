#include "functions.h"
#include <iostream>
#include <cmath>

//Пример использования
int main() {
    setlocale(LC_CTYPE, "rus");
    // Создаем две дроби
    Fraction f1(2, 3);
    Fraction f2(3, 4);

    std::cout << "Дробь 1: ";
    f1.print();
    std::cout << std::endl;

    std::cout << "Дробь 2: ";
    f2.print();
    std::cout << std::endl;

    // Сложение дробей
    Fraction sum = Fraction::addFractions(f1, f2);
    std::cout << "Сумма: ";
    sum.print();
    std::cout << " = " << Fraction::toDecimal(sum) << std::endl;

    // Умножение дробей
    Fraction product = Fraction::multiplyFractions(f1, f2);
    std::cout << "Произведение: ";
    product.print();
    std::cout << " = " << Fraction::toDecimal(product) << std::endl;

    // Упрощение дроби
    Fraction f3(8, 12);
    std::cout << "\nДо упрощения: ";
    f3.print();
    std::cout << std::endl;

    Fraction::simplifyFraction(f3);
    std::cout << "После упрощения: ";
    f3.print();
    std::cout << std::endl;

    // Преобразование в десятичное число
    std::cout << "В десятичном виде: " << Fraction::toDecimal(f3) << std::endl;

    return 0;
}
