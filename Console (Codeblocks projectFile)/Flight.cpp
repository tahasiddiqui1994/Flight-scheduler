#include <iostream>
#include <fstream>
#include <string>
#include "Flight.h"
using namespace std ;


Flight::Flight()
{
    FILE.open("Flight.txt") ;
    int flightID1 = 0, pilotID1 = 0, planeTotalSeats = 0 ;
    string pilotName1 = "", route1 = "", planeModel1 = "" ;
    FILE >> number ;

    flightID = new int[number] ;
    route = new string[number] ;
    for(int i = 0 ; i < number ; i++)
    {
        FILE >> flightID1 >> pilotID1 >> pilotName1 >> planeModel1 >> planeTotalSeats >> route1 ;

        setFlightID(i, flightID1) ;
        setFlightRoute(i, route1) ;
        pilot[i] = new Pilot(pilotID1, pilotName1) ;
        plane[i] = new Plane(planeModel1, planeTotalSeats) ;
        usedIndex++ ;
    }

    /*for(int i = 0 ; i < number ; i++)
    {
        cout << " Flight ID: " << getFlightID(i) << endl << " Pilot ID: "
        << pilot[i]->getPilotID() << endl << " Pilot Experiance: " << pilot[i]->getFlyingExperiance()
        << endl << " Pilot Basic Salary: " << pilot[i]->getBasicSalary() << endl
        << " Pilot Flying Fee: " << pilot[i]->getFlyingFee() << endl
        << " Plane Model: " << plane[i]->getAircraftModel() << endl
        << " Plane Seating capacity: " << plane[i]->getTotalSeats() << endl << endl ;
    }*/
}

Flight::Flight(int flightID1, int pilotID1, string pilotName1,
string aircraftModel1, int totalSeats1, string route1)
{
    tempFlightID = new int[number] ;
    for(int i = 0 ; i < number ; i++)
    {
        tempFlightID[i] = flightID[i] ;
    }
    tempRoute = new string[number] ;
    for(int i = 0 ; i < number ; i++)
    {
        tempRoute[i] = route[i] ;
    }

    delete[] flightID ;
    delete[] route ;
    number++ ;
    flightID = new int[number] ;
    route = new string[number] ;

    for(int i = 0 ; i < number-1 ; i++)
    {
        flightID[i] = tempFlightID[i] ;
    }
    for(int i = 0 ; i < number-1 ; i++)
    {
        route[i] = tempRoute[i] ;
    }

    flightID[number-1] = flightID1 ;
    route[number-1] = route1 ;
    pilot[usedIndex] = new Pilot(pilotID1, pilotName1) ;
    plane[usedIndex] = new Plane(aircraftModel1, totalSeats1) ;
    usedIndex++ ;

    delete[] tempFlightID ;
    delete[] tempRoute ;
}

void Flight::setFlight(int flightID1, int pilotID1, string pilotName1,
string aircraftModel1, int totalSeats1, string route1)
{

    tempFlightID = new int[number] ;
    for(int i = 0 ; i < number ; i++)
    {
        tempFlightID[i] = flightID[i] ;
    }
    tempRoute = new string[number] ;
    for(int i = 0 ; i < number ; i++)
    {
        tempRoute[i] = route[i] ;
    }

    delete[] flightID ;
    delete[] route ;
    number++ ;
    flightID = new int[number] ;
    route = new string[number] ;

    for(int i = 0 ; i < number-1 ; i++)
    {
        flightID[i] = tempFlightID[i] ;
    }
    for(int i = 0 ; i < number-1 ; i++)
    {
        route[i] = tempRoute[i] ;
    }

    flightID[number-1] = flightID1 ;
    route[number-1] = route1 ;
    cout << " Inside1" << endl;
    pilot[number-1] = new Pilot(pilotID1, pilotName1) ;
    plane[number-1] = new Plane(aircraftModel1, totalSeats1) ;
    cout << " Inside2" << endl;
    usedIndex++ ;

    delete[] tempFlightID ;
    delete[] tempRoute ;
    cout << " Inside3" << endl;
}


void Flight::getInfo(int FID, Pilot &argPilot, Plane &argPlane, string &argRoute)
{
    int index = -1 ;
    for(int i = 0 ; i < number ; i++)
    {
        if(FID == flightID[i])
        {
            index = i ;
            break ;
        }
    }

    argPilot.setPilotID(pilot[index]->getPilotID()) ;
    argPilot.setPilotName(pilot[index]->getPilotName()) ;

    argPlane.setAircraftModel(plane[index]->getAircraftModel()) ;
    argPlane.setTotalSeats(plane[index]->getTotalSeats()) ;

    argRoute = route[index] ;
}

void Flight::cancel(int index)
{
    tempFlightID = new int[number] ;
    for(int i = 0 ; i < number ; i++)
    {
        tempFlightID[i] = flightID[i] ;
    }
    tempRoute = new string[number] ;
    for(int i = 0 ; i < number ; i++)
    {
        tempRoute[i] = route[i] ;
    }
    delete[] flightID ;
    delete[] route ;
    usedIndex-- ;

    flightID = new int[number-1] ;
    route = new string[number-1] ;

    for(int i = 0 ; i < index ; i++)
    {
        flightID[i] = tempFlightID[i] ;
        route[i] = tempRoute[i] ;
    }
    for(int i = index ; i < number-1 ; i++)
    {
        flightID[i] = tempFlightID[i+1] ;
        route[i] = tempRoute[i+1] ;
    }
    for(int i = index ; i < number-1 ; i++)
    {
        pilot[i]->setPilotID(pilot[i+1]->getPilotID()) ;
        pilot[i]->setPilotName(pilot[i+1]->getPilotName()) ;
        plane[i]->setAircraftModel(plane[i+1]->getAircraftModel()) ;
        plane[i]->setTotalSeats(plane[i+1]->getTotalSeats()) ;
    }
    number-- ;

    delete[] tempFlightID ;
    delete[] tempRoute ;
}

int Flight::getNumber()
{
    return number ;
}
void Flight::setFlightID(int i, int value)
{
    flightID[i] = value ;
}
void Flight::setFlightRoute(int i, string value)
{
    route[i] = value ;
}

int Flight::getFlightID(int i)
{
    return flightID[i] ;
}
string Flight::getFlightRoute(int i)
{
    return route[i] ;
}
int Flight::getPilotID(int i)
{
    //cout << " pilot[i] ID: " << pilot[i]->getPilotID() << endl ;
    return pilot[i]->getPilotID() ;
}
string Flight::getPilotName(int i)
{
    //cout << " pilot[i] Name: " << pilot[i]->getPilotName() << endl ;
    return pilot[i]->getPilotName() ;
}
string Flight::getAircraftModel(int i)
{
    return plane[i]->getAircraftModel() ;
}
int Flight::getTotalSeats(int i)
{
    return plane[i]->getTotalSeats() ;
}
Flight::~Flight()
{
    for(int i = 0 ; i < number ; i++)
    {
        delete pilot[i] ;
        delete plane[i] ;
    }

    delete[] flightID ;
    delete[] route ;
}
