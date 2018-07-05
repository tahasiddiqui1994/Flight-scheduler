#include "flightstaff.h"

FlightStaff::FlightStaff()
{

}
string FlightStaff::getID(){
    return ID;
}

string FlightStaff::getFirstName(){
    return firstName;
}

string FlightStaff::getLastName(){
    return lastName;
}

int FlightStaff::getBasicPay(){
    return basicPay;
}

void FlightStaff::getInfo(string& inID,string& inFirstName, string& inLastName){
    ID=inID;
    firstName=inFirstName;
    lastName=inLastName;
}
void FlightStaff::setID(string inID){
    ID=inID;
}
