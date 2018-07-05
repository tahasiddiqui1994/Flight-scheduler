#ifndef PLANE_H
#define PLANE_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Plane
{
    public:
        Plane();    // default constructor
        Plane(string, int);     // parametrized constructor
        void setPlane(string, string, int); //setter
        void readFromFile(ifstream&); // reads data from file via istream
        void writeToFile(ofstream&);  // write data to file via ostream
        void printPlane();
        //getters
        string getModel();
        int getCapacity();
        string getID();
    private:
        string model;   //data member
        int capacity;   //data member
        string ID;      //data member
};

#endif // PLANE_H
