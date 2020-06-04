
#ifndef SEMESTR2_PLANETS_H
#define SEMESTR2_PLANETS_H
#include <iostream>
#include <string>
using namespace std;


class Planets {
public:
    Planets(void);  // конструктор класса по умолчанию
    Planets(int s,int c); //инициализация полей размерности массива
    Planets(const Planets &ref_op);    // Прототип конструктора копирования
    ~Planets();// Деструктор класса

    int arr_size_str; //кол. строк в массиве
    int arr_size_clmn;//кол. столбцов в массиве
    string sourceValue, newValue, saccess=" ";
    string sinchar;//переменная для сохранения считываемых символов введенных с клавиатуры
    void readFile(string path, bool isSort, bool isEdit);//path- путь к файлу; isSort - вывод с сортировкой если True
    void  writeFile(string pathTo);
    void sortArr(string arr_[10][4]);
    void editArr(string arr_[10][4]);
    string arr[10][4];
    void temp();



    friend ostream& operator<<(ostream &output, Planets &P ); //Перегружаем операцию “ << “ для классов «Планета» как friend класса.
    friend istream &operator>>(istream  &input, Planets &P ); //Перегружаем операцию “ >> “ для класса «Планета»  как friend класса.
    friend bool operator==(Planets &p1, Planets &p2);//Перегружае операцию сравнения “ <  и ==” для класса «Планета», использовав для этого значение одного из полей как friend класса.
    friend bool operator<(Planets &p1, Planets &p2);

};
ostream& operator<<(ostream &output, Planets &P );//Перегружаем операцию “ << “ для классов «Планета»  и ofstream для вывода на экран данных из массива.
istream &operator>>(istream  &input, Planets &P );//Перегружаем операцию “ >> “ для класса «Планета»  и ifstream для чтения данных о планетах из файла в массив «Солнечная система» из объектов класса «Планета».
bool operator==(Planets &p1, Planets &p2);//Перегружае операцию сравнения “ <  и ==” для класса «Планета»,
bool operator<(Planets &p1, Planets &p2);

#endif //SEMESTR2_PLANETS_H

