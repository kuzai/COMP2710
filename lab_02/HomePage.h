#ifndef HOME_H
#define HOME_H

#include "User.h"
#include <string>
#include <vector>

class HomePage
{
	private:
		std::string userBuffer;
	public:
		HomePage();
		void printHome(User user);
		void updateHome(User user, std::string buff, bool moreMessages);
};

#endif
