#include <iostream>
#include <cstdlib>
#include "Pilot.h"
#include "GroundStaff.h"
#include "onBoardStaff.h"
#include "Passenger.h"
#include "Plane.h"
#include "Airport.h"
#include "Flight.h"
using namespace std ;

int main()
{
	system("COLOR 4F") ;
	Airport obj1;
    obj1.LOOP() ;

	/*GroundStaff obj2 ;
	obj2.WholeStaff() ;

	cout << endl << " Onboard " << endl << endl;

    onBoardStaff obj5;
    obj5.WholeStaff() ;*/

	return 0 ;
}

/*

Color Codes:

0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White

*/
