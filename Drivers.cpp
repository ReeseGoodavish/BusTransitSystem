#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"

void Driver::setID(int ID){
    this->ID = ID;
}
int Driver::getID(){
    return ID;
}

Drivers::Drivers(){
    count = 100000;
}

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

void Driver::setPetsAllowed(bool PetsAllowed){
    this->PetsAllowed = PetsAllowed;
}
bool Driver::getPetsAllowed(){
    return PetsAllowed;
}

void Driver::setNotes(string Notes){
    this->Notes = Notes;
}
string Driver::getNotes(){
    return Notes;
}

void Drivers::addDriver(){
    Driver* newDriver = new Driver();

    static int ID = 100000;
    newDriver->setID(ID);
    cout << "New Driver ID Set To: " << newDriver->getID() << endl;
    ++ID;

    string FirstName;
    cout << "Enter New Driver First Name" << endl;
    cin.ignore();
    getline(cin, FirstName);
    newDriver->setFirstName(FirstName);

    // Correctly Displays First Name for new driver
    // cout << newDriver->getFirstName() << endl;
    
    string LastName;
    cout << "Enter New Driver Last Name" << endl;
    getline(cin, LastName);
    newDriver->setLastName(LastName);

    // Correctly Displays Last Name for new driver
    // cout << newDriver->getLastName() << endl;

    int Capacity;
    cout << "Enter New Driver Vehicle Capacity" << endl;
    cin >> Capacity;
    newDriver->setCapacity(Capacity);

    // Correctly Displays Capcaity for new driver
    // cout << newDriver->getCapacity() << endl;

    bool Handicapped;
    bool HandicappedLoopError; //automatically set to true / 1
    string inputHandicapped;

    do{
    cout << "Is New Driver Handicapped Capable 'Yes' or 'No' (without quotes) " << endl;
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
    newDriver->setHandicapped(Handicapped);

    // Handicapped Status Works 1 = Hanicapped (True) And 0 = Not Handicapped (False)
    // cout << "HandicappedStatus = " << newDriver.getHandicapped() << endl;

    string VehicleType;
    cout << "Enter Driver Vehicle Type (Sedan, Mini Van, SUV, etc.)" << endl;
    cin.ignore();
    getline(cin, VehicleType);
    newDriver->setVehicleType(VehicleType);

    // Correctly displays vehicle type for new driver
    // cout << newDriver->getVehicleType() << endl;

    float Rating;
    cout << "Enter Driver Rating 0-5" << endl;
    cin >> Rating;
    while(Rating > 5.0 || Rating < 0.0){
        cout << "Error Only Input Rating 0 to 5" << endl;
        cin >> Rating;
    }
    newDriver->setRating(Rating);

    // Correctly outputs rating for new driver
    // cout << newDriver->getRating() << endl;

    bool Available;
    bool AvailableLoopError; //automatically set as true / 1
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
    newDriver->setAvailable(Available);

    // correctly displays available status for new driver 0 = false, 1 = true
    // cout << newDriver->getAvailable() << endl;

    bool PetsAllowed;
    bool PetsAllowedLoopError; //automatically set to true / 1
    string inputPetsAllowed;

    do{
    cout << "Enter If New Driver Allows Pets 'Yes' or 'No' (without quotes) " << endl;
    cin >> inputPetsAllowed;

    if(inputPetsAllowed == "Yes" || inputPetsAllowed == "yes"){
        PetsAllowed = true;
        PetsAllowedLoopError = false;
    }
    else if(inputPetsAllowed == "No" || inputPetsAllowed == "no"){
        PetsAllowed = false;
        PetsAllowedLoopError = false;
    }
    else{
        cout << "Error Please Enter Again" << endl;
        PetsAllowedLoopError = true;
    }
    }while(PetsAllowedLoopError == true);
    newDriver->setPetsAllowed(PetsAllowed);
    // correctly displays if pets allowed for new driver 0 = false, 1 = true
    // cout << newDriver->getPetsAllowed() << endl;

    string NotesChoice;
    string Notes;
    bool NotesLoopError;
    cout << "Would You Like to Add Driver Notes? 'Yes' or 'No' (without quotes) " << endl;
    cin >> NotesChoice;

    do{
    if(NotesChoice == "Yes" || NotesChoice == "yes"){
        cin.ignore();
        getline(cin, Notes);
        NotesLoopError = false;
    }
    else if(NotesChoice == "No" || NotesChoice == "no"){
        cout << "No Notes Added For Driver" << endl;
        Notes = "No Notes For Driver";
        NotesLoopError = false;
    }
    else{
        cout << "Error Please Enter Again" << endl;
        NotesLoopError = true;
    }
    }while(NotesLoopError == true);
    newDriver->setNotes(Notes);

    // correcly displays notes for new driver
    // cout << newDriver->getNotes() << endl;

    DriverList.push_back(newDriver); //pushes all info for new driver into vector

    //Print All Info For New Drievr
    cout << "New Driver ID: " << newDriver->getID() << endl;
    cout << "New Driver Info: " << endl;
    cout << "First Name: " << newDriver->getFirstName() << endl;
    cout << "Last Name: " << newDriver->getLastName() << endl;
    cout << "Capacity: " << newDriver->getCapacity() << endl;

    // If-Else Block (better than displaying 0 or 1)
    if(newDriver->getHandicapped() == 1){
        cout << "Handicap Capable: Driver is Handicap Capiable" << endl;
    }
    else if(newDriver->getHandicapped() == 0){
        cout << "Handicap Capable: Driver is not Handicap Capiable" << endl;
    }

    cout << "Vehicle Type: " << newDriver->getVehicleType() << endl;
    cout << "Rating: " << newDriver->getRating() << endl;

    // If-Else Block (better than displaying 0 or 1)
    if(newDriver->getAvailable() == 1){
        cout << "Availability Status: Driver is not Available" << endl;
    }
    else if(newDriver->getAvailable() == 0){
        cout << "Availability Status: Driver is Available" << endl;
    }

    // If-Else Block (better than displaying 0 or 1)
    if(newDriver->getPetsAllowed() == 1){
        cout << "Pets Allowed: Driver does not allow Pets" << endl;
    }
    else if(newDriver->getPetsAllowed() == 0){
        cout << "Pets Allowed: Driver does allow Pets" << endl;
    }

    cout << "Driver Notes: " << newDriver->getNotes() << endl;


    /*
    for(int i = 0; i < DriverList.size(); ++i){
        cout << "New Driver Info: " << endl;
        cout << "First Name: " << DriverList[i]->getFirstName() << endl;
    }

    for(int i = 0; i < DriverList.size(); ++i){
        delete DriverList[i];
    }
    */

}

void editDriversMenu(){

    cout << "EDIT MENU: " << endl;
    cout << "1 - ID" << endl;
    cout << "2 - First Name" << endl;
    cout << "3 - Last Name" << endl;
    cout << "4 - Capacity" << endl;
    cout << "5 - Handicap Capibility Status" << endl;
    cout << "6 - Vehichle Type" << endl;
    cout << "7 - Rating" << endl;
    cout << "8 - Avaibility" << endl;
    cout << "9 - Pets Allowed Status" << endl;
    cout << "10 - Notes" << endl;
    cout << "What Info Would You Like To Edit: " << endl;
    
}

// EDIT DRIVER FUNCTION
void Drivers::editDrivers(){

    int EditID;
    int MenuChoice;
    bool IDLoopError = true;
    do{
    cout << "ENTER ID OF DRIVER TO EDIT" << endl;
    cin >> EditID;

    for(int i = 0; i < DriverList.size(); ++i){
        if(DriverList[i]->getID() == EditID){
            cout << "DRIVER FOUND" << endl;
            // INFO FOR DRIVER
            editDriversMenu();
            cin >> MenuChoice;
                if(MenuChoice == 1){
                    string newID;
                    bool newIDLoopError;
                    do{
                        cout << "Enter ID of 6 Digits " << endl;
                        cin >> newID;
                        
                        if(newID.size() != 6){
                            cout << "Error ID Must Be 6 Digits Long" << endl;
                            newIDLoopError = false;
                        }
                        else if(newID[0] == 'o'){
                            cout << "First Digit Can Not Be Zero" << endl;
                            newIDLoopError = false;
                        }
                        if(newIDLoopError == true){
                            for(char c: newID){
                                if(!isdigit(c)){
                                    cout << "ID Must Only Be Integers" << endl;
                                    newIDLoopError = false;
                                    break;
                                }
                            }
                        }

                    }while(newIDLoopError == false);
                }
                else{
                    cout << "NOT VALID CHOICE ENTER AGAIN" << endl;
                    IDLoopError = true;
                    break;
                }
            IDLoopError = false;
            break;
        }
        else{
            cout << "Driver Not Found" << endl;
        }
    }
    }while(IDLoopError == true);

}

//PRINT ALL DRIVERS
void Drivers::printAllDrivers(){

    if(DriverList.empty()){
        cout << "DRIVER LIST IS EMPTY" << endl;
    }
    else{
        for(int i = 0; i < DriverList.size(); ++i){
            cout << "ALL DRIVER INFO" << endl;
            cout << "Info For Driver " << i + 1  << ": " << endl;
            cout << "Driver ID: " << DriverList[i]->getID() << endl;
            cout << "First Name: " << DriverList[i]->getFirstName() << endl;
            cout << "Last Name: " << DriverList[i]->getLastName() << endl;
            cout << "Capacity: " << DriverList[i]->getCapacity() << endl;

            if(DriverList[i]->getHandicapped() == 1){
                cout << "Handicap Capable: Driver is Handicap Capable" << endl;
            }
            else if(DriverList[i]->getHandicapped() == 0){
                cout << "Handicap Capable: Driver is Not Handicap Capable" << endl;
            }

            cout << "Vehicle Type: " << DriverList[i]->getVehicleType() << endl;
            cout << "Rating: " << DriverList[i]->getRating() << endl;

            if(DriverList[i]->getAvailable() == 1){
                cout << "Available: Driver is Available" << endl;
            }
            else if(DriverList[i]->getAvailable() == 0){
                cout << "Available: Driver is not Available" << endl;
            }

            if(DriverList[i]->getPetsAllowed() == 1){
                cout << "Pets Allowed: Driver allows Pets" << endl;
            }
            else if(DriverList[i]->getPetsAllowed() == 0){
                cout << "Pets Allowed: Driver does not allow Pets" << endl;
            }

            cout << "Driver Notes: " << DriverList[i]->getNotes() << endl;
        }
    }

}
