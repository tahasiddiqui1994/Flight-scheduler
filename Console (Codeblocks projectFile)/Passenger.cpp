#include <iostream>
using namespace std ;
#include "Passenger.h"

string Passenger::getPassengerName()
{
	return passengersName ;
}
int Passenger::getTicketID()
{
	return ticketID ;
}
string Passenger::getDestination()
{
	return destinations ;
}
string Passenger::getSourceCity()
{
	return sourceCities ;
}

void Passenger::setPassengerName(string pN)
{
	passengersName = pN ;
}

void Passenger::setTicketID(int ID)
{
	ticketID = ID ;
}

void Passenger::setDestination(string dest)
{
	destinations = dest ;
}

void Passenger::setSourceCity(string sC)
{
	sourceCities = sC ;
}
/*
void Passenger::getInfo(int TID, string PNAME,
string DESTINATION, string SOURCECITY)
{
	int index = 0 ;
    for(int i = 0 ; i < number ; i++)
    {
        if(GID == ID[i])
        {
            index = i ;
            break ;
        }
    }

    NAME = getName(index) ;
    MSALARY = getmonthlySalary(index) ;
    HSALARY = getsalaryInHours(index) ;
    PNUMBER = getPhoneNumber(index) ;
    ADDRESS = getAddress(index) ;
    DESIGNATION = getDesignation(index) ;
}*/
