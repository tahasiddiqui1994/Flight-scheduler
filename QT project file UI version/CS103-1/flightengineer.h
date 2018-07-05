#ifndef FLIGHTENGINEER_H
#define FLIGHTENGINEER_H
#include "flightstaff.h"
#include <fstream>
#include <string>
using namespace std;

class FlightEngineer:public FlightStaff {
public:
    FlightEngineer();   //default constructor
    void setEngineer(string, string, string,int,string); //sets new engineer data
    void readFromFile(ifstream&);// read data of engineer from file
    void readNextFromFile(ifstream&);//temp
    void getInfo(string&, string&, string&, int&, string&);// to modify the data
    string getLisence();    //catagory of licence A or B
protected:
    string lisence; // data member
};

#endif // FLIGHTENGINEER_H
