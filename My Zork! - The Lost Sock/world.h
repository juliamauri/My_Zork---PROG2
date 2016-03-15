#ifndef __world__
#define __world__

#define NUM_CONNECTIONS 9
#define NUM_ROOMS 11

#include "rooms.h"
class Exits;
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