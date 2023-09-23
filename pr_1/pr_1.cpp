#include "ex1.h"
#include "ex2.h"
#include "ex3.h"

int main() {
    int task;

    cout << "enter task: ";
    cin >> task;

    switch(task) {
        default:
            return 0;
        case 1: {
            // задание 1 | практика 1
            ex1_a test1;
            ex1_b test2;
            ex1_c test3;

            test1.test();
            test2.test();
            test3.test();
            return 0;
        }
        case 2: {
            // задание 2 | практика 1
            ex2_a test4;
            ex2_b test5;
            ex2_c test6;

            test4.test();
            test5.test();
            test6.test();
            return 0;
        }
        case 3: {
            // задание 1
            cout << "loading.." << endl;
            string inputFileName = "input.txt";
            string outputFileName = "output.txt";

            FileSorter sorter(inputFileName, outputFileName);
            sorter.GenerateInputFile(250000, 10000000); // Генерация файла с 1 миллионом чисел в диапазоне от 0 до 10000.
            sorter.GenerateOutputFile();

            sorter.Sort(); // вызываем сортировку

            // задание 2
            size_t memory_usage = sorter.GetMemoryUsage();
            cout << "Memory usage of the vector: " << memory_usage << " bytes." << endl;
            return 0;
        }
    }
}