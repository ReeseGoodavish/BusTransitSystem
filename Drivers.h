#ifndef DRIVER_H
#define DRIVER

#include <iostream>
#include <vector>
using namespace std;

class Driver{
    public:

    private:
    int ID;
    char FirstName;
    char LastName;
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