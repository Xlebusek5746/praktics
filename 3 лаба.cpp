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

    // Тест 2: Прямоугольник с дробными сторонами
    double length2 = 7.5;
    double width2 = 2.5;
    double area2 = calculateRectangleArea(length2, width2);
    std::cout << "Прямоугольник " << length2 << " x " << width2
        << " имеет площадь: " << area2 << std::endl;

    // Тест 3: Квадрат (частный случай прямоугольника)
    double side = 4.0;
    double area3 = calculateRectangleArea(side, side);
    std::cout << "Квадрат со стороной " << side
        << " имеет площадь: " << area3 << std::endl;
}

