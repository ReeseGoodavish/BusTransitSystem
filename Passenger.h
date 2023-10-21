#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"
#include "Passengers.h"

class Passenger{
    public:
        void setID(int ID);
        int getID();

        void setName(string Name);
        string getName();

        void setPayment(string Payment);
        string getPayment();

        void setHandicapped(bool Handicapped);
        bool getHandicapped();

        void setRating(float Rating);
        float getRating();

        void setHasPets(bool HasPets);
        bool getHasPets();

    private:
        string Name;
        int ID;
        string Payment;
        bool Handicapped;
        float Rating;
        bool HasPets;

};

#endif