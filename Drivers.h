#ifndef DRIVERS_H
#define DRIVERS_H

#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"

class Drivers{
    public:

        void addDriver();
        void editDrivers();
        void deleteDriver();
        void searchAndFindDriver();
        void printAllDrivers();

    private:
        int count;
        vector<Driver*> DriverList;

};

#endif