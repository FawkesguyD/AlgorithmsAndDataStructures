#ifndef ALGORITHMSANDDATASTRUCTURES_PR_1_H
#define ALGORITHMSANDDATASTRUCTURES_PR_1_H

#include <iostream>
#include <cstdlib>
#include <bitset>
using namespace std;

class Ex1_C
{
public: static void test() {
        cout << "Ex1.c | ";
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

class Ex1_B
{
public:
    int number{};
    void test() {
        cout << "Ex1.b | ";
        cout << "enter number(changing 7th bit of the digit to 1): ";
        cin >> number;
        number |= (1 << 6);
        cout << "modified number: " << number << endl;
    }
};

class Ex1_A
{
public:
    int number{};
    void test() {
        cout << "Ex1.a | ";
        cout << "enter number(changing 5th bit of the digit to 0): ";
        cin >> number;
        number &= ~(1 << 4);
        cout << "modified number: " << number << endl;
    }
};
#endif //ALGORITHMSANDDATASTRUCTURES_PR_1_H
