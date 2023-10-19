#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"

//GETTERS AND SETTERS
void Passenger::setID(int ID){
    this->ID = ID;
}
int Passenger::getID(){
    return ID;
}

void Passenger::setName(string Name){
    this->Name = Name;
}
string Passenger::getName(){
    return Name;
}

void Passenger::setPayment(string Payment){
    this->Payment = Payment;
}
string Passenger::getPayment(){
    return Payment;
}

void Passenger::setHandicapped(bool Handicapped){
    this->Handicapped = Handicapped;
}
bool Passenger::getHandicapped(){
    return Handicapped;
}

void Passenger::setRating(float Rating){
    this->Rating = Rating;
}
float Passenger::getRating(){
    return Rating;
}

void Passenger::setHasPets(bool HasPets){
    this->HasPets = HasPets;
}
bool Passenger::getHasPets(){
    return HasPets;
}
// GETTETS AND SETTERS

//FUNCTIONS

void Passengers::addPassenger(){

    Passenger* newPassenger = new Passenger();

    static int count = 100000;
    cout << endl;
    cout << "NEW PASSENGER ID SET TO " << count << endl;
    newPassenger->setID(count);
    ++count;

    string Name;
    cout << "Enter Full Name For New Passenger" << endl;
    cin.ignore();
    getline(cin, Name);
    newPassenger->setName(Name);

    string Payment;
    int paymentOption;
    cout << "PAYMENT OPTIONS" << endl;
    cout << "1 - Cash" << endl;
    cout << "2 - Debit" << endl;
    cout << "3 - Credit" << endl;
    cout << "4 - Online Transfer" << endl;

    bool paymentOptionLoopError;
    do{
        cout << "Enter Integer For Which Payment New Passenger Uses (1,2,3,4)" << endl;
        cin >> paymentOption;
        if(paymentOption == 1){
            Payment = "Cash";
            newPassenger->setPayment(Payment);
            paymentOptionLoopError = false;
        }
        else if(paymentOption == 2){
            Payment = "Debit";
            newPassenger->setPayment(Payment);
            paymentOptionLoopError = false;
        }
        else if(paymentOption == 3){
            Payment = "Credit";
            newPassenger->setPayment(Payment);
            paymentOptionLoopError = false;
        }
        else if(paymentOption == 4){
            Payment = "Online Transfer";
            newPassenger->setPayment(Payment);
            paymentOptionLoopError = false;
        }
        else{
            cout << "ERROR INVALID CHOICE" << endl;
            paymentOptionLoopError = true;
        }
    }while(paymentOptionLoopError == true);

    bool Handicapped;
    bool HandicappedLoopError;
    string HandicappedString;

    do{
        cout << "Is The New Passenger Handicapped: 'Yes' or 'No' (without quotes)" << endl;
        cin >> HandicappedString;
        if(HandicappedString == "Yes" || HandicappedString == "yes"){
            Handicapped = true;
            newPassenger->setHandicapped(Handicapped);
            HandicappedLoopError = false;
        }
        else if(HandicappedString == "No" || HandicappedString == "no"){
            Handicapped = false;
            newPassenger->setHandicapped(Handicapped);
            HandicappedLoopError = false;
        }
        else{
            cout << "ERROR INVALID CHOICE" << endl;
            HandicappedLoopError = true;
        }
    }while(HandicappedLoopError == true);

    float Rating;
    bool RatingLoopError;
    do{
        cout << "Enter Rating For New Passenger 0 - 5" << endl;
        cin >> Rating;
        if(Rating < 0 || Rating > 5){
            cout << "ERROR ONLY INPUT 0 - 5" << endl;
            RatingLoopError = true;
        }
        else{
            newPassenger->setRating(Rating);
            RatingLoopError = false;
        }
    }while(RatingLoopError == true);

    bool HasPets;
    bool HasPetsLoopError;
    string HasPetsString;

    do{
        cout << "Does New Passenger Have Pets: 'Yes' or 'No' (without quotes)" << endl;
        cin >> HasPetsString;
        if(HasPetsString == "Yes" || HasPetsString == "yes"){
            HasPets = true;
            newPassenger->setHasPets(HasPets);
            HasPetsLoopError = false;
        }
        else if(HasPetsString == "No" || HasPetsString == "no"){
            HasPets = false;
            newPassenger->setHasPets(HasPets);
            HasPetsLoopError = false;
        }
        else{
            cout << "ERROR INVALID CHOICE" << endl;
            HasPetsLoopError = true;
        }
    }while(HasPetsLoopError == true);

    PassengerList.push_back(newPassenger);

    cout << "INFO FOR NEW PASSENGER" << endl;
    cout << "Passenger ID: " << newPassenger->getID() << endl;
    cout << "Name: " << newPassenger->getName() << endl;
    cout << "Payment Method: " << newPassenger->getPayment() << endl;
    if(newPassenger->getHandicapped() == 1){
        cout << "Handicapped Status: Driver Is HandiCapped" << endl;
    }
    else if(newPassenger->getHandicapped() == 0){
        cout << "Handicapped Status: Driver Is Not HandiCapped" << endl;
    }
    cout << "Passenger Rating: " << newPassenger->getRating() << "/5" << endl;
    if(newPassenger->getHasPets() == 1){
        cout << "Pets Status: Passenger Has Pets" << endl;
    }
    else if(newPassenger->getHasPets() == 0){
        cout << "Pets Status: Passenger Does Not Have Pets" << endl;
    }

}

void editPassengerMenu(){
    cout << "EDIT MENU" << endl;
    cout << "1 - ID" << endl;
    cout << "2 - Name" << endl;
    cout << "3 - Payment Method" << endl;
    cout << "4 - Handicapped Status" << endl;
    cout << "5 - Rating" << endl;
    cout << "6 - Has Pets Status" << endl;
}

void Passengers::editPassenger(){

    int EditID;
    string newID;
    bool PassengerExists = false;
    bool enterIDLoopError = true;

    do{
        if(PassengerList.empty()){
            cout << "PASSENGER LIST IS EMPTY" << endl;
            enterIDLoopError = false;
            PassengerExists = false;
        }
        else{
            do{
                cout << "ENTER ID OF PASSENGER TO EDIT" << endl;
                cin >> EditID;
                for(int i = 0; i < PassengerList.size(); ++i){
                    if(PassengerList[i]->getID() == EditID){
                        cout << "PASSENGER FOUND" << endl;
                        cout << "INFO FOR PASSENGER" << endl;
                        cout << "Passenger ID: " << PassengerList[i]->getID() << endl;
                        cout << "Passenger Name: " << PassengerList[i]->getName() << endl;
                        cout << "Passenger Payment Method: " << PassengerList[i]->getPayment() << endl;
                            if(PassengerList[i]->getHandicapped() == 1){
                                cout << "Passenger Handicapped Status: Passenger Is Handicapped" << endl;
                            }
                            else if(PassengerList[i]->getHandicapped() == 0){
                                cout << "Passenger Handicapped Status: Passenger Is Not Handicapped" << endl;
                            }
                        cout << "Passenger Rating: " << PassengerList[i]->getRating() << "/5" << endl;
                            if(PassengerList[i]->getHasPets() == 1){
                                cout << "Passenger Pet Status: Passenger Has Pets" << endl;
                            }
                            else if(PassengerList[i]->getHasPets() == 0){
                                cout << "Passenger Pet Status: Passenger Does Not Have Pets" << endl;
                            }  
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
    }while(PassengerExists == true);

    int EditChoice;
    bool newIDLoopError = false;
    while(PassengerExists == false && enterIDLoopError == true){
        editPassengerMenu();
        cin >> EditChoice;

        if(EditChoice ==1){
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
                for(int i = 0; i < PassengerList.size(); ++i){
                    if(PassengerList[i]->getID() == EditID){
                        int EditnewID = stoi(newID);
                        PassengerList[i]->setID(EditnewID);
                        cout << "DRIVER ID UPDATED" << endl;
                    }
                }
                PassengerExists = true;
                enterIDLoopError = false;                    
                }
            }while(newIDLoopError == true);
        }
        else if(EditChoice == 2){
            string editName;
            cout << "ENTER NEW FULL NAME FOR PASSENGER" << endl;
            cin.ignore();
            getline(cin, editName);

            for(int i = 0; i < PassengerList.size(); ++i){
                if(PassengerList[i]->getID() == EditID){
                    PassengerList[i]->setName(editName);
                    cout << "PASSENGER FULL NAME UPDATED" << endl;
                }
            }
            PassengerExists = true;
            enterIDLoopError = false;

        }
        else if(EditChoice == 3){
            int editPaymentChoice;
            bool PaymentOptionLoopError;
            string editPayment;
            do{
                    cout << "ENTER NEW PAYMENT FOR PASSENGER" << endl;
                    cout << "PAYMENT OPTIONS" << endl;
                    cout << "1 - Cash" << endl;
                    cout << "2 - Debit" << endl;
                    cout << "3 - Credit" << endl;
                    cout << "4 - Online Transfer" << endl;
                    cin >>editPaymentChoice;
                if(editPaymentChoice == 1){
                    PassengerExists = true;
                    enterIDLoopError = false;
                    PaymentOptionLoopError = false;
                    editPayment = "Cash";
                    for(int i = 0; i < PassengerList.size(); ++i){
                        if(PassengerList[i]->getID() == EditID){
                            PassengerList[i]->setPayment(editPayment);
                        }
                    }
                }
                else if(editPaymentChoice == 2){
                    PassengerExists = true;
                    enterIDLoopError = false;
                    PaymentOptionLoopError = false;
                    editPayment = "Debit";
                    for(int i = 0; i < PassengerList.size(); ++i){
                        if(PassengerList[i]->getID() == EditID){
                            PassengerList[i]->setPayment(editPayment);
                        }
                    }
                }
                else if(editPaymentChoice == 3){
                    PassengerExists = true;
                    enterIDLoopError = false;
                    PaymentOptionLoopError = false;
                    editPayment = "Credit";
                    for(int i = 0; i < PassengerList.size(); ++i){
                        if(PassengerList[i]->getID() == EditID){
                            PassengerList[i]->setPayment(editPayment);
                        }
                    }
                }
                else if(editPaymentChoice == 4){
                    PassengerExists = true;
                    enterIDLoopError = false;
                    PaymentOptionLoopError = false;
                    editPayment = "Online Transfer";
                    for(int i = 0; i < PassengerList.size(); ++i){
                        if(PassengerList[i]->getID() == EditID){
                            PassengerList[i]->setPayment(editPayment);
                        }
                    }
                }
                else{
                    cout << "ERROR INVALID CHOICE " << endl;
                    PaymentOptionLoopError = true;

                }

            }while(PaymentOptionLoopError == true);
        }
        else if(EditChoice == 4){
            string editHandicapStatusString;
            bool editHandicapStatus;
            bool editHandicapStatusLoopError;
            cout << "EDIT PASSENGER HANDICAP STATUS" << endl;
            do{
                cout << "Enter Handicapped Status: 'Yes' If Handicapped 'No' If Not Handicapped (without quotes)" << endl;
                cin >> editHandicapStatusString;
                if(editHandicapStatusString == "Yes" || editHandicapStatusString == "yes"){
                    PassengerExists = true;
                    enterIDLoopError = false; 
                    editHandicapStatus = true;
                    editHandicapStatusLoopError = false;
                    for(int i = 0; i < PassengerList.size(); ++i){
                        if(PassengerList[i]->getID() == EditID){
                            PassengerList[i]->setHandicapped(editHandicapStatus);
                        }
                    }
                }
                else if(editHandicapStatusString == "No" || editHandicapStatusString == "no"){
                    PassengerExists = true;
                    enterIDLoopError = false; 
                    editHandicapStatus = false;
                    editHandicapStatusLoopError = false;
                    for(int i = 0; i < PassengerList.size(); ++i){
                        if(PassengerList[i]->getID() == EditID){
                            PassengerList[i]->setHandicapped(editHandicapStatus);
                        }
                    }
                }
                else{
                    cout << "ERROR INVALID CHOICE " << endl;
                    editHandicapStatusLoopError = true;
                }
            }while(editHandicapStatusLoopError == true);

        } 
    }
}

void Passengers::printAllPassengers(){

    if(!PassengerList.empty()){
        cout << "LIST OF ALL PASSENGERS" << endl;
        for(int i = 0; i < PassengerList.size(); ++i){
            cout << "Info For Passenger " << i + 1 << ":" << endl;
            cout << "Passenger ID: " << PassengerList[i]->getID() << endl;
            cout << "Name: " << PassengerList[i]->getName() << endl;
            cout << "Payment Method: " << PassengerList[i]->getPayment() << endl;
            if(PassengerList[i]->getHandicapped() == 1){
                cout << "Handicapped Status: Driver Is HandiCapped" << endl;
            }
            else if(PassengerList[i]->getHandicapped() == 0){
                cout << "Handicapped Status: Driver Is Not HandiCapped" << endl;
            }
            cout << "Passenger Rating: " << PassengerList[i]->getRating() << "/5" << endl;
            if(PassengerList[i]->getHasPets() == 1){
                cout << "Pets Status: Passenger Has Pets" << endl;
            }
            else if(PassengerList[i]->getHasPets() == 0){
                cout << "Pets Status: Passenger Does Not Have Pets" << endl;
            }
            cout << endl;
        }
    }
    else{
        cout << "ERROR PASSENGER LIST EMPTY TEST" << endl;
    }

}

