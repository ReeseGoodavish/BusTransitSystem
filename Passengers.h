#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passenger.h"


class Passengers {
public:
    // Public member functions for the Passengers class

    // Function to add a new passenger
    void addPassenger();

    // Function to edit passenger information
    void editPassenger();

    // Function to delete a passenger
    void deletePassenger();

    // Function to search and find a passenger
    void searchAndFindPassenger();

    // Function to print information of all passengers
    void printAllPassengers();

private:
    int count;                      // A variable to keep track of the number of passengers
    vector<Passenger*> PassengerList;  // A vector to store pointers to Passenger objects
};

#endif