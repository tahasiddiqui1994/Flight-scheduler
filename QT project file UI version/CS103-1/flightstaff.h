#ifndef FLIGHTSTAFF_H
#define FLIGHTSTAFF_H
#include<string>
#include<fstream>
using namespace std;

class FlightStaff
{
public:
    FlightStaff();  // default constructor
    //getters
    string getID();
    string getFirstName();
    string getLastName();
    int getBasicPay();
    void setID(string);
    void getInfo(string&,string&, string&);
    virtual void readFromFile(ifstream&){};//read data from file
protected:
    //data members
    string ID;
    string firstName;
    string lastName;
    int basicPay;

};

#endif // FLIGHTSTAFF_H
