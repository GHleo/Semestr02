#include <cstdlib>
#include <iostream>
#include <fstream>
#include "planets.h"

using namespace std;

// Деструктор класса Planets
Planets::~Planets()
{
    // Динамически удаляем массив, который выделили ранее
    //delete[] arr;
}

Planets::Planets(void)
{
}

Planets::Planets(int s,int c)
{
    arr_size_str = s;
    arr_size_clmn = c;
}

//конструктор копирования
Planets::Planets(const Planets &ref_op)
{
    // копирование данных из одного объекта в другой
    arr_size_str = ref_op.arr_size_str;
    arr_size_clmn= ref_op.arr_size_clmn;
}

/*string Planets::GetA(void) { return sourceValue;}
string Planets::GetB(void) { return newValue; }*/


//функция чтения файла
//void  Planets::readFile(string path, bool isSort, bool isEdit)//метод объявляется в заголовочном файле
void  Planets::readFile(string path, bool isSort, bool isEdit)
{
   // arr_size_str =  10;
   // arr_size_clmn =  4;
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

    if (isSort==true) {sortArr(arr);}//если необходима сортировка массива\данных из файла
    if (isEdit==true) {editArr(arr);}//если необходимо редактирование массива\данных из файла

}
//функция для сортировки массива
void Planets::sortArr(string arr_[10][4])
{

/*    arr_size_str =  10;
    arr_size_clmn =  4;*/
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

//функция для редактирования данных массива
void Planets::editArr(string arr_[10][4])
{
   // arr_size_str =  10;
   // arr_size_clmn =  4;
    cout << "Vvodim Name for edit \n"; //подсказка
    cin >> sourceValue;//значение для редактирования
    cout << "Vvodim new Name \n"; //подсказка
    cin >> newValue;//новое значение
    for (int i=0;i<arr_size_str;i++)
    {
        for(int j=0;j<arr_size_clmn;j++)
        {
            if (arr_[i][j] == sourceValue)//если нашли значение на редактирование - меняем на новое
            {
                arr_[i][j] = newValue;
                saccess = "Value: "+sourceValue + " - Edited on " + newValue; //заполняем переменная для вывода на печать информации о редактировании
            }
        }
    }
    if (saccess == " ") saccess = "Value: "+sourceValue + " - not Edited!";//заполняем переменную для вывода на печать информации о редактировании (если редактирования не произошло)
    cout<<saccess<<endl;//вывод на печать информации о редактировании
    //Вывод на печать итогового массива
    cout<<endl;
    cout<<"Название "<<"Диаметр "<<"Жизнь "<<"Спутники "<<endl;
    for (int i = 0; i < arr_size_str; i++)
    {
        cout << arr_[i][0] << "  "<< arr_[i][1] << "       "<< arr_[i][2]<< "     "<< arr_[i][3]; //вывод пстрочно
        cout << endl;
    }

}

//функция чтения файла
void  Planets::writeFile(string pathTo)//метод объявляется в заголовочном файле
{
    arr_size_str =  2;//кол. строк
    arr_size_clmn =  4;//кол. столбцов

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
                cin >> sinchar;              //запоминаем введенное значение с клав.
                inOut << sinchar << " "; //запись в файл
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
//Перегружаем операцию “ << “
ostream &operator<<( ostream &output, const Planets &P ) {
    output << P.arr;
    return output;
}
//Перегружаем операцию “ >> “ для функции writeFile()
istream &operator>>( istream  &input, Planets &P ) {
    input >> P.sinchar;
    return input;
}

//Перегружаем '==' оператор для функции editArr()
bool operator==(Planets &p1, Planets &p2)
{
    int i,j;
    return ( p1.arr[i][j] == p2.sourceValue);
}

//Перегружаем '<' оператор для функции sortArr()
bool operator<(Planets &p1, Planets &p2)
{
    int i,j;
    return ( p1.arr[i][j] < p2.arr[i][j]);
}