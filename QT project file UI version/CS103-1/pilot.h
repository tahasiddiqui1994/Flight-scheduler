#ifndef PILOT_H
#define PILOT_H
#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class Pilot
{
    public:
        Pilot();    // default constructor
        void readFromFile(ifstream&);   //read data from file
        void printForFlight();  //print data on console
        void printPilot();      //print data on console
        void setPilot(string, string, string, int, int, int); //sets new pilot data
        //getters
        string getFirstName();
        string getLastName();
        string getID();//pilot ID
        int getExp();// experiance
        int getBasicPay(); //pilot Basic salary
        int getHourlyPay(); //pilot hourly pay

        void writeToFile(ofstream&);    //writes data to file ...
        void resetPilot();  //

    protected:
        // data members
        string firstName;
        string lastName;
        string ID;
        int experiance;
        int basicPay;
        int hourlyPay;
};

#endif // PILOT_H
