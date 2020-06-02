#include <cstdlib>
#include <iostream>
#include <fstream>
#include "planets.h"

using namespace std;

void  Planets::readFile(string path)//метод объявляется в заголовочном файле
{
    arr_size_str =  10;
    arr_size_clmn =  4;
    ifstream file_in; // окрываем файл для чтения
    file_in.open(path);
    if (file_in.is_open())
    {
        for (int i = 0; i < arr_size_str; i++) //заполняем массив размерностью 10 строк на 4 столбца
        {
            for (int j = 0; j < arr_size_clmn; j++) {
                file_in >> arr[i][j];// из потока записываем в массив
            }
        }
    }
    file_in.close();     // закрываем файл
    //выводим на консоль из массива
    cout<<"Название "<<"Диаметр "<<"Жизнь "<<"Спутники "<<endl;
    for (int i = 0; i < arr_size_str; i++)
    {
            cout << arr[i][0] << "  "<< arr[i][1] << "       "<< arr[i][2]<< "     "<< arr[i][3]; //вывод пстрочно
            cout << endl;
    }

    sortArr(arr);
}
void Planets::temp()
    {
    cout << "temp"<<endl;};
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