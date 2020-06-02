#include <cstdlib>
#include <iostream>
#include <fstream>
#include "planets.h"

using namespace std;

//функция чтения файла
void  Planets::readFile(string path, bool isSort)//метод объявляется в заголовочном файле
{
    arr_size_str =  10;
    arr_size_clmn =  4;
    ifstream file_out; // окрываем файл для чтения
    file_out.open(path);
    if (!file_out.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < arr_size_str; i++) //заполняем массив размерностью 10 строк на 4 столбца
        {
            for (int j = 0; j < arr_size_clmn; j++) {
                file_out >> arr[i][j];// из потока записываем в массив
            }
        }
    }
    file_out.close();     // закрываем файл
    //выводим на консоль из массива
    cout<<"Название "<<"Диаметр "<<"Жизнь "<<"Спутники "<<endl;
    for (int i = 0; i < arr_size_str; i++)
    {
            cout << arr[i][0] << "  "<< arr[i][1] << "       "<< arr[i][2]<< "     "<< arr[i][3]; //вывод пстрочно
            cout << endl;
    }

    if (isSort==true) {sortArr(arr);}
}
//функция для сортировки массива
void Planets::sortArr(string arr_[10][4])
{

    arr_size_str =  10;
    arr_size_clmn =  4;
    for (int i=0;i<arr_size_str;i++)
    {
        for(int j=0;j<arr_size_clmn;j++)
        {
            for (int k=arr_size_clmn-1;k>j;k--)
                if (arr_[i][k]<arr_[i][k-1])
                {
                    string tmp=arr_[i][k];
                    arr_[i][k]=arr_[i][k-1];
                    arr_[i][k-1]=tmp;
                }
            cout<<arr_[i][j]<<" ";
        }
        cout <<"\n";
    }
}

//функция чтения файла
void  Planets::writeFile(string pathTo)//метод объявляется в заголовочном файле
{
    arr_size_str =  2;//кол. строк
    arr_size_clmn =  4;//кол. столбцов
    string s;//переменная для сохранения считываемых символов введенных с клавиатуры

    fstream inOut;
    inOut.open(pathTo, ios::out);// окрываем файл для записи

    if (!inOut.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < arr_size_str; i++) //заполняем массив размерностью 10 строк на 4 столбца
        {
            cout << "Vvodim " << i + 1 << " stroku\n"; //подсказка
            for (int j = 0; j < arr_size_clmn; j++) {
                cin >> s;              //запоминаем введенное значение с клав.
                inOut << s << " "; //запись в файл
            }
            inOut <<endl;
        }
    }
    inOut.close();     // закрываем файл
    //выводим на консоль из массива
/*    cout<<"Название "<<"Диаметр "<<"Жизнь "<<"Спутники "<<endl;
    for (int i = 0; i < arr_size_str; i++)
    {
        cout << arr[i][0] << "  "<< arr[i][1] << "       "<< arr[i][2]<< "     "<< arr[i][3]; //вывод пстрочно
        cout << endl;
    }

    if (isSort==true) {sortArr(arr);}*/
}