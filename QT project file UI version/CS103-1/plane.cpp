#include "plane.h"

Plane::Plane(){} // default constructor
Plane::Plane(string m, int c)   // parametrized constructor
{
    model = m ;
    capacity = c ;
}
void Plane::setPlane(string i,string m, int c){     //sets plane model capacity and DI
    model = m ;
    capacity = c ;
    ID = i ;
}
void Plane::readFromFile(ifstream& inFile)
{
    inFile >> ID;
    inFile >> model;
    inFile >> capacity;
}
void Plane::printPlane()
{
    cout << model << endl ;
    cout << capacity << endl ;
}

string Plane::getModel(){
    return model;
}
int Plane::getCapacity(){
    return capacity;
}
string Plane::getID(){
    return ID;
}
void Plane::writeToFile(ofstream& outFile){
    outFile<<ID<<" ";
    outFile<<model<<" ";
    outFile<<capacity<<" ";
}
