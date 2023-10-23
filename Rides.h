#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"
#include "Passenger.h"
#include "Ride.h"

class Rides {
public:
    // Public member functions for the Rides class

    // Function to add a new ride
    void addRide();

    // Function to edit ride information
    void editRide();

    // Function to delete a ride
    void deleteRide();

    // Function to search and find a ride
    void searchAndFindRide();

    // Function to print information of all rides
    void printAllRides();

private:
    int count; // A variable to keep track of the number of rides
    vector<Ride*> RideList;// A vector to store pointers to Ride objects
};