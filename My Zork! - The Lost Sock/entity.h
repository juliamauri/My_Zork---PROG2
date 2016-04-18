#ifndef __entity__
#define __entity__

#include "My_String.h"
#include "VectorDynamic.h"

class Rooms;
class Exits;
class Items;
class Players;

class Entity
{
public:
	My_String name;
	My_String desc;
	Vector<Rooms*> room;
	Vector<Exits*> exit;
	Vector<Players*> player;
	Vector< Items* > item;

public:
	Entity(const char* name, const char* desc) : name(name), desc(desc){};
	~Entity(){};

	void Desc();
};

#endif //__entity__