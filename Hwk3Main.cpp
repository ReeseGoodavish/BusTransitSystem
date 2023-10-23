/*
Name: Reese Goodavish
ID: (11456359)
UNT EMAIL: (reesegoodavish@my.unt.edu)
Date: October 12th, 2023
Instructor: David Keathly
Class: CSCE 1040 Section 001-002 (2766) FALL 2023
Description: This program represents a back end input and mondify system for a transit system, 
users are given the choice to input and modify drivers, passengers, and rides. After gathering input
infomation is to be stored in their respected collections where they can be fetched for later use.
*/
#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"
#include "Rides.h"


//MAIN MENU, prints to user to pick from 3 categories, or quit to exit program.
void PrintMenu(){

    cout << "PICK AN OPTION" << endl;
    cout << "d - Driver" << endl;
    cout << "p - Passenger" << endl;
    cout << "r - Ride" << endl;
    cout << "q - Quit Main Menu" << endl;

}
//Driver Menu, prints to user to inform them what they can do with Driver
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

//Passenger Menu, prints to user to inform them what they can do with Passenger
void PassengerMenu(){
    cout << "PASSENGER MENU" << endl;
    cout << "a - Add Passenger" << endl;
    cout << "e - Edit Passenger" << endl;
    cout << "d - Delete Passenger" << endl;
    cout << "p - Print All Passengers" << endl;
    cout << "s - Search and Find Driver" << endl;
    cout << "q - Quit Passenger Menu" << endl;
    cout << "PICK AN OPTION" << endl;
}

//Ride Menu, prints to user to inform them what they can do with Ride
void RideMenu(){
    cout << "RIDE MENU" << endl;
    cout << "a - Add Ride" << endl;
    cout << "e - Edit Ride" << endl;
    cout << "d - Delete Ride" << endl;
    cout << "p - Print All Rides" << endl;
    cout << "s - Search and Find Ride" << endl;
    cout << "q - Quit Ride Menu" << endl;
}

//Execute, switch case for Drivers that calls functions based on users input of char.
void ExecuteDriverMenu(Drivers& driver, char driveroption){

    switch(driveroption){
        case 'a':
            driver.addDriver(); // if user picks a add driver is called
            break;
        case 'e':
            driver.editDrivers(); // else if user picks e edit drivers is called
            break;
        case 'd':
            driver.deleteDriver();// else if user picks d delete driver is called
            break;
        case 'p':
            driver.printAllDrivers();// else if user picks p print all drivers is called
            break;
        case 's':
            driver.searchAndFindDriver(); // else if user picks s search for drivers is called
            break;
        case 'q': // else if user picks q we exit the switch case 
            break;
        default: // else (user inputs char not apart of switch case we ask for input again)
            cout << endl;
            cout << "Error Invalid Input" << endl;
            cout << endl;
    }
}

// Execute, switch case for Passengers that calls function based off user input of char
void ExecutePassengerMenu(Passengers& passenger, char passengeroption){

    switch(passengeroption){ // we pass in passenger option of type char
        case 'a': // if passengeroption is a add passenger gets called.
            passenger.addPassenger();
            break;
        case 'e':
            passenger.editPassenger(); // else if e is input by user edit passenger is called
            break;
        case 'd':
            passenger.deletePassenger(); // else if user picks d delete passenger is called
            break;
        case 'p':
            passenger.printAllPassengers(); // else if user picks p print all passengers is called
            break;
        case 's':
            passenger.searchAndFindPassenger(); // else if user picks s search passenger is called
            break;
        case 'q': //else if q is picked we exit switch case
            break;
        default: // else if user inputs anything else we get error message
            cout << endl;
            cout << "Error Invalid Input" << endl;
            cout << endl;

    }
}

// Execute, switch case for Rides that calls function based off of user input of char
void ExecuteRideMenu(Rides& ride, char rideoption){

    switch(rideoption){
        case 'a':
            ride.addRide(); // if user inputs ride option to be a we call addride
            break;
        case 'e':
            ride.editRide(); // else if user picks e we call edit ride
            break;
        case 'd':
            ride.deleteRide(); // else if user picks d we call delete ride
            break;
        case 'p':
            ride.printAllRides(); // else if user picks p we call print all rides
            break;
        case 's':
            ride.searchAndFindRide(); // else if user picks s we call search for ride
            break;
        case 'q': // when user inputs q we quit menu and go back to main menu
            break;
        default: // else when input does not euqal to siwtch case we get error message 
            cout << endl;
            cout << "Error Invalid Input" << endl;
            cout << endl;
    }
}


// Blue print for repeating Main Menu
void ExecuteMenu(Rides& ride, Passengers& passenger, Drivers& driver, char option){

    char driveroption;
    char passengeroption;
    char rideoption;

// For each switch case we get their respected menu and as long as user does not input q the menu will keep repeating

    switch(option) {
        case 'd':
            do {
                cout << endl;
                DriverMenu();   // Display the driver menu
                cin >> driveroption;
                cout << endl;
                if (driveroption != 'q') {
                    ExecuteDriverMenu(driver, driveroption); // Execute driver-related actions based on user input
                }
            } while (driveroption != 'q'); // Continue the loop until the user enters 'q' to quit the driver menu
            break;

        case 'p':
            do {
                cout << endl;
                PassengerMenu();   // Display the passenger menu
                cin >> passengeroption;
                cout << endl;
                if (passengeroption != 'q') {
                    ExecutePassengerMenu(passenger, passengeroption); // Execute passenger-related actions based on user input
                }
            } while (passengeroption != 'q'); // Continue the loop until the user enters 'q' to quit the passenger menu
            break;

        case 'r':
            do {
                cout << endl;
                RideMenu();   // Display the ride menu
                cin >> rideoption;
                if (rideoption != 'q') {
                    ExecuteRideMenu(ride, rideoption); // Execute ride-related actions based on user input
                }
            } while (rideoption != 'q'); // Continue the loop until the user enters 'q' to quit the ride menu
            break;

        default:
            cout << endl;
            cout << "Error: Invalid Input" << endl; // Display an error message for an invalid input
            cout << endl;
            break;
    }

}


int main()
{

    cout << "-----------------------------------------" << endl;
    cout << "|            Reese Goodavish            |" << endl;
    cout << "|      (reese.e.goodavish@gmail.com)    |" << endl;
    cout << "-----------------------------------------" << endl;

    char option; // main menu option
    // delcaring calsses for each entity.
    Drivers driver;
    Passengers passenger;
    Rides ride;
    
    do{
    PrintMenu();
    cin >> option;

        // As long as option does not equal q the main menu will keep executing 
        if(option != 'q'){
        ExecuteMenu(ride, passenger, driver, option);
        }

    }while(option != 'q'); //while option does not equal q for Main Menu keep asking for intput

    return 0;
}
