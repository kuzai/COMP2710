#include <sstream>
#include <iterator>
#include "Game.h"
Game::Game() {

}

Game::Game(std::string filename) {
	file = filename;
}

void Game::fileParse(std::string filename) {
	std::ifstream istream;
	std::cout << filename << " filename!" << std::endl;
	istream.open(filename);
	if(istream.is_open()) {
		std::string line;
		int i = 0;
		int arrayLoc = 0;
		while(std::getline(istream, line)) {
			//std::cout << i << " i value!" << std::endl;
			if(i == 0) {
				//std::cout << line << "stoi" << std::endl;
				numNodes = std::stoi(line);
				nodes = new Node[numNodes];
			}
			else if(i == 1) {
				if(!checkNode(line)) {
					//Node newNode = Node(line);
					nodes[0] = Node(line);
					arrayLoc++;
				}
				startNode = &nodes[0];
			}
			
			else if(i == 2) {
				if(!checkNode(line)) {
					nodes[1] = Node(line);
					arrayLoc++;
				}
				endNode = &nodes[1];
			}

			else {
				std::vector<std::string> lineData;
				std::stringstream linestream(line);
				std::string value;
				while(linestream >> value) {
					lineData.push_back(value);
				}
				int j = 0;
				Node* workingNode;
				while(j <= 5) {
					//std::cout << "line data: " << lineData[j] << std::endl;
					if(j == 0) {
						if(!checkNode(lineData[j])) {
							nodes[arrayLoc] = Node(lineData[j]);
							arrayLoc++;
						}
						workingNode = getNode(lineData[j]);
						//std::cout << "working name " << workingNode->getNodeName() << std::endl;
					}
					else if(j == 5) {
						if(lineData[j] == "*")
							workingNode->attachSnakeLadderNode(NULL);
						else if(!checkNode(lineData[j])) {
							nodes[arrayLoc] = Node(lineData[j]);
							arrayLoc++;
							workingNode->attachSnakeLadderNode(getNode(lineData[j]));
						}
						else workingNode->attachSnakeLadderNode(getNode(lineData[j]));
					}
					else {
						if(lineData[j] == "*")
							workingNode->attachNewNode(NULL, j-1);
						else if(!checkNode(lineData[j])) {
							nodes[arrayLoc] = Node(lineData[j]);
							arrayLoc++;
							workingNode->attachNewNode(getNode(lineData[j]), j-1);
						}
						else workingNode->attachNewNode(getNode(lineData[j]), j-1);
					}
					j++;
				}
			}
			//std::cout << "What's going on down here?" << std::endl;
			i++;
		}
		istream.close();
	}
	else std::cout << "Couldn't open file with given name";
	
}

bool Game::checkNode(std::string name) {
	for(int i = 0; i < numNodes; i++) {
		if(nodes[i].getNodeName() == name)
			return true;
	}
	return false;
}

Node* Game::getNode(std::string name) {
	for(int i = 0; i < numNodes; i++) {
		if(nodes[i].getNodeName() == name) {
			//std::cout<< "LOL " << nodes[i].getNodeName() << std::endl;
			return &nodes[i];
		}
	}
	//Node n = Node();
	return NULL;
}

void Game::movePlayer(Node *node) {
	currentNode = node;
	path.insert(path.begin(), currentNode->getNodeName());
}

void Game::printOptions() {
	fileParse(file);
	currentNode = startNode;
	path.insert(path.begin(), currentNode->getNodeName());
	std::cout << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << " \t Welcome to The Maze Game! " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	//std::cout << "START " << startNode << std::endl;
	//std::cout << "START 2 " << &nodes[0] << std::endl;
	while(1) {
		std::cout << "------------------------------" << std::endl;	
		std::cout << "You are currently on Node " << currentNode->getNodeName() << std::endl;
		std::cout << "------------------------------" << std::endl;
		//std::cout << "Current path: " << std::endl;
 		//printPath();
		//std::cout << "Current Node address N " << currentNode->getAttachedNode(0) << std::endl;
		//std::cout << "Current Node address E " << currentNode->getAttachedNode(1) << std::endl;
		//std::cout << "Current Node address S " << currentNode->getAttachedNode(2) << std::endl;
		//std::cout << "Current Node address W " << currentNode->getAttachedNode(3) << std::endl;
		//std::cout << "Current Node address of N " << getNode("B1") << std::endl;
		bool n, e, s, w;
		n = e = s = w = false;
		//std::cout << "BOOLS" << n << " " << e << " " << s << " " << w << std::endl;
		int i = 0;
		while(i < 4){
			switch(i) {
				case 0:
					if(currentNode->getAttachedNode(0) != 0)
						n = true;
					break;
				case 1:
					if(currentNode->getAttachedNode(1) != 0)
						e = true;
					break;
				case 2:
					if(currentNode->getAttachedNode(2) != 0)
						s = true;
					break;
				case 3:
					if(currentNode->getAttachedNode(3) != 0)
						w = true;
					break;
			}
			i++;
		} 
	
		std::cout <<"You can go: ";
		if(n)
			std::cout << "North ";
		if(e)
			std::cout << "East ";
		if(s)
			std::cout << "South ";
		if(w)
			std::cout << "West";
		std::cout << std::endl;
		std::cout << "What is your choice? (n, e, s, w, q (to quit))" << std::endl;
		std::string choice;
		getline(std::cin, choice);
		bool ans = true;
		if(choice != "n" && choice != "e" && choice != "s" && choice != "w" && choice != "q")
			ans = false;
		if( (!n && choice == "n") || (!e && choice == "e") || (!s && choice == "s") || (!w && choice == "w"))
			ans = false; 
		//add check here for bad nodes
		while(!ans) {
			std::cout << "Not a valid response." << std::endl;
			std::cout << "What is your choice? (n, e, s, w, q (to quit))" << std::endl;
			choice = "";
			getline(std::cin, choice);
			if((choice == "n" && n) || (choice == "e" && e) || (choice == "s" && s) || (choice == "w" && w) || choice == "q")
				ans = true;
		}
		if(choice == "n")
			movePlayer(currentNode->getAttachedNode(0));
		else if(choice == "e")
			movePlayer(currentNode->getAttachedNode(1));
		else if(choice == "s")
			movePlayer(currentNode->getAttachedNode(2));
		else if(choice == "w")
			movePlayer(currentNode->getAttachedNode(3));
		else if(choice == "q")
			break;

		if(currentNode->getSnakeLadderNode() != NULL) {
			std::cout << "Ladder Node on " << currentNode->getNodeName() << "!" << std::endl;
			movePlayer(currentNode->getSnakeLadderNode());
		}//check snake/ladder
		if(currentNode == endNode) {
			std::cout << "Congratulations! You reached the end!" << std::endl;
			std::cout << "Path taken: ";
			printPath();
			break;
		}
		//check if end
	}
}

void Game::printPath() { 
	std::vector<std::string>::iterator it;
	for(it = path.begin(); it != path.end(); it++) {
		std::cout << (*it) << ", ";
	}
}








