
/*
//	The Following is the main cpp file for the program
//	Author: Walker Wood
//	UserId: whw0011
//	compile: g++ *.cpp -o <preffered name>
//	
//	THE USE CASES FOR THIS HOMEWORK WERE NOT WELL DEFINED
//	INSTEAD OF ATTEMPTING TO FIGURE OUT WHAT WAS MEANT
//	I ONLY IMPLEMENTED WHAT WAS DIRECTLY ASKED FOR
//	ALL REQUIRED FUNCTIONS ARE PRESENT HOWEVER THERE IS NO
//	GUARAUNTEE THAT THEY DO WHAT WAS INTENDED AS THE INTENDED
//	PURPOSE FOR EACH FUNCTION AND HOW THE USER SHOULD INTERACT
//	WITH THE PROGRAM WAS NEVER ACTUALLY SPECIFIED AT ALL SO
//	EVEN THE TEST CASES ARE REALLY JUST A BARE MINIMUM TO SHOW
//	THAT THIS SORT OF THING IS POSSIBLE.
*/

#include "Doctor.h"
#include "HeartSurgeon.h"
#define UNIT_TESTING
int main() {
	#ifdef UNIT_TESTING
	Doctor d;
	HeartSurgeon h;
	std::string s = "";
	std::string m = "asdfasdfasdfasdf";
	std::string l = "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf";
	std::string date = "1/1/1!1!1";
	std::cout << "d print names: " << std::endl;
	d.printNames();
	std::cout << " d num names: " << d.numPatients << std::endl;
	d.addPatient(s);
	d.addPatient(m);
	d.addPatient(l);
	d.printNames();
	Doctor a = d;
	d.deletePatients();
	d.printNames();
	std::cout << d.numPatients << std::endl;
	std::cout << a.numPatients << std::endl;
	
	std::cout << "h print names: " << std::endl;
	h.printNames();
	std::cout << " h num names: " << h.numPatients << std::endl;
	h.addSurgery(s, date);
	h.addSurgery(m, date);
	h.addSurgery(l, date);
	h.printNames();
	h.printSchedule();
	HeartSurgeon b = h;
	h.deleteSurgeries();
	h.printSchedule();
	std::cout << h.numPatients << std::endl;
	std::cout << b.numPatients << std::endl;
	#else
	while(1) {
		Doctor d;
		HeartSurgeon h;
		d.userInput();
		h.userInput();
		std::cout << "Quit? (y/n): ";
		std::string tmp;
		std::getline(std::cin, tmp);
		if(tmp == "y")
			break;
	}
	#endif
}
