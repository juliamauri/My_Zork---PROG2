#ifndef __rooms__
#define __rooms__

#include "entity.h"
#include "VectorDynamic.h"
#include "My_String.h"
#include "items.h"

class Rooms : public Entity
{
public:
	My_String descext;
	Vector<Items*> itemlist;

public:
	Rooms(const char* name, const char* desc, const char* descext) : Entity(name, desc), descext(descext){};
	~Rooms(){};
};

#endif //__rooms__