#ifndef __items__
#define __items__

#include "entity.h"

class Items : public Entity
{
public:

public:
	Items(const char* name, const char* desc) : Entity(name, desc){};
	//Items(const Items& copy) : Entity(copy.name.c_str, copy.desc.c_str){};
	~Items(){};
};

#endif //__items__