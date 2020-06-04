
#include <cstdlib>
#include <iostream>
#include "menu.h"
#include "planets.h"

using namespace std;


/*void Menu::PrintMenu()
{
    int myChoice = 0;

    cout << "********** Main Menu **********" << endl;
    cout << "(1): Option 1" << endl;
    cout << "(2): Option 2" << endl;
    cout << "(3): Option 3" << endl;
    cin >> myChoice;

    switch(myChoice)
    {
        case 1:
            cout << "case 1" << endl;
            //FunctionOne();
            break;
        case 2:
            "case 2";
            //FunctionTwo();
            break;
        case 3:
            "case 3";
            //FunctionThree();
            break;
        default:
            cout << "ERROR! You have selected an invalid choice." << endl;
            break;
    }
}*/

int Menu::GetInput()
{
    int choice;
    cin >> choice;
    return choice;
}

void Menu::DisplayMainMenu()
{
    cout << "Main Menu\n";
    cout << "Please make your selection\n";
    //cout << "1 - \n";
    cout << "1 - Options\n";
    cout << "2 - Quit\n";

}

void Menu::DisplayOptionsMenu()
{
    cout << "Options Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Open DB\n";
    cout << "2 - Write DB\n";
    cout << "3 - Sort DB\n";
    cout << "4 - Edit DB\n";
    cout << "5 - Out to console DB\n";
    cout << "6 - Exit\n";
}

void Menu::Options()
{
    string pathtofile= "/home/uleo/CLionProjects/Semestr02/planetsList.txt";
    string pathtofileTo= "/home/uleo/CLionProjects/Semestr02/planetsList2.txt";
    Planets p; // Создали объект класса Planets
    Planets p2(10, 4); // создание объекта p2 - вызывается конструктор по умолчанию
    Planets p3 = p2;// инициализация объекта => вызывается конструктор копирования

    int choice = 0;
    do
    {
        system("cls");
        DisplayOptionsMenu();
        choice = GetInput();
        switch(choice)
        {
            case 1:
                cout << "DB opened!";
                break;
            case 2:
                p3.writeFile(pathtofileTo);
                break;
            case 3:
                p3.readFile(pathtofile,true, false);
                break;
            case 4:
                p3.readFile(pathtofile,false,true);;
                break;
            case 5:
                p3.readFile(pathtofile,false,false);
                break;
            default:
                break;
        }
    } while(choice!=6);
}

