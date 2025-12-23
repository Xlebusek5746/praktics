#include <iostream>

/**
 * @brief Вычисляет площадь прямоугольника
 *
 * @param length Длина прямоугольника (должна быть положительным числом)
 * @param width Ширина прямоугольника (должна быть положительным числом)
 * @return double Площадь прямоугольника (length * width)
 * @exception Функция не проверяет корректность входных данных.
 *            При передаче отрицательных значений результат будет отрицательным.
 */
double calculateRectangleArea(double length, double width) {
    return length * width;
}


int main() {
    setlocale(LC_ALL, "Russian");
    // Тест 1: Прямоугольник с целыми сторонами
    double length1 = 5.0;
    double width1 = 3.0;
    double area1 = calculateRectangleArea(length1, width1);
    std::cout << "Прямоугольник " << length1 << " x " << width1
        << " имеет площадь: " << area1 << std::endl;

    // Тест 2: Прямоугольник с дробными сторонами
    double length2 = 7.5;
    double width2 = 2.5;
    double area2 = calculateRectangleArea(length2, width2);
    std::cout << "Прямоугольник " << length2 << " x " << width2
        << " имеет площадь: " << area2 << std::endl;
}

