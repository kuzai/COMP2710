#include <iostream>
#include "SurgerySchedule.h"

SurgerySchedule::SurgerySchedule(std::string name, std::string date) {
	patientName = name;
	surgeryDate = date;
}

void SurgerySchedule::print() {
	std::cout << "Name: " << patientName << "\t" << "Date: " << surgeryDate << std::endl;
}

