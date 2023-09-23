#ifndef ALGORITHMSANDDATASTRUCTURES_EX3_H
#define ALGORITHMSANDDATASTRUCTURES_EX3_H

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

using namespace std;

class FileSorter {
public:
    vector<int> numbers;
    FileSorter(const string& inputFileName, const string& outputFileName)
        : inputFileName_(inputFileName), outputFileName_(outputFileName) {}

    void Sort() {
        auto start = chrono::high_resolution_clock::now();

        ifstream inputFile(inputFileName_);
        if (!inputFile.is_open()) {
            cerr << "Failed to open input file." << endl;
            return;
        }

        // Чтение чисел из файла и сохранение их в векторе.
        int num;
        while (inputFile >> num) {
            numbers.push_back(num);
        }

        inputFile.close();

        // Сортировка чисел слиянием.
        MergeSort(numbers, 0, numbers.size() - 1);

        ofstream outputFile(outputFileName_);
        if (!outputFile.is_open()) {
            cerr << "Failed to open output file." << endl;
            return;
        }

        // Запись отсортированных чисел в выходной файл.
        for (int num : numbers) {
            outputFile << num << endl;
        }

        outputFile.close();

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "Sorting completed in " << duration.count() << " seconds." << endl;
    }

private:
    string inputFileName_;
    string outputFileName_;

    void Merge(std::vector<int>& arr, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }

        for (int i = 0; i < n2; i++) {
            rightArr[i] = arr[middle + 1 + i];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void MergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;
            MergeSort(arr, left, middle);
            MergeSort(arr, middle + 1, right);
            Merge(arr, left, middle, right);
        }
    }
public:
    void GenerateInputFile(int numElements, int maxValue) {
        ofstream inputFile(inputFileName_);
        if (!inputFile.is_open()) {
            cerr << "Failed to open input file for generation." << std::endl;
            return;
        }

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, maxValue);

        set<int> uniqueNumbers; // Для отслеживания уникальных значений

        while (uniqueNumbers.size() < numElements) {
            int num = dis(gen);
            if (uniqueNumbers.insert(num).second) { // Вставляем только уникальные числа
                inputFile << num << endl;
            }
        }

        inputFile.close();

        cout << "Input file generated." << endl;
    }

    void GenerateOutputFile() {
        // Here you can generate an empty output file if needed.
        // This method can be customized as per your requirements.
        ofstream outputFile(outputFileName_);
        if (!outputFile.is_open()) {
            cerr << "Failed to open output file for generation." << endl;
            return;
        }

        outputFile.close();

        cout << "Output file generated." << endl;
    }

    size_t GetMemoryUsage() {
        size_t element_size = sizeof(int); // Размер одного элемента (int) в байтах
        size_t vector_size = numbers.size();    // Количество элементов в векторе

        size_t memory_usage = element_size * vector_size;

        return memory_usage;
    }
};

#endif //ALGORITHMSANDDATASTRUCTURES_EX3_H
