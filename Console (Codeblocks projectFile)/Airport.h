#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include "Plane.h"
#include "GroundStaff.h"
#include "onBoardStaff.h"
#include "Flight.h"
#include <fstream>
#include <string>
using namespace std ;

class Airport{

	private:
		string airportName ;
		int numberOfRunways ;
		double* lengthOfRunwaysInKilometers ;
        int aircrafts ;
		Plane *plane ;
		int currentlyStationedAircrafts ;
		ifstream READ ;
        GroundStaff groundstaff ;
        onBoardStaff onboardstaff ;
        Flight flight ;
        bool endOrNot  ;
	public:
        void LOOP() ;
		Airport() ;
		//getters
		string getAirportName() ;//gets airport name
		int getNumberOfRunways() ;//gets number of runways
		int getLengthOfRunway() ;//gets length of runway
		int getAircraftsCapacity() ;//gets capacity
		int getCurrentlyStationedAircrafts() ;//gets station aircraft name
		//setters
		void setAirportName(string) ;//sets Airport name from file
		void setNumberOfRunways(int) ;//sets number of runways from file
		void setLengthOfRunway(int) ;//sets length of runways from file
		void setAircraftsCapacity(int) ;//sets aircrafts capacity from file
		void setCurrentlyStationedAircrafts(int) ;//sets station aircraft name from file

		void printAllData() ;

        void addFlight() ;
        int searchFlight() ;
        void printAllFlight() ;
        void cancelFlight() ;
        void exit() ;
        void searchGroundStaff() ;
        void searchOnboardStaff() ;
		void addNewAirCraft() ;
		void addNewRunway() ;


		~Airport() ;

};


#endif
