#include "Node.h"
#include <iostream>
Node::Node(std::string newname) {
	name = newname;
	
}

Node::Node() {
}

void Node::setNodeName(std::string newname) {
	name = newname;
}

std::string Node::getNodeName() {
	return name;
}

void Node::attachNewNode(Node *newNode, int direction) {
	//std::cout << &*newNode << " ADDRESS" << std::endl;
	attachedNodes[direction] = &*newNode;
}

Node *Node::getAttachedNode(int direction) {
	return attachedNodes[direction];
}

void Node::attachSnakeLadderNode(Node *newNode) {
	snakeOrLadderNodes = newNode;
}

Node* Node::getSnakeLadderNode() {
	return snakeOrLadderNodes;
}
