#ifndef ALGORITHMSANDDATASTRUCTURES_PR_1_H
#define ALGORITHMSANDDATASTRUCTURES_PR_1_H

#include <iostream>
#include <cstdlib>
#include <bitset>
using namespace std;

class ex1_c
{
public: void test() {
        unsigned int x = 25;
        const int n = sizeof(int)*8;
        unsigned maska = (1 << (n - 1));
        cout << "Start view of maska: " << bitset<n> (maska) << endl;
        cout << "Result: ";
        for (int i = 0; i < n; ++i) {
            cout << ((x & maska) >> (n - i));
        }
        cout << endl;
    }
};

class ex1_b
{
public:
    int number{};
    void test() {
        cout << "enter number: ";
        cin >> number;
        number |= (1 << 6);
        cout << "modified number: " << number << endl;
    }
};

class ex1_a
{
public:
    int number{};
    void test() {
        cout << "enter number: ";
        cin >> number;
        number &= ~(1 << 4);
        cout << "modified number: " << number << endl;
    }
};
#endif //ALGORITHMSANDDATASTRUCTURES_PR_1_H
