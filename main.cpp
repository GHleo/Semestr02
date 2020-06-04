#include "planets.h"
//#include "planets.cpp"
#include "menu.h"
//#include "menu.cpp"
#include <iostream>

using namespace std;

int main()
{
    Menu m; //Создаем объект класса Menu
    //m.PrintMenu();
/*    string file_name = "/home/uleo/CLionProjects/Semestr2/plantes.txt";
    Planets p;
    p.readFile(file_name,false,false);*/

/*    Planets p1; // создание объекта p1
    Planets p2(10, 4); // создание объекта p2 - вызывается конструктор по умолчанию
    Planets p3 = p2;// инициализация объекта => вызывается конструктор копирования*/


    int choice = 0;
    do
    {
        //system("cls");
        m.DisplayMainMenu();
        choice = m.GetInput();
        switch(choice) {
            case 1:
                m.Options();
                break;
            case 2:
                cout << "Exit!";
                break;

            default:
                break;
        }
    } while(choice!=2);


    return 0;
}