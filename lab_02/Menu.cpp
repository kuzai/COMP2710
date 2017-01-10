#include "Menu.h"
#include <iostream>

Menu::Menu(){}

void Menu::print(){
	std::cout << "Create new user(0), Post (1), Wall page (2), Home page (3), Add friend (4)," << 			std::endl;
	std::cout << "Follow hashtag (5), Change user (6), Quit (7)" << std::endl;
	std::cout << "Enter option: ";
}

void Menu::print(std::string name) {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "   Welcome Back to Aubiebook, " + name << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	print();
}

void Menu::newLogin(std::string name){
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "   Welcome to Aubiebook, " << name << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}
