#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passenger.h"

class Passengers{
    public:
        void addPassenger();
        void editPassenger();
        void deletePassenger();
        void searchAndFindPassenger();
        void printAllPassengers();

    private:
        int count;
        vector<Passenger*> PassengerList;
};

#endif