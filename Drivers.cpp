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

void Driver::setVehicleType(string VehicleType){
    this->VehicleType = VehicleType;
}
string Driver::getVehicleType(){
    return VehicleType;
}

void Driver::setRating(float Rating){
    this->Rating = Rating;
}
float Driver::getRating(){
    return Rating;
}

void Driver::setAvailable(bool Available){
    this->Available = Available;
}
bool Driver::getAvailable(){
    return Available;
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
    newDriver.setHandicapped(Handicapped);

    // Handicapped Status Works 1 = Hanicapped (True) And 0 = Not Handicapped (False)
    // cout << "HandicappedStatus = " << newDriver.getHandicapped() << endl;

    string VehicleType;
    cout << "Enter Driver Vehicle Type (Sedan, Mini Van, SUV, etc.)" << endl;
    cin.ignore();
    getline(cin, VehicleType);
    newDriver.setVehicleType(VehicleType);
    cout << newDriver.getVehicleType() << endl;

    float Rating;
    cout << "Enter Driver Rating 0-5" << endl;
    cin >> Rating;
    while(Rating > 5.0 || Rating < 0.0){
        cout << "Error Only Input Rating 0 to 5" << endl;
        cin >> Rating;
    }
    newDriver.setRating(Rating);
    cout << newDriver.getRating() << endl;

    bool Available;
    bool AvailableLoopError;
    string inputAvailable;

    do{
    cout << "Enter If New Driver Is Available Or Not 'Yes' or 'No' (without quotes) " << endl;
    cin >> inputAvailable;

    if(inputAvailable == "Yes" || inputAvailable == "yes"){
        Available = true;
        AvailableLoopError = false;
    }
    else if(inputAvailable == "No" || inputAvailable == "no"){
        Available = false;
        AvailableLoopError = false;
    }
    else{
        cout << "Error Please Enter Again" << endl;
        AvailableLoopError = true;
    }
    }while(AvailableLoopError == true);
    newDriver.setAvailable(Available);
    cout << newDriver.getAvailable() << endl;


    

    



}






