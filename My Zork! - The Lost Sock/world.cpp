#include "world.h"

World::World()
{
	room = new Rooms[2];
}

World::~World()
{
	delete[] room;
}