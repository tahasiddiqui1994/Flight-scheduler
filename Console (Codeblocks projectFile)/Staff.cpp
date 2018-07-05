#include <iostream>
#include "Staff.h"
#include "GroundStaff.h"
#include "onBoardStaff.h"
#include <string>
using namespace std ;

Staff::Staff()
{

}

Staff::~Staff()
{

}
int Staff::getNumber()
{
    return number ;
}
//getters
int Staff::getID(int i)   ///gets id at index i
{
	return ID[i] ;
}
string Staff::getName(int i)/// gets name at index i
{
	string name ;
	name = getFirstName(i) + " " + getLastName(i) ;

    return name ;
}
string Staff::getLastName(int i)/// gets last name at index i
{
	return lastName[i] ;
}
string Staff::getFirstName(int i)/// gets first name at index i
{
    return firstName[i] ;
}
int Staff::getmonthlySalary(int i)///gets monthly salary at index i
{
    return monthlySalary[i] ;
}
string Staff::getPhoneNumber(int i)/// gets phone number at index i
{
    return phoneNumber[i] ;
}
string Staff::getAddress(int i)///gets address at index i
{
    return address[i] ;
}
string Staff::getDesignation(int i)//gets desgnation at index i
{
	return designation[i] ;
}

///setters
void Staff::setID(int index, int value)/// replace value(which is ID) at index of ID "index"
{
	ID[index] = value ;
}
void Staff::setName(int index, string value)/// replace value(which is name) at index of name "index"
{
	string Name = "" ;
	int i = 0 ;

	while(value[i] != ' ')
	{
        Name += value[i] ;
		i++ ;
	}
    setFirstName(index, Name) ;
    i++ ;
    Name = "" ;
	while(value[i] != '\0')
	{
        Name += value[i] ;
		i++ ;
	}

    setLastName(index, Name) ;
}
void Staff::setFirstName(int index, string value)/// replace value(which is ID) at index of ID "index"
{
    firstName[index] = value ;
}
void Staff::setLastName(int index, string value)/// replace value(which is ID) at index of ID "index"
{
    lastName[index] = value ;
}
void Staff::setmonthlySalary(int index, int value)/// replace value(which is ID) at index of ID "index"
{
    monthlySalary[index] = value ;
}
void Staff::setPhoneNumber(int index, string value)/// replace value(which is ID) at index of ID "index"
{
    phoneNumber[index] = value ;
}
void Staff::setAddress(int index, string value)/// replace value(which is ID) at index of ID "index"
{
    address[index] = value ;
}
void Staff::setDesignation(int index, string value)/// replace value(which is ID) at index of ID "index"
{
    designation[index] = value ;
}
