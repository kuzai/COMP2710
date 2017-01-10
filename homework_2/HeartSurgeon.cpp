
#include <iterator>
#include <iostream>
#include "HeartSurgeon.h"

//sets numpatients to zero 
HeartSurgeon::HeartSurgeon() {
	numSurgeriesScheduled = 0;
	numPatients = 0;
}

//not needed due to use of vector
HeartSurgeon::~HeartSurgeon() {

}


//prints out the entire surgery schedule, name and date, for the surgeon
void HeartSurgeon::printSchedule() {
	std::vector<SurgerySchedule>::iterator it;
	for(it = schedule.begin(); it != schedule.end(); it++) {
		(*it).print();
	}
}

//adds a surgery, used to unit test the SurgerySchedule object along with the vector
void HeartSurgeon::addSurgery(std::string name, std::string date) {
	if(name == "" || date == "")
		return;
	SurgerySchedule s(name, date);
	numSurgeriesScheduled++;
	numPatients++;
	schedule.push_back(s);
}

//not needed
void HeartSurgeon::removeSurgery() {

}

//clears the vector and resets the schedule and numPatients
void HeartSurgeon::deleteSurgeries() {
	schedule.clear();
	numSurgeriesScheduled = 0;
	numPatients = 0;
}

//operator overload
HeartSurgeon HeartSurgeon::operator=(const HeartSurgeon& h) {
	HeartSurgeon n;
	n.patientList = h.patientList;
	n.schedule = h.schedule;
	n.numPatients = h.numPatients;
	n.numSurgeriesScheduled = h.numSurgeriesScheduled;
	return n;
}

//used to take in user input
void HeartSurgeon::userInput() {
	bool inp = true;
	while(inp) {
		std::cout << "Enter patient name: ";
		std::string tmp;
		std::string tmpDate;
		std::getline(std::cin, tmp);
		std::cout << std::endl;
		bool cont = true;
		if(tmp == "")
			cont = false;
		while(cont == false) {
			std::cout << "empty string, try again: ";
			std::getline(std::cin, tmp);
			if(tmp != "")
				cont = true;
		}
		std::cout << "Enter Surgery Date: ";
		std::getline(std::cin, tmpDate);
		numPatients++;
		patientList.push_back(tmp);
		SurgerySchedule s(tmp, tmpDate);
		schedule.push_back(s);
		tmp = "";
		std::cout << std::endl;
		std::cout << "More Patients? (y/n): ";
		std::getline(std::cin, tmp);
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
