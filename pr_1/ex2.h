#ifndef ALGORITHMSANDDATASTRUCTURES_EX2_H
#define ALGORITHMSANDDATASTRUCTURES_EX2_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Ex2_A
{
public:
    Ex2_A() {
        cout << "Ex2.a Sorting(unique numbers)| ";
        // Инициализируем генератор случайных чисел
        srand(static_cast<unsigned int>(time(nullptr)));

        // Запрашиваем у пользователя количество чисел (не более 8)
        int numCount;
        do {
            cout << "enter amount of numbers (no more than 7): ";
            cin >> numCount;
        } while (numCount < 1 || numCount > 7);

        // Генерируем случайные числа от 0 до 7 и добавляем их в вектор
        vector<unsigned char> numbers;
        for (int i = 0; i < numCount; ++i) {
            unsigned char num = static_cast<unsigned char>(rand() % 8);
            numbers.push_back(num);
        }

        // Выводим исходный набор чисел
        cout << "Default: ";
        for (unsigned char num : numbers) {
            cout << static_cast<int>(num) << " ";
        }
        cout << std::endl;

        // Инициализируем битовый массив
        unsigned char bitArray = 0;

        // Устанавливаем биты в битовом массиве в соответствии с числами из вектора
        for (unsigned char num : numbers) {
            bitArray |= (1 << num);
        }

        // Выводим отсортированный набор чисел из битового массива
        cout << "Sorted: ";
        for (int i = 0; i < 8; ++i) {
            if (bitArray & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << std::endl;
    }
};

class Ex2_B
{
public:
    Ex2_B() {
        cout << "Ex2.b Sorting(unique numbers)| ";
        // Инициализируем генератор случайных чисел
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Запрашиваем у пользователя количество чисел (не более 64)
        int numCount;
        do {
            std::cout << "enter amount of numbers (no more than 63): ";
            std::cin >> numCount;
        } while (numCount < 1 || numCount > 63);

        // Генерируем случайные числа от 0 до 63 и добавляем их в вектор
        std::vector<unsigned long long> numbers;
        for (int i = 0; i < numCount; ++i) {
            unsigned long long num = static_cast<unsigned long long>(std::rand() % 64);
            numbers.push_back(num);
        }

        // Выводим исходный набор чисел
        std::cout << "Default: ";
        for (unsigned long long num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Инициализируем битовый массив
        unsigned long long bitArray = 0;

        // Устанавливаем биты в битовом массиве в соответствии с числами из вектора
        for (unsigned long long num : numbers) {
            bitArray |= (1ULL << num);
        }

        // Выводим отсортированный набор чисел из битового массива
        std::cout << "Sorted: ";
        for (int i = 0; i < 64; ++i) {
            if (bitArray & (1ULL << i)) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }
};

class Ex2_C
{
public:
    Ex2_C() {
        cout << "Ex2.c Sorting(unique numbers)| ";
        // Инициализируем генератор случайных чисел
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Запрашиваем у пользователя количество чисел (не более 64)
        int numCount;
        do {
            std::cout << "enter amount of numbers (no more than 64): ";
            std::cin >> numCount;
        } while (numCount < 1 || numCount > 63);

        // Генерируем случайные числа от 0 до 63 и добавляем их в вектор
        std::vector<unsigned char> numbers;
        for (int i = 0; i < numCount; ++i) {
            unsigned char num = static_cast<unsigned char>(std::rand() % 64);
            numbers.push_back(num);
        }

        // Выводим исходный набор чисел
        std::cout << "Default: ";
        for (unsigned char num : numbers) {
            std::cout << static_cast<int>(num) << " ";
        }
        std::cout << std::endl;

        // Инициализируем битовый массив (массив из 8 байт)
        unsigned char bitArray[8] = {0};

        // Устанавливаем биты в битовом массиве в соответствии с числами из вектора
        for (unsigned char num : numbers) {
            int byteIndex = num / 8;
            int bitIndex = num % 8;
            bitArray[byteIndex] |= (1 << bitIndex);
        }

        // Выводим отсортированный набор чисел из битового массива
        std::cout << "Sorted: ";
        for (int byteIndex = 0; byteIndex < 8; ++byteIndex) {
            for (int bitIndex = 0; bitIndex < 8; ++bitIndex) {
                if (bitArray[byteIndex] & (1 << bitIndex)) {
                    std::cout << static_cast<int>(byteIndex * 8 + bitIndex) << " ";
                }
            }
        }
        std::cout << std::endl;
    }
};
#endif //ALGORITHMSANDDATASTRUCTURES_EX2_H
