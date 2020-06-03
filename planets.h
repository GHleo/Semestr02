
#ifndef SEMESTR2_PLANETS_H
#define SEMESTR2_PLANETS_H
#include <iostream>
#include <string>
using namespace std;


class Planets {
public:
    int arr_size_str; //кол. строк в массиве
    int arr_size_clmn;//кол. столбцов в массиве
    string sinchar;//переменная для сохранения считываемых символов введенных с клавиатуры
    void readFile(string path, bool isSort, bool isEdit);//path- путь к файлу; isSort - вывод с сортировкой если True
    void  writeFile(string pathTo);
    void sortArr(string arr_[10][4]);
    void editArr(string arr_[10][4]);
    string arr[10][4];
    void temp();

    friend ostream& operator<<(ostream &output, Planets &P ); //Перегружаем операцию “ << “ для классов «Планета» как friend класса.
    friend istream &operator>>(istream  &input, Planets &P ); //Перегружаем операцию “ >> “ для класса «Планета»  как friend класса.

};
ostream& operator<<(ostream &output, Planets &P );//Перегружаем операцию “ << “ для классов «Планета»  и ofstream для вывода на экран данных из массива.
istream &operator>>(istream  &input, Planets &P );//Перегружаем операцию “ >> “ для класса «Планета»  и ifstream для чтения данных о планетах из файла в массив «Солнечная система» из объектов класса «Планета».

#endif //SEMESTR2_PLANETS_H

