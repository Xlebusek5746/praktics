#include <iostream>
#include <cmath>

class SquareOperations {
private:
    double a, b;
    double multiplyResult, divideResult;

public:
    // Конструктор по умолчанию
    SquareOperations() : a(0), b(1), multiplyResult(0), divideResult(0) {}

    // Конструктор с параметрами
    SquareOperations(double num1, double num2) {
        setNumbers(num1, num2);
    }

    // Метод для установки двух чисел
    void setNumbers(double num1, double num2) {
        a = num1;
        b = num2;
        // Обнуляем предыдущие результаты при установке новых чисел
        multiplyResult = 0;
        divideResult = 0;
    }

    // Умножение квадратов чисел
    void multiplySquares() {
        multiplyResult = pow(a, 2) * pow(b, 2);
    }

    // Деление квадратов чисел
    void divideSquares() {
        if (b != 0) {
            divideResult = pow(a, 2) / pow(b, 2);
        }
        else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            divideResult = 0;
        }
    }

    // Вывод результатов вычислений
    void getResults() const {
        std::cout << "Число a = " << a << std::endl;
        std::cout << "Число b = " << b << std::endl;
        std::cout << "a² = " << pow(a, 2) << std::endl;
        std::cout << "b² = " << pow(b, 2) << std::endl;
        std::cout << "a² * b² = " << multiplyResult << std::endl;
        std::cout << "a² / b² = " << divideResult << std::endl;
    }

    // Геттеры для получения отдельных результатов (опционально)
    double getMultiplyResult() const {
        return multiplyResult;
    }

    double getDivideResult() const {
        return divideResult;
    }

    // Геттеры для чисел
    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }
};

// Пример использования класса
int main() {
    int q;
    setlocale(LC_ALL, "Russian");
    // Создание объекта с помощью конструктора с параметрами
    SquareOperations ops1(3, 4);

    std::cout << "Пример 1:" << std::endl;
    ops1.multiplySquares();
    ops1.divideSquares();
    ops1.getResults();

    std::cout << "\nПример 2:" << std::endl;
    // Создание объекта с помощью конструктора по умолчанию
    SquareOperations ops2;

    // Установка чисел через метод setNumbers
    ops2.setNumbers(5, 2);
    ops2.multiplySquares();
    ops2.divideSquares();
    ops2.getResults();

    std::cout << "\nПример 3 (проверка деления на ноль):" << std::endl;
    SquareOperations ops3(7, 0);
    ops3.multiplySquares();
    ops3.divideSquares(); // Будет сообщение об ошибке
    ops3.getResults();
    std::cin >> q;

    return 0;
}