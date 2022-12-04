#ifndef NODE_H
#define NODE_H
#include <iostream>

class node
{
	public:
		std::string data;
		long long up;
		node *next;
		node(char data) : data(data), next(NULL) {}
};

#endif
