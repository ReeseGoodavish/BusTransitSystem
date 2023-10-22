#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"
#include "Passenger.h"
#include "Ride.h"

class Rides{
    public:
        void addRide();
        void editRide();
        void deleteRide();
        void searchAndFindRide();
        void printAllRides();

    private:
        int count;
        vector<Ride*> RideList;

};