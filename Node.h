#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		char data;
		Node *next;
		Node(char data) : data(data), next(NULL) {}
};

#endif
