#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <string>
using namespace std ;

class Passenger{

	private:
		string passengersName ;
		int ticketID ;
		string destinations ;
		string sourceCities ;

	public:
		//getters
		string getPassengerName() ;
		int getTicketID() ;
		string getDestination() ;
		string getSourceCity() ;
		//setters
		void setPassengerName(string) ;//passengername
		void setTicketID(int) ;//ticketNo
		void setDestination(string) ;//DestName
		void setSourceCity(string) ;//Srccity

		void getInfo(int TID, string PNAME, string DESTINATION, string SOURCECITY) ;

};


#endif
