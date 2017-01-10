#ifndef WALL_H
#define WALL_H
#include <string>
#include <vector>
#include "User.h"

class WallPage {
	private:

	public:
		WallPage();
		//void printWall(User user);
		void updateWall(User user, std::string buff, bool moreMessages);
};

#endif
