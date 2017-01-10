#include "Menu.h"
#include <iostream>

Menu::Menu(){}

void Menu::print(){
	std::cout << "Post (0), Wall page (1), Home page (2), Add friend (3)," << 			std::endl;
	std::cout << "Follow hashtag (4), Quit (5)" << std::endl;
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
