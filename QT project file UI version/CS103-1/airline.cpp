#include "airline.h"

Airline::Airline()
{
    Flight tempFlight;
    filePath="flightrec.txt";
    inFile.open(filePath.c_str());
    int values;
    inFile>>values;
    for(int i=0;i<values;i++){
        tempFlight.readFlight(inFile);
        flights.push_back(tempFlight);
    }
    for(unsigned int i=0;i<flights.size();i++){
        if(getPilotIndex(flights[i].getPilotID())==-1)
            if(flights[i].getPilotID()!="N/A"){
                pilots.push_back(flights[i].getPilot());
           }
    }
    for(unsigned int i=0;i<flights.size();i++){
        if(getAircraftIndex(flights[i].getPlaneID())==-1){
            if(flights[i].getPlaneID()!="N/A"){
                aircrafts.push_back(flights[i].getPlane());
            }
        }
    }
    for(unsigned int i=0;i<flights.size();i++){
        if(getEngineerIndex(flights[i].getEngineerID())==-1){
            if(flights[i].getEngineerID()!="N/A"){
                engineers.push_back(flights[i].getEngineer());
            }
        }
    }
    inFile.close();
}
int Airline::getPilotIndex(string id){
    for(unsigned int i=0;i<pilots.size();i++){
        if(id==pilots[i].getID()){
            return i;
        }
    }
    return -1;
}

void Airline::printFlight(int index){
    flights[index].printFlight();
}

void Airline::addFlight(string inID,Plane inPlane, Pilot inPilot, string inRoute){
    Flight tempFlight;
    tempFlight.setFlight(inID,inPlane,inPilot,inRoute);
    flights.push_back(tempFlight);
}

void Airline::getFlightValues(int index, string& inID, string& inModel, int& inCapacity, string& pilotID, string& pilotFirstName, string& pilotLastName, string& inRoute, string& EngineerID){
    inID=flights[index].getID();
    inRoute=flights[index].getRoute();
    inCapacity=flights[index].getCapacity();
    inModel=flights[index].getModel();
    pilotFirstName=flights[index].getPilotFirstName();
    pilotLastName=flights[index].getPilotLastName();
    pilotID=flights[index].getPilotID();
    EngineerID=flights[index].getEngineerID();
}
int Airline::getTotalFlights(){
    return flights.size();
}
int Airline::getTotalPilots(){
    return pilots.size();
}
void Airline::getPilotValues(int index, string& FirstName,string& LastName, string& id, int& Exp, int& BasicPay, int& HourlyPay){
    FirstName=pilots[index].getFirstName();
    LastName=pilots[index].getLastName();
    id=pilots[index].getID();
    Exp=pilots[index].getExp();
    BasicPay=pilots[index].getBasicPay();
    HourlyPay=pilots[index].getHourlyPay();
}
void Airline::getPlaneValues(int index, string& ID, string& Model, int& Capacity){
    ID=aircrafts[index].getID();
    Model=aircrafts[index].getModel();
    Capacity=aircrafts[index].getCapacity();
}
int Airline::getAircraftIndex(string id){
    for(unsigned int i=0;i<aircrafts.size();i++){
        if(id==aircrafts[i].getID()){
            return i;
        }
    }
    return -1;
}
int Airline::getTotalPlanes(){
    return aircrafts.size();
}
void Airline::writeToFile(){
    outFile.open(filePath.c_str(),ios::trunc);
    outFile<<getTotalFlights()<<endl;
    for(int i=0;i<getTotalFlights();i++){
        flights[i].writeToFile(outFile);
    }
    outFile.close();
}
void Airline::addPilot(Pilot inPilot){
    pilots.push_back(inPilot);
}
Pilot Airline::getPilot(int index){
    return pilots[index];
}
void Airline::addPlane(Plane inPlane){
    aircrafts.push_back(inPlane);
}
Plane Airline::getPlane(int index){
    return aircrafts[index];
}
void Airline::addFlight(Flight inFlight){
    flights.push_back(inFlight);
}
Flight Airline::getFlight(int index){
    return flights[index];
}

void Airline::removePilot(string pilotID){
    unsigned int index=getPilotIndex(pilotID);
    vector<Pilot> temp;
    for(unsigned int i=0;i<pilots.size();i++){
        if(i!=index){
            temp.push_back(pilots[i]);
        }
    }
    pilots=temp;
    for(unsigned int i=0;i<flights.size();i++){
        if(flights[i].getPilotID()==pilotID){
            flights[i].removePilot();
        }
    }
}

int Airline::getFlightIndex(string inID){
    for(unsigned int i=0;i<flights.size();i++){
        if(flights[i].getID()==inID){
            return i;
        }
    }
    return -1;
}

void Airline::removePlane(string inID){
    vector<Plane> temp;
    for(unsigned int i=0;i<aircrafts.size();i++){
        if(aircrafts[i].getID()!=inID){
               temp.push_back(aircrafts[i]);
        }
    }
    aircrafts=temp;
    for(unsigned int i=0;i<flights.size();i++){
        if(flights[i].getPlaneID()==inID){
            flights[i].setPlane("N/A","N/A",0);
        }
    }
}

void Airline::removeFlight(string inID){
    vector<Flight> temp;
    for(unsigned int i=0;i<flights.size();i++){
        if(flights[i].getID()!=inID){
            temp.push_back(flights[i]);
        }
    }
    flights=temp;
}

int Airline::getEngineerIndex(string inID){
    for(unsigned int i=0;i<engineers.size();i++){
        if(engineers[i].getID()==inID){
            return i;
        }
    }
    return -1;
}
int Airline::getTotalEngineers(){
    return engineers.size();
}

void Airline::getEngineerValues(int index,string& inID,string& inFirstName,string& inLastName,int& inPay,string& inLisence){
    engineers[index].getInfo(inID,inFirstName,inLastName,inPay,inLisence);
}
void Airline::addEngineer(FlightEngineer inEngineer){
    engineers.push_back(inEngineer);
}
void Airline::removeEngineer(string inID){
    vector<FlightEngineer> temp;
    for(unsigned int i=0;i<engineers.size();i++){
        if(engineers[i].getID()!=inID){
            temp.push_back(engineers[i]);
        }
    }
    engineers=temp;
    for(unsigned int i=0;i<flights.size();i++){
        if(flights[i].getEngineerID()==inID){
            flights[i].removeEngineer();
        }
    }
}
