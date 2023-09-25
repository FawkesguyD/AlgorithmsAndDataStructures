#include "ex1.h"
#include "ex2.h"
#include "ex3.h"

int main() {
    int task;

    cout << "enter task: ";
    cin >> task;
    cout << endl;

    switch(task) {
        default:
            return 0;
        case 1: {
            // задание 1 | практика 1
            Ex1_A ex1_a;
            Ex1_B ex1_b;
            Ex1_C ex1_c;

            ex1_a.test();
            ex1_b.test();
            ex1_c.test();
            return 0;
        }
        case 2: {
            // задание 2 | практика 1
            Ex2_A ex2_a;
            Ex2_B ex2_b;
            Ex2_C ex2_c;

            ex2_a.test();
            ex2_b.test();
            ex2_c.test();
            return 0;
        }
        case 3: {
            cout << "Ex3 |\n";
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
            cout << "Memory usage of the vector: " << memory_usage << "B(" << memory_usage * 0.0000010 << "MB) bytes." << endl;
            return 0;
        }
    }
}