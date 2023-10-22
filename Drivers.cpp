#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"
#include "Passenger.h"
#include "Rides.h"


void Drivers::addDriver(){
    Driver* newDriver = new Driver(); // Anytime add Driver is called new Driver(); is made

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
    cout << "Rating: " << newDriver->getRating() << "/5" << endl;

    // If-Else Block (better than displaying 0 or 1)
    if(newDriver->getAvailable() == 0){
        cout << "Availability Status: Driver is not Available" << endl;
    }
    else if(newDriver->getAvailable() == 1){
        cout << "Availability Status: Driver is Available" << endl;
    }

    // If-Else Block (better than displaying 0 or 1)
    if(newDriver->getPetsAllowed() == 0){
        cout << "Pets Allowed: Driver does not allow Pets" << endl;
    }
    else if(newDriver->getPetsAllowed() == 1){
        cout << "Pets Allowed: Driver does allow Pets" << endl;
    }

    cout << "Driver Notes: " << newDriver->getNotes() << endl;
    

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
    string newID;
    bool DriverExists = false;
    bool enterIDLoopError = true;

    do{
        if(DriverList.empty()){
            cout << "DRIVER LIST IS EMPTY " << endl;
            enterIDLoopError = false;
            DriverExists = false;
        }
        else{
            do{
                cout << "ENTER ID OF DRIVER TO EDIT" << endl; 
                cin >> EditID;
                for(int i = 0; i < DriverList.size(); ++i){
                    if(DriverList[i]->getID() == EditID){
                        cout << "DRIVER FOUND" << endl;
                        cout << "INFO FOR DRIVER" << endl;
                        cout << "Driver ID: " << DriverList[i]->getID() << endl;
                        cout << "First Name: " << DriverList[i]->getFirstName() << endl;
                        cout << "Last Name: " << DriverList[i]->getLastName() << endl;
                        cout << "Capacity: " << DriverList[i]->getCapacity() << endl;
                        if(DriverList[i]->getHandicapped() == 1){
                            cout << "Handicap Capable: Driver is Handicap Capable " << endl;
                        }
                        else if(DriverList[i]->getHandicapped() == 0){
                        cout << "Handicap Capable: Driver is Not Handicap Capable" << endl;
                        }

                        cout << "Vehicle Type: " << DriverList[i]->getVehicleType() << endl;
                        cout << "Rating: " << DriverList[i]->getRating() << "/5" <<endl;

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

                        enterIDLoopError = true;
                        break;
                    }
                    else{
                        cout << "DRIVER NOT FOUND" << endl;
                        enterIDLoopError = false;
                    }
                }
            }while(enterIDLoopError == false);
            
        }
    }while(DriverExists == true);


    int EditChoice;
    bool newIDLoopError = false;
    while(DriverExists == false && enterIDLoopError == true){
        editDriversMenu();
        cin >> EditChoice;
        
        if(EditChoice == 1){
            do{
            cout << "Enter ID of 6 Digits " << endl;
            cin >> newID;
            newIDLoopError = false;
            
            if(newID.size() != 6){
                cout << "ID MUST BE 6 DIGITS LONG" << endl;
                newIDLoopError = true;
            }
            else if(newID[0] == '0'){
                cout << "FIRST DIGIT CANT EQUAL ZERO" << endl;
                newIDLoopError = true;
            }
            else if(newIDLoopError == false){
                for(char c: newID){
                    if(!isdigit(c)){
                        cout << "ID MUST BE ONLY INTEGERS" << endl;
                        newIDLoopError = true;
                        break;
                    }
                }
            }

            if(!newIDLoopError){
                for(int i = 0; i < DriverList.size(); ++i){
                    if(DriverList[i]->getID() == EditID){
                        int EditnewID = stoi(newID);
                        DriverList[i]->setID(EditnewID);
                        cout << "DRIVER ID UPDATED" << endl;
                    }
                }
                DriverExists = true;
                enterIDLoopError = false;
            }

            }while(newIDLoopError == true);

        }
        else if(EditChoice == 2){
            string editFirstName;
            cout << "ENTER NEW FIRST NAME FOR DRIVER" << endl;
            cin >> editFirstName;

            for(int i = 0; i < DriverList.size(); ++i){
                if(DriverList[i]->getID() == EditID){
                    DriverList[i]->setFirstName(editFirstName);
                    cout << "DRIVER FIRST NAME UPDATED" << endl;
                }
            }
            DriverExists = true;
            enterIDLoopError = false;
        }
        else if(EditChoice == 3){
            string editLastName;
            cout << "ENTER NEW LAST NAME FOR DRIVER" << endl;
            cin >> editLastName;

            for(int i = 0; i < DriverList.size(); ++i){
                if(DriverList[i]->getID() == EditID){
                    DriverList[i]->setLastName(editLastName);
                    cout << "DRIVER LAST NAME UPDATED" << endl;
                }
            }
            DriverExists = true;
            enterIDLoopError = false;            
        }
        else if(EditChoice == 4){
            int editCapacity;
            cout << "ENTER NEW VEHICLE CAPACITY FOR DRIVER" << endl;
            cin >> editCapacity;

            for(int i = 0; i < DriverList.size(); ++i){
                if(DriverList[i]->getID() == EditID){
                    DriverList[i]->setCapacity(editCapacity);
                    cout << "VEHICLE CAPACITY UPDATED FOR DRIVER" << endl;
                }
            }
            DriverExists = true;
            enterIDLoopError = false;

        }
        else if(EditChoice == 5){
            bool editHandicapStatus;
            bool editHandicapStatusLoopError;
            string editHandicap;
            cout << "EDIT HANDICAP CAPABLE STATUS" << endl;
            do{
                cout << "Enter Handicap Capable Status 'Yes' if capable or 'No' if not capable (without quotes)" << endl;
                cin >> editHandicap;
                if(editHandicap == "Yes" || editHandicap == "yes"){
                    editHandicapStatus = true;
                    for(int i = 0; i < DriverList.size(); ++i){
                            if(DriverList[i]->getID() == EditID){
                                DriverList[i]->setHandicapped(editHandicapStatus);
                                cout << "HANDICAP CAPABILITY UPDATED" << endl;
                            }
                    }
                    editHandicapStatusLoopError = false;
                }
                else if(editHandicap == "No" || editHandicap == "no"){
                    editHandicapStatus = false;
                    for(int i = 0; i < DriverList.size(); ++i){
                            if(DriverList[i]->getID() == EditID){
                                DriverList[i]->setHandicapped(editHandicapStatus);
                                cout << "HANDICAP CAPABILITY UPDATED" << endl;
                            }
                    }
                    editHandicapStatusLoopError = false;

                }
                else{
                    cout << "ERROR INVALID CHOICE" << endl;
                    editHandicapStatusLoopError = true;
                }
            }while(editHandicapStatusLoopError == true);
            DriverExists = true;
            enterIDLoopError = false;
        }
        else if(EditChoice == 6){
            string editVehicleType;
            cout << "ENTER NEW VEHICLE TYPE FOR DRIVER" << endl;
            cin.ignore();
            getline(cin, editVehicleType);
            for(int i = 0; i < DriverList.size(); ++i){
                if(DriverList[i]->getID() == EditID){
                    DriverList[i]->setVehicleType(editVehicleType);
                    cout << "VEHICLE TYPE UPDATED FOR DRIVER" << endl;
                }
            }

            DriverExists = true;
            enterIDLoopError = false;
        }
        else if(EditChoice == 7){
            float editRating;
            bool editRatingLoopError;
            do{
                cout << "ENTER NEW RATING 0 - 5 FOR DRIVER" << endl;
                cin >> editRating;
                if(editRating < 0.0 || editRating > 5.0){
                    cout << "ERROR RATING MUST BE 0 - 5" << endl;
                    editRatingLoopError = true;
                }
                else{
                    for(int i = 0; i < DriverList.size(); ++i){
                        if(DriverList[i]->getID() == EditID){
                            DriverList[i]->setRating(editRating);
                            cout << "RATING UPDATED FOR DRIVER" << endl;
                        }
                    }
                    editRatingLoopError = false;
                    DriverExists = true;
                    enterIDLoopError = false;
                }
            }while(editRatingLoopError == true);
        }
        else if(EditChoice == 8){
            string editAvabilityString;
            bool editAvability;
            bool editAvabilityLoopError;
            cout << "EDIT AVABILITY" << endl;
            do{
                cout << "Enter If Driver Is Available 'Yes' or 'No' (without quotes)" << endl;
                cin >> editAvabilityString;
                if(editAvabilityString == "Yes" || editAvabilityString == "yes"){
                    editAvability = true;
                    for(int i = 0; i < DriverList.size(); ++i){
                        if(DriverList[i]->getID() == EditID){
                            DriverList[i]->setAvailable(editAvability);
                            cout << "AVABILITY UPDATED FOR DRIVER" << endl;
                            editAvabilityLoopError = false;
                        }
                    }
                }
                else if(editAvabilityString == "No" || editAvabilityString == "no"){
                    editAvability = false;
                    for(int i = 0; i < DriverList.size(); ++i){
                        if(DriverList[i]->getID() == EditID){
                            DriverList[i]->setAvailable(editAvability);
                            cout << "AVABILITY UPDATED FOR DRIVER" << endl;
                            editAvabilityLoopError = false;
                        }
                    }
                }
                else{
                    cout << "ERROR INVALID CHOICE" << endl;
                    editAvabilityLoopError = true;
                }

            }while(editAvabilityLoopError == true);
            DriverExists = true;
            enterIDLoopError = false;
        }
        else if(EditChoice == 9){
            bool editPetsAllowedStatusLoopError;
            bool editPetsAllowed;
            string editPetsAllowedString;
            cout << "EDIT PETS ALLOWED STATUS" << endl;
            do{
                cout << "Enter If Driver Allows Pets 'Yes' or 'No'" << endl;
                cin >> editPetsAllowedString;
                if(editPetsAllowedString == "Yes" || editPetsAllowedString == "yes"){
                    editPetsAllowed = true;
                    for(int i = 0; i < DriverList.size(); ++i){
                        if(DriverList[i]->getID() == EditID){
                            DriverList[i]->setPetsAllowed(editPetsAllowed);
                            cout << "PETS ALLOWED STATUS UPDATED FOR DRIVER" << endl;
                            editPetsAllowedStatusLoopError = false;
                        }
                    }
                }
                else if(editPetsAllowedString == "No" || editPetsAllowedString == "no"){
                    editPetsAllowed = false;
                    for(int i = 0; i < DriverList.size(); ++i){
                        if(DriverList[i]->getID() == EditID){
                            DriverList[i]->setPetsAllowed(editPetsAllowed);
                            cout << "PETS ALLOWED STATUS UPDATED FOR DRIVER" << endl;
                            editPetsAllowedStatusLoopError = false;
                        }
                    }        
                }
                else{
                    cout << "ERROR INVALID CHOICE" << endl;
                    editPetsAllowedStatusLoopError = true;
                }
            }while(editPetsAllowedStatusLoopError == true);
            DriverExists = true;
            enterIDLoopError = false;
        }
        else if(EditChoice == 10){
            string editNotes;
            cout << "EDIT DRIVER NOTES" << endl;
            cin.ignore();
            getline(cin, editNotes);
                for(int i = 0; i < DriverList.size(); ++i){
                    if(DriverList[i]->getID() == EditID){
                        DriverList[i]->setNotes(editNotes);
                        cout << "NOTES UPDATED FOR DRIVER" << endl;
                    }
                }   
            DriverExists = true;
            enterIDLoopError = false;

        }
        else{
            cout << "ERROR NOT VALID OPTION" << endl;

        }

    }

}

void Drivers::deleteDriver(){
    
    if(DriverList.empty()){
        cout << "DRIVER LIST IS EMPTY" << endl;
    }
    else{
        int DeleteID;
        bool deleteDriverLoopError;
        do{
            cout << "ENTER ID OF DRIVER TO DELETE" << endl;
            cin >> DeleteID;
                for(int i = 0; i < DriverList.size(); ++i){
                    deleteDriverLoopError = false;
                    if(DriverList[i]->getID() == DeleteID){
                        DriverList.erase(DriverList.begin() + i);
                        cout << "Driver Deleted" << endl;
                    }
                    else{
                        cout << "DRIVER NOT FOUND" << endl;
                        deleteDriverLoopError = true;
                    }
                }
        }while(deleteDriverLoopError == true);
    }
}

void Drivers::searchAndFindDriver(){

    if(DriverList.empty()){
        cout << "DRIVER LIST IS EMPTY" << endl;
    }
    else{
        int findID;
        bool findDriverLoopError;
        do{
        cout << "ENTER ID OF DRIVER TO FIND" << endl;
        cin >> findID;
            for(int i = 0; i < DriverList.size(); ++i){
                findDriverLoopError = false;
                if(DriverList[i]->getID() == findID){
                    cout << "DRIVER FOUND" << endl;
                    cout << "DRIVER INFO:" << endl;
                    cout << "ID: " << DriverList[i]->getID() << endl;
                    cout << "FIRST NAME : " << DriverList[i]->getFirstName() << endl;
                    cout << "LAST NAME: " << DriverList[i]->getLastName() << endl;
                    cout << "Capacity: " << DriverList[i]->getCapacity() << endl;
                    if(DriverList[i]->getHandicapped() == 1){
                        cout << "Handicap Capable: Driver is Handicap Capable " << endl;
                    }
                    else if(DriverList[i]->getHandicapped() == 0){
                        cout << "Handicap Capable: Driver is Not Handicap Capable" << endl;
                    }
                    cout << "Vehicle Type: " << DriverList[i]->getVehicleType() << endl;
                    cout << "Rating: " << DriverList[i]->getRating() << "/5" << endl;
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
                else{
                    cout << "DRIVER NOT FOUND" << endl;
                    findDriverLoopError = true;
                }
            }
        }while(findDriverLoopError == true);
    }
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
            cout << "Rating: " << DriverList[i]->getRating() << "/5" << endl;

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
