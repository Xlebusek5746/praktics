#include <windows.h> // Библиотека для работы с Windows API, включая реестр
#include <iostream>
#include <string>

int main() {
    setlocale(0, "ru");
    HKEY hKey; // Указатель для работы с ключом реестра
    LPCSTR subKey = "Software\\MyConsoleApp"; // Путь к нашему ключу в реестре

    // Создаем или открываем ключ
    if (RegCreateKeyExA(HKEY_CURRENT_USER, subKey, 0, NULL, 0, KEY_WRITE | KEY_READ, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        char color[255]; // Буфер для хранения строки с цветом
        DWORD size = sizeof(color); // Переменная для хранения размера буфера
        DWORD type = REG_SZ; // Переменная для хранения типа данных (REG_SZ - строковый тип)

        // Пробуем прочитать значение
        if (RegQueryValueExA(hKey, "FavoriteColor", NULL, &type, (BYTE*)color, &size) == ERROR_SUCCESS) {
            std::cout << "Текущий любимый цвет из реестра: " << color << std::endl;

            std::cout << "Хотите изменить цвет? (y/n): ";
            char choice; // Переменная для хранения выбора пользователя
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                std::cout << "Введите новый любимый цвет: ";
                std::cin >> color;
                // Записываем новое значение в реестр
                RegSetValueExA(hKey, "FavoriteColor", 0, REG_SZ, (BYTE*)color, strlen(color) + 1);
                std::cout << "Цвет обновлен!" << std::endl;
            }
        }
        else {
            // Значение не найдено - запрашиваем впервые
            std::cout << "Введите любимый цвет: ";
            std::cin >> color;
            // Записываем значение в реестр впервые
            RegSetValueExA(hKey, "FavoriteColor", 0, REG_SZ, (BYTE*)color, strlen(color) + 1);
            std::cout << "Цвет сохранен в реестр!" << std::endl;
        }

        RegCloseKey(hKey); // Закрываем дескриптор ключа (важно для освобождения ресурсов)
    }
    else {
        std::cout << "Ошибка при работе с реестром!" << std::endl;
    }

    return 0;
} 