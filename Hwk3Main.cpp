#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"


void PrintMenu(){

    cout << "PICK AN OPTION" << endl;
    cout << "d - Driver" << endl;
    cout << "p - Passenger" << endl;
    cout << "r - Ride" << endl;
    cout << "q - Quit Main Menu" << endl;

}

void DriverMenu(){
    cout << "DRIVER MENU" << endl;
    cout << "a - Add Driver" << endl;
    cout << "e - Edit Driver" << endl;
    cout << "d - Delete Driver" << endl;
    cout << "p - Print All Drivers" << endl;
    cout << "s - Search and Find Driver" << endl;
    cout << "q - Quit Driver Menu" << endl;
    cout << "PICK AN OPTION" << endl;
}

void PassengerMenu(){
    cout << "PASSENGER MENU" << endl;
    cout << "a - Add Passenger" << endl;
    cout << "e - Edit Passenger" << endl;
    cout << "d - Delete Passenger" << endl;
    cout << "p - Print All Passengers" << endl;
    cout << "q - Quit Passenger Menu" << endl;
    cout << "PICK AN OPTION" << endl;
}

void ExecuteDriverMenu(Drivers& driver, char driveroption){

    switch(driveroption){
        case 'a':
            driver.addDriver();
            break;
        case 'e':
            driver.editDrivers();
            break;
        case 'd':
            driver.deleteDriver();
            break;
        case 'p':
            driver.printAllDrivers();
            break;
        case 's':
            driver.searchAndFindDriver();
            break;
        case 'q':
            break;
        default:
            cout << endl;
            cout << "Error Invalid Input" << endl;
            cout << endl;
    }
}

void ExecutePassengerMenu(Passengers& passenger, char passengeroption){

    switch(passengeroption){
        case 'a':
            passenger.addPassenger();
            break;
        case 'e':
            passenger.editPassenger();
            break;
        case 'd':
            passenger.deletePassenger();
            break;
        case 'p':
            passenger.printAllPassengers();
            break;
        case 'q':
            break;
        default:
            cout << endl;
            cout << "Error Invalid Input" << endl;
            cout << endl;

    }
}

void ExecuteMenu(Passengers& passenger, Drivers& driver, char option){

    char driveroption;
    char passengeroption;

    switch(option){
        case 'd':
            do{
            cout << endl;
            DriverMenu();
            cin >> driveroption;
            cout << endl;
                if(driveroption != 'q'){
                    ExecuteDriverMenu(driver, driveroption);
                }

            }while(driveroption != 'q');

            break;

        case 'p':
            do{
            cout << endl;
            PassengerMenu();
            cin >> passengeroption;
            cout << endl;
                if(passengeroption != 'q'){
                    ExecutePassengerMenu(passenger, passengeroption);
                }
            }while(passengeroption != 'q');
            break;

        case 'r':
            cout << "Rider" << endl;
            break;

        default:
            cout << endl;
            cout << "Error Invalid Input " << endl;
            cout << endl;
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
    Drivers driver;
    Passengers passenger;
    
    do{
    PrintMenu();
    cin >> option;

        if(option != 'q'){
        ExecuteMenu(passenger, driver, option);
        }

    }while(option != 'q');

    return 0;
}
