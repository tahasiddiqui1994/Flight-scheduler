#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <string>
using namespace std ;

class Plane{

	private:
		string aircraftModel ;
		int totalSeats ;
	public:
		Plane() ;
		Plane(string aircraftModel, int totalSeats) ;

		//getters
		string getAircraftModel() ;
		int getTotalSeats() ;
		//setters
		void setAircraftModel(string) ;//model
		void setTotalSeats(int) ;//seatCount

};

#endif
