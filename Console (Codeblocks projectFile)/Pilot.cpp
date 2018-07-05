#include <iostream>
#include <string>
using namespace std ;
#include "Pilot.h"

Pilot::Pilot()
{

}
Pilot::Pilot(int pilotID, string pilotName):pilotID(pilotID), pilotName(pilotName){}

string Pilot::getPilotName()
{
	return pilotName ;
}
int Pilot::getPilotID()
{
	return pilotID ;
}

void Pilot::setPilotName(string pN)
{
	pilotName = pN ;
}

void Pilot::setPilotID(int pID)
{
	pilotID = pID ;
}

/*
void Pilot::getInfo(int PID, string PNAME, int PFEXPERIANCE, int BASICSALARY, int FFEE)
{
	int index = 0 ;
    for(int i = 0 ; i < number ; i++)
    {
        if(PID == pilotID)
        {
            index = i ;
            break ;
        }
    }
}
*/
Pilot::~Pilot()
{

}
