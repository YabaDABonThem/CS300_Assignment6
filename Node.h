#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "UPCEntry.h"

class node
{
	public:
		UPCEntry upc;
		node *next;
		node(const UPCEntry& upc) : upc(upc), next(nullptr) {}
};

#endif
