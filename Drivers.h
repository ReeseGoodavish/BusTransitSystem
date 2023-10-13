#ifndef DRIVER_H
#define DRIVER

#include <iostream>
#include <vector>
using namespace std;

class Driver{
    public:
        void setFirstName(string FirstName);
        string getFirstName();

        void setLastName(string LastName);
        string getLastName();

        void setCapacity(int Capacity);
        int getCapacity();

        void setHandicapped(bool Handicapped);
        bool getHandicapped();

    private:
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

class Drivers{
    public:
    void addDriver();

    private:
    int count;

};

#endif