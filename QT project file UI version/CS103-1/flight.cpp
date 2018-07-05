#include "flight.h"

Flight::Flight()
{
}
void Flight::readFlight(ifstream& inFile){
    string EngineerID;
    int engFileSize;
    string temp;
    inFile>>ID;
    plane.readFromFile(inFile);
    pilot.readFromFile(inFile);
    inFile>>route;
    inFile>>EngineerID;
    ifstream engineerFile;
    engineerFile.open("flightEng.txt");
    engineerFile>>engFileSize;
    for(int i=0;i<engFileSize*5;i++){
        engineerFile>>temp;
        if(temp==EngineerID){
            string fn;
            string ln;
            int bp;
            string lis;
            engineerFile>>fn;
            engineerFile>>ln;
            engineerFile>>bp;
            engineerFile>>lis;
            engineer.setEngineer(temp,fn,ln,bp,lis);
        }
    }
    engineerFile.close();
}

void Flight::printFlight(){
    cout<<ID<<endl;
    plane.printPlane();
    pilot.printForFlight();
    cout<<route<<endl;

}
void Flight::setFlight(string inID,Plane inPlane, Pilot inPilot, string inRoute){
    ID=inID;
    plane=inPlane;
    pilot=inPilot;
    route=inRoute;
}
string Flight::getID(){
    return ID;
}

string Flight::getRoute(){
    return route;
}

int Flight::getCapacity(){
    return plane.getCapacity();
}

string Flight::getModel(){
   return plane.getModel();
}

string Flight::getPilotFirstName(){
    return pilot.getFirstName();
}

string Flight::getPilotLastName(){
    return pilot.getLastName();
}
string Flight::getPilotID(){
    return pilot.getID();
}
Pilot Flight::getPilot(){
    return pilot;
}
Plane Flight::getPlane(){
    return plane;
}
string Flight::getPlaneID(){
    return plane.getID();
}
void Flight::writeToFile(ofstream& outFile){
    outFile<<ID<<" ";
    plane.writeToFile(outFile);
    pilot.writeToFile(outFile);
    outFile<<route<<" ";
    outFile<<engineer.getID()<<endl;
}
void Flight::removePilot(){
    pilot.resetPilot();
}
void Flight::setPlane(string ID, string Model, int Capacity){
    plane.setPlane(ID,Model,Capacity);
}
FlightEngineer Flight::getEngineer(){
    return engineer;
}
string Flight::getEngineerID(){
    return engineer.getID();
}
void Flight::removeEngineer(){
    engineer.setEngineer("N/A","N/A","N/A",0,"N/A");
}
