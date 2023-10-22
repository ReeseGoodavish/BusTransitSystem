#ifndef RIDE_H
#define RIDE_H

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"

class Ride{
    public:
        void setID(int ID);
        int getID();
        void setPickUpLocation(string PickUpLocation);
        string getPickUpLocation();
        void setDropOffLocation(string DropOffLocation);
        string getDropOffLocation();
        void setPartySize(int PartySize);
        int getPartySize();
        void setIncludesPets(bool IncludesPets);
        bool getIncludesPets();
        void setRatingByCustomer(float RatingByCustomer);
        float getRatingByCustomer();

    private:
        int ID;
        string PickUpLocation;
        string DropOffLocation;
        tm PickUpTime;
        tm DropOffTime;
        int PartySize;
        bool IncludesPets;
        string Status;
        float RatingByCustomer;

};

#endif