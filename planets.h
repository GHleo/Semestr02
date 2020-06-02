
#ifndef SEMESTR2_PLANETS_H
#define SEMESTR2_PLANETS_H
#include <string>
using namespace std;


class Planets {
public:
    int arr_size_str; //кол. строк в массиве
    int arr_size_clmn;//кол. столбцов в массиве
    void readFile(string path);
    void sortArr(string arr_[10][4]);
    string arr[10][4];
    void temp();

};


#endif //SEMESTR2_PLANETS_H

