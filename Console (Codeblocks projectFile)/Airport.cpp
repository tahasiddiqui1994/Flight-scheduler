#include <iostream>
#include <fstream>
using namespace std ;
#include <string>
#include "Airport.h"
#include "Pilot.h"
#include "Plane.h"
void Airport::LOOP()
{
    if(endOrNot != true)
    {
		int temp = 0 ;
		while(true)
		{
			char choice = '\0' ;
			cout << endl << "\t\b AIRLINE MANAGEMENT SYSTEM" << endl;

			cout << endl << "   - Add Flight (press 'A')" << endl <<
					"   - Search Flight (press 'F')" << endl <<
					"   - Print All Flight (press 'P')" << endl <<
					"   - Cancel Flight (press 'c')" << endl <<
					"   - Search GroundStaff member (press 'G')" << endl <<
					"   - Search OnBoardStaff member (press 'O')" << endl <<
					"   - add GroundStaff member (press 'S')" << endl <<
					"   - add OnBoardStaff member (press 'N')" << endl <<
					"   - remove GroundStaff member (press 'R')" << endl <<
					"   - remove OnBoardStaff member (press 'D')" << endl <<
					"   - Exit (press 'X')" << endl ;

		LOOP:
			cout << endl << "   - Enter your choice: " ;
			cin >> choice ;
            int id = 0 ;
            int temp1 = 1 ;
			switch(choice)
			{
				case 'A':
				case 'a':
					addFlight() ;
					break;
				case 'f':
				case 'F':
					searchFlight() ;
					break;
				case 'p':
				case 'P':
					printAllFlight() ;
					break;
				case 'c':
				case 'C':
                    cancelFlight() ;
					break;
				case 'X':
				case 'x':
				    temp = 1 ;
					exit() ;
					break;
                case 'g':
                case 'G':
                    searchGroundStaff() ;
                    break;
                case 'O':
                case 'o':
                    searchOnboardStaff() ;
                    break;
                case 's':
                case 'S':
                    groundstaff.addNewStaffMember() ;
                    break;
                case 'r':
                case 'R':
                    cout << " Enter ID: " ;
                    cin >> id ;
                    for(int i = 0 ; i < groundstaff.getNumber() ; i++)
                    {
                        if(id == groundstaff.getID(i))
                        {
                            groundstaff.removeStaffMember(id) ;
                            temp1 = 0 ;
                            cout << " Deleted" << endl << endl;
                            break;
                        }
                    }
                    if(temp1 == 1)
                    {
                        cout << " Invalid ID .." << endl << endl ;
                    }
                    break;
                case 'n':
                case 'N':
                    onboardstaff.addNewStaffMember() ;
                    break ;
                case 'd':
                case 'D':

                    cout << " Enter ID: " ;
                    cin >> id ;
                    for(int i = 0 ; i < onboardstaff.getNumber() ; i++)
                    {
                        if(id == onboardstaff.getID(i))
                        {
                            onboardstaff.removeStaffMember(id) ;
                            cout << " Deleted" << endl << endl;
                            break;
                        }
                    }
                    break ;
				default:
					cout << "   - Invalid command, try again" << endl;
					goto LOOP ;
				}
			if(temp == 1)
				break;
		}
    }
}
istream& operator >> (istream& READ, Plane& object) /// overloaded extraction operator
{
	string x = "" ;
	int y = 0 ;

	//cout << " Inside operator >> (istream& in, Circle& rhs)" << endl ;
    READ >> x >> y ;
	object.setAircraftModel(x) ;
	object.setTotalSeats(y) ;

	return READ;
}
ostream& operator << (ostream& WRITE, Plane& object) /// overloaded insertion operator
{
    WRITE << object.getAircraftModel() <<  " " ;
    WRITE << object.getTotalSeats() << endl ;

	return WRITE;
}
void Airport::addFlight()
{
	int flightID1 = 0 ;
	int pilotID1 = 0 ;
	string pilotName1 = "" ;
	string aircraftModel1 = "" ;
	int totalSeats1 = 0 ;
	string route1 = "" ;

    cout << " Enter Flight ID: " ;
    FID:
        cin >> flightID1 ;
		for(int i = 0 ; i < flight.getNumber() ; i++)
		{
            if(flightID1 == flight.getFlightID(i))
			{
				cout << " Flight is already exist .." << endl ;
				cout << " Please Enter again: " ;
				goto FID;
			}
		}

    cout << " Enter Pilot ID: " ;
	cin >> pilotID1 ;
    cout << " Enter Pilot Name: " ;
    cin >> pilotName1 ;
    cout << " Enter Plane Model: " ;
    cin >> aircraftModel1 ;
    cout << " Enter Plane's Total Seats: " ;
    cin >> totalSeats1 ;
    cout << " Enter Route of Flight: " ;
    cin >> route1 ;

    flight.setFlight(flightID1, pilotID1, pilotName1,
	aircraftModel1, totalSeats1, route1) ;
}
int Airport::searchFlight()
{
	int flightID1 = 0, index = -1 ;

    cout << " Enter Flight ID: " ;
    cin >> flightID1 ;
	for(int i = 0 ; i < flight.getNumber() ; i++)
	{
		if(flightID1 == flight.getFlightID(i))
		{
            index = i ;
            break;
		}
	}

	return index ;
}
void Airport::printAllFlight()
{
	for(int i = 0 ; i < flight.getNumber() ; i++)
	{
		cout << " Flight ID: " << flight.getFlightID(i) << endl ;
		cout << " Pilot ID: " << flight.getPilotID(i) << endl ;
		cout << " Pilot Name: " << flight.getPilotName(i) << endl ;
        cout << " Plane's Model: " << flight.getAircraftModel(i) << endl ;
        cout << " Plane's Total seat: " << flight.getTotalSeats(i) << endl;
        cout << " Route: " << flight.getFlightRoute(i) << endl << endl ;
	}
}
void Airport::cancelFlight()
{
	int flightID1 = 0, index = -1 ;

	cout << " Enter Flight ID: " ;
	cin >> flightID1 ;
	for(int i = 0 ; i < flight.getNumber() ; i++)
	{
		if(flightID1 == flight.getFlightID(i))
		{
            index = i ;
            break;
		}
	}

	if(index == -1)
	{
        cout << " ID does not exists ... " << endl;
	}
	else
	{
		flight.cancel(index) ;
		cout << " Flight Cancelled .." << endl;
	}
}
void Airport::exit()
{
    ofstream FILE ;
    ofstream FILE1 ;
    ofstream FILE2 ;
    ofstream FILE3 ;
    FILE.open("GroundStaff.txt") ;
    FILE << groundstaff.getNumber() << endl ;

    for(int i = 0 ; i < groundstaff.getNumber() ; i++)
    {
        FILE << groundstaff.getID(i) << " " << groundstaff.getFirstName(i) << " " << groundstaff.getLastName(i) << " " << groundstaff.getmonthlySalary(i) << " "
		<< groundstaff.getPhoneNumber(i) << " " << groundstaff.getAddress(i) << " " << groundstaff.getDesignation(i) << endl ;
    }
    FILE.close() ;

    FILE1.open("onBoardStaff.txt") ;
    FILE1 << onboardstaff.getNumber() << endl ;
    for(int i = 0 ; i < onboardstaff.getNumber() ; i++)
    {
        FILE1 << onboardstaff.getID(i) << " " << onboardstaff.getFirstName(i) << " " << onboardstaff.getLastName(i) << " " << onboardstaff.getsalaryInHours(i)
        << " " << onboardstaff.getmonthlySalary(i) << " " << onboardstaff.getPhoneNumber(i) << " " << onboardstaff.getAddress(i) << " " << onboardstaff.getDesignation(i) << endl ;
    }

    FILE2.open("Flight.txt") ;
    FILE2 << flight.getNumber() << endl ;
    for(int i = 0 ; i < flight.getNumber() ; i++)
    {
        FILE2 << flight.getFlightID(i) << " " << flight.getPilotID(i) << " " << flight.getPilotName(i) << " " << flight.getAircraftModel(i)
        << " " << flight.getTotalSeats(i) << " " << flight.getFlightRoute(i) << endl ;
    }

    FILE3.open("Airport.txt") ;
    FILE3 << airportName << endl ;
    FILE3 << numberOfRunways << endl ;
    for(int i = 0 ; i < numberOfRunways ; i++)
	{
        FILE3 << lengthOfRunwaysInKilometers[i] << endl ;
	}
    FILE3 << aircrafts << endl ;
    for(int i = 0 ; i < aircrafts ; i++)
	{
        FILE3 << plane[i] ; /// read data through extraction ostream operator overloaded on above
	}
	FILE3 << currentlyStationedAircrafts << endl ;

    FILE.close() ;
    FILE1.close() ;
    FILE2.close() ;
    FILE3.close() ;
    endOrNot = true ;
}
void Airport::searchGroundStaff()
{
    int ID = 0 ;
    int index = -1 ;
    cout << " Enter staff member ID: " ;
    cin >> ID ;

    for(int i = 0 ; i < groundstaff.getNumber() ; i++)
    {
        if(ID == groundstaff.getID(i))
        {
            index = i ;
            break;
        }
    }
    if(index == -1)
    {
        cout << " ID is not valid ..." ;
    }
    else
    {
        cout << endl ;
        cout << " Name: " << groundstaff.getName(index) << endl;
        cout << " Salary: " << groundstaff.getmonthlySalary(index) << endl;
        cout << " Phone Number: " << groundstaff.getPhoneNumber(index) << endl;
        cout << " Address: " << groundstaff.getAddress(index) << endl;
        cout << " Designation: " << groundstaff.getDesignation(index) << endl;
        cout << endl;
    }
}
void Airport::searchOnboardStaff()
{
    int ID = 0 ;
    int index = -1 ;
    cout << " Enter staff member ID: " ;
    cin >> ID ;

    for(int i = 0 ; i < onboardstaff.getNumber() ; i++)
    {
        if(ID == onboardstaff.getID(i))
        {
            index = i ;
            break;
        }
    }
    if(index == -1)
    {
        cout << " ID is not valid ..." ;
    }
    else
    {
        cout << endl ;
        cout << " Name: " << onboardstaff.getName(index) << endl;
        cout << " Salary: " << onboardstaff.getmonthlySalary(index) << endl;
        cout << " Phone Number: " << onboardstaff.getPhoneNumber(index) << endl;
        cout << " Address: " << onboardstaff.getAddress(index) << endl;
        cout << " Designation: " << onboardstaff.getDesignation(index) << endl;
        cout << endl;
    }
}
///Default constructor,this constructor will read the file and saves the data in dynamic arrays
Airport::Airport()
{
	READ.open("Airport.txt") ;

    getline(READ, airportName) ;///takes input for airport name from file
    READ >> numberOfRunways ; //gets number of runways
	lengthOfRunwaysInKilometers = new double[numberOfRunways] ;///dynamic allocation for runway length
    for(int i = 0 ; i < numberOfRunways ; i++)///loop to get all runway lengths
	{
		READ >> lengthOfRunwaysInKilometers[i] ;
	}
    READ >> aircrafts ;
    plane = new Plane[aircrafts] ;///dynamic allocation for planes
    for(int i = 0 ; i < aircrafts ; i++)
	{
        READ >> plane[i] ; /// read data through extraction ostream operator overloaded on above
	}
    READ >> currentlyStationedAircrafts ; /// read stationed aircrafts from file "Airport.txt"

}
void Airport::addNewAirCraft()
{
	string model = "" ;
	int capacity = 0 ;
    Plane *tempPlane ;

	cout << " Enter Model Of Aircraft: " ;
	cin >> model ;
	cout << " Enter Capacity: " ;
	cin >> capacity ;

    tempPlane = new Plane[aircrafts] ;
    for(int i = 0 ; i < aircrafts ; i++)
	{
        tempPlane[i].setAircraftModel(plane[i].getAircraftModel()) ;
        tempPlane[i].setTotalSeats(plane[i].getTotalSeats()) ;
	}

	delete[] plane ;
	aircrafts++ ;
    plane = new Plane[aircrafts] ;///dynamic allocation for planes

    for(int i = 0 ; i < aircrafts-1 ; i++)
	{
		plane[i].setAircraftModel(tempPlane[i].getAircraftModel()) ;
		plane[i].setTotalSeats(tempPlane[i].getTotalSeats()) ;
	}
    plane[aircrafts-1].setAircraftModel(model) ;
    plane[aircrafts-1].setTotalSeats(capacity) ;

    delete[] tempPlane ;
}
void Airport::addNewRunway()
{
    double *tempLengthOfRunwaysInKilometers ;
	double length = 0.0 ;

	cout << " Enter Length of a Runway: " ;
	cin >> length ;

    tempLengthOfRunwaysInKilometers = new double[numberOfRunways] ;
    for(int i = 0 ; i < numberOfRunways ; i++)
	{
        tempLengthOfRunwaysInKilometers[i] = lengthOfRunwaysInKilometers[i] ;
	}

    delete[] lengthOfRunwaysInKilometers ;
    numberOfRunways++ ;

	lengthOfRunwaysInKilometers = new double[numberOfRunways] ;
	for(int i = 0 ; i < numberOfRunways-1 ; i++)
	{
        lengthOfRunwaysInKilometers[i] = tempLengthOfRunwaysInKilometers[i] ;
	}
	lengthOfRunwaysInKilometers[numberOfRunways-1] = length ;

    delete[] tempLengthOfRunwaysInKilometers ;
}
void Airport::printAllData()        ///prints all data of airport
{
	cout << endl << " Airport Name: " << airportName << endl ;
    cout << endl << " Total Runways: " << numberOfRunways << endl ;
    for(int i = 0 ; i < numberOfRunways ; i++)
	{
        cout << " Runway " << i+1 << ": " << lengthOfRunwaysInKilometers[i] << " km" << endl ;
	}
	cout << endl << " Total Aircrafts: " << endl << endl ;
	for(int i = 0 ; i < aircrafts ; i++)
	{
		cout << plane[i] ;
	}
	cout << " Stationed Aircraft: " << currentlyStationedAircrafts << endl << endl ;

}

Airport::~Airport()///destructor for dynamically allocated memory
{
	delete[] lengthOfRunwaysInKilometers ;      ///deallocate lengths of runways
	delete[] plane ;                            ///deallocate plane
}
