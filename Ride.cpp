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

// GETTERS AND SETTERS FOR RIDE CLASS
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
//GETTERS AND SETTERS FOR RIDE CLASS