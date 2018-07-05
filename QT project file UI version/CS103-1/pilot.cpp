#include "pilot.h"

Pilot::Pilot()
{
    //ctor
}
void Pilot::readFromFile(ifstream& inFile){
    inFile>>ID;
    inFile>>firstName;
    inFile>>lastName;
    inFile>>experiance;
    inFile>>basicPay;
    inFile>>hourlyPay;
}

void Pilot::printPilot(){
    cout<<ID<<endl;
    cout<<firstName<<endl;
    cout<<lastName<<endl;
    cout<<experiance<<endl;
    cout<<basicPay<<endl;
    cout<<hourlyPay<<endl;
}
void Pilot::printForFlight(){
    cout<<ID<<endl;
    cout<<firstName<<endl;
    cout<<lastName<<endl;
}
void Pilot::setPilot(string inID, string inFirstName, string inLastName, int inExp, int inBasicPay, int inHourlyPay){
    ID=inID;
    firstName=inFirstName;
    lastName=inLastName;
    experiance=inExp;
    basicPay=inBasicPay;
    hourlyPay=inHourlyPay;
}
string Pilot::getFirstName(){

    return firstName;
}

string Pilot::getLastName(){
    return lastName;
}

string Pilot::getID(){
    return ID;
}
int Pilot::getExp(){
 return experiance;
}

int Pilot::getBasicPay(){
    return basicPay;
}

int Pilot::getHourlyPay(){
    return hourlyPay;
}
void Pilot::writeToFile(ofstream& outFile){
    outFile<<ID<<" ";
    outFile<<firstName<<" ";
    outFile<<lastName<<" ";
    outFile<<experiance<<" ";
    outFile<<basicPay<<" ";
    outFile<<hourlyPay<<" ";
}
void Pilot::resetPilot(){
    firstName="N/A";
    lastName="N/A";
    ID="N/A";
    experiance=0;
    basicPay=0;
    hourlyPay=0;
}
