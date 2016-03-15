#ifndef __world__
#define __world__

#include "rooms.h"
#include "exits.h"
class Players;

class World
{
public:
	bool loop = true;

	Rooms* room = nullptr;
	Exits* exit = nullptr;
	Players* player = nullptr;

public:
	World();
	~World();

	void CreateWorld();
	void Command();
	void Loop();

};

#endif //__world__