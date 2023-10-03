#include "InterpolationSearch.h"



void genegateFile(const string& fileName, int amountOfNotes) {
    Data data;
    //открытие файла и его проверка
    ofstream file(fileName, ios::out);

    if (!file.is_open()) {
        cerr << "error of open the file" << endl;
        return;
    }

    //инициализация рандомайзера
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> key(100, 1000);
    uniform_int_distribution<int> disease(0, 100);

    //рандомайзер для фио
    vector<string> firstNames = {"John", "Mary", "Alexander", "Catherine", "Michael", "Anna"};
    vector<string> lastNames = {"Smith", "Johnson", "Brown", "Davis", "Miller", "Wilson"};
    uniform_int_distribution<int> firstNameIndex(0, int(firstNames.size()) - 1);
    uniform_int_distribution<int> lastNameIndex(0, int(lastNames.size()) - 1);

    //заполнение файла значениями
    for (int i = 0; i < 1; ++i) {
        data.key = key(gen);
        data.disease_id = disease(gen);
//        string lastName = lastNames[lastNameIndex(gen)];
        data.fullName = "Mary";
        file << data.key << " " << data.disease_id<< " " << data.fullName;
    }

    //закрываем файл
    file.close();

    cout << "File " << fileName << " was updated successfully" << endl;
}

void generateBinaryFile(const string& fileName, const string& binaryFileName) {
    Data data;
    // Открытие текстового файла для чтения
    ifstream textFile(fileName);

    if (!textFile.is_open()) {
        cerr << "error of open the file" << std::endl;
        return;
    }
    // Открытие бинарного файла для чтения
    ofstream binaryFile(binaryFileName, ios_base::binary);

    if (!binaryFile.is_open()) {
        cerr << "error of open the file" << std::endl;
        textFile.close();
        return;
    }

    //записываем строки из txt файла в бинарный
    while (textFile >> data.key >> data.disease_id >> data.fullName) {
//      getline(textFile, data.fullName);
        binaryFile.write(reinterpret_cast<const char*>(&data), sizeof(Data));
    }

    binaryFile.close();
    textFile.close();

    cout << "File was updated successfully" << endl;
}


void LinearSearch(const string& binaryFileName, int key) {
    Data data;
    ifstream binaryFile("binaryData.bin", ios_base::binary);

    if (!binaryFile.is_open() && !binaryFile.good()) {
        cerr << "error of open the file" << std::endl;
        return;
    }

    while(binaryFile.read(reinterpret_cast<char *>(&data), sizeof(Data))) {
        if (data.key == key) {
            cout << "Found the record -" << endl;
            cout << "Key: " << data.key << endl;
            cout << "Disease: " << data.disease_id << endl;
            cout << "Full name: " << data.fullName << endl;
            return;
        }
    }
    cout << "no such record" << endl;
}
