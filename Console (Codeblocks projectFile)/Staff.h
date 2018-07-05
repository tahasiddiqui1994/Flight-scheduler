#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

class Staff{

	protected:
		ifstream FILE ;
		ofstream FILE1 ;
		int number ;
		int *ID ;
		string *firstName ;
		string *lastName ;
		int *monthlySalary ;
		string *phoneNumber ;
		string *address ;
		string *designation ;

	public:
		Staff() ;
		virtual void WholeStaff() = 0 ;
		virtual void addNewStaffMember() = 0 ;
		virtual void removeStaffMember(int) = 0 ;

		//getters
		int getNumber() ;
		int getID(int) ;//index
		string getFirstName(int) ;//index
		string getName(int) ;//index
		string getLastName(int) ;//index
		int getmonthlySalary(int) ;//index
		string getPhoneNumber(int) ;//index
		string getAddress(int) ;//index
		string getDesignation(int) ;//index
		//setters
		void setID(int, int) ;//index, id
		void setName(int, string) ;//index, name
		void setFirstName(int, string) ;//index, name
		void setLastName(int, string) ;//index, Lname
		void setmonthlySalary(int, int) ;//index, monthsalary
		void setPhoneNumber(int, string) ;//index, phNumber
		void setAddress(int, string) ;//index, Address
		void setDesignation(int, string) ;//index, Designtaion

		virtual ~Staff() ;

};


#endif // STAFF_H
