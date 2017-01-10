#ifndef NODE_H
#define NODE_H

#include <string>
class Node {
	public:
		Node(std::string newname);
		Node();
		void setNodeName(std::string newname);
		std::string getNodeName();
		void attachNewNode(Node *newNode, int direction);
		Node *getAttachedNode(int direction);
		void attachSnakeLadderNode(Node *newNode);
		Node *getSnakeLadderNode();
	private:
		std::string name;
		Node *attachedNodes[4];
		Node *snakeOrLadderNodes;
};
#endif
