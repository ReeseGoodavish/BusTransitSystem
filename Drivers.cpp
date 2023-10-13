#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"

void Driver::setFirstName(string FirstName){
    this->FirstName = FirstName;
}
string Driver::getFirstName(){
    return FirstName;
}

void Driver::setLastName(string LastName){
    this->LastName = LastName;
}
string Driver::getLastName(){
    return LastName;
}

void Driver::setCapacity(int Capacity){
    this->Capacity = Capacity;
}
int Driver::getCapacity(){
    return Capacity;
}

void Driver::setHandicapped(bool Handicapped){
    this->Handicapped = Handicapped;
}
bool Driver::getHandicapped(){
    return Handicapped;
}

void Drivers::addDriver(){
    Driver newDriver;


    string FirstName;
    cout << "Enter New Driver First Name" << endl;
    cin.ignore();
    getline(cin, FirstName);
    newDriver.setFirstName(FirstName);
    cout << newDriver.getFirstName() << endl;
    
    string LastName;
    cout << "Enter New Driver Last Name" << endl;
    getline(cin, LastName);
    newDriver.setLastName(LastName);
    cout << newDriver.getLastName() << endl;

    int Capacity;
    cout << "Enter New Driver Vehicle Capacity" << endl;
    cin >> Capacity;
    newDriver.setCapacity(Capacity);
    cout << newDriver.getCapacity() << endl;

    bool Handicapped;
    bool HandicappedLoopError = true;
    string inputHandicapped;

    do{
    cout << "Enter New Driver Handicapped Status 'Yes' or 'No' (without quotes) " << endl;
    cin >> inputHandicapped;

    if(inputHandicapped == "Yes" || inputHandicapped == "yes"){
        Handicapped = true;
        HandicappedLoopError = false;
    }
    else if(inputHandicapped == "No" || inputHandicapped == "no"){
        Handicapped = false;
        HandicappedLoopError = false;
    }
    else{
        cout << "Error Please Enter Again" << endl;
        HandicappedLoopError = true;
    }
    }while(HandicappedLoopError == true);
    cout << endl;
    newDriver.setHandicapped(Handicapped);

    // Handicapped Status Works 1 = Hanicapped (True) And 0 = Not Handicapped (False)
    // cout << "HandicappedStatus = " << newDriver.getHandicapped() << endl;

}






