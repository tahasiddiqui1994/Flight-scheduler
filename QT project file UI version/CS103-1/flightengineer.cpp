#include "flightengineer.h"

FlightEngineer::FlightEngineer()
{
    ID="N/A";
    firstName="N/A";
    lastName="N/A";
    lisence="N/A";
    basicPay=0;
}
string FlightEngineer::getLisence(){
    return lisence;
}

void FlightEngineer::readFromFile(ifstream& inFile){
    inFile>>ID;
    inFile>>firstName;
    inFile>>lastName;
    inFile>>basicPay;
    inFile>>lisence;

}
void FlightEngineer::readNextFromFile(ifstream& inFile){
    inFile>>firstName;
    inFile>>lastName;
    inFile>>basicPay;
    inFile>>lisence;
}
void FlightEngineer::setEngineer(string inID, string inFirstName, string inLastName,int inPay,string inLisence){
    ID=inID;
    firstName=inFirstName;
    lastName=inLastName;
    basicPay=inPay;
    lisence=inLisence;
}

void FlightEngineer::getInfo(string& inID,string& inFirstName,string& inLastName,int& inPay,string& inLisence){
    inFirstName=firstName;
    inLastName=lastName;
    inID=ID;
    inPay=basicPay;
    inLisence=lisence;
}
