#ifndef DRIVERS_H
#define DRIVERS_H

// Include necessary C++ standard libraries and headers
#include <iostream>
#include <vector>
using namespace std;

// Include user-defined class headers
#include "Driver.h"
#include "Passengers.h"
#include "Passenger.h"

// Declare the Drivers class
class Drivers {
public:
    // Public member functions for the Drivers class
    void addDriver();               // Function to add a new driver
    void editDrivers();             // Function to edit driver information
    void deleteDriver();            // Function to delete a driver
    void searchAndFindDriver();     // Function to search and find a driver
    void printAllDrivers();         // Function to print information of all drivers

private:
    int count;                      // A variable to keep track of the number of drivers
    vector<Driver*> DriverList;     // A vector to store pointers to Driver objects
};

#endif // End of the header guard