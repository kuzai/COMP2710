#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
	public:
		Menu();
		void print();
		void print(std::string name);
		void newLogin(std::string name);
};
#endif
