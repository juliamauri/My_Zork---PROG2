#ifndef __items__
#define __items__

#include "entity.h"

class Items : public Entity
{
public:
	bool objectsarea;
	unsigned int itemcarry = NULL;
	unsigned int max_itemcarry = NULL;

public:
	Items(const char* name, const char* desc, bool objectsarea = false, unsigned int max_itemcarry = 2) : Entity(name, desc), objectsarea(objectsarea), max_itemcarry(max_itemcarry){};
	~Items(){};
};

#endif //__items__