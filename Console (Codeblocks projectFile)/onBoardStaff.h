#ifndef ONBOARDSTAFF_H
#define ONBOARDSTAFF_H
#include <iostream>
#include <fstream>
#include <string>
#include "Staff.h"
using namespace std ;

class onBoardStaff: public Staff
{

	protected:
		int *salaryInHours ;
	public:
		onBoardStaff() ;
		void WholeStaff() ;
		void addNewStaffMember() ;
		void removeStaffMember(int) ;

		void getInfo(int GID, string NAME, int MSALARY, int HSALARY,
		string PNUMBER, string ADDRESS, string DESIGNATION) ;

		//getters
		int getsalaryInHours(int) ;//index
		//setters
		void setsalaryInHours(int, int) ;//index,perhrSalary


		~onBoardStaff() ;
};

#endif
