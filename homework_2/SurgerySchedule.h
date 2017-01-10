#ifndef SURGERY_H
#define SURGERY_H

#include <string>

class SurgerySchedule {
	public:
		SurgerySchedule(std::string name, std::string date);
		void print();
	private:
		std::string patientName;
		std::string surgeryDate;

};
#endif
