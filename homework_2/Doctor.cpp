#include <iterator>
#include <iostream>
#include "Doctor.h"
//general constructor
Doctor::Doctor() {

}

//not used
Doctor::Doctor(int size) {
	numPatients = size;
}

//not needed due to use of vector
Doctor::~Doctor() {
	
}

//prints the names of all of the names stored in the vector
void Doctor::printNames() {
	std::vector<std::string>::iterator it;
	for(it = patientList.begin(); it != patientList.end(); it++) {
		std::cout << "name: " << *it << std::endl;
	}
}

//add a patient in, used to unit test the vector
void Doctor::addPatient(std::string p){
	if(p == "")
		return; 
	patientList.push_back(p);
	numPatients++;
}

//deletes all patients and resets counter to zero
void Doctor::deletePatients() {
	patientList.clear();
	numPatients = 0;
}

//function operator overload of assignment
Doctor Doctor::operator=(const Doctor& d) {
	Doctor n;
	n.patientList = d.patientList;
	n.numPatients = d.numPatients;
	return n;
}

//used to take in user input
void Doctor::userInput() {
	bool inp = true;
	while(inp) {
		std::cout << "Enter patient name: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		std::cout << tmp << " tmp" << std::endl;
		bool cont = true;
		if(tmp == "")
			cont = false;
		while(cont == false) {
			std::cout << "empty string, try again: ";
			std::getline(std::cin, tmp);
			if(tmp != "")
				cont = true;
		}
		numPatients++;
		patientList.push_back(tmp);
		tmp = "";
		std::cout << std::endl;
		std::cout << "More Patients? (y/n): ";
		std::getline(std::cin, tmp);
		std::cout << tmp << std::endl;
		bool inp2 = true;
		if(tmp != "y" && tmp != "n")
			inp2 = false;
		while(!inp2) {
			tmp = "";
			std::cout << std::endl;
			std::cout << "not a valid input, more patients? (y/n): ";
			std::getline(std::cin, tmp);
			if(tmp != "y" && tmp != "n")
				inp2 = false;
			else inp2 = true;
		}
		if(tmp == "n")
			inp = false;
	}

}
