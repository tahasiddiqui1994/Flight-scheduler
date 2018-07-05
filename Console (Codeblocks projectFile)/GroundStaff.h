#ifndef GROUNDSTAFF_H
#define GROUNDSTAFF_H
#include <iostream>
#include <fstream>
#include <string>
#include "Staff.h"
using namespace std ;

class GroundStaff: public Staff{

	protected:

	public:
		GroundStaff() ;
		void WholeStaff() ;
		void addNewStaffMember() ;
		void removeStaffMember(int) ;

		void getInfo(int GID, string NAME,
		int MSALARY, string PNUMBER, string ADDRESS, string DESIGNATION) ;


		~GroundStaff() ;
};

#endif
