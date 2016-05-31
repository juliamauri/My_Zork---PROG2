#ifndef __EXITS_H__
#define __EXITS_H__

#include "Entity.h"
#include "Rooms.h"

class Exits : public Entity
{
public:
	bool door = false;
	Rooms* origin = nullptr;
	Rooms* destiny = nullptr;
	char dir_dest;

public:
	Exits(const char* name, const char* desc, const char& dir_dest, Rooms* o, Rooms* d, EntityType type) : Entity(name, desc, type), dir_dest(dir_dest), origin(o), destiny(d){};
	~Exits(){};
};

#endif //__EXITS_H__