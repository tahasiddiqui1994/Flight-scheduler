#ifndef AIRLINE_H
#define AIRLINE_H
#include"flight.h"
#include"plane.h"
#include"pilot.h"
#include <fstream>
#include <vector>
class Airline
{
    public:
        Airline();  //dafault constructor
        Airline(string FilePath); //parametrized constructor

        void addPilot(Pilot);// adds pilot to pilot vector
        Pilot getPilot(int);//returns pilot from pilot vector
        void addPlane(Plane);// adds plane to pilot vector
        Plane getPlane(int);//returns pilot from pilot vector
        void addFlight(Flight);// Add Flight TO FLIGHT vector
        Flight getFlight(int);  //return flight at given index
        void readFlightsFromFile(string FilePath); // reads flights from given filePath
        void printFlight(int);  //printFlight on console
        void addFlight(string ,Plane, Pilot, string);   //add flight in flight vector
        //returns flight by refrence
        void getFlightValues(int index, string& inID, string& inModel, int& inCapacity, string& PilotID, string& pilotFirstName, string& pilotLastName, string& route,string& EngineerID);
        //getters
        int getTotalFlights();
        int getPilotIndex(string);
        void getPilotValues(int index, string& FirstName,string& LastName, string& id, int& Exp, int& BasicPay, int& HourlyPay);
        void getPlaneValues(int index, string& ID, string& Model, int& Capacity);
        int getTotalPilots();
        int getAircraftIndex(string id);
        int getTotalPlanes();
        int getFlightIndex(string);
        //returns engineer index
        int getEngineerIndex(string);
        //add engineer to flight engineer vector
        void addEngineer(FlightEngineer);
        int getTotalEngineers();//gets total engineers
        void getEngineerValues(int index,string& inID,string& inFirstName,string& inLastName,int& inPay,string& inLisence);
        void writeToFile();//write whole airline file
        void removePilot(string);   // remove pilot from vector
        void removePlane(string);   // remove plane from vector
        void removeFlight(string);  //  remove flight from vector
        void removeEngineer(string); //removes engineer

    protected:
        // vectors objects
        vector<Flight> flights;
        vector<Plane> aircrafts;
        vector<Pilot> pilots;
        vector<FlightEngineer> engineers;
        //filing variables for read and write
        ifstream inFile;
        ofstream outFile;
        //data member
        string filePath;

    private:
};

#endif // AIRLINE_H
