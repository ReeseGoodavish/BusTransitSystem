#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"
#include "Passenger.h"

void Driver::setID(int ID){
    this->ID = ID;
}
int Driver::getID(){
    return ID;
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
