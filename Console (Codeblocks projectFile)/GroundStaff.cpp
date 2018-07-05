#include <iostream>
#include <string>
using namespace std ;
#include <fstream>
#include "GroundStaff.h"
///Default constructor for Groundstaff which reads file and generates dynamic arrays
GroundStaff::GroundStaff()
{
	FILE.open("GroundStaff.txt") ;
	FILE >> number ;

	ID = new int[number] ;              ///Dynamic array for ID
	firstName = new string[number] ;    ///Dynamic array for firstname
	lastName = new string[number] ;     ///Dynamic array for lastname
	monthlySalary = new int[number] ;   ///Dynamic array for monthly salary
	phoneNumber = new string[number] ;  ///Dynamic array for phone number
	address = new string[number] ;      ///Dynamic array for address
	designation = new string[number] ;  ///Dynamic array for designation

	for(int i = 0 ; i < number ; i++) /// read data from file "GroundStaff.txt"
	{
		FILE >> ID[i] >> firstName[i] >> lastName[i] >> monthlySalary[i]
		>> phoneNumber[i] >> address[i] >> designation[i] ;
	}

}
GroundStaff::~GroundStaff()
{
	///cout << " Inside ~GroundStaff() .." << endl;
	number = 0 ;
	delete[] ID ;           ///deallocating ID
	delete[] firstName ;    ///deallocating firstname
	delete[] lastName ;     ///deallocating lastname
	delete[] monthlySalary ;///deallocating monthly salary
	delete[] phoneNumber ;  ///deallocating phone number
	delete[] address ;      ///deallocating address
	delete[] designation ;  ///deallocating designation

	FILE.close() ;
	FILE1.close() ;
}
///print function to prind data of all ground staff member
void GroundStaff::WholeStaff()
{
	cout << " Ground Staff .." << endl << endl;
	for(int i = 0 ; i < number ; i++)
	{
		cout << " ID: " << ID[i] << endl ;
		cout << " First Name: " << firstName[i];
		cout << " " << lastName[i] << endl ;
		cout << " Monthly Salary: " << monthlySalary[i] << endl ;
		cout << " Phone Number: " << phoneNumber[i] << endl ;
		cout << " Address: " << address[i] << endl ;
		cout << " Designation: " << designation[i] << endl << endl ;
	}
}

void GroundStaff::addNewStaffMember()
{
    int id = 0, salary = 0  ;
    string fname = "", lname = "", address1 = "", designation1 = "", cellNo = "" ;

    cout << " Enter ID: " ;
    LOOP:
    cin >> id ;
    for(int i = 0 ; i < number ; i++)
    {
        if(id == ID[i])
        {
            cout << " ID is already allotted to a staff member .. " << endl;
            cout << " enter again ... " ;
            goto LOOP;
        }
    }
    cout << " Enter First Name: " ;
    cin >> fname ;
    cout << " Enter Last Name: " ;
    cin >> lname ;
    cout << " Enter Address: " ;
    cin >> address1 ;
    cout << " Enter designation: " ;
    cin >> designation1 ;
    cout << " Enter salary: " ;
    cin >> salary ;
    cout << " Enter Cell No: " ;
    cin >> cellNo ;


    int *tempID ;
    string *tempfirstName ;
    string *templastName ;
    int *tempmonthlySalary ;
    string *tempphoneNumber ;
    string *tempaddress ;
    string *tempdesignation ;

	tempID = new int[number] ;              ///Dynamic array for ID
	tempfirstName = new string[number] ;    ///Dynamic array for firstname
	templastName = new string[number] ;     ///Dynamic array for lastname
	tempmonthlySalary = new int[number] ;   ///Dynamic array for monthly salary
	tempphoneNumber = new string[number] ;  ///Dynamic array for phone number
	tempaddress = new string[number] ;      ///Dynamic array for address
	tempdesignation = new string[number] ;  ///Dynamic array for designation

    for(int i = 0 ; i < number ; i++)
    {
        tempID[i] = ID[i] ;
        tempfirstName[i] = firstName[i] ;
        templastName[i] = lastName[i] ;
        tempmonthlySalary[i] = monthlySalary[i] ;
        tempphoneNumber[i] = phoneNumber[i] ;
        tempaddress[i] = address[i] ;
        tempdesignation[i] = designation[i] ;
    }

	delete[] ID ;           ///deallocating ID
	delete[] firstName ;    ///deallocating firstname
	delete[] lastName ;     ///deallocating lastname
	delete[] monthlySalary ;///deallocating monthly salary
	delete[] phoneNumber ;  ///deallocating phone number
	delete[] address ;      ///deallocating address
	delete[] designation ;  ///deallocating designation
    number++ ;
	ID = new int[number] ;              ///Dynamic array for ID
	firstName = new string[number] ;    ///Dynamic array for firstname
	lastName = new string[number] ;     ///Dynamic array for lastname
	monthlySalary = new int[number] ;   ///Dynamic array for monthly salary
	phoneNumber = new string[number] ;  ///Dynamic array for phone number
	address = new string[number] ;      ///Dynamic array for address
	designation = new string[number] ;  ///Dynamic array for designation
    for(int i = 0 ; i < number-1 ; i++)
    {
        ID[i] = tempID[i];
        firstName[i] = tempfirstName[i] ;
        lastName[i] = templastName[i] ;
        monthlySalary[i] = tempmonthlySalary[i] ;
        phoneNumber[i]= tempphoneNumber[i] ;
        address[i] = tempaddress[i] ;
        designation[i] = tempdesignation[i] ;
    }
        ID[number-1] = id;
        firstName[number-1] = fname ;
        lastName[number-1] = lname ;
        monthlySalary[number-1] = salary ;
        phoneNumber[number-1]= cellNo ;
        address[number-1] = address1 ;
        designation[number-1] = designation1 ;
}

void GroundStaff::removeStaffMember(int arg)
{
    int index = 0 ;
    for(int i = 0 ; i < number ; i++)
    {
        if(arg == ID[i])
        {
            index = i ;
            break;
        }
    }
    for(int i = index ; i < number-1 ; i++)
    {
        ID[i] = ID[i+1] ;
        firstName[i] = firstName[i+1] ;
        lastName[i] = lastName[i+1] ;
        monthlySalary[i] = monthlySalary[i+1] ;
        phoneNumber[i] = phoneNumber[i+1] ;
        address[i] = address[i+1] ;
        designation[i] = designation[i+1] ;
    }
    number -- ;
}
void GroundStaff::getInfo(int GID, string NAME,
int MSALARY, string PNUMBER, string ADDRESS, string DESIGNATION)
{
	int index = 0 ;
    for(int i = 0 ; i < number ; i++)
    {
        if(GID == ID[i])
        {
            index = i ;
            break ;
        }
    }

    NAME = getName(index) ;
    MSALARY = getmonthlySalary(index) ;
    PNUMBER = getPhoneNumber(index) ;
    ADDRESS = getAddress(index) ;
    DESIGNATION = getDesignation(index) ;
}
