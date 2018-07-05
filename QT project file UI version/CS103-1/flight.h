
#ifndef FLIGHT_H
#define FLIGHT_H
#include "plane.h"
#include "pilot.h"
#include "flightengineer.h"
class Flight
{
    public:
        Flight();// default constructor
        //setters
        void setFlight(string inID,Plane inPlane, Pilot inPilot, string inRoute);
        void readFlight(ifstream&);
        void setPilot(Pilot);
        void printFlight();
        void setPlane(string, string, int);
        //getters
        string getID();
        string getRoute();
        int getCapacity();
        string getModel();
        string getPilotFirstName();
        string getPilotLastName();
        string getPilotID();
        Pilot getPilot();
        Plane getPlane();
        string getPlaneID();
        //write data to file
        void writeToFile(ofstream&);
        //remove pilot data from flight
        void removePilot();
        FlightEngineer getEngineer();
        //return engineer's ID
        string getEngineerID();
        //remove engineer ID from flight
        void removeEngineer();

    protected:
        //data members
        string ID;
        Plane plane;
        Pilot pilot;
        string route;
        //FlightEngineer object
        FlightEngineer engineer;
    private:

};
#endif // FLIGHT_H
