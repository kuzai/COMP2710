#ifndef HEART_H
#define HEART_H

#include <string>
#include <iostream>
#include "Doctor.h"
#include "SurgerySchedule.h"
#include <vector>

class HeartSurgeon : public Doctor {
	public:
		HeartSurgeon();
		~HeartSurgeon();
		void printSchedule();
		//void printPatients();
		void addSurgery(std::string name, std::string date);
		void removeSurgery();
		void deleteSurgeries();
		void userInput();
		HeartSurgeon operator=(const HeartSurgeon& h);
		
	private:
		int numSurgeriesScheduled;
		std::vector<SurgerySchedule> schedule;
		

};
#endif
