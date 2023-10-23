#ifndef RIDE_H
#define RIDE_H

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"

class Ride {
public:
    // Public member functions for the Ride class

    // Setter and getter for the ride's ID
    void setID(int ID);// Set the ride's ID
    int getID();// Get the ride's ID

    // Setter and getter for the pick-up location
    void setPickUpLocation(string PickUpLocation); // Set the pick-up location
    string getPickUpLocation();// Get the pick-up location

    // Setter and getter for the drop-off location
    void setDropOffLocation(string DropOffLocation); // Set the drop-off location
    string getDropOffLocation();  // Get the drop-off location

    // Setter and getter for the party size (number of passengers)
    void setPartySize(int PartySize);  // Set the party size
    int getPartySize(); // Get the party size

    // Setter and getter for whether the ride includes pets
    void setIncludesPets(bool IncludesPets);  // Set whether the ride includes pets
    bool getIncludesPets();// Get whether the ride includes pets

    // Setter and getter for the customer's rating of the ride
    void setRatingByCustomer(float RatingByCustomer);  // Set the customer's rating of the ride
    float getRatingByCustomer(); // Get the customer's rating

private:
    int ID;  // Private member variable to store the ride's ID
    string PickUpLocation; // Private member variable to store the pick-up location
    string DropOffLocation;// Private member variable to store the drop-off location
    tm PickUpTime;         // Private member variable for pick-up time (requires inclusion of <ctime>)
    tm DropOffTime;        // Private member variable for drop-off time (requires inclusion of <ctime>)
    int PartySize;         // Private member variable to store the party size
    bool IncludesPets;     // Private member variable to indicate whether the ride includes pets
    string Status;         // Private member variable for ride status (not set or used in the provided code)
    float RatingByCustomer;// Private member variable to store the customer's rating
};

#endif