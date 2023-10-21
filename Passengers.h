#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <iostream>
#include <vector>
using namespace std;

#include "Drivers.h"
#include "Driver.h"

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