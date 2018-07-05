#ifndef PILOT_H
#define PILOT_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

class Pilot{

	private:
		string pilotName ;
		int pilotID ;
		ifstream FILE ;
		int number ;

	public:
		Pilot() ;
		Pilot(int pilotID, string pilotName) ;
		//getters
		string getPilotName() ;
		int getPilotID() ;

		//setters
		void setPilotName(string) ;
		void setPilotID(int) ;


        ~Pilot() ;
};

#endif
