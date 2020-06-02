
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
    Planets p;

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
                cout << "Write ???";
                break;
            case 3:
                cout << "Sort ???";
                break;
            case 4:
                cout << "Edit ???";
                break;
            case 5:
                p.readFile(pathtofile);
                break;
            default:
                break;
        }
    } while(choice!=6);
}

