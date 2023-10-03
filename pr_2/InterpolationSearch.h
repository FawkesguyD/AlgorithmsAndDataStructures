#ifndef ALGORITHMSANDDATASTRUCTURES_INTERPOLATIONSEARCH_H
#define ALGORITHMSANDDATASTRUCTURES_INTERPOLATIONSEARCH_H
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <cstring>
using namespace std;

struct Data {
    int key;
    int disease_id;
    string fullName;
};

int InterpolationSearch();
void genegateFile(const string& fileName, int amountOfNotes);
void generateBinaryFile(const string& fileName, const string& binaryFileName);
void LinearSearch(const string& binaryFileName, int key);

#endif //ALGORITHMSANDDATASTRUCTURES_INTERPOLATIONSEARCH_H
