#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"


class Passenger {
public:
    // Public member functions for the Passenger class

    // Setter and getter for the passenger's ID
    void setID(int ID);       // Set the passenger's ID
    int getID();              // Get the passenger's ID

    // Setter and getter for the passenger's name
    void setName(string Name);   // Set the passenger's name
    string getName();           // Get the passenger's name

    // Setter and getter for the passenger's payment information
    void setPayment(string Payment);   // Set the payment information for the passenger
    string getPayment();             // Get the payment information

    // Setter and getter for the passenger's handicapped status
    void setHandicapped(bool Handicapped);  // Set whether the passenger is handicapped
    bool getHandicapped();                 // Get the handicapped status of the passenger

    // Setter and getter for the passenger's rating
    void setRating(float Rating);    // Set the passenger's rating
    float getRating();               // Get the passenger's rating

    // Setter and getter for whether the passenger has pets
    void setHasPets(bool HasPets);   // Set whether the passenger has pets
    bool getHasPets();              // Get whether the passenger has pets

private:
    string Name;       // Private member variable to store the passenger's name
    int ID;            // Private member variable to store the passenger's ID
    string Payment;   // Private member variable to store payment information
    bool Handicapped; // Private member variable to store the handicapped status
    float Rating;     // Private member variable to store the passenger's rating
    bool HasPets;     // Private member variable to indicate whether the passenger has pets
};

#endif