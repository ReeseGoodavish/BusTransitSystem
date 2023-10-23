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


void Rides::addRide(){
    
    Ride* newRide = new Ride; //CREATES RIDE POINTER NAMED NEW RIDE (anytime function is called)

    static int count = 100000; //static allows count to always be updated even when function is called again
    cout << endl;
    cout << "NEW RIDE ID SET TO " << count << endl;
    newRide->setID(count); // sets ID 
    ++count;

    string PickUpLocation;
    cout << "Enter Ride Pick Up Location" << endl;
    cin.ignore();
    getline(cin, PickUpLocation);
    newRide->setPickUpLocation(PickUpLocation); //sets Pickuplocation 

    string DropOffLocation;
    cout << "Enter Ride Drop Off Location" << endl;
    getline(cin, DropOffLocation);
    newRide->setDropOffLocation(DropOffLocation); // sets drop off location

    int PartySize;
    do{
    cout << "Enter Ride Party Size" << endl;
    cin >> PartySize;
    }while(PartySize < 1); // Party size cant be less than 1 (need at least 1 person to be transported)
    newRide->setPartySize(PartySize);


    //if string = yes or no sets bool to true or false based off user input
    string IncludesPets;
    bool IncludesPetsBool;
    bool IncludesPetsLoopError;
    do{
        cout << "Does Ride Include Pets 'yes' or 'no' (without quotes)" << endl;
        cin >> IncludesPets;
        if(IncludesPets == "yes" || IncludesPets == "Yes"){
            IncludesPetsBool = true;
            IncludesPetsLoopError = false;
            newRide->setIncludesPets(IncludesPetsBool); // sets bool to true returns as 1
        }
        else if(IncludesPets == "No" || IncludesPets == "no"){
            IncludesPetsBool = true;
            IncludesPetsLoopError = false;
            newRide->setIncludesPets(IncludesPetsBool); // sets bool as false returns as 0
        }
        else{
            cout << "Error Invalid Input" << endl; // if user inputs anything other than yes or no it returns with error
            IncludesPetsBool = false;
        }

    float RatingByCustomer;
    bool RatingByCustomerLoopError;
    do{
        cout << "Enter Rating For Ride 0 - 5" << endl;
        cin >> RatingByCustomer;
        if(RatingByCustomer < 0 || RatingByCustomer > 5){ // if rating is less than 0 or greater than 5 we get an error
            cout << "Error Only Enter Number 0 - 5 " << endl;
            RatingByCustomerLoopError = true;
        }
        else{
            newRide->setRatingByCustomer(RatingByCustomer); // if not we set rating by customer to input from user 
            RatingByCustomerLoopError = false;
        }
    }while(RatingByCustomerLoopError == true);

    }while(IncludesPetsLoopError == true);

    RideList.push_back(newRide);
}

// Function called when user chooses to edit a Ride
// Displays options user can pick to edit
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

void Rides::deleteRide() {
    if (RideList.empty()) {
        cout << "RIDE LIST IS EMPTY" << endl;
    } else {
        int deleteID;
        bool deleteRideLoopError;

        do {
            cout << "ENTER ID FOR RIDE TO DELETE: ";
            cin >> deleteID;
            
            for (int i = 0; i < RideList.size(); ++i) {
                if (deleteID == RideList[i]->getID()) {
                    // Delete the ride by erasing the element from the RideList
                    RideList.erase(RideList.begin() + i);
                    cout << "Ride Deleted" << endl;
                    deleteRideLoopError = false;
                    break; // Exit the loop after successfully deleting the ride
                } else {
                    cout << "RIDE NOT FOUND" << endl;
                    deleteRideLoopError = true;
                }
            }
        } while (deleteRideLoopError); // Repeat until the ride is found and deleted
    }
}

void Rides::searchAndFindRide() {
    if (RideList.empty()) {
        cout << "RIDE LIST IS EMPTY" << endl;
    } else {
        int findID;
        bool findRideLoopError;

        do {
            cout << "ENTER ID OF RIDE TO FIND: ";
            cin >> findID;
            findRideLoopError = true; // Initialize the error flag to true

            for (int i = 0; i < RideList.size(); ++i) {
                if (RideList[i]->getID() == findID) {
                    // Ride with the specified ID is found
                    findRideLoopError = false; // Set the error flag to false

                    cout << "RIDE FOUND" << endl;
                    cout << "RIDE INFO:" << endl;
                    cout << "ID: " << RideList[i]->getID() << endl;
                    cout << "PICK UP LOCATION: " << RideList[i]->getPickUpLocation() << endl;
                    cout << "DROP OFF LOCATION: " << RideList[i]->getDropOffLocation() << endl;
                    cout << "PARTY SIZE: " << RideList[i]->getPartySize() << endl;

                    // Check if the ride includes pets and display the appropriate status
                    if (RideList[i]->getIncludesPets() == 1) {
                        cout << "PET STATUS: Ride Includes Pets" << endl;
                    } else {
                        cout << "PET STATUS: Ride Does Not Include Pets" << endl;
                    }

                    cout << "RATING: " << RideList[i]->getRatingByCustomer() << "/5" << endl;
                }
            }

            if (findRideLoopError) {
                cout << "RIDE NOT FOUND" << endl;
            }
        } while (findRideLoopError); // Repeat until the ride is found or user decides to exit
    }
}


void Rides::printAllRides() {
    if (RideList.empty()) {
        cout << "RIDE LIST IS EMPTY" << endl;
    } else {
        for (int i = 0; i < RideList.size(); ++i) {
            cout << "INFO FOR RIDE " << i + 1 << ": " << endl;
            cout << "RIDE ID: " << RideList[i]->getID() << endl;
            cout << "Pick Up Location: " << RideList[i]->getPickUpLocation() << endl;
            cout << "Drop Off Location: " << RideList[i]->getDropOffLocation() << endl;
            cout << "Party Size: " << RideList[i]->getPartySize() << endl;

            // Check if the ride includes pets and display the appropriate status
            if (RideList[i]->getIncludesPets() == 1) {
                cout << "Pet Status: Ride Has Pets" << endl;
            } else {
                cout << "Pet Status: Ride Does Not Have Pets" << endl;
            }

            cout << "Rating By Customer: " << RideList[i]->getRatingByCustomer() << endl;
        }
    }
}



