#ifndef DOCTOR_H
#define DOCTOR_H


#include <string>
#include <vector>

class Doctor {
	public:
		Doctor();
		Doctor(int size);
		~Doctor();
		void printNames();
		void deletePatients();
		std::string name;
		int numPatients;
		std::vector<std::string> patientList;
		virtual void userInput();
		void addPatient(std::string p);
		Doctor operator=(const Doctor& d);
	private:
		
		
};
#endif
