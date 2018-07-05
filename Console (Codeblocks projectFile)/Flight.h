#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include "Pilot.h"
#include "Plane.h"
#include <iostream>
#include <string>
using namespace std ;

class Flight{

	private:
		Pilot *pilot[50] ;
		Plane *plane[50] ;
		int *flightID ;
		string *route ;

		int *tempFlightID ;
		string *tempRoute ;

		ifstream FILE ;
        int number ;
        int usedIndex ;

	public:
	    Flight() ;
		Flight(int flightID, int pilotID, string pilotName,
		string aircraftModel, int totalSeats, string route) ;

        void getInfo(int FID, Pilot &argPilot, Plane &argPlane, string &argRoute) ;

        void setFlightID(int i, int value) ;
        void setFlightRoute(int i, string value) ;
        void setFlight(int flightID1, int pilotID1, string pilotName1,
		string aircraftModel1, int totalSeats1, string route1) ;

        int getFlightID(int) ;
        string getFlightRoute(int) ;
		int getNumber() ;
		void cancel(int) ;

        int getPilotID(int) ;
        string getPilotName(int) ;
        string getAircraftModel(int) ;
        int getTotalSeats(int) ;

		~Flight() ;
};

#endif
