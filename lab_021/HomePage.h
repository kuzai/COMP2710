#ifndef HOME_H
#define HOME_H

#include "User.h"
#include <string>
#include <vector>
#include "FileHandler.h"

class HomePage
{
	private:
		std::string userBuffer;
		FileHandler fHandler;
	public:
		HomePage(FileHandler fHandle);
		void printHome(User user);
		void updateHome(User user, std::string buff, bool moreMessages);
		void userSort(User user);
};

#endif
