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
           new Ex1_A;
           new Ex1_B;
           new Ex1_C;
           return 0;
       }
       case 2: {
           // задание 2 | практика 1
           new Ex2_A;
           new Ex2_B;
           new Ex2_C;
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