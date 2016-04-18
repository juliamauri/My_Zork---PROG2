#ifndef __exits__
#define __exits__

#include "entity.h"
#include "rooms.h"

class Exits : public Entity
{
public:
	bool door = false;
	Rooms* origin = nullptr;
	Rooms* destiny = nullptr;
	char dir_dest;

public:
	Exits(const char* name, const char* desc, const char& dir_dest, Rooms* o, Rooms* d) : Entity(name, desc), dir_dest(dir_dest), origin(o), destiny(d){};
	~Exits()
	{
	};
};

#endif //__exits__