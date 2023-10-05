#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"

Drivers input;

void PrintMenu(){

    cout << "PICK AN OPTION" << endl;
    cout << "d - Driver" << endl;
    cout << "p - Passenger" << endl;
    cout << "r - Ride" << endl;
    cout << "q - Quit Main Menu" << endl;

}

void DriverMenu(){
    cout << "PICK AN OPTION" << endl;
    cout << "a - Add Driver" << endl;
    cout << "q - Quit Driver Menu" << endl;
}

void ExecuteDriverMenu(char driveroption){

    switch(driveroption){
        case 'a':
            cout << "add" << endl;
            input.addDriver();
            break;
        case 'q':
            break;
        default:
            cout << "Error Invalid Input" << endl;

    }
}

void ExecuteMenu(char option){

    char driveroption;

    switch(option){
        case 'd':
            do{
            DriverMenu();
            cin >> driveroption;
                if(driveroption != 'q'){
                    ExecuteDriverMenu(driveroption);
                }

            }while(driveroption != 'q');

            break;

        case 'p':
            cout << "Passenger" << endl;
            break;

        case 'r':
            cout << "Rider" << endl;
            break;

        default:
            cout << "Error Invalid Input " << endl;
            break;
    }


}


int main()
{

    cout << "-----------------------------------------" << endl;
    cout << "|            Reese Goodavish            |" << endl;
    cout << "|      (reesegoodavish@my.unt.edu)      |" << endl;
    cout << "-----------------------------------------" << endl;

    char option;

    do{
    PrintMenu();
    cin >> option;

        if(option != 'q'){
        ExecuteMenu(option);
        }

    }while(option != 'q');


    return 0;
}