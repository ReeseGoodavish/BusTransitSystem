#ifndef DRIVER_H
#define DRIVER

#include <iostream>
#include <vector>
using namespace std;

class Driver{
    public:
        void setID(int ID);

        int getID();

        void setFirstName(string FirstName);
        string getFirstName();

        void setLastName(string LastName);
        string getLastName();

        void setCapacity(int Capacity);
        int getCapacity();

        void setHandicapped(bool Handicapped);
        bool getHandicapped();

        void setVehicleType(string VehicleType);
        string getVehicleType();

        void setRating(float Rating);
        float getRating();

        void setAvailable(bool Available);
        bool getAvailable();

        void setPetsAllowed(bool PetsAllowed);
        bool getPetsAllowed();

        void setNotes(string Notes);
        string getNotes();



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
        Drivers();

        void addDriver();
        void editDrivers();
        void printAllDrivers();

    private:
        int count;
        vector<Driver*> DriverList;

};

#endif