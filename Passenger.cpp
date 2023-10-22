#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"
#include "Rides.h"


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