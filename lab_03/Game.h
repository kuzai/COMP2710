#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Node.h"

class Game {
	
	public:
		Game();
		Game(std::string filename);
		void printOptions();

	private:
		Node* nodes;
		Node *currentNode;
		Node *startNode;
		Node *endNode;
		std::string file;
		std::vector<std::string> path;
		int numNodes;
		void movePlayer(Node *node);
		//void snakeLadderNode();
		void fileParse(std::string filename);
		bool checkNode(std::string name);
		Node* getNode(std::string name);
		void printPath();
};



#endif
