#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"
#include "Passenger.h"


class Driver {
public:
    // Public member functions for the Driver class

    // Setter and getter for the driver's ID
    void setID(int ID);       // Set the driver's ID
    int getID();              // Get the driver's ID

    // Setter and getter for the driver's first name
    void setFirstName(string FirstName);   // Set the driver's first name
    string getFirstName();                 // Get the driver's first name

    // Setter and getter for the driver's last name
    void setLastName(string LastName);     // Set the driver's last name
    string getLastName();                 // Get the driver's last name

    // Setter and getter for the driver's capacity (e.g., number of passengers)
    void setCapacity(int Capacity);        // Set the driver's capacity
    int getCapacity();                     // Get the driver's capacity

    // Setter and getter for the driver's handicapped status
    void setHandicapped(bool Handicapped);  // Set whether the driver can accommodate handicapped passengers
    bool getHandicapped();                 // Get the driver's handicapped status

    // Setter and getter for the driver's vehicle type
    void setVehicleType(string VehicleType);  // Set the type of vehicle the driver uses
    string getVehicleType();                 // Get the driver's vehicle type

    // Setter and getter for the driver's rating
    void setRating(float Rating);        // Set the driver's rating
    float getRating();                   // Get the driver's rating

    // Setter and getter for the driver's availability status
    void setAvailable(bool Available);   // Set whether the driver is available
    bool getAvailable();                // Get the driver's availability status

    // Setter and getter for the driver's policy on pets
    void setPetsAllowed(bool PetsAllowed);  // Set whether the driver allows pets
    bool getPetsAllowed();                 // Get the driver's pet policy

    // Setter and getter for any additional notes about the driver
    void setNotes(string Notes);     // Set additional notes about the driver
    string getNotes();               // Get any additional notes about the driver

private:
    // Private member variables to store driver information
    int ID;
    string FirstName;
    string LastName;
    int Capacity;
    bool Handicapped;
    string VehicleType;
    float Rating;
    bool Available;
    bool PetsAllowed;
    string Notes;
};

#endif