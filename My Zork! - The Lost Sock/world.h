#ifndef __world__
#define __world__

#define NUM_ROOMS 11
#define NUM_CONNECTIONS 9  //NUM_ROMS - 1 - (NUM_WORLDS(in my case, 2) - 1)

#include "rooms.h"
#include "exits.h"
class Players;

class World
{
	friend class Rooms;
	friend class Exits;
	friend class Players;

private:
	bool loop = true;

	Rooms* room = nullptr;
	Exits* exit = nullptr;
	Players* player = nullptr;

public:
	World();
	~World();

	void CreateWorld();
	void Command();
	void Help();
	void Loop();
};

#endif //__world__