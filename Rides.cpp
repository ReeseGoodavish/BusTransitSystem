#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"
#include "Passenger.h"
#include "Rides.h"

void Ride::setID(int ID){
    this->ID = ID;
}
int Ride::getID(){
    return ID;
}

void Ride::setPickUpLocation(string PickUpLocation){
    this->PickUpLocation = PickUpLocation;
}
string Ride::getPickUpLocation(){
    return PickUpLocation;
}

void Ride::setDropOffLocation(string DropOffLocation){
    this->DropOffLocation = DropOffLocation;
}
string Ride::getDropOffLocation(){
    return DropOffLocation;
}

void Ride::setPartySize(int PartySize){
    this->PartySize = PartySize;
}
int Ride::getPartySize(){
    return PartySize;
}
void Ride::setIncludesPets(bool IncludesPets){
    this->IncludesPets = IncludesPets;
}
bool Ride::getIncludesPets(){
    return IncludesPets;
}
void Ride::setRatingByCustomer(float RatingByCustomer){
    this->RatingByCustomer = RatingByCustomer;
}
float Ride::getRatingByCustomer(){
    return RatingByCustomer;
}


void Rides::addRide(){
    
    Ride* newRide = new Ride;

    static int count = 100000;
    cout << endl;
    cout << "NEW RIDE ID SET TO " << count << endl;
    newRide->setID(count);
    ++count;

    string PickUpLocation;
    cout << "Enter Ride Pick Up Location" << endl;
    cin.ignore();
    getline(cin, PickUpLocation);
    newRide->setPickUpLocation(PickUpLocation);

    string DropOffLocation;
    cout << "Enter Ride Drop Off Location" << endl;
    getline(cin, DropOffLocation);
    newRide->setDropOffLocation(DropOffLocation);

    int PartySize;
    do{
    cout << "Enter Ride Party Size" << endl;
    cin >> PartySize;
    }while(PartySize < 1);
    newRide->setPartySize(PartySize);


    string IncludesPets;
    bool IncludesPetsBool;
    bool IncludesPetsLoopError;
    do{
        cout << "Does Ride Include Pets 'yes' or 'no' (without quotes)" << endl;
        cin >> IncludesPets;
        if(IncludesPets == "yes" || IncludesPets == "Yes"){
            IncludesPetsBool = true;
            IncludesPetsLoopError = false;
            newRide->setIncludesPets(IncludesPetsBool);
        }
        else if(IncludesPets == "No" || IncludesPets == "no"){
            IncludesPetsBool = true;
            IncludesPetsLoopError = false;
            newRide->setIncludesPets(IncludesPetsBool);
        }
        else{
            cout << "Error Invalid Input" << endl;
            IncludesPetsBool = false;
        }

    float RatingByCustomer;
    bool RatingByCustomerLoopError;
    do{
        cout << "Enter Rating For Ride 0 - 5" << endl;
        cin >> RatingByCustomer;
        if(RatingByCustomer < 0 || RatingByCustomer > 5){
            cout << "Error Only Enter Number 0 - 5 " << endl;
            RatingByCustomerLoopError = true;
        }
        else{
            newRide->setRatingByCustomer(RatingByCustomer);
            RatingByCustomerLoopError = false;
        }
    }while(RatingByCustomerLoopError == true);

    }while(IncludesPetsLoopError == true);

    RideList.push_back(newRide);
}

void editRideMenu(){
    cout << "EDIT MENU" << endl;
    cout << "1 - ID" << endl;
    cout << "2 - Pick Up Location" << endl;
    cout << "3 - Drop Off Location" << endl;
    cout << "4 - Party Size" << endl;
    cout << "5 - Pet Status" << endl;
    cout << "6 - Rating By Customer" << endl;
}

void Rides::editRide(){

    int EditID;
    string newID;
    bool RideExists = false;
    bool enterIDLoopError = true;

    do{
        if(RideList.empty()){
            cout << "RIDE LIST IS EMPTY" << endl;
            enterIDLoopError = false;
            RideExists = false;
        }
        else{
            do{
                cout << "ENTER ID OF RIDE TO EDIT" << endl;
                cin >> EditID;
                for(int i = 0; i < RideList.size(); ++i){
                    if(RideList[i]->getID() == EditID){
                        cout << "RIDE FOUND" << endl;
                        cout << "INFO FOR RIDE" << endl;
                        cout << "RIDE ID: " << RideList[i]->getID() << endl;
                        cout << "PICK UP LOCATION: " << RideList[i]->getPickUpLocation() << endl;
                        cout << "DROP OFF LOCATION: " << RideList[i]->getDropOffLocation() << endl;
                        cout << "PARTY SIZE: " << RideList[i]->getPartySize() << endl; 
                            if(RideList[i]->getIncludesPets() == 1){
                                cout << "PET STATUS: Ride Does Include Pets" << endl;
                            }
                            else if(RideList[i]->getIncludesPets() == 0){
                                cout << "PET STATUS: Ride Does Not Include Pets" << endl;
                            }
                        cout << "Ride Rating: " << RideList[i]->getRatingByCustomer() << "/5" << endl;
                        enterIDLoopError = true;
                        break;                          
                    }
                    else{
                        cout << "PASSENGER NOT FOUND" << endl;
                        enterIDLoopError = false;
                    }
                }
            }while(enterIDLoopError == false);
        }
    }while(RideExists == true);

    int EditChoice;
    bool newIDLoopError = false;
    while(RideExists == false && enterIDLoopError == true){
        editRideMenu();
        cin >> EditChoice;
        if(EditChoice == 1){
            do{
                cout << "Enter ID of 6 Digits" << endl;
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
                for(int i = 0; i < RideList.size(); ++i){
                    if(RideList[i]->getID() == EditID){
                        int EditnewID = stoi(newID);
                        RideList[i]->setID(EditnewID);
                        cout << "DRIVER ID UPDATED" << endl;
                    }
                }
                RideExists = true;
                enterIDLoopError = false;                    
                }                
            }while(newIDLoopError == true);
        }
        else if(EditChoice == 2){
            string editPickUpLocation;
            cout << "ENTER NEW PICK UP LOCATION" << endl;
            cin.ignore();
            getline(cin, editPickUpLocation);

            for(int i = 0; i < RideList.size(); ++i){
                if(RideList[i]->getID() == EditID){
                    RideList[i]->setPickUpLocation(editPickUpLocation);
                }
            }
            RideExists = true;
            enterIDLoopError = false;
        }
        else if(EditChoice == 3){
            string editDropOffLocation;
            cout << "ENTER NEW DROP OFF LOCATOIN" << endl;
            cin.ignore();
            getline(cin,editDropOffLocation);
            for(int i = 0; i < RideList.size(); ++i){
                if(RideList[i]->getID() == EditID){
                    RideList[i]->setDropOffLocation(editDropOffLocation);
                }
            }
            RideExists = true;
            enterIDLoopError = false;
        }
        else if(EditChoice == 4){
            int editPartySize;
            bool editPartySizeLoopError;
            do{
                cout << "ENTER NEW PARTY SIZE" << endl;
                cin >> editPartySize;
                if(editPartySize < 1){
                    cout << "Error Invalid Input" << endl;
                    editPartySizeLoopError = true;
                }
                else{
                    editPartySizeLoopError = false;
                    RideExists = true;
                    for(int i = 0; i < RideList.size(); ++i){
                        if(RideList[i]->getID() == EditID){
                            RideList[i]->setPartySize(editPartySize);
                        }
                    }
                }
            }while(editPartySizeLoopError == true);
        }
        else if(EditChoice == 5){
            bool editPetStatus;
            bool editPetStatusLoopError;
            string editPetStatusString;
            do{
                cout << "ENTER PET STATUS: 'yes' If Ride Has Pets 'no' If Ride Does Not Have Pets (without quotes)" << endl;
                cin >> editPetStatusString;
                if(editPetStatusString == "yes"||editPetStatusString == "Yes"){
                    editPetStatus = true;
                    editPetStatusLoopError = false;
                    RideExists = true;
                    for(int i = 0; i < RideList.size(); ++i){
                        if(RideList[i]->getID() == EditID){
                            RideList[i]->setIncludesPets(editPetStatus);
                        }
                    }
                }
                else if(editPetStatusString == "no" ||editPetStatusString == "No"){
                    editPetStatus = false;
                    editPetStatusLoopError = false;
                    RideExists = true;
                    for(int i = 0; i < RideList.size(); ++i){
                        if(RideList[i]->getID() == EditID){
                            RideList[i]->setIncludesPets(editPetStatus);
                        }
                    }
                }
                else{
                    cout << "ERROR INVALID INPUT" << endl;
                    editPetStatusLoopError = true;
                }
            }while(editPetStatusLoopError == true);
        }
        else if(EditChoice == 6){
            float editRatingByCustomer;
            bool editRatingByCustomerLoopError;
            do{
                cout << "ENTER RIDE RATING" << endl;
                cin >> editRatingByCustomer;
                if(editRatingByCustomer < 0 || editRatingByCustomer > 5){
                    cout << "ERROR INVALID INPUT" << endl;
                    editRatingByCustomerLoopError = true;
                }
                else{
                    RideExists = true;
                    editRatingByCustomerLoopError = false;
                    for(int i = 0; i < RideList.size(); ++i){
                        if(RideList[i]->getID() == EditID){
                            RideList[i]->setRatingByCustomer(editRatingByCustomer);
                        }
                    }
                }
            }while(editRatingByCustomerLoopError == true);
        }
    }
}

void Rides::deleteRide(){
    if(RideList.empty()){
        cout << "RIDE LIST EMPTY" << endl;
    }
    else{
        int deleteID;
        bool deleteRideLoopError;
        do{
        cout << "ENTER ID FOR RIDE TO DELETE" << endl;
        cin >> deleteID;
            for(int i = 0; i < RideList.size(); ++i){
                if(deleteID == RideList[i]->getID()){
                    RideList.erase(RideList.begin() + i);
                    cout << "Passenger Deleted" << endl;
                    deleteRideLoopError = false;
                    break;
                }
                else{
                    cout << "RIDE NOT FOUND" << endl;
                    deleteRideLoopError = true;
                }
            }
        }while(deleteRideLoopError == true);
        
    }
}

void Rides::searchAndFindRide(){
    if(RideList.empty()){
        cout << "RIDE LIST EMPTY" << endl;
    }
    else{
        int findID;
        bool findRideLoopError;
        do{
            cout << "ENTER ID OF RIDE TO FIND" << endl;
            cin >> findID;
            for(int i = 0; i < RideList.size(); ++i){
                for(int i = 0; i < RideList.size(); ++i){
                    if(RideList[i]->getID() == findID){
                        findRideLoopError = false;
                        cout << "RIDE FOUND" << endl;
                        cout << "RIDE INFO" << endl;
                        cout << "ID: " << RideList[i]->getID() << endl;
                        cout << "PICK UP LOCATION: " << RideList[i]->getPickUpLocation() << endl;
                        cout << "DROP OFF LOCATION: " << RideList[i]->getDropOffLocation() << endl;
                        cout << "PARTY SIZE: " << RideList[i]->getPartySize() << endl;
                        if(RideList[i]->getIncludesPets() == 1){
                            cout << "PET STATUS: Ride Includes Pets" << endl; 
                        }
                        else if(RideList[i]->getIncludesPets() == 0){
                            cout << "PET STATUS: Ride Does Not Include Pets" << endl;
                        }
                        cout << "RATING: " << RideList[i]->getRatingByCustomer() << "/5" << endl;
                    }
                }
                if(findRideLoopError == true){
                    cout << "RIDE NOT FOUND" << endl;
                    findRideLoopError = true;
                }
            }
        }while(findRideLoopError == true);
    }
}

void Rides::printAllRides(){
    if(RideList.empty()){
        cout << "RIDE LIST EMPTY" << endl;
    }
    else{
        for(int i = 0; i < RideList.size(); ++i){
            cout << "INFO FOR RIDE " << i + 1 << ": " << endl;
            cout << "RIDE ID: " << RideList[i]->getID() << endl;
            cout << "Pick Up Location: " << RideList[i]->getPickUpLocation() << endl;
            cout << "Drop Off Location: " << RideList[i]->getDropOffLocation() << endl;
            cout << "Party Size: " << RideList[i]->getPartySize() << endl;
            if(RideList[i]->getIncludesPets() == 1){
                cout << "Pet Status: Ride Has Pets" << endl;
            }
            else if(RideList[i]->getIncludesPets() == 0){
                cout << "Pet Status: Ride Does Not Have Pets" << endl;
            }
            cout << "Rating By Customer " << RideList[i]->getRatingByCustomer() << endl;
        }
    }
}



