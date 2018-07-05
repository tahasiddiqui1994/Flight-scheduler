#include <iostream>
using namespace std ;
#include "Plane.h"

Plane::Plane()
{
	aircraftModel = "" ;
	totalSeats = 0 ;
}

Plane::Plane(string aircraftModel, int totalSeats):
aircraftModel(aircraftModel), totalSeats(totalSeats){}

string Plane::getAircraftModel()
{
	return aircraftModel ;
}
int Plane::getTotalSeats()
{
	return totalSeats ;
}

void Plane::setAircraftModel(string aM)
{
	aircraftModel = aM ;
}

void Plane::setTotalSeats(int tS)
{
	totalSeats = tS ;
}
