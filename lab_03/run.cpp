
#include "Game.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	cout << "Enter name of maze file: " << endl;
	string file;	
	getline(cin, file);
	//cout << file << " file before call" << endl;
	Game g = Game(file);
	g.printOptions();
	 
}
