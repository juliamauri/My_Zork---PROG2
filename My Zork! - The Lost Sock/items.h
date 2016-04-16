#ifndef __items__
#define __items__

#include "entity.h"

class Items : public Entity
{
public:
	bool objectsarea;
public:
	Items(const char* name, const char* desc, bool objectsarea = false) : Entity(name, desc), objectsarea(objectsarea){};
	//Items(const Items& copy) : Entity(copy.name.c_str, copy.desc.c_str){};
	~Items(){};
};

#endif //__items__